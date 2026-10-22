#include "recomp/hooks.h"

#include <rex/cvar.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/game.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"
#include "game/sigma/type_descriptor/type_descriptor.h"
#include "recomp/static_data_dumper.h"

REXCVAR_DEFINE_BOOL(dump_type_descriptors, false, "Development", "Dumps type descriptors on boot")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_BOOL(dump_game_messages, false, "Development", "Dumps game message metadata on boot")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_BOOL(dump_attrib_defs, false, "Development", "Dumps attribute definitions on boot")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_BOOL(log_server_messages, false, "Development", "Logs server -> client messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

REXCVAR_DEFINE_BOOL(log_client_messages, false, "Development", "Logs client -> server messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

// Game

void HydraHook_SGameInitializeGame(PPCRegister& r3)
{
    const GameParams* tParams = MemoryUtils::GetHostPtr<GameParams>(r3.u32);

    REXLOG_INFO("SGameInitializeGame():\n  bValid={}\n  snoInitialWorld={}\n  snoInitialQuest={}\n  nInitialQuestStepUID={}\n  snoInitialHero={}\n  bResumeFromSave={}\n  dwSeed={}\n  eGameType={}\n  dwCreationFlags=0x{:08X}\n  szServerAddress={}\n  szReplayFileName={}\n  szGameName={}",
        tParams->bValid.get(),
        static_cast<u32>(tParams->snoInitialWorld.get()),
        static_cast<u32>(tParams->snoInitialQuest.get()),
        tParams->nInitialQuestStepUID.get(),
        static_cast<u32>(tParams->snoInitialHero.get()),
        tParams->bResumeFromSave.get(),
        tParams->dwSeed.get(),
        tParams->eGameType.get(),
        tParams->dwCreationFlags.get(),
        tParams->szServerAddress,
        tParams->szReplayFileName,
        tParams->szGameName);
}

// Input
void HydraHook_PostInputUpdate(PPCRegister& r3)
{
    // not using this for anything yet
}

// Network

void HydraHook_ClientMessageReceiveAllMessage(PPCRegister& r3)
{
    const RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r3.u32);

    // not using this for anything right now
}

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3)
{
    const RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r3.u32);

    // not using this for anything right now
}

void HydraHook_ServerSendOutgoingMessagesForGameConnection(PPCRegister& r3)
{
    GameConnection* ptGameConnection = MemoryUtils::GetHostPtr<GameConnection>(r3.u32);

    if (!REXCVAR_GET(log_server_messages))
        return;

    i32 nBufferCount = ptGameConnection->tOutgoingPacketBufferList.m_nCount;
    if (!nBufferCount)
        return;

    REXLOG_INFO("ServerSendOutgoingMessagesForGameConnection(): count={}", nBufferCount);

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

void HydraHook_ServerMessageReceiveOutsideGame(PPCRegister& r3, PPCRegister& r4)
{
    int idServerSocket = static_cast<int>(r3.s32);
    const RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r4.u32);

    if (REXCVAR_GET(log_client_messages))
        REXLOG_INFO("ServerMessageReceiveOutsideGame(): [0x{:08X}] eType={}", idServerSocket, GameMessageTypeToName(pMessage->eType));
}

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4)
{
    int nPlayerIndex = static_cast<int>(r3.s32);
    const RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r4.u32);

    // not using this for anything right now
}

// Subsystem

void HydraHook_PostNetworkInitializeForApp()
{
    if (REXCVAR_GET(dump_type_descriptors))
        StaticDataDumper::DumpTypeDescriptors("_TypeDescriptors.bin");

    if (REXCVAR_GET(dump_game_messages))
        StaticDataDumper::DumpGameMessages("_GameMessages.bin");

    REXLOG_INFO("NetworkInitializeForApp() finished");
}

void HydraHook_PostFastAttribInitializeForApp()
{
    if (REXCVAR_GET(dump_attrib_defs))
        StaticDataDumper::DumpAttribDefs("_AttribDefs.bin");

    REXLOG_INFO("FastAttribInitializeForApp() finished");
}
