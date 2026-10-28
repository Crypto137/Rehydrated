#include "recomp/network/pc_proxy.h"

#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/memory_utils.h"
#include "core/network/tcp_session.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"
#include "recomp/network/game_message_encoder.h"
#include "recomp/network/game_message_translator.h"
#include "recomp/network/xencoder.h"

REXCVAR_DEFINE_BOOL(server_pc_proxy_enabled, false, "Hydra/Server", "Enables PC server mode")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REX_IMPORT(__imp__NetworkGetDecodeBuffer, Guest_NetworkGetDecodeBuffer, u32());
REX_IMPORT(__imp__ServerEventReceive, Guest_ServerEventReceive, void(u32, u32));

namespace
{

// We can't use buffer sizes larger than 0x8000 because this is what the PC code uses for decoding.
constexpr u32 kEncodeBufferSize = 0x8000;

char* GetEncodeBuffer()
{
    thread_local std::unique_ptr<char[]> buffer = std::make_unique<char[]>(kEncodeBufferSize);
    return buffer.get();
}

char* GetDecodeBuffer()
{
    thread_local std::unique_ptr<char[]> buffer = std::make_unique<char[]>(kEncodeBufferSize);
    return buffer.get();
}

}

PCProxy::PCProxy() :
    m_isEnabled(REXCVAR_GET(server_pc_proxy_enabled)),
    m_isReadingUpdate(false),
    m_tcpServer(this),
    m_lastGuestSocketId(0)
{
}

void PCProxy::Initialize()
{
    if (!m_isEnabled)
        return;

    m_tcpServer.Start("0.0.0.0", "6112");

    REXLOG_INFO("PC proxy initialized and started");
}

bool PCProxy::PartyCanStartGame()
{
    if (m_isEnabled)
    {
        if (!m_tcpServer.HasActiveSessions())
            return false;
    }

    return true;
}

void PCProxy::OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection)
{
    XEncoder encoder = {};
    char* encodeBuffer = GetEncodeBuffer();

    encoder.SetData(encodeBuffer, kEncodeBufferSize);
    encoder.SetUsed(32);

    TPacketBufferListNode* listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(ptGameConnection->tOutgoingPacketBufferList.m_pHead);
    while (listNode)
    {
        PacketBuffer* tPacketBuffer = MemoryUtils::GetHostPtr<PacketBuffer>(listNode->m_tData);
        RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(listNode->m_tData + 8);
        
        // TODO: Handle persistence messages separately?
        GameMessageType pcType = GameMessageTranslator::ConvertMessageTypeConsoleToPC(pMessage->eType);
        if (GameMessageTranslator::IsMessagePCCompatible(pMessage))
        {
            // Stop when the encode buffer is filled. This may potentially cause issues on initial load
            // because we drop some messages, so some things may end up being sent twice.
            if (!GameMessageEncoder::EncodeMessage(pMessage, encoder))
                break;
        }

        listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(listNode->m_pNext);
    }

    size_t dwSize = encoder.GetUsedBytes();
    if (dwSize <= 4)
        return;

    encoder.SetUsed(0);
    encoder.Put(dwSize, 32);

    REXLOG_INFO("OnServerSendOutgoingMessagesForGameConnection(): dwSize={}", dwSize);

    std::shared_ptr<TcpSession> session = m_tcpServer.GetFirstSession();
    if (session)
        session->Send(encodeBuffer, dwSize);
}

void PCProxy::OnPostXServerReadUpdate()
{
    if (!m_isEnabled)
        return;

    if (!m_lastGuestSocketId)
        return;

    m_isReadingUpdate = true;

    // TODO: inject received PC messages by calling ServerEventReceive (guest)
    // copy message data to buffer returned by NetworkGetDecodeBuffer() before passing
    //u32 ptDecodeBufferGuest = Guest_NetworkGetDecodeBuffer();
    //char* ptDecodeBuffer = MemoryUtils::GetHostPtr<char>(ptDecodeBufferGuest);
    //std::memcpy(nullptr, nullptr, 0);
    //Guest_ServerEventReceive(m_lastGuestSocketId, ptDecodeBufferGuest);

    m_isReadingUpdate = false;
}

bool PCProxy::OnServerEventReceive(u32 idServerSocket, u32 pMessage)
{
    if (!m_isEnabled)
        return false;

    m_lastGuestSocketId = idServerSocket;

    // Suppress X360 client messages
    return !m_isReadingUpdate;
}

size_t PCProxy::OnDataReceived(TcpSession* session, const char* buf, size_t len)
{
    // This is roughly equivalent to NetworkParseGameDataBlock().

    // TODO: decode and queue messages to be passed to games in OnPostXServerReadUpdate()

    if (len < 4)
        return 0;

    // TODO: handle PC client input
    REXLOG_INFO("OnDataReceived(): len={}", len);
    return len;
}
