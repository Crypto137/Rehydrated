#pragma once

#include <rex/types.h>

#include "game/types.h"

namespace OnlineService
{

struct GameId
{
    rex::be<u64> m_uMatchmakerGuid;
    rex::be<u64> m_uGameServerGuid;
    rex::be<u32> m_uGameInstanceId;
};

// Both HeroId and GameAccountHandle are also referred to as EntityId

struct HeroId
{
    rex::be<u64> id_high;
    rex::be<u64> id_low;
};

struct GameAccountHandle
{
    rex::be<u64> id_high;
    rex::be<u64> id_low;
};

}

struct GameParams
{
    rex::be<u32> bValid;
    rex::be<SNO> snoInitialWorld;
    rex::be<SNO> snoInitialQuest;
    rex::be<u32> nInitialQuestStepUID;
    rex::be<SNO> snoInitialHero;
    rex::be<u32> bResumeFromSave;
    rex::be<u32> dwSeed;
    rex::be<u32> eGameType;
    rex::be<u32> dwCreationFlags;
    rex::be<u32> dword24;   // dwInitialUpdateCount
    rex::be<u32> dword28;   // dwMaxGameTime
    rex::be<u32> dword2C;   // eMode
    rex::be<u32> nGameParts;
    rex::be<u32> eDifficulty;
    rex::be<u32> nHandicapLevel;
    rex::be<Act> eAct;
    rex::be<u32> dword40;   // tTemplate
    rex::be<u32> dword44;
    rex::be<u32> dword48;
    rex::be<u32> dword4C;
    rex::be<u32> dword50;
    rex::be<u32> dword54;
    rex::be<u32> dword58;
    rex::be<u32> dword5C;
    rex::be<u32> dword60;
    rex::be<u32> dword64;   // uEntranceGUIDOverride
    char szServerAddress[260];
    rex::be<u32> dword16C;  // idGameConnection
    char szReplayFileName[260];
    char szGameName[260];
    rex::be<u32> dword378;
    rex::be<u32> dword37C;
    OnlineService::GameId tGameId;
    OnlineService::HeroId uHeroId;
    rex::be<u64> uServerAuthToken;
    rex::be<SGameID> idSGame;
};
