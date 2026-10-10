#include "recomp/hooks.h"
#include "game/game.h"
#include "game/network.h"
#include "core/memory_utils.h"

#include <rex/logging.h>

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

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3)
{
    const int* pMessage = MemoryUtils::GetHostPtr<int>(r3.u32);

    GameMessageType eType = static_cast<GameMessageType>(MemoryUtils::Byteswap(pMessage[1]));

    REXLOG_INFO("ClientMessageReceiveGameMessage(): eType={}", GameMessageTypeToName(eType));
}
