#include "recomp/hooks.h"
#include "game/game.h"
#include "game/network.h"
#include "game/sigma/type_descriptor/type_descriptor.h"
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
    rex::TypedGuestPointer<ComplexTypeDescriptor>* pRegistrationHead = MemoryUtils::GetHostPtr<rex::TypedGuestPointer<ComplexTypeDescriptor>>(ComplexTypeDescriptor::pRegistrationHead);

    ComplexTypeDescriptor* ptTypeDesc = MemoryUtils::GetHostPtr<ComplexTypeDescriptor>(*pRegistrationHead);
    while (ptTypeDesc)
    {
        REXLOG_INFO("ComplexTypeDescriptor: szName={}, nVersion={}, nFieldCount={}, dwFlags=0x{:08X}",
            MemoryUtils::GetHostPtr<char>(ptTypeDesc->szName),
            static_cast<i32>(ptTypeDesc->nVersion),
            static_cast<i32>(ptTypeDesc->nFieldCount),
            static_cast<u32>(ptTypeDesc->dwFlags));

        ptTypeDesc = MemoryUtils::GetHostPtr<ComplexTypeDescriptor>(ptTypeDesc->pNextRegisteredDescriptor);
    }

    REXLOG_INFO("NetworkInitializeForApp finished");
}

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4)
{
    int nPlayerIndex = static_cast<int>(r3.s32);
    const int* pMessage = MemoryUtils::GetHostPtr<int>(r4.u32);

    GameMessageType eType = static_cast<GameMessageType>(rex::byte_swap(pMessage[1]));

    REXLOG_INFO("ServerMessageReceive(): [{}] eType={}", nPlayerIndex, GameMessageTypeToName(eType));
}
