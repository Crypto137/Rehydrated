#pragma once

#include "core/memory.h"
#include "game/types.h"

namespace OnlineService
{

struct GameId
{
    be<u64> m_uMatchmakerGuid;
    be<u64> m_uGameServerGuid;
    be<u32> m_uGameInstanceId;
};

// Both HeroId and GameAccountHandle are also referred to as EntityId

struct HeroId
{
    be<u64> id_high;
    be<u64> id_low;
};

struct GameAccountHandle
{
    be<u64> id_high;
    be<u64> id_low;
};

}

struct GameParams
{
    be<u32> bValid;
    be<SNO> snoInitialWorld;
    be<SNO> snoInitialQuest;
    be<u32> nInitialQuestStepUID;
    be<SNO> snoInitialHero;
    be<u32> bResumeFromSave;
    be<u32> dwSeed;
    be<u32> eGameType;
    be<u32> dwCreationFlags;
    be<u32> dword24;   // dwInitialUpdateCount
    be<u32> dword28;   // dwMaxGameTime
    be<u32> dword2C;   // eMode
    be<u32> nGameParts;
    be<u32> eDifficulty;
    be<u32> nHandicapLevel;
    be<Act> eAct;
    be<u32> dword40;   // tTemplate
    be<u32> dword44;
    be<u32> dword48;
    be<u32> dword4C;
    be<u32> dword50;
    be<u32> dword54;
    be<u32> dword58;
    be<u32> dword5C;
    be<u32> dword60;
    be<u32> dword64;   // uEntranceGUIDOverride
    char szServerAddress[260];
    be<u32> dword16C;  // idGameConnection
    char szReplayFileName[260];
    char szGameName[260];
    be<u32> dword378;
    be<u32> dword37C;
    OnlineService::GameId tGameId;
    OnlineService::HeroId uHeroId;
    be<u64> uServerAuthToken;
    be<SGameID> idSGame;
};
