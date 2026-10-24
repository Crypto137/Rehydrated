#include "recomp/network/pc_proxy.h"

#include <cstring>

#include <rex/ppc.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"
#include "recomp/network/game_message_translator.h"

REXCVAR_DEFINE_BOOL(server_pc_proxy_enabled, false, "Hydra/Server", "Enables PC server mode")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REX_IMPORT(__imp__SigmaMemoryNew, Guest_SigmaMemoryNew, u32(u32, u32, u32, u32));
REX_IMPORT(__imp__NetworkGetEncodeBuffer, Guest_NetworkGetEncodeBuffer, u32());
REX_IMPORT(__imp__XEncoder__SetData, Guest_XEncoder__SetData, void(u32, u32, u32));
REX_IMPORT(__imp__XEncoder__SetUsed, Guest_XEncoder__SetUsed, void(u32, u32));
REX_IMPORT(__imp__XEncoder__Put, Guest_XEncoder__Put, void(u32, u32, u32));
REX_IMPORT(__imp__EncodeMessage, Guest_EncodeMessage, i32(u32, u32));

namespace
{

struct XEncoder
{
    rex::be<u32> __vftable;
    rex::be<u32> m_data;
    rex::be<u32> m_size;
    rex::be<u32> m_used;
};

static constexpr u32 kMessageTranslationBufferSize = 0x8000;

static u32 GetMessageTranslationBuffer()
{
    static u32 ptMessageBuffer = Guest_SigmaMemoryNew(kMessageTranslationBufferSize, 4, 0, 0);
    return ptMessageBuffer;
}

}

PCProxy::PCProxy() :
    m_isEnabled(REXCVAR_GET(server_pc_proxy_enabled)),
    m_tcpServer(this)
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
    auto* memory = REX_KERNEL_MEMORY();
    if (!memory)
        return;
    auto* base = memory->virtual_membase();

    rex::CallFrame frame(*rex::runtime::ThreadState::Get()->context());
    rex::ppc::stack_guard guard(frame.ctx);

    // construct XEncoder on the guest stack
    XEncoder encoder = { 0x820200A8, 0, 0, 0 };
    u32 ptEncoderGuest = rex::ppc::stack_push(frame.ctx, base, reinterpret_cast<void*>(&encoder), sizeof(encoder));
    XEncoder* ptEncoderHost = MemoryUtils::GetHostPtr<XEncoder>(ptEncoderGuest);

    u32 encodeBuffer = Guest_NetworkGetEncodeBuffer();

    Guest_XEncoder__SetData(ptEncoderGuest, encodeBuffer, 0x8000);
    Guest_XEncoder__SetUsed(ptEncoderGuest, 32);

    u32 ptMessageTranslationBufferGuest = GetMessageTranslationBuffer();
    char* ptMessageTranslationBufferHost = MemoryUtils::GetHostPtr<char>(ptMessageTranslationBufferGuest);

    TPacketBufferListNode* listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(ptGameConnection->tOutgoingPacketBufferList.m_pHead);
    while (listNode)
    {
        PacketBuffer* tPacketBuffer = MemoryUtils::GetHostPtr<PacketBuffer>(listNode->m_tData);
        RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(listNode->m_tData + 8);
        
        // We copy the console message to our custom buffer to avoid disrupting normal console flow (at least for now)
        assert(pMessage->dwSize <= kMessageTranslationBufferSize);
        std::memcpy(ptMessageTranslationBufferHost, pMessage, pMessage->dwSize);

        // this is where the magic happens (also some messages are dropped if this returns false)
        if (GameMessageTranslator::ConsoleToPC(reinterpret_cast<RequiredMessageHeader*>(ptMessageTranslationBufferHost)))
            Guest_EncodeMessage(listNode->m_tData + 8, ptEncoderGuest); // TODO: replace listNode->m_tData + 8 with ptPCMessageBufferGuest when guest GetGameMessageTypeAndSize is hooked

        listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(listNode->m_pNext);
    }

    u32 dwSize = (ptEncoderHost->m_used + 7) / 8;
    if (dwSize <= 4)
        return;

    Guest_XEncoder__SetUsed(ptEncoderGuest, 0);
    Guest_XEncoder__Put(ptEncoderGuest, dwSize, 32);

    REXLOG_INFO("OnServerSendOutgoingMessagesForGameConnection(): dwSize={}", dwSize);
}

int PCProxy::OnDataReceived(TcpSession* session, const char* buf, int len)
{
    // TODO: handle PC client input
    REXLOG_INFO("OnDataReceived(): len={}", len);
    return len;
}
