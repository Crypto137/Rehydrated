#include "recomp/network/pc_proxy.h"

#include <cstring>
#include <string>

#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/memory_utils.h"
#include "core/network/tcp_session.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"
#include "game/sigma/type_descriptor/type_descriptor.h"
#include "recomp/network/game_message_dumper.h"
#include "recomp/network/game_message_encoder.h"
#include "recomp/network/game_message_translator.h"
#include "recomp/network/xencoder.h"

REXCVAR_DEFINE_BOOL(server_pc_proxy_enabled, false, "Hydra/Server", "Enables PC server mode")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REX_IMPORT(__imp__NetworkGetDecodeBuffer, Guest_NetworkGetDecodeBuffer, u32());
REX_IMPORT(__imp__ServerEventReceive, Guest_ServerEventReceive, void(u32, u32));
REX_IMPORT(__imp__XServerSocketDisconnect, Guest_XServerSocketDisconnect, void(i32, i32));
REX_IMPORT(__imp__ServerSendOutOfGameMessage, Guest_ServerSendOutOfGameMessage, void(i32, u32, i32, u32));

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
    m_guestSocketId(0)
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

    //REXLOG_INFO("OnServerSendOutgoingMessagesForGameConnection(): dwSize={}", dwSize);

    std::shared_ptr<TcpSession> session = m_tcpServer.GetFirstSession();
    if (session)
        session->Send(encodeBuffer, dwSize);
}

void PCProxy::OnPostXServerReadUpdate()
{
    if (!m_isEnabled)
        return;

    if (!m_guestSocketId)
        return;

    m_isReadingUpdate = true;

    std::unique_lock<std::mutex> lock(m_pcMessageMutex);

    u32 ptDecodeBufferGuest = Guest_NetworkGetDecodeBuffer();
    char* ptDecodeBuffer = MemoryUtils::GetHostPtr<char>(ptDecodeBufferGuest);

    while (!m_pcMessageQueue.empty())
    {
        auto it = m_pcMessageQueue.begin();
        std::memcpy(ptDecodeBuffer, it->get(), kEncodeBufferSize);
        m_pcMessageQueue.pop_front();
        
        Guest_ServerEventReceive(m_guestSocketId, ptDecodeBufferGuest);
    }

    m_isReadingUpdate = false;
}

bool PCProxy::OnServerEventReceive(u32 idServerSocket, u32 pMessage)
{
    if (!m_isEnabled)
        return false;

    // Suppress X360 client messages
    return !m_isReadingUpdate;
}

void PCProxy::OnServerSocketDisconnect(u32 idServerSocket, i32 eReason)
{
    if (!m_isEnabled)
        return;

    REXLOG_INFO("OnServerSocketDisconnect(): idServerSocket=0x{:08X}, eReason={}", idServerSocket, eReason);

    if (m_guestSocketId == idServerSocket)
    {
        m_guestSocketId = 0;

        std::shared_ptr<TcpSession> session = m_tcpServer.GetFirstSession();
        if (session)
            session->Disconnect();
    }
}

void PCProxy::OnConnectionAccepted(u32 idServerSocket)
{
    if (!m_isEnabled)
        return;

    REXLOG_INFO("OnConnectionAccepted(): idServerSocket=0x{:08X}", idServerSocket);

    if (m_guestSocketId)
    {
        REXLOG_WARN("OnConnectionAccepted(): Already bound to guest socket 0x{:08X}", m_guestSocketId);
        return;
    }

    m_guestSocketId = idServerSocket;
}

size_t PCProxy::OnDataReceived(TcpSession* session, const char* buf, size_t len)
{
    if (!m_isEnabled)
        return len;

    // This is roughly equivalent to NetworkParseGameDataBlock().
    size_t consumed = 0;

    while (consumed < len)
    {
        if (len < 4)
            break;

        XDecoder tDecoder = {};
        tDecoder.SetData(buf + consumed, len);
        
        u32 dwSize = 0;
        if (tDecoder.Get(dwSize, 32))
            break;

        if (dwSize > kEncodeBufferSize || dwSize > len)
            break;

        ReceiveMessages(buf + consumed + 4, dwSize - 4);

        len -= dwSize;
        consumed += dwSize;
    }

    return consumed;
}

void PCProxy::ReceiveMessages(const char* buf, size_t len)
{
    std::unique_lock<std::mutex> lock(m_pcMessageMutex);

    // This is roughly equivalent to sXServerReceive
    char* ptDecodeBuffer = GetDecodeBuffer();

    XDecoder tDecoder = {};
    tDecoder.SetData(buf, len);

    while (tDecoder.GetUsed() < tDecoder.GetSize())
    {
        size_t msgStart = tDecoder.GetUsed();

        // We just read the id directly instead of using the whole type descriptor
        // the original code does here.
        u32 dwType = 0;
        tDecoder.Get(dwType, 9);

        GameMessageType eType = GameMessageTranslator::ConvertMessageTypePCToConsole(static_cast<GameMessageType>(dwType));
        if (eType == MSG_INVALID)
        {
            REXLOG_WARN("Received invalid message id {}", dwType);
            break;
        }

        if (eType == CMSG_KEEPALIVE)
            continue;

        tDecoder.SetUsed(msgStart);

        XDecoder::Result result = GameMessageEncoder::DecodeMessage(eType, ptDecodeBuffer, kEncodeBufferSize, tDecoder);
        if (result)
        {
            if (result == XDecoder::RESULT_TRUNCATED)
                REXLOG_WARN("Received truncated message (id={})", static_cast<int>(eType));
            else if (result == XDecoder::RESULT_CORRUPTED)
                REXLOG_WARN("Received corrupted message (id={})", static_cast<int>(eType));
            else
                REXLOG_WARN("Received bad message (id={}, result={})", static_cast<int>(eType), static_cast<int>(result));
            break;
        }

        REXLOG_INFO("Incoming PC message: {}", GameMessageDumper::PrintGameMessage(ptDecodeBuffer));

        if (eType != CMSG_JOIN_BNET_GAME)
        {
            std::unique_ptr<char[]> ptMessageBuffer = std::make_unique<char[]>(kEncodeBufferSize);
            std::memcpy(ptMessageBuffer.get(), ptDecodeBuffer, kEncodeBufferSize);
            m_pcMessageQueue.push_back(std::move(ptMessageBuffer));
        }
    }
}
