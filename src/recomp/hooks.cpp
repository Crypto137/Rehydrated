#include "recomp/hooks.h"

#include <vector>

#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/game.h"
#include "game/target.h"
#include "game/types.h"
#include "recomp/input_manager.h"
#include "recomp/static_data_dumper.h"
#include "recomp/network/game_message_dumper.h"
#include "recomp/network/pc_proxy.h"

struct RequiredMessageHeader;
struct GameConnection;

// Game

void HydraHook_ItemIsLargeSlotItem(PPCRegister& r3)
{
    GBID gbidItem = r3.u32;
    r3.u32 = PCProxy::Instance().ItemIsLargeSlotItem(gbidItem) ? 1 : 0;
}

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

void HydraHook_LootCreateItem_IsItemQualityLevelDropUnidentified(PPCRegister& r25, PPCRegister& r26)
{
    ItemQualityLevel eIQL = static_cast<ItemQualityLevel>(r25.s32);
    i32& bIsIdentified = r26.s32;

    // TODO: make this configurable
    if (eIQL >= IQL_RARE_4_AFFIX && eIQL <= IQL_RARE_6_AFFIX)
        bIsIdentified = 0;
}

// Input
void HydraHook_InputPlatformKeyConvert(PPCRegister& r3)
{
    // Don't need to do anything, just keep the original value passed in r3 as is.
    // We have this hook so that InputPlatformKeyConvert() calls don't crash the game.
}

void HydraHook_InputUpdate()
{
    InputManager::Instance().OnGuestInputUpdate();
}

void HydraHook_CPlayerUtilGetTarget(PPCRegister& r3, PPCRegister& r4, PPCRegister& r5, PPCRegister& r6, PPCRegister& r7, PPCRegister& r8)
{
    // Clear the ResolvedClick pointer to force this function to go through the full path like on PC.
    r8.s32 = 0;
}

// Network

bool HydraHook_Console_Online_PartyCanStartGame(PPCRegister& r3)
{
    if (!PCProxy::Instance().PartyCanStartGame())
    {
        r3.u32 = 0;
        return false;
    }

    return true;
}

void HydraHook_ClientMessageReceiveAllMessage(PPCRegister& r3)
{
    RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r3.u32);

    // not using this for anything right now
}

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3)
{
    RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r3.u32);

    // not using this for anything right now
}

void HydraHook_PostXServerReadUpdate()
{
    PCProxy::Instance().OnPostXServerReadUpdate();
}

void HydraHook_ServerSendOutgoingMessagesForGameConnection(PPCRegister& r3)
{
    GameConnection* ptGameConnection = MemoryUtils::GetHostPtr<GameConnection>(r3.u32);

    GameMessageDumper::OnServerSendOutgoingMessages(ptGameConnection);

    PCProxy::Instance().OnServerSendOutgoingMessagesForGameConnection(ptGameConnection);
}

bool HydraHook_ServerEventReceive(PPCRegister& r3, PPCRegister& r4)
{
    u32 idServerSocket = r3.u32;
    u32 pMessage = r4.u32;

    // return true to prevent client data from being routed to game instances
    return PCProxy::Instance().OnServerEventReceive(idServerSocket, pMessage);
}

bool HydraHook_ServerPutMessageOnOutgoingQueue(PPCRegister& r3, PPCRegister& r4)
{
    u32 idGameConnection = r3.u32;
    u32 pMessage = r4.u32;

    // return true to prevent message from being sent to the X360 client
    return PCProxy::Instance().OnServerPutMessageOnOutgoingQueue(idGameConnection, pMessage);
}

void HydraHook_XServerSocketDisconnect(PPCRegister& r3, PPCRegister& r4)
{
    u32 idServerSocket = r3.u32;
    i32 eReason = r4.s32;

    PCProxy::Instance().OnServerSocketDisconnect(idServerSocket, eReason);
}

void HydraHook_XServerReadUpdate_OnJoined(PPCRegister& r3)
{
    u32 idServerSocket = r3.u32;

    PCProxy::Instance().OnConnectionAccepted(idServerSocket);
}

void HydraHook_ServerMessageReceiveOutsideGame(PPCRegister& r3, PPCRegister& r4)
{
    int idServerSocket = r3.s32;
    RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r4.u32);

    GameMessageDumper::OnServerMessageReceiveOutsideGame(idServerSocket, pMessage);
}

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4)
{
    int nPlayerIndex = static_cast<int>(r3.s32);
    RequiredMessageHeader* pMessage = MemoryUtils::GetHostPtr<RequiredMessageHeader>(r4.u32);

    // not using this for anything right now
}

// Subsystem

void HydraHook_PostNetworkInitializeForApp()
{
    StaticDataDumper::OnNetworkInitializeForAppFinished();
}

void HydraHook_PostFastAttribInitializeForApp()
{
    StaticDataDumper::OnFastAttribInitializeForAppFinished();
}
