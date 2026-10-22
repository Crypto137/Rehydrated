#include "recomp/network/game_message_dumper.h"

#include <rex/cvar.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"
#include "game/network/game_message_type.h"

REXCVAR_DEFINE_BOOL(server_log_outgoing_messages, false, "Hydra/Server", "Logs server -> client messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

REXCVAR_DEFINE_BOOL(server_log_incoming_messages, false, "Hydra/Server", "Logs client -> server messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

void GameMessageDumper::OnServerSendOutgoingMessages(const GameConnection* ptGameConnection)
{
    if (!REXCVAR_GET(server_log_outgoing_messages))
        return;

    i32 nBufferCount = ptGameConnection->tOutgoingPacketBufferList.m_nCount;
    if (!nBufferCount)
        return;

    REXLOG_INFO("OUTGOING PACKET (nMessageCount={})", nBufferCount);

    TPacketBufferListNode* listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(ptGameConnection->tOutgoingPacketBufferList.m_pHead);
    int i = 0;
    while (listNode)
    {
        PacketBuffer* tPacketBuffer = MemoryUtils::GetHostPtr<PacketBuffer>(listNode->m_tData);
        RequiredMessageHeader* pMessage = reinterpret_cast<RequiredMessageHeader*>(&tPacketBuffer->byteData[0]);

        REXLOG_INFO("  [{}] {}", i++, GameMessageTypeToName(pMessage->eType));

        listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(listNode->m_pNext);
    }
}

void GameMessageDumper::OnServerMessageReceiveOutsideGame(int idServerSocket, const RequiredMessageHeader* pMessage)
{
    // TODO: handle this at packet level rather than message level

    if (REXCVAR_GET(server_log_incoming_messages))
        REXLOG_INFO("OnServerMessageReceiveOutsideGame(): [0x{:08X}] eType={}", idServerSocket, GameMessageTypeToName(pMessage->eType));
}
