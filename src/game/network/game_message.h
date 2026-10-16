#pragma once

#include <rex/types.h>

#include "game/game.h"
#include "game/game_balance.h"
#include "game/scene.h"
#include "game/tags.h"
#include "game/types.h"
#include "game/attributes/attrib.h"
#include "game/world_place.h"
#include "game/network/game_message_type.h"
#include "game/sigma/math/ivector2d.h"
#include "game/sigma/math/transform.h"

// Common Structures

struct RequiredMessageHeader
{
    rex::be<u16> dwSize;
    char nControllerIndex;
    char nPadding;
    rex::be<GameMessageType> eType;
};

template <typename T>
struct XOptional
{
    T m_tValue;
    rex::be<i32> m_bExists;
};

struct SNOName
{
    rex::be<SNOGroup> snoGroup;
    rex::be<SNO> snoHandle;
};

struct RNG
{
    rex::be<u32> dwSeed;
    rex::be<u32> dwCarry;
};

struct RGBAColor
{
    char r;
    char g;
    char b;
    char a;
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

struct BoolDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> bVal;
};

struct DataIDDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<DataID> id;
};

struct ANNDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
};

struct SNODataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoData;
};

struct SNONameDataMessage
{
    RequiredMessageHeader tHeader;
    SNOName snoname;
};

struct GBIDDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<GBID> gbidData;
};

struct PlayerIndexMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
};

struct PlayerDWordDataMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> dwData;
    rex::be<i32> nPlayerIndex;
};

struct GenericBlobMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> uBlobSize;
};

struct PRTransformMessage
{
    RequiredMessageHeader tHeader;
    PRTransform tTransform;
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

struct JoinConsoleGameMessage
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

struct HotbarButtonData
{
    rex::be<SNO> m_snoPower;
    rex::be<RuneType> m_eRuneType;
    rex::be<GBID> m_gbidItem;
};

struct HirelingInfo
{
    rex::be<HirelingClass> eClass;
    rex::be<GBID> gbidName;
    rex::be<i32> field8;    // max 0x7F, bit count 7
    rex::be<i32> field12;
    rex::be<i32> fDead;
    rex::be<i32> arnPowerKeyParam[4];
};

struct HirelingSavedData
{
    HirelingInfo tHireling[4];
    rex::be<HirelingClass> eActiveHireling;
    rex::be<u32> dwAvailableHirelings;
};

struct LearnedLore
{
    rex::be<i32> m_nLearnedCount;
    rex::be<SNO> m_snoLoreLearned[256];
};

struct SavedConversations
{
    rex::be<i32> m_nSavedConvCount;
    char m_arPlayedConv[32];
    rex::be<SNO> m_snoSavedConv[256];
};

struct ActiveSkillSavedData
{
    rex::be<SNO> snoSkill;
    rex::be<RuneType> eRuneType;
};

struct SavePointData
{
    rex::be<SNO> snoWorld;
    rex::be<i32> nNum;
    rex::be<i32> bCreatesPortal;
    rex::be<ACDID> idACDReturnPortal;
};

struct PlayerSavedData
{
    HotbarButtonData tHotbarBtnAssignments[6];
    HotbarButtonData tPotionBtn;
    char bSkillSlotEverAssigned;
    rex::be<u32> uSecondsPlayed;
    rex::be<u32> m_ActivatedWaypoints;
    HirelingSavedData tHirelingSavedData;
    rex::be<u32> uTimeLastLevel;
    LearnedLore tLearnedLore;
    SavedConversations tSavedConversations;     // skipped in the type descriptor
    ActiveSkillSavedData tActiveSkills[6];
    SNO snoTraits[3];
    SavePointData tLastSavePoint;
};

struct PlayerQuestRewardHistoryEntry
{
    rex::be<SNO> snoQuest;
    rex::be<i32> nStepUID;
    char uDifficultyFlags;
};

struct PlayerQuestHistoryEntry
{
    rex::be<SNO> snoQuest;
    rex::be<i32> nStepUID;
    rex::be<DifficultyLevel> eDifficulty;
};

struct PlayerSavedQuest
{
    rex::be<SNO> snoQuest;
    rex::be<DifficultyLevel> eDifficulty;
    rex::be<i32> nCurrentStepUID;
    rex::be<i32> arObjectiveState[20];
    rex::be<i32> arFailureConditionState[20];
};

struct HeroStateData
{
    rex::be<Act> eLastPlayedAct;
    rex::be<Act> eHighestUnlockedAct;
    rex::be<DifficultyLevel> eLastPlayedDifficulty;
    rex::be<DifficultyLevel> eHighestUnlockedDifficulty;
    rex::be<u32> uPlayerFlags;
    PlayerSavedData tSavedData;
    rex::be<i32> nNumQuestRewardEntries;
    PlayerQuestRewardHistoryEntry tQuestRewardHistory[100];
    PlayerQuestHistoryEntry tQuestHistory[200];     // skipped in the type descriptor
    PlayerSavedQuest tSavedQuest[64];               // skipped in the type descriptor
    rex::be<i32> uBossKillFlags[4];
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

struct PlayerKickTimerMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> dwLastKickAttempt;
    rex::be<u32> dwLastSuccessfulKick;
};

struct EnterWorldMessage
{
    RequiredMessageHeader tHeader;
    Vector3D wpLocation;
    rex::be<SWorldID> idSWorld;
    rex::be<SNO> snoWorld;
    rex::be<i32> nPlayerIndex;
};

struct RevealSceneMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SWorldID> idSWorld;
    SceneSpecification tSceneSpec;
    rex::be<SSceneID> idSScene;
    rex::be<SNO> snoScene;
    PRTransform transform;
    rex::be<SSceneID> idSSceneParent;
    rex::be<SNO> snoSceneGroup;
    rex::be<u32> uLabelCount;
    rex::be<GBID> arAppliedLabels[256];
};

struct DestroySceneMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SWorldID> idSWorld;
    rex::be<SSceneID> idSScene;
};

struct SwapSceneMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SWorldID> idSWorld;
    rex::be<SSceneID> idSSceneOld;
    rex::be<SSceneID> idSSceneNew;
};

struct RevealWorldMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SWorldID> idSWorld;
    rex::be<SNO> snoWorld;
    rex::be<i32> nOriginX;
    rex::be<i32> nOriginY;
    rex::be<i32> nStitchSizeInFeetX;
    rex::be<i32> nStitchSizeInFeetY;
    rex::be<i32> nWorldSizeInFeetX;
    rex::be<i32> nWorldSizeInFeetY;
};

struct RevealTeamMessage
{
    RequiredMessageHeader tHeader;
    rex::be<Team> eTeam;
    rex::be<u32> dwTeamFlags;
    rex::be<TeamColor> eTeamColoring;
};

struct PlayerActorSetInitialMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<i32> nPlayerIndex;
};

struct HeroStateMessage
{
    RequiredMessageHeader tHeader;
    HeroStateData tStateData;
    rex::be<i32> nPlayerIndex;
};

struct PlayerSavedDataMessage
{
    RequiredMessageHeader tHeader;
    PlayerSavedData tSavedData;
    rex::be<i32> nPlayerIndex;
};

struct SavePointDataMessage
{
    RequiredMessageHeader tHeader;
    SavePointData tData;
    rex::be<i32> nPlayerIndex;
};

struct WorldLocationMessageData
{
    rex::be<f32> flScale;
    PRTransform transform;
    rex::be<SWorldID> idSWorld;
};

struct InventoryLocationMessageData
{
    rex::be<ACDNetworkName> annContainer;
    rex::be<InventorySlotType> eSlot;
    IVector2D pt;
};

struct ACDEnterKnownMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoActor;
    rex::be<u32> dwFlags;
    rex::be<ActorLocationType> eLocationType;
    XOptional<WorldLocationMessageData> tWorldLocationData;
    XOptional<InventoryLocationMessageData> tInvLocationData;
    GBHandle hGB;
    SNOName tSNOName;
    rex::be<i32> nRarity;
    char nLookLinkIndex;
    XOptional<rex::be<i32>> snoMarkerSet;
    XOptional<rex::be<i32>> nMarkerIndex;
    XOptional<rex::be<i32>> snoAmbientOcclusionOverrideTex;
    XOptional<rex::be<u32>> dwTimeActorCreated;
};

struct PlayerEnterKnownMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    rex::be<ACDNetworkName> ann;
};

struct ACDWorldPositionMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    WorldLocationMessageData tWorldLocationData;
};

struct ACDInventoryPositionMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    InventoryLocationMessageData tInvLocationData;
    rex::be<ActorLocationType> tLocType;
};

struct ACDInventoryUpdateActorSNO
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoActor;
};

enum TrickleInfoType : int
{
    TRICKLE_INFO_INVALID,
    TRICKLE_INFO_LOCAL_PLAYER,
    TRICKLE_INFO_MY_PET,
    TRICKLE_INFO_FRIENDLY_PLAYER,
    TRICKLE_INFO_FRIENDLY_PLAYER_PET,
    TRICKLE_INFO_FOLLOWER_PET,
    TRICKLE_INFO_HOSTILE_PLAYER,
    TRICKLE_INFO_HOSTILE_PLAYER_PET,
    TRICKLE_INFO_NPC,
    TRICKLE_INFO_FRIENDLY_MONSTER,
    TRICKLE_INFO_HOSTILE_MONSTER,
    TRICKLE_INFO_GIZMO,
    TRICKLE_INFO_PVP_FRIENDLY,
    TRICKLE_INFO_PVP_HOSTILE,
    TRICKLE_INFO_PVP_NEUTRAL,
    TRICKLE_INFO_NUM_TYPES,
};

struct TrickleMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoActor;
    WorldPlace tPlace;
    XOptional<rex::be<u32>> nPlayerIndexOwner;
    rex::be<SNO> snoLevelArea;
    XOptional<rex::be<f32>> flHealthPercent;
    rex::be<TrickleInfoType> eTrickleInfoType;
    rex::be<u32> dwTrickleFlags;
    XOptional<rex::be<i32>> dwHeadstoneCorpseReviveTime;
    XOptional<rex::be<i32>> snoMinimapIcon;
    XOptional<rex::be<u32>> hMinimapStringLabel;
    XOptional<rex::be<u32>> hMinimapIconLabel;
    XOptional<rex::be<u32>> snoStringList;
    XOptional<rex::be<f32>> fMinDisplayRangeSq;
    XOptional<rex::be<f32>> fMaxDisplayRangeSq;
    XOptional<rex::be<i32>> field116;    // this is a bool that existed since at least 1.0.0.8370, so it's probably not bBrawling or bInUberFight
    XOptional<rex::be<u32>> field124;
    XOptional<rex::be<u32>> field132;
    // i32 nAction
    // u32 uEngagedWithRareTime
    // u32 uEngagedWithGoblinTime
    // i32 bInCombat
    // i32 nTieredRiftRank
    // i32 bBrawling
    // i32 bInUberFight
    // i32 gbidPortraitFrame
};

struct MapRevealSceneMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SSceneID> idSScene;
    rex::be<SNO> snoScene;
    PRTransform transform;
    rex::be<SWorldID> idSWorld;
    rex::be<i32> bRevealed;
};

struct SavePointInfoMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoLevelArea;
};

struct HearthPortalInfoMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoLevelArea;
    rex::be<ACDNetworkName> annPortal;
};

struct ReturnPointInfoMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoLevelArea;
};

enum AffixMessageFlag : int
{
    AFFIX_MESSAGE_FLAG_INVALID,
    AFFIX_MESSAGE_FLAG_IDENTIFIED,
    AFFIX_MESSAGE_FLAG_UNIDENTIFIED,
    AFFIX_MESSAGE_FLAG_COUNT,
};

struct AffixMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<AffixMessageFlag> eAffixArray;
    rex::be<GBID> aAffixGBIDs[32];
    rex::be<u32> dwAffixArrayCount;
};

struct RareMonsterNamesMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<GBID> pgbidRareNames[2];
    rex::be<GBID> pgbidMonsterAffixes[8];
};

struct RareItemName
{
    rex::be<i32> fItemNameIsPrefix;
    rex::be<SNO> snoAffixStringList;
    rex::be<i32> nAffixStringListIndex;
    rex::be<i32> nItemStringListIndex;
};

struct RareItemNameMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    RareItemName tRareItemName;
};

struct ResolvedPortalDestination
{
    rex::be<SNO> snoWorld;
    rex::be<u32> uEntranceGUID;
    rex::be<SNO> snoDestLevelArea;
};

struct PortalSpecifierMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    ResolvedPortalDestination tResolvedDest;
};

struct NetAttributeKeyValue
{
    XOptional<rex::be<i32>> nKeyParam;
    rex::be<Attrib> eKeyAttrib;
    rex::be<i32> nValue;
};

struct AttributeSetValueMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    NetAttributeKeyValue tKeyVal;
};

struct AttributesSetValuesMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<i32> nAttributeCount;
    NetAttributeKeyValue atKeyVals[15];
};

struct VisualItem
{
    rex::be<GBID> gbidItem;
    rex::be<DyeType> eDyeType;
    rex::be<ItemEffectType> eItemEffectType;
    rex::be<i32> nEffectLevel;
};

struct VisualEquipment
{
    VisualItem tVisualItem[8];
};

struct VisualInventoryMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    VisualEquipment tEquipment;
};

struct ProjectileStickMessage
{
    RequiredMessageHeader tHeader;
    Vector3D wpSourceLoc;
    rex::be<ACDNetworkName> annTarget;
    rex::be<SNO> snoActorAttachment;
};

enum TargetType : int
{
    TT_INVALID = -1,
    TT_NONE,
    TT_ACTOR,
    TT_POINT,
    TT_ACTOR_WITH_FALLBACK_POINT,
    TT_NUM_TYPES,
};

struct AnimPreplayData
{
    rex::be<u32> dwAnimPrePlayDataFlags;
    rex::be<u32> dwServerTimeAnimStarted;
    rex::be<u32> dwSyncedSeed;
};

struct TargetMessage
{
    RequiredMessageHeader tHeader;
    rex::be<TargetType> eType;
    rex::be<ACDNetworkName> annTarget;
    WorldPlace tPlace;
    rex::be<SNO> snoPower;
    rex::be<ACDNetworkName> annItemBeingUsed;
    rex::be<i32> nComboLevel;
    XOptional<AnimPreplayData> tAnimPreplayData;
    XOptional<rex::be<u32>> dwFlags;
};

struct SecondaryAnimationPowerMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoPower;
    XOptional<AnimPreplayData> tAnimPreplayData;
};

struct LoopingAnimationPowerMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoPower;
    rex::be<SNO> snoData0;
    rex::be<i32> nData1;
};

enum TryChatDestination : int
{
    TRY_CHAT_NONE,
    TRY_CHAT_ALL,
    TRY_CHAT_ALL_AND_ME,
    TRY_CHAT_WHISPER,
    TRY_CHAT_TEAMMEMBERS,
    TRY_CHAT_FRIENDLY,
    TRY_CHAT_LOCAL_ECHO,
    TRY_CHAT_NUM_DESTINATIONS,
};

struct TryChatMessage
{
    RequiredMessageHeader tHeader;
    rex::be<TryChatDestination> eDestination;
    rex::be<i32> nPlayerTarget;
    char usMessage[1024];
};

enum EChatColor
{
    CHAT_COLOR_NORMAL,
    CHAT_COLOR_WHISPER,
    CHAT_COLOR_SHOUT,
    CHAT_COLOR_ERROR,
    NUM_CHAT_COLORS,
};

struct ChatMessage
{
    RequiredMessageHeader tHeader;
    rex::be<EChatColor> eColor;
    rex::be<i32> nPlayerIndex;
    char usMessage[1024];
};

struct InvLoc
{
    rex::be<ACDNetworkName> annOwner;
    rex::be<InventorySlotType> eSlot;
    rex::be<i32> nSlotX;
    rex::be<i32> nSlotY;
};

struct InventoryRequestMoveMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItem;
    InvLoc tLocation;
};

struct InventoryRequestQuickMoveMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItem;
    rex::be<ACDNetworkName> annOwner;
    rex::be<InventorySlotType> eSlot;
    rex::be<i32> nSlotMinY;
    rex::be<i32> nSlotMaxY;
};

struct InventoryRequestSocketMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annGem;
    rex::be<ACDNetworkName> annItemToReceiveGem;
};

struct InventorySplitStackMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItem;
    rex::be<u64> uAmount;
    InvLoc tLocation;
};

struct InventoryStackTransferMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItemSrc;
    rex::be<ACDNetworkName> annItemDest;
    rex::be<u64> uAmount;
};

struct GoldTransferMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annPlayer;
    rex::be<u64> uAmount;
};

struct InventoryRequestUseMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItemToUse;
    rex::be<TargetType> eType;
    rex::be<ACDNetworkName> annTarget;
    WorldPlace tPlace;
};

struct HelperDetachMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annHelper;
};

struct AssignSkillMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoPower;
    rex::be<i32> nRuneType;
    rex::be<i32> nSlot;
    rex::be<i32> nPlayerIndex;
};

struct UnassignSkillMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nSlot;
};

struct AssignTraitsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoPower[3];
};

struct HirelingRequestLearnSkillMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoSkill;
};

enum AnimReason : int
{
    ANIM_REASON_NOT_ANIMATING,
    ANIM_REASON_IDLE,
    ANIM_REASON_WALKING,
    ANIM_REASON_POWER,
    ANIM_REASON_SPAWN,
    ANIM_REASON_GIZMO,
    ANIM_REASON_STANCE,
    ANIM_REASON_INTERRUPTABLE_ANIMATION,
    ANIM_REASON_PREPLAY_POWER,
    ANIM_REASON_CUTSCENE,
    ANIM_REASON_PREPLAY_CHANNELLED,
    ANIM_REASON_DEATH,
    ANIM_REASON_FLOAT_CONVERSATION,
    ANIM_REASON_INTERRUPTABLE_ANIMATION_NO_LOOKSWITCH,
    ANIM_REASON_COUNT,
};

struct PlayAnimationMessageSpec
{
    rex::be<u32> dwDuration;
    rex::be<SNO> snoAnim;
    rex::be<u32> dwAnimationTag;
    rex::be<i32> nPermutationIndex;
    rex::be<f32> flAnimSpeedScale;
};

struct PlayAnimationMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<AnimReason> eAnimReason;
    rex::be<f32> flUnitAnimStartTime;
    rex::be<i32> nUsedAnimArrayElements;
    PlayAnimationMessageSpec tAnim[3];
};

struct ACDTranslateNormalMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    XOptional<Vector3D> vDest;
    XOptional<rex::be<Angle>> aDesiredYaw;
    XOptional<rex::be<i32>> bSnapFacing;
    XOptional<rex::be<f32>> flMovementSpeed;
    XOptional<rex::be<u32>> uMoveFlags;
    XOptional<rex::be<ActorAnimationTag>> eAnimTag;
    XOptional<rex::be<u32>> uWalkInPlaceTicks;
    XOptional<rex::be<SNO>> snoPowerPassability;
    XOptional<rex::be<u32>> uAckValue;
    XOptional<rex::be<u32>> eMoveType;
    //XOptional<int> nMaxTicksToWalk
};

struct ACDTranslateSnappedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    Vector3D vDest;
    rex::be<Angle> aDesiredYaw;
    rex::be<i32> bSnapFacing;
    rex::be<u32> uMoveFlags;
    XOptional<rex::be<u32>> uAckValue;
};

struct ACDTranslateFacingMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<Angle> aDesiredYaw;
    rex::be<i32> bSnapFacing;
};

struct ACDTranslateFixedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    Vector3D vVel;
    rex::be<u32> uMoveFlags;
    rex::be<ActorAnimationTag> eAnimTag;
    rex::be<SNO> snoPowerPassability;
};

struct ACDTranslateArcMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    Vector3D vPos;
    Vector3D vVel;
    rex::be<u32> uMoveFlags;
    rex::be<ActorAnimationTag> eAnimTag;
    rex::be<ActorAnimationTag> eLandingAnimTag;
    rex::be<f32> flGravity;
    rex::be<SNO> snoPowerPassability;
    rex::be<f32> flUnitBounce;
    rex::be<f32> flDesiredHeight;
};

// TODO: clean up entries that didn't exist in 17339
enum DeterministicPathType
{
    DPATH_NONE,
    DPATH_CHARGED_BOLT,
    DPATH_PLAGUE_OF_TOADS,
    DPATH_CHAKRAM_LEFT,
    DPATH_CHAKRAM_RIGHT,
    DPATH_SIN_WAVE,
    DPATH_PEDAL_CURVE,
    DPATH_SPIRAL,
    DPATH_PLAGUE_OF_TOADS_STRAIGHT,
    DPATH_PIE_WEDGE,
    DPATH_CURVED_OFFSET,
    DPATH_FIRESTORM,
    DPATH_SPIRAL_IMMEDIATE,
    DPATH_COUNT,
};

struct ACDTranslateDetPathMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<DeterministicPathType> eDPath;
    RNG tSeed;
    Vector3D wvVelocity;
    rex::be<Angle> aOriginalYaw;
    Vector3D vStartPos;
    rex::be<u32> uMoveFlags;
    rex::be<ActorAnimationTag> eAnimTag;
    rex::be<SNO> snoPowerPassability;
    rex::be<u32> nVar0;
    rex::be<f32> flVar0;
    rex::be<f32> flVar1;
    rex::be<f32> flVar2;
    rex::be<f32> flVar3;
    rex::be<f32> flVar4;
};

struct DPathSinData
{
    rex::be<f32> flSinIncPerTick;
    rex::be<f32> flSinIncAccel;
    rex::be<f32> flLateralMaxDistance;
    rex::be<f32> flOOLateralDistanceToScale;
    rex::be<f32> flLateralStartDistance;
    rex::be<f32> flSpeed;
};

struct ACDTranslateDetPathSinMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<DeterministicPathType> eDPath;
    RNG tSeed;
    Vector3D wvVelocity;
    rex::be<Angle> aOriginalYaw;
    Vector3D vStartPos;
    rex::be<u32> uMoveFlags;
    rex::be<ActorAnimationTag> eAnimTag;
    rex::be<SNO> snoPowerPassability;
    rex::be<i32> nVar0;
    rex::be<f32> flVar0;
    DPathSinData tSinData;
    rex::be<f32> flSpeedMult;
};

struct ACDTranslateDetPathSpiralMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    Vector3D vStartPos;
    Vector3D vTargetPos;
    rex::be<u32> uMoveFlags;
    rex::be<ActorAnimationTag> eAnimTag;
    rex::be<f32> flVar0;
    DPathSinData tSinData;
    rex::be<f32> flSpeedMult;
};

struct ACDTranslateSyncMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    Vector3D vPos;
    XOptional<rex::be<i32>> bSnap;
    XOptional<rex::be<u32>> uAckValue;
};

struct ACDTranslateFixedUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    Vector3D vPos;
    Vector3D vVel;
};

struct ACDClientTranslateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> uTickBase;
    rex::be<u32> uTicksAhead;
    Vector3D vDest;
    Angle aDesiredYaw;
    rex::be<f32> flMovementSpeed;
    rex::be<u32> uMoveFlags;
    rex::be<u32> eAnimTag;
    XOptional<rex::be<SNO>> snoPower;
};

struct ACDTranslateAckMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> uAckValue;
};

struct PlayEffectMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<EffectType> eEffectType;
    XOptional<rex::be<i32>> nEffectParameter;
};

struct PlayHitEffectMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<ACDNetworkName> annAttacker;
    rex::be<DamageType> eDamageType;
    rex::be<i32> fCrit;
};

struct PlayHitEffectOverrideMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<ACDNetworkName> annAttacker;
    rex::be<SNO> snoEffectGroup;
};

struct PlayNonPositionalSoundMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoSound;
};

struct PlayErrorSoundMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ActorTag> dwSoundTag;
};

struct PlayMusicMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoMusic;
};

struct PlayCutsceneMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nIndex;
};

struct ComplexEffectAddMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SComplexEffectID> idSComplexEffect;
    rex::be<ComplexEffectType> eType;
    rex::be<SNO> snoEffectGroup;
    rex::be<ACDNetworkName> annSource;
    rex::be<ACDNetworkName> annDest;
    rex::be<u32> dwParam1;
    rex::be<u32> dwParam2;
    rex::be<u32> bIgnoreOwnerAlpha;
};

struct FlippyMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annLauncher;
    rex::be<SNO> snoFlippyParticle;
    rex::be<SNO> snoActorLoot;
    Vector3D wpDest;
};

struct WaypointActivatedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annWaypoint;
    rex::be<ACDNetworkName> annActivatingPlayer;
    rex::be<SNO> snoLevelArea;
    rex::be<i32> bAnnounce;
};

struct AimTargetMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<TargetType> eType;
    rex::be<ACDNetworkName> annTarget;
    WorldPlace tPlace;
};

struct ACDChangeGBHandleMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    GBHandle hGB;
};

struct EndOfTickMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> dwTickEnding;
    rex::be<u32> dwTickNext;
};

struct TryWaypointMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annWaypoint;
    rex::be<u32> nWaypoint;
};

enum NPCInteractionType
{
    // TODO
};

struct NPCInteraction
{
    rex::be<NPCInteractionType> eType;
    rex::be<u32> dwData;
    rex::be<u32> dwData2;
    rex::be<u32> dwFlags;
};

enum NPCMenu
{
    // TODO
};

struct NPCInteractOptionsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annTalkingTo;
    NPCInteraction tNPCInteraction[20];
    rex::be<i32> nNumInteractions;
    rex::be<NPCMenu> ePreferredMenu;
};

struct QuestUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoQuest;
    rex::be<SNO> snoLevelArea;
    rex::be<i32> nStepUID;
    rex::be<i32> bFailed;
    rex::be<i32> bDisplayButton;
};

struct QuestMeterMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoQuest;
    rex::be<ACDNetworkName> annMeter;
    rex::be<f32> flMeter;
};

struct QuestCounterMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoQuest;
    rex::be<SNO> snoLevelArea;
    rex::be<i32> nStepUID;
    rex::be<i32> nObjectiveIndex;
    rex::be<i32> nValue;
    rex::be<i32> bCompleted;
};

struct PlayerLevel
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    rex::be<i32> nNewLevel;
};

enum PickupResponse : int
{
    PICKUP_RESPONSE_INVALID,
    PICKUP_RESPONSE_OK,
    PICKUP_RESPONSE_TRADING,
    PICKUP_RESPONSE_OWNED_BY_OTHER,
    PICKUP_RESPONSE_SINGULAR,
    PICKUP_RESPONSE_NO_SUITABLE_SLOT_FOUND,
    PICKUP_RESPONSE_UNUSABLE_GLYPH,
    PICKUP_RESPONSE_NOT_RIGHT_NOW,
    NUM_PICKUP_RESPONSES,
};

struct ACDPickupFailedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> bIsCurrency;
    rex::be<PickupResponse> ePickupResponse;
    rex::be<ACDNetworkName> annPickee;
};

struct PetMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nOwner;
    rex::be<i32> nIndex;
    rex::be<ACDNetworkName> annPet;
    rex::be<i32> nType;
};

struct PetDetachMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annPet;
    rex::be<i32> bDisplayChatMessage;
};

struct HirelingInfoUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> eClass;
    rex::be<i32> fDead;
    rex::be<GBID> gbidName;
    rex::be<i32> eValidClass;
    rex::be<i32> arnPowerKeyParam[5];
    rex::be<ACDNetworkName> annItems[6];
    rex::be<i32> nPlayerIndex;
};

enum UIElement : int
{
    // TODO
};

enum UIElementAction : int
{
    // TODO
};

struct UIElementMessage
{
    RequiredMessageHeader tHeader;
    rex::be<UIElement> eElement;
    rex::be<UIElementAction> eAction;
};

enum eTradeMessageType
{
    TRADE_MSG_TRY_START,
    TRADE_MSG_CANCEL,
    TRADE_MSG_ACCEPT,
    TRADE_MSG_START,
    TRADE_MSG_GOLD,
    TRADE_MSG_COMPLETE,
    TRADE_MSG_ITEM,
    TRADE_MSG_OTHER_BUSY,
    TRADE_MSG_STATE,
    TRADE_MSG_ITEM_REMOVED,
    NUM_MESSAGE_TYPES,
};

struct TradeMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> eMessageType;
    rex::be<u32> dwData;
    rex::be<u32> dwData2;
    rex::be<u64> uData64;
    rex::be<ACDNetworkName> ann;
    rex::be<ACDNetworkName> arrItems[4];
};

struct SetIdleAnimationMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<u32> dwAnimTag;
};

struct ACDCollFlagsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<u32> uCollFlags;
};

enum GoldModifiedReason : int
{
    GMR_UNKNOWN,
    GMR_SOLD,
    GMR_KILL,
    GMR_QUEST,
    GMR_SCRIPT,
    GMR_CRAFTING,
    GMR_BUY_STASH,
    GMR_PURCHASE,
    GMR_CHEAT_REPAIR_ALL,
    GMR_CHEAT,
    GMR_TRADE,
    GMR_TRADE_FAILED,
    GMR_PICKUP,
    //GMR_RESET_PARAGON_POINTS,
    //GMR_MAIL,
    //GMR_ACHIEVEMENT,
    //GMR_DAILY_FIRST,
    //GMR_STORE_PURCHASE,
    //GMR_EMPOWERED_RIFT,
    //GMR_CURRENCY_CONVERSION,
    //GMR_CUBE_RECIPE,
    GMR_COUNT,
};

struct GoldModifiedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> bPlaySound;
    rex::be<GoldModifiedReason> eReason;
};

struct ActTransitionMessage
{
    RequiredMessageHeader tHeader;
    rex::be<Act> eAct;
    rex::be<i32> bOnJoin;
};

struct InterstitialMessage
{
    RequiredMessageHeader tHeader;
    rex::be<PlayerClass> ePlayerClass;
    rex::be<i32> fIsMale;
};

struct EffectGroupACDToACDMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoEffectGroup;
    rex::be<ACDNetworkName> annFrom;
    rex::be<ACDNetworkName> annTo;
};

enum RopePosition : int
{
    ROPE_POSITION_DEFAULT,
    ROPE_POSITION_CHEST,
    ROPE_POSITION_MOUTH,
    ROPE_POSITION_LEFT_HAND,
    ROPE_POSITION_RIGHT_HAND,
    ROPE_POSITION_MANA_GATHER,
    ROPE_POSITION_BACK,
    ROPE_POSITION_HEAD,
    ROPE_POSITION_LEFT_FOOT,
    ROPE_POSITION_RIGHT_FOOT,
    ROPE_POSITION_PELVIS,
    ROPE_POSITION_LEFT_WEAPON,
    ROPE_POSITION_RIGHT_WEAPON,
    ROPE_POSITION_EMITTER,
    ROPE_POSITION_EMITTER_FLOOR,
    ROPE_POSITION_EXPLOSION,
    ROPE_POSITION_BEAM_CENTER,
    ROPE_POSITION_BEAM_LEFT,
    ROPE_POSITION_BEAM_RIGHT,
    ROPE_POSITION_COUNT,
};

struct RopeEffectMessageACDToACD
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoRope;
    rex::be<ACDNetworkName> annFrom;
    rex::be<RopePosition> ePositionFrom;
    rex::be<ACDNetworkName> annTo;
    rex::be<RopePosition> ePositionTo;
    rex::be<i32> bIgnoreOwnerAlpha;
};

struct RopeEffectMessageACDToPlace
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoRope;
    rex::be<ACDNetworkName> annFrom;
    rex::be<RopePosition> ePositionFrom;
    WorldPlace tPlaceTo;
    rex::be<i32> bIgnoreOwnerAlpha;
};

enum PVPGameResult : int
{
    PVP_GR_INVALID = -1,
    PVP_GR_WIN,
    PVP_GR_LOSS,
    PVP_GR_TIE,
    NUM_PVP_GAME_RESULTS,
};

struct GameSyncedData
{
    rex::be<u32> dwGameSyncedFlags;
    rex::be<Act> eAct;
    rex::be<Team> arPlayerAllyTeam[4];  // there is a 40 byte gap in the type descriptor here, team data fits the most
    rex::be<Team> arMonsterTeam[4];
    rex::be<Team> eSceneryTeam;
    rex::be<Team> eNeutralTeam;
    rex::be<i32> bPregame;
    rex::be<u32> dwPregameEnd;
    rex::be<u32> dwRoundStart;
    rex::be<u32> dwRoundEnd;
    rex::be<i32> bPVPGameOver;
    rex::be<i32> bPVPAwardsAssigned;
    rex::be<u32> nTeamWins[2];
    rex::be<u32> nTeamScore[2];
    rex::be<PVPGameResult> ePVPGameResult[2];
    OnlineService::HeroId uPartyGuideHeroId;
};

struct GameSyncedDataMessage
{
    RequiredMessageHeader tHeader;
    GameSyncedData tSyncedData;
};

struct ACDChangeActorMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoActor;
};

enum PlayerWarpReason : int
{
    WARP_UNKNOWN,
    WARP_TOWN_PORTAL,
    WARP_WAYPOINT,
    WARP_CHANGING_ACTS,
    WARP_HEARTH_PORTAL,
    WARP_CHECKPOINT,
    WARP_COMPANION,
    WARP_BOSS_FIGHT,
    WARP_ELEVATOR,
    WARP_PORTAL,
    WARP_SCRIPT,
    WARP_HEADSTONE,
    WARP_CONSOLE_PORTAL,
    WARP_CHALLENGE,
    WARP_CANCELLED,
    WARP_CONSOLE_PVP_SS,
    //WARP_TIERED_RIFT,
    //WARP_SET_DUNGEON,
    WARP_COUNT,
};

struct PlayerWarpedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<PlayerWarpReason> eWarpReason;
    rex::be<f32> flWarpFadeInSeconds;
};

enum MonsterRarity : int
{
    MR_NONE = -1,
    MR_NORMAL,
    MR_CHAMPION,
    MR_RARE,
    MR_RARE_MINION,
    MR_UNIQUE,
    MR_HIRELING,
    MR_6,
    MR_BOSS,
    MR_NUM_RARITIES,
};

struct VictimMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerVictimIndex;
    rex::be<i32> nKillerLevel;
    rex::be<i32> nKillerPlayerIndex;
    rex::be<MonsterRarity> eKillerMonsterRarity;
    rex::be<SNO> snoKillerActor;
    rex::be<Team> eKillerTeam;
    rex::be<GBID> pKillerRareNameGBIDs[2];
    rex::be<SNO> snoPowerDmgSource;
};

struct EngagedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    rex::be<SNO> snoActorMonster;
    rex::be<i32> eMonsterRarity;
    rex::be<GBID> pRareNameGBIDs[2];
};

struct KillCountMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    rex::be<i32> nPlayerKills;
    rex::be<i32> nDeaths;
    rex::be<i32> nAssists;
};

struct WorldStatusMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SWorldID> idSWorld;
    rex::be<u32> dwWorldStatusBits;
};

struct WeatherOverrideMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoWeatherOverride;
    rex::be<f32> flWeatherIntensityOverride;
    rex::be<f32> flWeatherIntensityOverrideEnd; // dword in later versions
};

struct ACDShearMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<f32> flShear;
};

struct ACDGroupMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<u32> uPrimaryGroup;
    rex::be<u32> uSecondaryGroup;
};

enum ConversationSpeaker : int
{
    CONV_SPEAKER_INVALID = -1,
    CONV_SPEAKER_PLAYER,
    CONV_SPEAKER_PRIMARY_NPC,
    CONV_SPEAKER_ALT_NPC1,
    CONV_SPEAKER_ALT_NPC2,
    CONV_SPEAKER_ALT_NPC3,
    CONV_SPEAKER_ALT_NPC4,
    CONV_SPEAKER_FOLLOWER_TEMPLAR,
    CONV_SPEAKER_FOLLOWER_SCOUNDREL,
    CONV_SPEAKER_FOLLOWER_ENCHANTRESS,
    NUM_CONV_SPEAKERS,
};

enum ActorGender : int
{
    ACTOR_GENDER_INVALID = -1,
    ACTOR_GENDER_MALE,
    ACTOR_GENDER_FEMALE,
    NUM_ACTOR_GENDERS,
};

struct PlayLineParams
{
    rex::be<SNO> snoConversation;
    rex::be<i32> nSpeakingPlayerIndex;
    rex::be<i32> bZoom;
    rex::be<i32> bFirstLine;
    rex::be<i32> bHostile;
    rex::be<i32> bPlayerInitiated;
    rex::be<u32> dwLineUID;
    rex::be<ConversationSpeaker> eLineSpeaker;
    rex::be<ActorGender> eLineGender;
    rex::be<PlayerClass> eLineClass;
    rex::be<ConversationSpeaker> eSpeakerTarget;
    rex::be<SNO> snoSpeakerActor;
    rex::be<ActorGender> ePlayerGender;
    rex::be<PlayerClass> ePlayerClass;
    rex::be<u32> dwLineFlags;
    rex::be<u32> dwLineAnimTag;
    rex::be<u32> dwLineDisplayTime;
    rex::be<i32> nLineGUID;
    rex::be<i32> nPriority;
};

struct PlayConvLineMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annSpeaker;
    rex::be<ACDNetworkName> annParticipants[9];
    PlayLineParams tParams;
    rex::be<u32> dwTimeToDisplay;
};

struct StopConvLineMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nConvLineGUID;
    rex::be<i32> fStoppedByUser;
};

struct AdvanceConvMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoConv;
    rex::be<i32> nLineUID;
};

struct UpdateConvAutoAdvanceMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoConv;
    rex::be<i32> nLineUID;
    rex::be<u32> dwNextAdvanceTime;
};

struct EndConversationMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoConversation;
    rex::be<ACDNetworkName> annSpeaker;
};

struct HirelingSwapMessage
{
    RequiredMessageHeader tHeader;
    rex::be<HirelingClass> eNewClass;
};

struct DeathFadeTimeMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<i32> nTimeUntilFade;
    rex::be<i32> nFadeTime;
    rex::be<i32> bRecurseForAttachments;
};

struct DisplayGameTextMessage
{
    RequiredMessageHeader tHeader;
    char szMsg[1024];
    XOptional<rex::be<i32>> nParam1;
    XOptional<rex::be<i32>> nParam2;
};

struct ACDLookAtMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annSrc;
    rex::be<ACDNetworkName> annTarget;
};

enum KillCounterType : int
{
    KILLCOUNTER_MONSTER,
    KILLCOUNTER_OBJECT_DESTRUCTION,
    KILLCOUNTER_SINGLE_ATTACK,
    KILLCOUNTER_ENVIRONMENT_ATTACK,
    KILLCOUNTER_COUNT,
};

struct KillCounterUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<KillCounterType> eType;
    rex::be<u32> uCount;
    // float flXPMultiplier
    rex::be<u32> uTotalTime;
    rex::be<i32> bExpired;
};

struct LowHealthCombatMessage
{
    RequiredMessageHeader tHeader;
    rex::be<f32> flHealthPercent;
    rex::be<u32> uXPRewarded;
};

struct SaviorMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annSavedPlayer;
    rex::be<u32> uXPRewarded;
};

enum FloatingNumberType : int
{
    FLOATING_NUMBER_TYPE_DAMAGE_DONE,
    FLOATING_NUMBER_TYPE_DOT_DAMAGE_DONE,
    FLOATING_NUMBER_TYPE_CRITICAL_HIT_DONE,
    FLOATING_NUMBER_TYPE_DAMAGE_TAKEN,
    FLOATING_NUMBER_TYPE_DOT_DAMAGE_TAKEN,
    FLOATING_NUMBER_TYPE_CRITICAL_HIT_TAKEN,
    FLOATING_NUMBER_TYPE_DODGE,
    FLOATING_NUMBER_TYPE_DODGED,
    FLOATING_NUMBER_TYPE_BLOCK ,
    FLOATING_NUMBER_TYPE_PARRY,
    FLOATING_NUMBER_TYPE_HEAL,
    FLOATING_NUMBER_TYPE_ABSORB,
    FLOATING_NUMBER_TYPE_ROOT,
    FLOATING_NUMBER_TYPE_STUN,
    FLOATING_NUMBER_TYPE_BLIND,
    FLOATING_NUMBER_TYPE_FROZEN,
    FLOATING_NUMBER_TYPE_FEAR,
    FLOATING_NUMBER_TYPE_CHARM,
    FLOATING_NUMBER_TYPE_TAUNT,
    FLOATING_NUMBER_TYPE_SNARE,
    FLOATING_NUMBER_TYPE_ATTACK_SPEED_SLOW,
    FLOATING_NUMBER_TYPE_BROKE_FREEZE,
    FLOATING_NUMBER_TYPE_BROKE_BLIND,
    FLOATING_NUMBER_TYPE_BROKE_STUN,
    FLOATING_NUMBER_TYPE_BROKE_ROOT,
    FLOATING_NUMBER_TYPE_BROKE_SNARE,
    FLOATING_NUMBER_TYPE_BROKE_FEAR,
    FLOATING_NUMBER_TYPE_IMMUNE,
    //FLOATING_NUMBER_TYPE_CRUSHING_BLOW,
    FLOATING_NUMBER_TYPE_GOLD,
    //FLOATING_NUMBER_TYPE_BLOODSHARDS,
    //FLOATING_NUMBER_TYPE_PLATINUM,
    FLOATING_NUMBER_TYPE_GBID,
    FLOATING_NUMBER_TYPE_XP,
    FLOATING_NUMBER_TYPE_BONUS_QUEST_REWARD,
    FLOATING_NUMBER_TYPE_PVP_KILL,
    FLOATING_NUMBER_TYPE_PVP_ASSIST,
    //FLOATING_NUMBER_TYPE_NEPHALEM_GLORY_GAINED,
    //FLOATING_NUMBER_TYPE_NEPHALEM_GLORY_EXTRA_TIME,
    FLOATING_NUMBER_TYPE_COUNT,
};

struct FloatingNumberMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annTarget;
    rex::be<f32> flDamage;
    rex::be<FloatingNumberType> eType;
};

struct FloatingAmountMessage
{
    RequiredMessageHeader tHeader;
    WorldPlace wpPlace;
    rex::be<i32> nAmount;
    XOptional<rex::be<i32>> nAmount2;
    rex::be<FloatingNumberType> eType;
};

struct RemoveRagdollMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annTarget;
    rex::be<SNO> snoMonster;
};

struct LoreMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoLore;
};

struct WorldDeletedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SWorldID> idSWorld;
};

struct ActiveEvent
{
    rex::be<SNO> snoTimedEvent;
    rex::be<u32> dwStartTime;
    rex::be<u32> dwExpirationTime;
    // uint32 dwArtificiallyElapsedTime
};

struct TimedEventStartedMessage
{
    RequiredMessageHeader tHeader;
    ActiveEvent tEvent;
};

struct ActTransitionStartedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> dwActTransitionTime;
    //rex::be<i32> bRecreateGameWithParty;
    rex::be<i32> nPlayerIndex;
};

struct PlayerQuestMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndex;
    rex::be<SNO> snoQuest;
    // SNO snoLevelArea
};

enum DeSyncReason : int
{
    DESYNC_REASON_POWER,
    DESYNC_REASON_REJECTED,
    DESYNC_REASON_CANNOT_MOVE,
    DESYNC_REASON_TOO_FAR,
    DESYNC_REASON_COUNT,
};

struct PlayerDeSyncSnapMessage
{
    RequiredMessageHeader tHeader;
    WorldPlace placeSnap;
    rex::be<DeSyncReason> eReason;
    rex::be<SNO> snoPowerCurrent;
    rex::be<i32> nPlayerIndex;
};

enum ItemQualityLevel : int
{
    IQL_INVALID = -1,
    IQL_INFERIOR,
    IQL_NORMAL,
    IQL_SUPERIOR,
    IQL_MAGIC_1_AFFIX,
    IQL_MAGIC_2_AFFIX,
    IQL_MAGIC_3_AFFIX,
    IQL_RARE_4_AFFIX,
    IQL_RARE_5_AFFIX,
    IQL_RARE_6_AFFIX,
    IQL_LEGENDARY,
    //IQL_SPECIAL,  // the field specifies -1 to 10 range, so IQL_SPECIAL was probably added later
    IQL_NUM_ITEM_QUALITY_LEVELS,
    IQL_DISPLAY_AS_SET_ITEM = IQL_NUM_ITEM_QUALITY_LEVELS,
};

struct SalvageResultsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<GBID> gbidOriginalItem;
    rex::be<ItemQualityLevel> eIQLOriginalItem;
    rex::be<u32> field16;
    rex::be<GBID> gbidMaterials[10];
};

struct MapMarkerInfoMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> m_nHashedName;
    WorldPlace m_Place;
    rex::be<SNO> m_ImageInfo;
    rex::be<u32> m_hImage;
    rex::be<SNO> m_snoStringList;
    rex::be<u32> m_hLabel;
    rex::be<i32> m_bActive;
    rex::be<i32> m_bCanBecomeArrow;
    rex::be<i32> m_bRespectsFoW;
    rex::be<i32> m_bIsPing;
    rex::be<f32> m_fMaxDisplayRangeSq;
    rex::be<f32> m_fMinDisplayRangeSq;
    rex::be<f32> m_fDiscoveryRangeSq;
    rex::be<u32> m_nPlayerUseFlags;
};

struct DebugActorTooltipMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    char szTooltip[1024];
};

struct BossEncounterMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> nPlayerIndex;
    rex::be<SNO> snoEncounter;
};

struct EncounterInviteStateMessage
{
    RequiredMessageHeader tHeader;
    char m_AcceptedPlayers;
    char m_PendingPlayers;
    char m_DeclinedPlayers;
};

struct CameraFocusMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<i32> bSnap;
    rex::be<f32> flDuration;
};

struct CameraZoomMessage
{
    RequiredMessageHeader tHeader;
    rex::be<f32> flZoom;
    rex::be<i32> bSnap;
    rex::be<f32> flDuration;
};

struct CameraYawMessage
{
    RequiredMessageHeader tHeader;
    rex::be<Angle> aAngle;
    rex::be<i32> bSnap;
    rex::be<f32> flDuration;
};

struct BossZoomMessage
{
    RequiredMessageHeader tHeader;
    rex::be<f32> flZoom;
    rex::be<f32> flZoomSpeed;
};

struct EnchantItemMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItem;
    rex::be<GBID> gbidAffix;
};

enum DebugDrawPrimType : int
{
    DBG_PRIM_LINE,
    DBG_PRIM_SPHERE,
    DBG_PRIM_HALF_SPHERE,
    DBG_PRIM_CYLINDER,
    DBG_PRIM_CAPSULE,
    DBG_PRIM_PIE,
    DBG_PRIM_BOX,
    DBG_PRIM_TEXT,
    DBG_PRIM_COUNT,
};

struct DebugDrawPrimMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> uID;
    rex::be<DebugDrawPrimType> eType;
    rex::be<SWorldID> idSWorld;
    Vector3D vPos0;
    Vector3D vPos1;
    rex::be<f32> flLength;
    rex::be<f32> flRadius;
    rex::be<u32> uLifetimeInTicks;
    RGBAColor rgbaColor;
    char szText[128];
};

struct CraftingResultsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> annItem;
    rex::be<GBID> gbidItem;
    rex::be<ItemQualityLevel> eIQL;
};

struct CrafterLevelUpMessage
{
    RequiredMessageHeader tHeader;
    rex::be<CrafterType> eType;
    rex::be<u32> dwAnimTag;
    rex::be<u32> dwNewIdle;
    //rex::be<i32> nLevel;
};

struct UnlockDifficultyMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> field8;
    rex::be<u32> field12;
};

struct DifficultyAndHandicapMessage
{
    RequiredMessageHeader tHeader;
    rex::be<DifficultyLevel> eDifficulty;
    rex::be<i32> nHandicapLevel;
};

struct GameTestingSamplingStartMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoWorld;
    rex::be<SNO> snoScene;
};

struct RequestBuffCancelMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoPower;
    rex::be<i32> nBuffIndex;
};

struct OpenGameToPublicMessage
{
    RequiredMessageHeader tHeader;
    char szGameTag[16];
};

struct BroadcastTextMessage
{
    RequiredMessageHeader tHeader;
    char szMsg[1024];
};

struct VoteKickMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerIndexToKick;
    rex::be<i32> nPlayerIndexInitiating;
    char usMessage[1024];
};

struct MailSendMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nToAccount;
};

struct MailReadMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
};

struct MailRetrieveMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
};

struct MailDeleteMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
};

struct MailSentResponseMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
    rex::be<i32> idErr;
};

struct MailReadResponseMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
    rex::be<i32> idErr;
};

struct MailRetrieveResponseMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
    rex::be<i32> idErr;
};

struct MailDeleteResponseMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u64> idMail;
    rex::be<i32> idErr;
};

struct PVPTokenRedemptionMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> nItems;
    rex::be<ACDNetworkName> arrItems[4];
    rex::be<GBID> arrGBIDs[4];
    rex::be<u32> nStackSize[4];
};

struct PlayerSetCameraObserverMessage
{
    RequiredMessageHeader tHeader;
    rex::be<SNO> snoObserver;
    XOptional<WorldPlace> wpToOrbit;
};

struct PlayerSetCameraOrbitMessage
{
    RequiredMessageHeader tHeader;
    WorldPlace wpToOrbit;
};

struct PlayerSetCameraDefaultsMessage
{
    RequiredMessageHeader tHeader;
};

struct PlayerConsoleSetCameraDefaultsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> bForce;
};

struct PlayerSavedQuestUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<DifficultyLevel> eLastPlayedDifficulty;
    rex::be<Act> eLastPlayedAct;
    rex::be<SNO> snoLastPlayedQuest;
    rex::be<i32> nLastPlayedStepUID;
    //rex::be<i32> nHandicapLevel;
    PlayerSavedQuest tSavedQuest[64];
    rex::be<u32> dwNumQuests;
};

struct PlayerQuestHistoryUpdateMessage
{
    RequiredMessageHeader tHeader;
    PlayerQuestHistoryEntry tQuestHistory[200];
    rex::be<u32> dwNumEntries;
};

struct PlayerQuestRewardHistoryUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nNumQuestRewardEntries;
    PlayerQuestRewardHistoryEntry tQuestRewardHistory[100];
};

struct PlayerSavedConversationsUpdateMessage
{
    RequiredMessageHeader tHeader;
    SavedConversations tSavedConversations;
};

struct ConsoleCriteriaUpdate
{
    rex::be<u32> field0;
    rex::be<u32> field4;
};

struct ConsoleAchievementCriteriaUpdateMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nNumUpdates;
    ConsoleCriteriaUpdate tUpdates[64];
};

struct ConsoleAchievementAwardedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<u32> field8;
    rex::be<u64> field16;
    rex::be<u32> field24;
};

struct DuelResultMessage
{
    RequiredMessageHeader tHeader;
    rex::be<i32> nPlayerVictimIndex;
    rex::be<i32> nPlayerKillerIndex;
    rex::be<SNO> snoPowerDmgSource;
};

struct ItemJunkFlagChangedMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<i32> bJunkFlag;
};

struct SpendParagonPointsMessage
{
    RequiredMessageHeader tHeader;
    rex::be<GBID> gbidParagonBonus;
    rex::be<i32> nPoints;
};

struct PlayerClearClientWalkPowerMessage
{
    RequiredMessageHeader tHeader;
    rex::be<ACDNetworkName> ann;
    rex::be<SNO> snoPower;
};
