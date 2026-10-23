#include "recomp/network/pc_proxy.h"

#include <rex/ppc.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/network/game_connection.h"
#include "recomp/network/game_message_translator.h"

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

}

PCProxy::PCProxy() :
    m_isEnabled(false)
{

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
    u32 encoderGuestPtr = rex::ppc::stack_push(frame.ctx, base, reinterpret_cast<void*>(&encoder), sizeof(encoder));
    XEncoder* encoderHostPtr = MemoryUtils::GetHostPtr<XEncoder>(encoderGuestPtr);

    u32 encodeBuffer = Guest_NetworkGetEncodeBuffer();

    Guest_XEncoder__SetData(encoderGuestPtr, encodeBuffer, 0x8000);
    Guest_XEncoder__SetUsed(encoderGuestPtr, 32);

    TPacketBufferListNode* listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(ptGameConnection->tOutgoingPacketBufferList.m_pHead);
    while (listNode)
    {
        PacketBuffer* tPacketBuffer = MemoryUtils::GetHostPtr<PacketBuffer>(listNode->m_tData);
        u32 result = Guest_EncodeMessage(listNode->m_tData + 8, encoderGuestPtr);
        listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(listNode->m_pNext);
    }

    u32 dwSize = (encoderHostPtr->m_used + 7) / 8;
    if (dwSize <= 4)
        return;

    Guest_XEncoder__SetUsed(encoderGuestPtr, 0);
    Guest_XEncoder__Put(encoderGuestPtr, dwSize, 32);

    REXLOG_INFO("OnServerSendOutgoingMessagesForGameConnection(): dwSize={}", dwSize);
}
