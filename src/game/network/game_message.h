#pragma once

#include "core/memory.h"
#include "game/game.h"
#include "game/game_balance.h"
#include "game/scene.h"
#include "game/tags.h"
#include "game/target.h"
#include "game/types.h"
#include "game/attributes/attrib.h"
#include "game/world_place.h"
#include "game/network/game_message_type.h"
#include "game/sigma/math/ivector2d.h"
#include "game/sigma/math/transform.h"

// Common Structures

struct RequiredMessageHeader
{
    be<u16> dwSize;
    char nControllerIndex;
    char nPadding;
    be<GameMessageType> eType;
};

template <typename T>
struct XOptional
{
    be<i32> m_bExists;
    T m_tValue;
};

struct SNOName
{
    be<SNOGroup> snoGroup;
    be<SNO> snoHandle;
};

struct RNG
{
    be<u32> dwSeed;
    be<u32> dwCarry;
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
    be<u32> dwData;
};

struct IntDataMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nData;
};

struct BoolDataMessage
{
    RequiredMessageHeader tHeader;
    be<i32> bVal;
};

struct DataIDDataMessage
{
    RequiredMessageHeader tHeader;
    be<DataID> id;
};

struct ANNDataMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
};

struct SNODataMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoData;
};

struct SNONameDataMessage
{
    RequiredMessageHeader tHeader;
    SNOName snoname;
};

struct GBIDDataMessage
{
    RequiredMessageHeader tHeader;
    be<GBID> gbidData;
};

struct PlayerIndexMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
};

struct PlayerDWordDataMessage
{
    RequiredMessageHeader tHeader;
    be<u32> dwData;
    be<i32> nPlayerIndex;
};

struct GenericBlobMessage
{
    RequiredMessageHeader tHeader;
    be<u32> uBlobSize;
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
    be<i32> nPlayerIndex;
    char usMessage[1024];
    WorldPlace tPlaceTarget;
    be<ACDNetworkName> annTarget;
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
    be<QuitReason> eReason;
};

struct PreloadSceneDataMessage
{
    RequiredMessageHeader tHeader;
    be<SSceneID> idSScene;
    be<SNO> snoScene;
    be<SNO> snoLevelAreas[4];
};

struct PreloadACDDataMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<SNO> snoActor;
    be<WeaponClass> eWeaponClass;
    be<GBID> gbidMonsterAffixes[8];
};

struct JoinBNetGameMessage
{
    RequiredMessageHeader tHeader;
    OnlineService::HeroId uHeroId;
    OnlineService::GameId tGameId;
    be<SGameID> idSGame;   // to be confirmed
    be<u64> uAuthToken;
    be<XLocale> eXLocale;
    be<u32> uProtocolHash;
    be<u32> dwSNOCoreDataHash;
};

struct JoinLANGameMessage
{
    RequiredMessageHeader tHeader;
    be<SGameID> idSGame;
    char szAccount[128];
    char szHero[49];
    be<XLocale> eXLocale;
};

struct JoinConsoleGameMessage
{
    RequiredMessageHeader tHeader;
    be<XLocale> eXLocale;
    char uControllerIndex;
    be<u32> uLicenses;
};

struct VersionsMessage
{
    RequiredMessageHeader tHeader;
    be<u32> uSNOPackHash;
    be<u32> uProtocolHash;
    char szBuildVer[32];
};

struct StackPortionMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItem;
    be<u64> uAmount;
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
    be<LogoutContext> eLogoutContext;
};

struct LogoutTickTimeMessage
{
    RequiredMessageHeader tHeader;
    be<LogoutContext> eContext;
    be<u32> uMinWaitTicks;
    be<u32> uMaxWaitTicks;
    be<u32> uKickTicks;
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
    be<LogEventType> eEventType;
    be<ACDNetworkName> idACDSource;
    be<ACDNetworkName> idACDTarget;
    be<SNO> snoData;
    be<f32> flParam1;
    be<f32> flParam2;
    be<u32> dwParam1;
};

}  // namespace CombatLog

struct ConnectionEstablishedMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    be<u32> dwAnimSyncedSeed;
    be<u32> dwSnoCoreDataHash;
};

struct GameSetupMessage
{
    RequiredMessageHeader tHeader;
    be<u32> dwFirstHeartbeat;
};

struct HotbarButtonData
{
    be<SNO> m_snoPower;
    be<RuneType> m_eRuneType;
    be<GBID> m_gbidItem;
};

struct HirelingInfo
{
    be<HirelingClass> eClass;
    be<GBID> gbidName;
    be<i32> field8;    // max 0x7F, bit count 7
    be<i32> field12;
    be<i32> fDead;
    be<SNO> arnPowerKeyParam[4];
};

struct HirelingSavedData
{
    HirelingInfo tHireling[4];
    be<HirelingClass> eActiveHireling;
    be<u32> dwAvailableHirelings;
};

struct LearnedLore
{
    be<i32> m_nLearnedCount;
    be<SNO> m_snoLoreLearned[256];
};

struct SavedConversations
{
    be<i32> m_nSavedConvCount;
    char m_arPlayedConv[32];
    be<SNO> m_snoSavedConv[256];
};

struct ActiveSkillSavedData
{
    be<SNO> snoSkill;
    be<RuneType> eRuneType;
};

struct SavePointData
{
    be<SNO> snoWorld;
    be<i32> nNum;
    be<i32> bCreatesPortal;
    be<ACDID> idACDReturnPortal;
};

struct PlayerSavedData
{
    HotbarButtonData tHotbarBtnAssignments[6];
    HotbarButtonData tPotionBtn;
    char bSkillSlotEverAssigned;
    be<u32> uSecondsPlayed;
    be<u32> m_ActivatedWaypoints;
    HirelingSavedData tHirelingSavedData;
    be<u32> uTimeLastLevel;
    LearnedLore tLearnedLore;
    SavedConversations tSavedConversations;     // skipped in the type descriptor
    ActiveSkillSavedData tActiveSkills[6];
    SNO snoTraits[3];
    SavePointData tLastSavePoint;
};

struct PlayerQuestRewardHistoryEntry
{
    be<SNO> snoQuest;
    be<i32> nStepUID;
    char uDifficultyFlags;
};

struct PlayerQuestHistoryEntry
{
    be<SNO> snoQuest;
    be<i32> nStepUID;
    be<DifficultyLevel> eDifficulty;
};

struct PlayerSavedQuest
{
    be<SNO> snoQuest;
    be<DifficultyLevel> eDifficulty;
    be<i32> nCurrentStepUID;
    be<i32> arObjectiveState[20];
    be<i32> arFailureConditionState[20];
};

struct HeroStateData
{
    be<Act> eLastPlayedAct;
    be<Act> eHighestUnlockedAct;
    be<DifficultyLevel> eLastPlayedDifficulty;
    be<DifficultyLevel> eHighestUnlockedDifficulty;
    be<u32> uPlayerFlags;
    PlayerSavedData tSavedData;
    be<i32> nNumQuestRewardEntries;
    PlayerQuestRewardHistoryEntry tQuestRewardHistory[100];
    PlayerQuestHistoryEntry tQuestHistory[200];     // skipped in the type descriptor
    PlayerSavedQuest tSavedQuest[64];               // skipped in the type descriptor
    be<i32> uBossKillFlags[4];
};

struct NewPlayerMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    OnlineService::HeroId tHeroId;
    OnlineService::GameAccountHandle tAccountId;
    char usHeroName[49];
    be<Team> eTeam;
    be<PlayerClass> eClass;
    be<SNO> snoActorPortrait;
    be<i32> nCurrentLevel;
    be<i32> nCurrentAltLevel;
    HeroStateData tHeroStateData;
    be<i32> bJustJoined;
    be<GameConnectionID> idGameConnection;
    be<ACDNetworkName> ann;
    char usGamerTag[128];
    be<u64> uAcceptedLicenseBitsHero;
};

struct PlayerKickTimerMessage
{
    RequiredMessageHeader tHeader;
    be<u32> dwLastKickAttempt;
    be<u32> dwLastSuccessfulKick;
};

struct EnterWorldMessage
{
    RequiredMessageHeader tHeader;
    Vector3D wpLocation;
    be<SWorldID> idSWorld;
    be<SNO> snoWorld;
    be<i32> nPlayerIndex;
};

struct RevealSceneMessage
{
    RequiredMessageHeader tHeader;
    be<SWorldID> idSWorld;
    SceneSpecification tSceneSpec;
    be<SSceneID> idSScene;
    be<SNO> snoScene;
    PRTransform transform;
    be<SSceneID> idSSceneParent;
    be<SNO> snoSceneGroup;
    be<u32> uLabelCount;
    be<GBID> arAppliedLabels[256];
};

struct DestroySceneMessage
{
    RequiredMessageHeader tHeader;
    be<SWorldID> idSWorld;
    be<SSceneID> idSScene;
};

struct SwapSceneMessage
{
    RequiredMessageHeader tHeader;
    be<SWorldID> idSWorld;
    be<SSceneID> idSSceneOld;
    be<SSceneID> idSSceneNew;
};

struct RevealWorldMessage
{
    RequiredMessageHeader tHeader;
    be<SWorldID> idSWorld;
    be<SNO> snoWorld;
    be<i32> nOriginX;
    be<i32> nOriginY;
    be<i32> nStitchSizeInFeetX;
    be<i32> nStitchSizeInFeetY;
    be<i32> nWorldSizeInFeetX;
    be<i32> nWorldSizeInFeetY;
};

struct RevealTeamMessage
{
    RequiredMessageHeader tHeader;
    be<Team> eTeam;
    be<u32> dwTeamFlags;
    be<TeamColor> eTeamColoring;
};

struct PlayerActorSetInitialMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<i32> nPlayerIndex;
};

struct HeroStateMessage
{
    RequiredMessageHeader tHeader;
    HeroStateData tStateData;
    be<i32> nPlayerIndex;
};

struct PlayerSavedDataMessage
{
    RequiredMessageHeader tHeader;
    PlayerSavedData tSavedData;
    be<i32> nPlayerIndex;
};

struct SavePointDataMessage
{
    RequiredMessageHeader tHeader;
    SavePointData tData;
    be<i32> nPlayerIndex;
};

struct WorldLocationMessageData
{
    be<f32> flScale;
    PRTransform transform;
    be<SWorldID> idSWorld;
};

struct InventoryLocationMessageData
{
    be<ACDNetworkName> annContainer;
    be<InventorySlotType> eSlot;
    IVector2D pt;
};

struct ACDEnterKnownMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<SNO> snoActor;
    be<u32> dwFlags;
    be<ActorLocationType> eLocationType;
    XOptional<WorldLocationMessageData> tWorldLocationData;
    XOptional<InventoryLocationMessageData> tInvLocationData;
    GBHandle hGB;
    SNOName tSNOName;
    be<i32> nRarity;
    char nLookLinkIndex;
    XOptional<be<i32>> snoMarkerSet;
    XOptional<be<i32>> nMarkerIndex;
    XOptional<be<i32>> snoAmbientOcclusionOverrideTex;
    XOptional<be<u32>> dwTimeActorCreated;
};

struct PlayerEnterKnownMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    be<ACDNetworkName> ann;
};

struct ACDWorldPositionMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    WorldLocationMessageData tWorldLocationData;
};

struct ACDInventoryPositionMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    InventoryLocationMessageData tInvLocationData;
    be<ActorLocationType> tLocType;
};

struct ACDInventoryUpdateActorSNO
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<SNO> snoActor;
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
    be<ACDNetworkName> ann;
    be<SNO> snoActor;
    WorldPlace tPlace;
    XOptional<be<u32>> nPlayerIndexOwner;
    be<SNO> snoLevelArea;
    XOptional<be<f32>> flHealthPercent;
    be<TrickleInfoType> eTrickleInfoType;
    be<u32> dwTrickleFlags;
    XOptional<be<i32>> dwHeadstoneCorpseReviveTime;
    XOptional<be<i32>> snoMinimapIcon;
    XOptional<be<u32>> hMinimapStringLabel;
    XOptional<be<u32>> hMinimapIconLabel;
    XOptional<be<u32>> snoStringList;
    XOptional<be<f32>> fMinDisplayRangeSq;
    XOptional<be<f32>> fMaxDisplayRangeSq;
    XOptional<be<i32>> field116;    // this is a bool that existed since at least 1.0.0.8370, so it's probably not bBrawling or bInUberFight
    XOptional<be<u32>> field124;
    XOptional<be<u32>> field132;
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
    be<SSceneID> idSScene;
    be<SNO> snoScene;
    PRTransform transform;
    be<SWorldID> idSWorld;
    be<i32> bRevealed;
};

struct SavePointInfoMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoLevelArea;
};

struct HearthPortalInfoMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoLevelArea;
    be<ACDNetworkName> annPortal;
};

struct ReturnPointInfoMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoLevelArea;
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
    be<ACDNetworkName> ann;
    be<AffixMessageFlag> eAffixArray;
    be<GBID> aAffixGBIDs[32];
    be<u32> dwAffixArrayCount;
};

struct RareMonsterNamesMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<GBID> pgbidRareNames[2];
    be<GBID> pgbidMonsterAffixes[8];
};

struct RareItemName
{
    be<i32> fItemNameIsPrefix;
    be<SNO> snoAffixStringList;
    be<i32> nAffixStringListIndex;
    be<i32> nItemStringListIndex;
};

struct RareItemNameMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    RareItemName tRareItemName;
};

struct ResolvedPortalDestination
{
    be<SNO> snoWorld;
    be<u32> uEntranceGUID;
    be<SNO> snoDestLevelArea;
};

struct PortalSpecifierMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    ResolvedPortalDestination tResolvedDest;
};

struct NetAttributeKeyValue
{
    XOptional<be<i32>> nKeyParam;
    be<Attrib> eKeyAttrib;
    be<i32> nValue;
};

struct AttributeSetValueMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    NetAttributeKeyValue tKeyVal;
};

struct AttributesSetValuesMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<i32> nAttributeCount;
    NetAttributeKeyValue atKeyVals[15];
};

struct VisualItem
{
    be<GBID> gbidItem;
    be<DyeType> eDyeType;
    be<ItemEffectType> eItemEffectType;
    be<i32> nEffectLevel;
};

struct VisualEquipment
{
    VisualItem tVisualItem[8];
};

struct VisualInventoryMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    VisualEquipment tEquipment;
};

struct ProjectileStickMessage
{
    RequiredMessageHeader tHeader;
    Vector3D wpSourceLoc;
    be<ACDNetworkName> annTarget;
    be<SNO> snoActorAttachment;
};

struct AnimPreplayData
{
    be<u32> dwAnimPrePlayDataFlags;
    be<u32> dwServerTimeAnimStarted;
    be<u32> dwSyncedSeed;
};

struct TargetMessage
{
    RequiredMessageHeader tHeader;
    be<TargetType> eType;
    be<ACDNetworkName> annTarget;
    WorldPlace tPlace;
    be<SNO> snoPower;
    be<ACDNetworkName> annItemBeingUsed;
    be<i32> nComboLevel;
    XOptional<AnimPreplayData> tAnimPreplayData;
    XOptional<be<u32>> dwFlags;
};

struct SecondaryAnimationPowerMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoPower;
    XOptional<AnimPreplayData> tAnimPreplayData;
};

struct LoopingAnimationPowerMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoPower;
    be<SNO> snoData0;
    be<i32> nData1;
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
    be<TryChatDestination> eDestination;
    be<i32> nPlayerTarget;
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
    be<EChatColor> eColor;
    be<i32> nPlayerIndex;
    char usMessage[1024];
};

struct InvLoc
{
    be<ACDNetworkName> annOwner;
    be<InventorySlotType> eSlot;
    be<i32> nSlotX;
    be<i32> nSlotY;
};

struct InventoryRequestMoveMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItem;
    InvLoc tLocation;
};

struct InventoryRequestQuickMoveMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItem;
    be<ACDNetworkName> annOwner;
    be<InventorySlotType> eSlot;
    be<i32> nSlotMinY;
    be<i32> nSlotMaxY;
};

struct InventoryRequestSocketMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annGem;
    be<ACDNetworkName> annItemToReceiveGem;
};

struct InventorySplitStackMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItem;
    be<u64> uAmount;
    InvLoc tLocation;
};

struct InventoryStackTransferMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItemSrc;
    be<ACDNetworkName> annItemDest;
    be<u64> uAmount;
};

struct GoldTransferMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annPlayer;
    be<u64> uAmount;
};

struct InventoryRequestUseMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItemToUse;
    be<TargetType> eType;
    be<ACDNetworkName> annTarget;
    WorldPlace tPlace;
};

struct HelperDetachMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annHelper;
};

struct AssignSkillMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoPower;
    be<i32> nRuneType;
    be<i32> nSlot;
    be<i32> nPlayerIndex;
};

struct UnassignSkillMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nSlot;
};

struct AssignTraitsMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoPower[3];
};

struct HirelingRequestLearnSkillMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<SNO> snoSkill;
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
    be<u32> dwDuration;
    be<SNO> snoAnim;
    be<u32> dwAnimationTag;
    be<i32> nPermutationIndex;
    be<f32> flAnimSpeedScale;
};

struct PlayAnimationMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<AnimReason> eAnimReason;
    be<f32> flUnitAnimStartTime;
    be<i32> nUsedAnimArrayElements;
    PlayAnimationMessageSpec tAnim[3];
};

struct ACDTranslateNormalMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    XOptional<Vector3D> vDest;
    XOptional<be<Angle>> aDesiredYaw;
    XOptional<be<i32>> bSnapFacing;
    XOptional<be<f32>> flMovementSpeed;
    XOptional<be<u32>> uMoveFlags;
    XOptional<be<ActorAnimationTag>> eAnimTag;
    XOptional<be<u32>> uWalkInPlaceTicks;
    XOptional<be<SNO>> snoPowerPassability;
    XOptional<be<u32>> uAckValue;
    XOptional<be<u32>> eMoveType;
    //XOptional<int> nMaxTicksToWalk
};

struct ACDTranslateSnappedMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    Vector3D vDest;
    be<Angle> aDesiredYaw;
    be<i32> bSnapFacing;
    be<u32> uMoveFlags;
    XOptional<be<u32>> uAckValue;
};

struct ACDTranslateFacingMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<Angle> aDesiredYaw;
    be<i32> bSnapFacing;
};

struct ACDTranslateFixedMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    Vector3D vVel;
    be<u32> uMoveFlags;
    be<ActorAnimationTag> eAnimTag;
    be<SNO> snoPowerPassability;
};

struct ACDTranslateArcMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    Vector3D vPos;
    Vector3D vVel;
    be<u32> uMoveFlags;
    be<ActorAnimationTag> eAnimTag;
    be<ActorAnimationTag> eLandingAnimTag;
    be<f32> flGravity;
    be<SNO> snoPowerPassability;
    be<f32> flUnitBounce;
    be<f32> flDesiredHeight;
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
    be<ACDNetworkName> ann;
    be<DeterministicPathType> eDPath;
    RNG tSeed;
    Vector3D wvVelocity;
    be<Angle> aOriginalYaw;
    Vector3D vStartPos;
    be<u32> uMoveFlags;
    be<ActorAnimationTag> eAnimTag;
    be<SNO> snoPowerPassability;
    be<u32> nVar0;
    be<f32> flVar0;
    be<f32> flVar1;
    be<f32> flVar2;
    be<f32> flVar3;
    be<f32> flVar4;
};

struct DPathSinData
{
    be<f32> flSinIncPerTick;
    be<f32> flSinIncAccel;
    be<f32> flLateralMaxDistance;
    be<f32> flOOLateralDistanceToScale;
    be<f32> flLateralStartDistance;
    be<f32> flSpeed;
};

struct ACDTranslateDetPathSinMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<DeterministicPathType> eDPath;
    RNG tSeed;
    Vector3D wvVelocity;
    be<Angle> aOriginalYaw;
    Vector3D vStartPos;
    be<u32> uMoveFlags;
    be<ActorAnimationTag> eAnimTag;
    be<SNO> snoPowerPassability;
    be<i32> nVar0;
    be<f32> flVar0;
    DPathSinData tSinData;
    be<f32> flSpeedMult;
};

struct ACDTranslateDetPathSpiralMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    Vector3D vStartPos;
    Vector3D vTargetPos;
    be<u32> uMoveFlags;
    be<ActorAnimationTag> eAnimTag;
    be<f32> flVar0;
    DPathSinData tSinData;
    be<f32> flSpeedMult;
};

struct ACDTranslateSyncMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    Vector3D vPos;
    XOptional<be<i32>> bSnap;
    XOptional<be<u32>> uAckValue;
};

struct ACDTranslateFixedUpdateMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    Vector3D vPos;
    Vector3D vVel;
};

struct ACDClientTranslateMessage
{
    RequiredMessageHeader tHeader;
    be<u32> uTickBase;
    be<u32> uTicksAhead;
    Vector3D vDest;
    Angle aDesiredYaw;
    be<f32> flMovementSpeed;
    be<u32> uMoveFlags;
    be<u32> eAnimTag;
    XOptional<be<SNO>> snoPower;
};

struct ACDTranslateAckMessage
{
    RequiredMessageHeader tHeader;
    be<u32> uAckValue;
};

struct PlayEffectMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<EffectType> eEffectType;
    XOptional<be<i32>> nEffectParameter;
};

struct PlayHitEffectMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<ACDNetworkName> annAttacker;
    be<DamageType> eDamageType;
    be<i32> fCrit;
};

struct PlayHitEffectOverrideMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<ACDNetworkName> annAttacker;
    be<SNO> snoEffectGroup;
};

struct PlayNonPositionalSoundMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoSound;
};

struct PlayErrorSoundMessage
{
    RequiredMessageHeader tHeader;
    be<ActorTag> dwSoundTag;
};

struct PlayMusicMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoMusic;
};

struct PlayCutsceneMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nIndex;
};

struct ComplexEffectAddMessage
{
    RequiredMessageHeader tHeader;
    be<SComplexEffectID> idSComplexEffect;
    be<ComplexEffectType> eType;
    be<SNO> snoEffectGroup;
    be<ACDNetworkName> annSource;
    be<ACDNetworkName> annDest;
    be<u32> dwParam1;
    be<u32> dwParam2;
    be<u32> bIgnoreOwnerAlpha;
};

struct FlippyMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annLauncher;
    be<SNO> snoFlippyParticle;
    be<SNO> snoActorLoot;
    Vector3D wpDest;
};

struct WaypointActivatedMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annWaypoint;
    be<ACDNetworkName> annActivatingPlayer;
    be<SNO> snoLevelArea;
    be<i32> bAnnounce;
};

struct AimTargetMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<TargetType> eType;
    be<ACDNetworkName> annTarget;
    WorldPlace tPlace;
};

struct ACDChangeGBHandleMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    GBHandle hGB;
};

struct EndOfTickMessage
{
    RequiredMessageHeader tHeader;
    be<u32> dwTickEnding;
    be<u32> dwTickNext;
};

struct TryWaypointMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annWaypoint;
    be<u32> nWaypoint;
};

enum NPCInteractionType
{
    NIT_INVALID,
    NIT_CANCEL,
    NIT_TALK_IMPORTANT,
    NIT_TALK_DIALOG,
    NIT_PET_DISMISS,
    NIT_CRAFT,
    NIT_IDENTIFY,
    NIT_HIRE,
    NIT_INVENTORY,
    NIT_CUSTOMIZATION,
    //NIT_EQUIPMENT_MANAGER,
    NIT_NUM_TYPES,
};

struct NPCInteraction
{
    be<NPCInteractionType> eType;
    be<u32> dwData;
    be<u32> dwData2;
    be<u32> dwFlags;
};

enum NPCMenu
{
    // TODO
};

struct NPCInteractOptionsMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annTalkingTo;
    NPCInteraction tNPCInteraction[20];
    be<i32> nNumInteractions;
    be<NPCMenu> ePreferredMenu;
};

struct QuestUpdateMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoQuest;
    be<SNO> snoLevelArea;
    be<i32> nStepUID;
    be<i32> bFailed;
    be<i32> bDisplayButton;
};

struct QuestMeterMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoQuest;
    be<ACDNetworkName> annMeter;
    be<f32> flMeter;
};

struct QuestCounterMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoQuest;
    be<SNO> snoLevelArea;
    be<i32> nStepUID;
    be<i32> nObjectiveIndex;
    be<i32> nValue;
    be<i32> bCompleted;
};

struct PlayerLevel
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    be<i32> nNewLevel;
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
    be<i32> bIsCurrency;
    be<PickupResponse> ePickupResponse;
    be<ACDNetworkName> annPickee;
};

struct PetMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nOwner;
    be<i32> nIndex;
    be<ACDNetworkName> annPet;
    be<i32> nType;
};

struct PetDetachMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annPet;
    be<i32> bDisplayChatMessage;
};

struct HirelingInfoUpdateMessage
{
    RequiredMessageHeader tHeader;
    be<i32> eClass;
    be<i32> fDead;
    be<GBID> gbidName;
    be<i32> eValidClass;
    be<SNO> arnPowerKeyParam[5];
    be<ACDNetworkName> annItems[6];
    be<i32> nPlayerIndex;
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
    be<UIElement> eElement;
    be<UIElementAction> eAction;
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
    be<i32> eMessageType;
    be<u32> dwData;
    be<u32> dwData2;
    be<u64> uData64;
    be<ACDNetworkName> ann;
    be<ACDNetworkName> arrItems[4];
};

struct SetIdleAnimationMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<u32> dwAnimTag;
};

struct ACDCollFlagsMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<u32> uCollFlags;
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
    be<i32> bPlaySound;
    be<GoldModifiedReason> eReason;
};

struct ActTransitionMessage
{
    RequiredMessageHeader tHeader;
    be<Act> eAct;
    be<i32> bOnJoin;
};

struct InterstitialMessage
{
    RequiredMessageHeader tHeader;
    be<PlayerClass> ePlayerClass;
    be<i32> fIsMale;
};

struct EffectGroupACDToACDMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoEffectGroup;
    be<ACDNetworkName> annFrom;
    be<ACDNetworkName> annTo;
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
    be<SNO> snoRope;
    be<ACDNetworkName> annFrom;
    be<RopePosition> ePositionFrom;
    be<ACDNetworkName> annTo;
    be<RopePosition> ePositionTo;
    be<i32> bIgnoreOwnerAlpha;
};

struct RopeEffectMessageACDToPlace
{
    RequiredMessageHeader tHeader;
    be<SNO> snoRope;
    be<ACDNetworkName> annFrom;
    be<RopePosition> ePositionFrom;
    WorldPlace tPlaceTo;
    be<i32> bIgnoreOwnerAlpha;
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
    be<u32> dwGameSyncedFlags;
    be<Act> eAct;
    be<Team> arPlayerAllyTeam[4];  // there is a 40 byte gap in the type descriptor here, team data fits the most
    be<Team> arMonsterTeam[4];
    be<Team> eSceneryTeam;
    be<Team> eNeutralTeam;
    be<i32> bPregame;
    be<u32> dwPregameEnd;
    be<u32> dwRoundStart;
    be<u32> dwRoundEnd;
    be<i32> bPVPGameOver;
    be<i32> bPVPAwardsAssigned;
    be<u32> nTeamWins[2];
    be<u32> nTeamScore[2];
    be<PVPGameResult> ePVPGameResult[2];
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
    be<ACDNetworkName> ann;
    be<SNO> snoActor;
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
    //WARP_CHALLENGE,
    WARP_CANCELLED,
    //WARP_CONSOLE_PVP_SS,
    //WARP_TIERED_RIFT,
    //WARP_SET_DUNGEON,
    WARP_COUNT,
    WARP_COUNT_PC = 12,
};

struct PlayerWarpedMessage
{
    RequiredMessageHeader tHeader;
    be<PlayerWarpReason> eWarpReason;
    be<f32> flWarpFadeInSeconds;
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
    be<i32> nPlayerVictimIndex;
    be<i32> nKillerLevel;
    be<i32> nKillerPlayerIndex;
    be<MonsterRarity> eKillerMonsterRarity;
    be<SNO> snoKillerActor;
    be<Team> eKillerTeam;
    be<GBID> pKillerRareNameGBIDs[2];
    be<SNO> snoPowerDmgSource;
};

struct EngagedMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    be<SNO> snoActorMonster;
    be<i32> eMonsterRarity;
    be<GBID> pRareNameGBIDs[2];
};

struct KillCountMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    be<i32> nPlayerKills;
    be<i32> nDeaths;
    be<i32> nAssists;
};

struct WorldStatusMessage
{
    RequiredMessageHeader tHeader;
    be<SWorldID> idSWorld;
    be<u32> dwWorldStatusBits;
};

struct WeatherOverrideMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoWeatherOverride;
    be<f32> flWeatherIntensityOverride;
    be<f32> flWeatherIntensityOverrideEnd; // dword in later versions
};

struct ACDShearMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<f32> flShear;
};

struct ACDGroupMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<u32> uPrimaryGroup;
    be<u32> uSecondaryGroup;
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
    be<SNO> snoConversation;
    be<i32> nSpeakingPlayerIndex;
    be<i32> bZoom;
    be<i32> bFirstLine;
    be<i32> bHostile;
    be<i32> bPlayerInitiated;
    be<u32> dwLineUID;
    be<ConversationSpeaker> eLineSpeaker;
    be<ActorGender> eLineGender;
    be<PlayerClass> eLineClass;
    be<ConversationSpeaker> eSpeakerTarget;
    be<SNO> snoSpeakerActor;
    be<ActorGender> ePlayerGender;
    be<PlayerClass> ePlayerClass;
    be<u32> dwLineFlags;
    be<u32> dwLineAnimTag;
    be<u32> dwLineDisplayTime;
    be<i32> nLineGUID;
    be<i32> nPriority;
};

struct PlayConvLineMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annSpeaker;
    be<ACDNetworkName> annParticipants[9];
    PlayLineParams tParams;
    be<u32> dwTimeToDisplay;
};

struct StopConvLineMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nConvLineGUID;
    be<i32> fStoppedByUser;
};

struct AdvanceConvMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoConv;
    be<i32> nLineUID;
};

struct UpdateConvAutoAdvanceMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoConv;
    be<i32> nLineUID;
    be<u32> dwNextAdvanceTime;
};

struct EndConversationMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoConversation;
    be<ACDNetworkName> annSpeaker;
};

struct HirelingSwapMessage
{
    RequiredMessageHeader tHeader;
    be<HirelingClass> eNewClass;
};

struct DeathFadeTimeMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<i32> nTimeUntilFade;
    be<i32> nFadeTime;
    be<i32> bRecurseForAttachments;
};

struct DisplayGameTextMessage
{
    RequiredMessageHeader tHeader;
    char szMsg[1024];
    XOptional<be<i32>> nParam1;
    XOptional<be<i32>> nParam2;
};

struct ACDLookAtMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annSrc;
    be<ACDNetworkName> annTarget;
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
    be<KillCounterType> eType;
    be<u32> uCount;
    // float flXPMultiplier
    be<u32> uTotalTime;
    be<i32> bExpired;
};

struct LowHealthCombatMessage
{
    RequiredMessageHeader tHeader;
    be<f32> flHealthPercent;
    be<u32> uXPRewarded;
};

struct SaviorMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annSavedPlayer;
    be<u32> uXPRewarded;
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
    be<ACDNetworkName> annTarget;
    be<f32> flDamage;
    be<FloatingNumberType> eType;
};

struct FloatingAmountMessage
{
    RequiredMessageHeader tHeader;
    WorldPlace wpPlace;
    be<i32> nAmount;
    XOptional<be<i32>> nAmount2;
    be<FloatingNumberType> eType;
};

struct RemoveRagdollMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annTarget;
    be<SNO> snoMonster;
};

struct LoreMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoLore;
};

struct WorldDeletedMessage
{
    RequiredMessageHeader tHeader;
    be<SWorldID> idSWorld;
};

struct ActiveEvent
{
    be<SNO> snoTimedEvent;
    be<u32> dwStartTime;
    be<u32> dwExpirationTime;
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
    be<u32> dwActTransitionTime;
    //be<i32> bRecreateGameWithParty;
    be<i32> nPlayerIndex;
};

struct PlayerQuestMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerIndex;
    be<SNO> snoQuest;
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
    be<DeSyncReason> eReason;
    be<SNO> snoPowerCurrent;
    be<i32> nPlayerIndex;
};

struct SalvageResultsMessage
{
    RequiredMessageHeader tHeader;
    be<GBID> gbidOriginalItem;
    be<ItemQualityLevel> eIQLOriginalItem;
    be<u32> field16;
    be<GBID> gbidMaterials[10];
};

struct MapMarkerInfoMessage
{
    RequiredMessageHeader tHeader;
    be<u32> m_nHashedName;
    WorldPlace m_Place;
    be<SNO> m_ImageInfo;
    be<u32> m_hImage;
    be<SNO> m_snoStringList;
    be<u32> m_hLabel;
    be<i32> m_bActive;
    be<i32> m_bCanBecomeArrow;
    be<i32> m_bRespectsFoW;
    be<i32> m_bIsPing;
    be<f32> m_fMaxDisplayRangeSq;
    be<f32> m_fMinDisplayRangeSq;
    be<f32> m_fDiscoveryRangeSq;
    be<u32> m_nPlayerUseFlags;
};

struct DebugActorTooltipMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    char szTooltip[1024];
};

struct BossEncounterMessage
{
    RequiredMessageHeader tHeader;
    be<u32> nPlayerIndex;
    be<SNO> snoEncounter;
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
    be<ACDNetworkName> ann;
    be<i32> bSnap;
    be<f32> flDuration;
};

struct CameraZoomMessage
{
    RequiredMessageHeader tHeader;
    be<f32> flZoom;
    be<i32> bSnap;
    be<f32> flDuration;
};

struct CameraYawMessage
{
    RequiredMessageHeader tHeader;
    be<Angle> aAngle;
    be<i32> bSnap;
    be<f32> flDuration;
};

struct BossZoomMessage
{
    RequiredMessageHeader tHeader;
    be<f32> flZoom;
    be<f32> flZoomSpeed;
};

struct EnchantItemMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItem;
    be<GBID> gbidAffix;
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
    be<u32> uID;
    be<DebugDrawPrimType> eType;
    be<SWorldID> idSWorld;
    Vector3D vPos0;
    Vector3D vPos1;
    be<f32> flLength;
    be<f32> flRadius;
    be<u32> uLifetimeInTicks;
    RGBAColor rgbaColor;
    char szText[128];
};

struct CraftingResultsMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> annItem;
    be<GBID> gbidItem;
    be<ItemQualityLevel> eIQL;
};

struct CrafterLevelUpMessage
{
    RequiredMessageHeader tHeader;
    be<CrafterType> eType;
    be<u32> dwAnimTag;
    be<u32> dwNewIdle;
    //be<i32> nLevel;
};

struct UnlockDifficultyMessage
{
    RequiredMessageHeader tHeader;
    be<u32> field8;
    be<u32> field12;
};

struct DifficultyAndHandicapMessage
{
    RequiredMessageHeader tHeader;
    be<DifficultyLevel> eDifficulty;
    be<i32> nHandicapLevel;
};

struct GameTestingSamplingStartMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoWorld;
    be<SNO> snoScene;
};

struct RequestBuffCancelMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoPower;
    be<i32> nBuffIndex;
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
    be<i32> nPlayerIndexToKick;
    be<i32> nPlayerIndexInitiating;
    char usMessage[1024];
};

struct MailSendMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nToAccount;
};

struct MailReadMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
};

struct MailRetrieveMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
};

struct MailDeleteMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
};

struct MailSentResponseMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
    be<i32> idErr;
};

struct MailReadResponseMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
    be<i32> idErr;
};

struct MailRetrieveResponseMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
    be<i32> idErr;
};

struct MailDeleteResponseMessage
{
    RequiredMessageHeader tHeader;
    be<u64> idMail;
    be<i32> idErr;
};

struct PVPTokenRedemptionMessage
{
    RequiredMessageHeader tHeader;
    be<u32> nItems;
    be<ACDNetworkName> arrItems[4];
    be<GBID> arrGBIDs[4];
    be<u32> nStackSize[4];
};

struct PlayerSetCameraObserverMessage
{
    RequiredMessageHeader tHeader;
    be<SNO> snoObserver;
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
    be<i32> bForce;
};

struct PlayerSavedQuestUpdateMessage
{
    RequiredMessageHeader tHeader;
    be<DifficultyLevel> eLastPlayedDifficulty;
    be<Act> eLastPlayedAct;
    be<SNO> snoLastPlayedQuest;
    be<i32> nLastPlayedStepUID;
    //be<i32> nHandicapLevel;
    PlayerSavedQuest tSavedQuest[64];
    be<u32> dwNumQuests;
};

struct PlayerQuestHistoryUpdateMessage
{
    RequiredMessageHeader tHeader;
    PlayerQuestHistoryEntry tQuestHistory[200];
    be<u32> dwNumEntries;
};

struct PlayerQuestRewardHistoryUpdateMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nNumQuestRewardEntries;
    PlayerQuestRewardHistoryEntry tQuestRewardHistory[100];
};

struct PlayerSavedConversationsUpdateMessage
{
    RequiredMessageHeader tHeader;
    SavedConversations tSavedConversations;
};

struct ConsoleCriteriaUpdate
{
    be<u32> field0;
    be<u32> field4;
};

struct ConsoleAchievementCriteriaUpdateMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nNumUpdates;
    ConsoleCriteriaUpdate tUpdates[64];
};

struct ConsoleAchievementAwardedMessage
{
    RequiredMessageHeader tHeader;
    be<u32> field8;
    be<u64> field16;
    be<u32> field24;
};

struct DuelResultMessage
{
    RequiredMessageHeader tHeader;
    be<i32> nPlayerVictimIndex;
    be<i32> nPlayerKillerIndex;
    be<SNO> snoPowerDmgSource;
};

struct ItemJunkFlagChangedMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<i32> bJunkFlag;
};

struct SpendParagonPointsMessage
{
    RequiredMessageHeader tHeader;
    be<GBID> gbidParagonBonus;
    be<i32> nPoints;
};

struct PlayerClearClientWalkPowerMessage
{
    RequiredMessageHeader tHeader;
    be<ACDNetworkName> ann;
    be<SNO> snoPower;
};
