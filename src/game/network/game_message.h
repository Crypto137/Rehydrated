#pragma once

#include <rex/types.h>

#include "game/attributes/attrib.h"
#include "game/game.h"
#include "game/game_balance.h"
#include "game/scene.h"
#include "game/types.h"
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
    NetAttributeKeyValue tKeyVals[15];
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
