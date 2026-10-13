#pragma once

#include <rex/types.h>

#include "game/game.h"
#include "game/types.h"
#include "game/world_place.h"
#include "game/network/game_message_type.h"

// Common Structures

struct RequiredMessageHeader
{
    rex::be<u16> dwSize;
    char nControllerIndex;
    char nPadding;
    rex::be<GameMessageType> eType;
};

// Primitive Messages

struct SimpleMessage
{
    RequiredMessageHeader tHeader;
};

struct DWordDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> dwData;
};

struct IntDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nData;
};

struct ANNDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
};

struct PlayerIndexMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
};

struct GenericBlobMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> uBlobSize;
};

// Complex Messages

struct TryConsoleCommand
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    char usMessage[1024];
    WorldPlace tPlaceTarget;
    rex::be<ACDNetworkName> annTarget;
};

// TODO: clean up entries that didn't exist in 17339
enum QuitReason : int
{
    QUIT_REASON_NORMAL,
    QUIT_REASON_REMOVED,
    QUIT_REASON_MISMATCHING_PROTOCOL_VERSION,
    QUIT_REASON_JOIN_FAILED,
    QUIT_REASON_ASSET_MISMATCH,
    QUIT_REASON_ACCOUNT_CREATE_FAILED,
    QUIT_REASON_USING_NDB,
    QUIT_REASON_SHUTDOWN_GAME,
    QUIT_REASON_HARDCORE_DEATH,
    QUIT_REASON_KICKED_BY_PLAYERS,
    QUIT_REASON_GAME_END,
    QUIT_REASON_NOT_LEGAL_FOR_RESTRICTED_PLAYER,
    QUIT_REASON_GAME_HOST_LEFT_NEWLY_CREATED_GAME,
    QUIT_REASON_GAME_ALREADY_OVER,
    QUIT_REASON_COUNT,
};

struct QuitGameMessage
{
    RequiredMessageHeader tHeader;
    rex::be<QuitReason> eReason;
};

struct PreloadSceneDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SSceneID> idSScene;
    rex::be<SNO> snoScene;
    rex::be<SNO> snoLevelAreas[4];
};

struct PreloadACDDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoActor;
    rex::be<WeaponClass> eWeaponClass;
    rex::be<GBID> gbidMonsterAffixes[8];
};

struct JoinBNetGameMessage
{
    RequiredMessageHeader tHeader;
    OnlineService::HeroId uHeroId;
    OnlineService::GameId tGameId;
    rex::be<SGameID> idSGame;   // to be confirmed
    rex::be<u64> uAuthToken;
    rex::be<XLocale> eXLocale;
    rex::be<u32> uProtocolHash;
    rex::be<u32> dwSNOCoreDataHash;
};

struct JoinLANGameMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SGameID> idSGame;
    char szAccount[128];
    char szHero[49];
    rex::be<XLocale> eXLocale;
};

struct JoinConsoleGame
{
    RequiredMessageHeader tHeader;
    rex::be<XLocale> eXLocale;
    char uControllerIndex;
    rex::be<u32> uLicenses;
};

struct VersionsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> uSNOPackHash;
    rex::be<u32> uProtocolHash;
    char szBuildVer[32];
};

struct StackPortionMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItem;
    rex::be<u64> uAmount;
};

enum LogoutContext : int
{
    LOGOUT_CONTEXT_SOLO = 0,
    LOGOUT_CONTEXT_PARTY = 1,
    LOGOUT_CONTEXT_BOTH = 2,
    LOGOUT_CONTEXT_COUNT = 2,
};

struct LogoutContextMessage
{
    RequiredMessageHeader tHeader;
    rex::be<LogoutContext> eLogoutContext;
};

struct LogoutTickTimeMessage
{
    RequiredMessageHeader tHeader;
    rex::be<LogoutContext> eContext;
    rex::be<u32> uMinWaitTicks;
    rex::be<u32> uMaxWaitTicks;
    rex::be<u32> uKickTicks;
};

struct StashIconStateMessage
{
    RequiredMessageHeader tHeader;
    char bStashIcons[3];
};

namespace CombatLog
{

// TODO: clean up entries that didn't exist in 17339
enum LogEventType
{
    LOG_EVENT_INVALID = -1,
    LOG_EVENT_POWER_USE,
    LOG_EVENT_DODGE,
    LOG_EVENT_HIT_ROLL,
    LOG_EVENT_TARGET_INVULNERABLE,
    LOG_EVENT_CRITICAL_HIT,
    LOG_EVENT_DAMAGE_REDUCTION,
    LOG_EVENT_BLOCK_ROLL,
    LOG_EVENT_RESISTANCE_APPLIED,
    LOG_EVENT_DAMAGE_DONE,
    LOG_EVENT_DEATH,
    LOG_EVENT_HEALING_DONE,
    LOG_EVENT_ITEM_PROC_ROLL,
    LOG_EVENT_CRUSHING_BLOW,
};

struct Message
{
    RequiredMessageHeader tHeader;
    rex::be<LogEventType> eEventType;
    rex::be<ACDNetworkName> idACDSource;
    rex::be<ACDNetworkName> idACDTarget;
    rex::be<SNO> snoData;
    rex::be<f32> flParam1;
    rex::be<f32> flParam2;
    rex::be<u32> dwParam1;
};

}  // namespace CombatLog

struct ConnectionEstablishedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    rex::be<u32> dwAnimSyncedSeed;
    rex::be<u32> dwSnoCoreDataHash;
};

struct GameSetupMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> dwFirstHeartbeat;
};

struct HeroStateData
{
    // TODO
};

struct NewPlayerMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    OnlineService::HeroId uHeroId;
    OnlineService::GameAccountHandle tAccountId;
    char usHeroName[49];
    rex::be<Team> eTeam;
    rex::be<PlayerClass> eClass;
    rex::be<SNO> snoActorPortrait;
    rex::be<i32> nCurrentLevel;
    rex::be<i32> nCurrentAltLevel;
    HeroStateData tHeroStateData;
    rex::be<i32> bJustJoined;
    rex::be<GameConnectionID> idGameConnection;
    rex::be<ACDNetworkName> ann;
    char usGamerTag[128];
    rex::be<u64> uAcceptedLicenseBitsHero;
};
