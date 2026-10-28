#include "recomp/hooks.h"

#include <vector>

#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/game.h"
#include "recomp/static_data_dumper.h"
#include "recomp/network/game_message_dumper.h"
#include "recomp/network/pc_proxy.h"

struct RequiredMessageHeader;
struct GameConnection;

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

bool HydraHook_XServerSendBuffer(PPCRegister& r3, PPCRegister& r4, PPCRegister& r5)
{
    u32 idServerSocket = r3.u32;
    u32 pMessage = r4.u32;
    u32 dwSize = r5.u32;

    //REXLOG_INFO("XServerSendBuffer(): idServerSocket={:08X}, dwSize={}", idServerSocket, dwSize);
    
    // return true to prevent data from being flushed to the X360 client
    return PCProxy::Instance().IsEnabled();
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
