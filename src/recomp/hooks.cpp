#include "recomp/hooks.h"

#include <rex/cvar.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/game.h"
#include "game/network.h"
#include "game/sigma/type_descriptor/type_descriptor.h"
#include "recomp/static_data_dumper.h"

REXCVAR_DEFINE_BOOL(dump_type_descriptors, false, "Development", "Dumps type descriptors on boot")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_BOOL(dump_game_messages, false, "Development", "Dumps game message metadata on boot")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

// Game

void HydraHook_SGameInitializeGame(PPCRegister& r3)
{
    const GameParams* tParams = MemoryUtils::GetHostPtr<GameParams>(r3.u32);

    REXLOG_INFO("SGameInitializeGame():\n bValid=0x{:X},\n snoInitialWorld=0x{:X},\n snoInitialQuest=0x{:X},\n nInitialQuestStepUID=0x{:X},\n dword10=0x{:X},\n bResumeFromSave=0x{:X},\n dwSeed=0x{:X},\n eGameType=0x{:X},\n dwCreationFlags=0x{:X},\n szServerAddress={},\n szReplayFileName={},\n szGameName={}",
        tParams->bValid,
        tParams->snoInitialWorld,
        tParams->snoInitialQuest,
        tParams->nInitialQuestStepUID,
        tParams->dword10,
        tParams->bResumeFromSave,
        tParams->dwSeed,
        tParams->eGameType,
        tParams->dwCreationFlags,
        tParams->szServerAddress,
        tParams->szReplayFileName,
        tParams->szGameName);
}

// Network

void HydraHook_ClientMessageReceiveAllMessage(PPCRegister& r3)
{
    const int* pMessage = MemoryUtils::GetHostPtr<int>(r3.u32);

    GameMessageType eType = static_cast<GameMessageType>(rex::byte_swap(pMessage[1]));

    REXLOG_INFO("ClientMessageReceiveAllMessage(): eType={}", GameMessageTypeToName(eType));
}

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3)
{
    // not using this for anything yet
}

void HydraHook_PostNetworkInitializeForApp()
{
    if (REXCVAR_GET(dump_type_descriptors))
        StaticDataDumper::DumpTypeDescriptors("TypeDescriptors.bin");

    if (REXCVAR_GET(dump_game_messages))
        StaticDataDumper::DumpGameMessages("GameMessages.bin");

    REXLOG_INFO("NetworkInitializeForApp() finished");
}

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4)
{
    int nPlayerIndex = static_cast<int>(r3.s32);
    const int* pMessage = MemoryUtils::GetHostPtr<int>(r4.u32);

    GameMessageType eType = static_cast<GameMessageType>(rex::byte_swap(pMessage[1]));

    REXLOG_INFO("ServerMessageReceive(): [{}] eType={}", nPlayerIndex, GameMessageTypeToName(eType));
}
