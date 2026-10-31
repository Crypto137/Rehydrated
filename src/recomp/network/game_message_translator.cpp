#include "recomp/network/game_message_translator.h"

#include "game/sigma/type_descriptor/type_descriptor.h"

namespace
{

constexpr u32 dwSNOCoreDataHashPC = 0xF2B9DA6E;   // 1.0.8.16603

struct GameMessageTypeMapping
{
    GameMessageType ConsoleType;
    int PCType;
};

constexpr GameMessageTypeMapping s_MessageTypeMappings[] = {
    { CMSG_TRY_CONSOLE_COMMAND,                                1 },
    { SMSG_TRY_CONSOLE_COMMAND,                                2 },
    { SMSG_QUIT,                                               3 },
    // Preload and Player Warping messages have no handlers on PC,
    // so sending them results in an AssetMismatch disconnect.
    { SMSG_PRELOAD_ADD_SCENE,                                  0 }, // 6
    { SMSG_PRELOAD_ADD_ACD,                                    0 }, // 7
    { SMSG_PRELOAD_REMOVE_SCENE,                               0 }, // 8
    { SMSG_PRELOAD_REMOVE_ACD,                                 0 }, // 9
    { SMSG_PLAYER_WARPING,                                     0 }, // 10
    { CMSG_REQUEST_LAN_GAME_PARAMS,                           13 },
    { SMSG_NET_LOUNGE_ADVERTIZE_GAME,                          0 },
    { CMSG_JOIN_BNET_GAME,                                    17 },
    { CMSG_JOIN_LAN_GAME,                                     18 },
    { CMSG_JOIN_CONSOLE_GAME,                                 19 },
    { CMSG_LEAVE_CONSOLE_GAME,                                 0 },
    { SMSG_VERSIONS,                                          21 },
    { SMSG_CRAFTER_OPEN,                                      42 },
    { CMSG_VENDOR_CLOSE,                                      43 },
    { SMSG_SHOP_OPEN,                                         44 },
    { CMSG_SHOP_TRY_BUY,                                      45 },
    { CMSG_SHOP_TRY_SELL,                                     46 },
    { CMSG_SHOP_TRY_SELL_STACK_PORTION,                        0 },
    { SMSG_SHOP_BUYBACK_NOTIFY,                               47 },
    { CMSG_START_LOGOUT_TIMER,                                48 },
    { SMSG_LOGOUT_TIMER_STARTED,                              49 },
    { CMSG_LOGOUT_NOW,                                        50 },
    { CMSG_CANCEL_LOGOUT,                                     51 },
    { SMSG_PLAYER_DELETE,                                     52 },
    { SMSG_PLAYER_HAS_DIED,                                   53 },
    { CMSG_ACCEPTED_DEATH,                                    54 },
    { SMSG_ACCEPTED_DEATH_ACK,                                55 },
    { SMSG_TUTORIAL,                                          56 },
    { SMSG_TUTORIAL_STATE,                                    57 },
    { SMSG_STASH_ICON_STATE,                                  58 },
    { CMSG_STASH_ICON_STATE,                                  59 },
    { SMSG_COMBAT_LOG_ENTRY,                                  60 },
    { CMSG_COMBAT_LOG_TOGGLE,                                 61 },
    { SMSG_CONNECTION_ESTABLISHED,                            62 },
    { SMSG_CONNECTION_ADD_PLAYER,                              0 },
    { SMSG_GAME_SETUP,                                        63 },
    { CMSG_FINISHED_GAME_SETUP,                               64 },
    { SMSG_NEW_PLAYER,                                        65 },
    { SMSG_PLAYER_KICK_TIMERS,                                66 },
    { SMSG_PLAYER_BANNER,                                     67 },
    { SMSG_ENTER_WORLD,                                       68 },
    { SMSG_REVEAL_SCENE,                                      69 },
    { SMSG_DESTROY_SCENE,                                     70 },
    { SMSG_SWAP_SCENE,                                        71 },
    { SMSG_REVEAL_WORLD,                                      72 },
    { SMSG_REVEAL_TEAM,                                       73 },
    { SMSG_PLAYER_ACTOR_SET,                                  74 },
    { SMSG_HERO_STATE,                                        75 },
    { SMSG_HERO_STATE_SAVEDDATA,                              76 },
    { SMSG_HERO_STATE_PLAYERFLAGS,                            77 },
    { SMSG_HERO_STATE_WAYPOINTS,                              78 },
    { SMSG_HERO_STATE_LASTSAVEPOINT,                          79 },
    { SMSG_ACD_ENTER_KNOWN,                                   80 },
    { SMSG_ACD_EXIT_KNOWN,                                    81 },
    { SMSG_PLAYER_ENTER_KNOWN,                                82 },
    { SMSG_UI_ENTER_KNOWN,                                    83 },
    { SMSG_ACD_WORLD_POSITION,                                84 },
    { SMSG_ACD_INVENTORY_POSITION,                            85 },
    { SMSG_ACD_INVENTORY_UPDATE_ACTOR_SNO,                    86 },
    { SMSG_TRICKLE_UPDATE,                                    87 },
    { SMSG_TRICKLE_REMOVE,                                    88 },
    { SMSG_MAP_REVEAL_SCENE,                                  89 },
    { SMSG_SAVEPOINT_INFO,                                    90 },
    { SMSG_HEARTHPORTAL_INFO,                                 91 },
    { SMSG_RETURNPOINT_INFO,                                  92 },
    //{ SMSG_AFFIX,                                             93 },
    { SMSG_AFFIX,                                             0 },  // disabled until crashes are fixed
    { SMSG_RARE_MONSTER_NAMES,                                94 },
    { SMSG_RARE_ITEM_NAME,                                    95 },
    { SMSG_PORTAL_SPECIFIER,                                  96 },
    { SMSG_ATTRIBUTE_SET_VALUE,                               97 },
    { SMSG_ATTRIBUTES_SET_VALUES,                             98 },
    { SMSG_VISUAL_INVENTORY,                                  99 },
    { SMSG_PROJECTILE_STICK,                                 100 },
    { CMSG_TARGET,                                           101 },
    { CMSG_SECONDARY_ANIMATION_POWER,                        102 },
    { CMSG_LOOPING_ANIMATION_POWER,                          103 },
    { CMSG_EXECUTE_NON_PRIMARY_POWER,                        104 },
    { CMSG_CHANNELLED_POWER_ABORTED,                         105 },
    { CMSG_LOOPING_POWER_ABORTED,                            106 },
    { CMSG_CLIENT_WALK_POWER_ABORTED,                        107 },
    { CMSG_TRY_CHAT,                                         108 },
    { SMSG_CHAT,                                             109 },
    { CMSG_TRY_DROP,                                         110 },
    { CMSG_TRY_INVENTORY_MOVE,                               111 },
    { CMSG_TRY_INVENTORY_QUICK_MOVE,                         112 },
    { CMSG_TRY_INVENTORY_SOCKET,                             113 },
    { CMSG_TRY_INVENTORY_STACK,                              114 },
    { CMSG_TRY_INVENTORY_SPLIT_STACK,                        115 },
    { CMSG_TRY_INVENTORY_DROP_STACK_PORTION,                 116 },
    { CMSG_TRY_INVENTORY_STACK_TRANSFER,                     117 },
    { CMSG_TRY_GOLD_TRANSFER,                                  0 },
    { SMSG_STACK_NOTIFY,                                     118 },
    { SMSG_STACK_DECREASE_NOTIFY,                              0 },
    { SMSG_IDENTIFY_NOTIFY,                                  119 },
    { SMSG_ITEM_DELETE_NOTIFY,                               120 },
    { CMSG_TRY_INVENTORY_SWAP_TO_BODY,                       121 },
    { CMSG_TRY_INVENTORY_USE,                                122 },
    { CMSG_HELPER_DETACH,                                    123 },
    { CMSG_TRY_ASSIGN_SKILL_TO_SLOT,                         124 },
    { CMSG_UNASSIGN_SKILL,                                   125 },
    { CMSG_TRY_ASSIGN_TRAITS,                                126 },
    { SMSG_ASSIGNED_SKILL_TO_SLOT,                           127 },
    { SMSG_ASSIGNED_TRAIT_TO_SLOT,                           128 },
    { CMSG_TRY_CHOOSE_HIRELING_SKILL,                        129 },
    { CMSG_TRY_PORTRAIT_DROP,                                130 },
    { CMSG_PLAYER_CHANGE_POTION_BUTTON,                      131 },
    { SMSG_AUTOASSIGNED_TO_BUTTON,                           132 },
    { SMSG_PLAY_ANIMATION,                                   133 },
    { SMSG_PLAY_IDLE_ANIMATION,                              134 },
    { SMSG_ACD_TRANSLATE_NORMAL,                             135 },
    { SMSG_ACD_TRANSLATE_SNAPPED,                            136 },
    { SMSG_ACD_TRANSLATE_FACING,                             137 },
    { SMSG_ACD_TRANSLATE_FIXED,                              138 },
    { SMSG_ACD_TRANSLATE_ARC,                                139 },
    { SMSG_ACD_TRANSLATE_DETPATH,                            140 },
    { SMSG_ACD_TRANSLATE_DETPATH_SIN,                        141 },
    { SMSG_ACD_TRANSLATE_DETPATH_SPIRAL,                     142 },
    { SMSG_ACD_TRANSLATE_SYNC,                               143 },
    { SMSG_ACD_TRANSLATE_FIXED_UPDATE,                       144 },
    { CMSG_ACD_TRANSLATE_NORMAL,                             145 },
    { CMSG_ACD_TRANSLATE_FACING,                             146 },
    { CMSG_ACD_TRANSLATE_ACK,                                147 },
    { SMSG_PLAY_EFFECT,                                      148 },
    { SMSG_PLAY_HIT_EFFECT,                                  149 },
    { SMSG_PLAY_HIT_EFFECT_OVERRIDE,                         150 },
    { SMSG_PLAY_NONPOSITIONAL_SOUND,                         151 },
    { SMSG_PLAY_ERROR_SOUND,                                 152 },
    { SMSG_PLAY_MUSIC,                                       153 },
    { SMSG_STOP_MUSIC_OVERLAY,                               154 },
    { SMSG_PLAY_CUTSCENE,                                    155 },
    { SMSG_SCOMPLEX_EFFECT_ADD,                              156 },
    { SMSG_FLIPPY,                                           157 },
    { SMSG_ACTIVATE_WAYPOINT,                                158 },
    { SMSG_OPERATE_WAYPOINT,                                 159 },
    { SMSG_CONFIRM_OPERATION,                                160 },
    { SMSG_OPEN_BANNER_CUSTOMIZATION,                        161 },
    { CMSG_OPERATE_GIZMO,                                    162 },
    { CMSG_ACCEPT_RESURRECT,                                 163 },
    { SMSG_AIM_TARGET,                                       164 },
    { SMSG_ACD_CHANGE_GB_HANDLE,                             165 },
    { SMSG_HEARTBEAT,                                        166 },
    { SMSG_PVP_ARENA_WIN,                                    167 },
    { SMSG_PVP_ARENA_LOSE,                                   168 },
    { CCMSG_END_OF_TICK,                                     169 },
    { CMSG_TRY_WAYPOINT,                                     170 },
    { SMSG_NPC_INTERACT,                                     171 },
    { CMSG_NPC_TALK_REQUEST,                                 172 },
    { CMSG_NPC_VENDOR_REQUEST,                               173 },
    { SMSG_FORCE_NPC_INTERACT_CLOSE,                         174 },
    { SMSG_QUEST_UPDATE,                                     175 },
    { SMSG_QUEST_METER,                                      176 },
    { SMSG_QUEST_COUNTER,                                    177 },
    { SMSG_QUEST_REWARD,                                     178 },
    { SMSG_PLAYER_LEVEL,                                     180 },
    { SMSG_PLAYER_ALT_LEVEL,                                 181 },
    { SMSG_SHARED_STASH_OPEN,                                182 },
    { SMSG_ACD_PICKUP_FAILED,                                183 },
    { SMSG_ATTACH_PET,                                       184 },
    { SMSG_DETACH_PET,                                       185 },
    { SMSG_SET_HIRELING_DEAD,                                186 },
    { SMSG_UI_ELEMENT_ACTION,                                187 },
    { CMSG_PLAYER_BUSY,                                      188 },
    { CMSG_TRADE,                                            189 },
    { SMSG_TRADE,                                            190 },
    { CMSG_INSPECT_START,                                    191 },
    { CMSG_INSPECT_END,                                      192 },
    { SMSG_INSPECT,                                          193 },
    { SMSG_ACD_SET_IDLE_ANIM,                                194 },
    { SMSG_ACD_COLL_FLAGS,                                   195 },
    { SMSG_GOLD_MODIFIED,                                    196 },
    { SMSG_ACT,                                              197 },
    { SMSG_INTERSTITIAL,                                     198 },
    { SMSG_EFFECT_GROUP_ACD_TO_ACD,                          199 },
    { SMSG_ROPE_EFFECT_ACD_TO_ACD,                           200 },
    { SMSG_ROPE_EFFECT_ACD_TO_PLACE,                         201 },
    { SMSG_INVENTORY_CREATE,                                 202 },
    { SMSG_SHRINE_TEXT_DISPLAY,                              203 },
    { SMSG_GAME_SYNCED_DATA,                                 204 },
    { SMSG_CHANGE_ACTOR,                                     205 },
    { SMSG_PLAYER_WARPED,                                    206 },
    { SMSG_VICTIM,                                           207 },
    { SMSG_MONSTER_ENGAGED,                                  208 },
    { SMSG_KILLCOUNT,                                        209 },
    { SMSG_WORLD_STATUS,                                     210 },
    { SMSG_WEATHER_OVERRIDE,                                 211 },
    { SMSG_TRIGGER_LIGHTNING,                                212 },
    { SMSG_SHEAR,                                            213 },
    { SMSG_GROUP,                                            214 },
    { CMSG_KEEPALIVE,                                        215 },
    { SMSG_PLAY_CONV_LINE,                                   216 },
    { SMSG_STOP_CONV_LINE,                                   217 },
    { CMSG_REQUEST_CONV_ADVANCE,                             218 },
    { CMSG_UPDATE_CONV_AUTO_ADVANCE,                         219 },
    { CMSG_REQUEST_CONV_CANCEL,                              220 },
    { SMSG_END_CONV,                                         221 },
    { SMSG_CONFIRM_HIRELING_SWAP,                            224 },
    { SMSG_HIRELING_AUTO_DISMISS,                            225 },
    { CMSG_REQUEST_HIRELING_SWAP,                            226 },
    { SMSG_SET_DEATH_FADE_TIMES,                             227 },
    { SMSG_RESET_DEATH_FADE_TIMES,                           228 },
    { SMSG_REMOVE_FROM_SPHERE_LIST,                          229 },
    { SMSG_DISPLAY_GAME_TEXT,                                230 },
    { SMSG_DISPLAY_ERROR,                                    231 },
    { SMSG_DISPLAY_VAGUE_LOCKED_ERROR,                       232 },
    { SMSG_DISPLAY_ITEM_REQUIRED_ERROR,                      233 },
    { SMSG_CANCEL_ACD_TARGET,                                234 },
    { SMSG_RESET_ACD_EFFECTS,                                235 },
    { SMSG_LOOK_AT_ACD,                                      236 },
    { SMSG_KILL_COUNTER_UPDATE,                              237 },
    { SMSG_LOW_HEALTH_COMBAT,                                238 },
    { SMSG_SAVIOR,                                           239 },
    { SMSG_FLOATING_NUMBER,                                  240 },
    { SMSG_FLOATING_AMOUNT,                                  241 },
    { SMSG_REMOVE_NEAREST_RAGDOLL,                           242 },
    { SMSG_PREFETCH,                                         243 },
    { SMSG_PREFETCH_AND_SCAN_CHILDREN,                       244 },
    { SMSG_LORE_LEARNED,                                     245 },
    { CMSG_AV_CAMERA_MODE_TOGGLE,                            246 },
    { CMSG_AV_CAMERA_LOCATION,                               247 },
    { SMSG_TRIAL_OVER,                                       248 },
    { SMSG_DEMO_OVER,                                          0 },
    { SMSG_WORLD_DELETED,                                    249 },
    { SMSG_PVP_ARENA_RESTART,                                250 },
    { SMSG_SET_SCREENSHOT_VIEW,                              251 },
    { SMSG_TIMED_EVENT_STARTED,                              252 },
    { SMSG_TIMED_EVENT_FINISHED,                             253 },
    { SMSG_ACT_TRANSITION_STARTED,                           254 },
    { SMSG_ACT_TRANSITION_ENDED,                             255 },
    { CMSG_SHARED_STASH_TRY_BUY,                             256 },
    { SMSG_PLAYER_ACTIVATED_QUEST,                           257 },
    { SMSG_PLAYER_COMPLETED_QUEST,                           258 },
    { SMSG_PLAYER_DESYNC_SNAP,                               259 },
    { CMSG_TRY_SALVAGE,                                      260 },
    { SMSG_SALVAGE_RESULT,                                   261 },
    { SMSG_RETURNED_GEMS_NOTIFICATION,                       262 },
    { SMSG_MAP_MARKER,                                       263 },
    { SMSG_CRAFTING_DATA_BLACKSMITH,                         264 },
    { SMSG_CRAFTING_DATA_JEWELER,                            265 },
    { SMSG_CRAFTING_DATA_MYSTIC,                             266 },
    { SMSG_CRAFTING_DATA_BLACKSMITH_INITIAL,                 267 },
    { SMSG_CRAFTING_DATA_JEWELER_INITIAL,                    268 },
    { SMSG_CRAFTING_DATA_MYSTIC_INITIAL,                     269 },
    { CMSG_REQUEST_DEBUG_ACTOR_TOOLTIP,                      270 },
    { SMSG_DISPLAY_DEBUG_ACTOR_TOOLTIP,                      271 },
    { SMSG_BOSS_JOIN_ENCOUNTER,                              272 },
    { CMSG_BOSS_JOIN_ACCEPTED,                               273 },
    { CMSG_BOSS_START_ACCEPTED,                              274 },
    { SMSG_BOSS_START_ENCOUNTER,                             275 },
    { CMSG_BOSS_START_DECLINED,                              276 },
    { CMSG_BOSS_JOIN_DECLINED,                               277 },
    { SMSG_BOSS_ENCOUNTER_INVITE_STATE,                      278 },
    { SMSG_BOSS_ENCOUNTER_STARTED,                           279 },
    { SMSG_BOSS_ENCOUNTER_CANCELED,                          280 },
    { SMSG_BOSS_ENCOUNTER_ONE_DECLINED,                      281 },
    { CMSG_BOSS_VOTE_CONTINUE,                               282 },
    { CMSG_BOSS_VOTE_CANCEL,                                 283 },
    { SMSG_CAMERA_SCRIPTED_SEQUENCE_START,                   284 },
    { SMSG_CAMERA_SCRIPTED_SEQUENCE_STOP,                    285 },
    { SMSG_CAMERA_FOCUS_ACD,                                 286 },
    { SMSG_CAMERA_ZOOM,                                      287 },
    { SMSG_CAMERA_YAW,                                       288 },
    { SMSG_CAMERA_TRIGGER_FADE,                              289 },
    { SMSG_CAMERA_TRIGGER_FADE_TO_BLACK,                     290 },
    { SMSG_CAMERA_TRIGGER_INSTANT_FADE_TO_BLACK,             291 },
    { SMSG_BOSS_ZOOM,                                        292 },
    { CMSG_TRY_ENHANCE,                                      293 },
    { CMSG_TRY_REPAIR,                                       294 },
    { CMSG_TRY_REPAIR_ALL,                                   295 },
    { CMSG_TRY_REPAIR_EQUIPPED,                              296 },
    { SMSG_REPAIR_ACK,                                         0 },
    { CMSG_VENDOR_TRY_TRAIN,                                 297 },
    { SMSG_VENDOR_TRAIN_RESULTS,                             298 },
    { SMSG_DEBUG_DRAW_PRIM,                                  299 },
    { CMSG_TRY_CRAFT_ITEM,                                   300 },
    { SMSG_CRAFTING_RESULT,                                  301 },
    { SMSG_VENDOR_LEVEL_UP,                                  302 },
    { CMSG_TRY_IDENTIFY_WITH_CAST,                           303 },
    { CMSG_TRY_IDENTIFY_ALL_WITH_CAST,                       304 },
    { CMSG_TRY_REMOVE_GEMS,                                  305 },
    { SMSG_CALLOUT_EVENT,                                    306 },
    { SMSG_HIGHEST_UNLOCKED_DIFFICULTY_LEVEL,                307 },
    { SMSG_CURRENT_DIFFICULTY_AND_HANDICAP_LEVEL,            308 },
    { CMSG_FOLLOWER_RETRAIN_REQUEST,                         309 },
    { SMSG_GAME_TESTING_DONE,                                310 },
    { SMSG_GAME_TESTING_START_SAMPLING,                      311 },
    { SMSG_GAME_TESTING_STOP_SAMPLING,                       312 },
    { CMSG_SHOWN_TUTORIAL,                                   313 },
    { CMSG_REQUEST_BUFF_CANCEL,                              314 },
    { CMSG_REQUEST_EVENT_SKIP,                               315 },
    { SMSG_HANDLE_EVENT_SKIP,                                316 },
    { CMSG_REQUEST_PROMOTE_GAME_TO_PUBLIC,                   317 },
    { SMSG_GAME_PROMOTED_TO_PUBLIC,                          318 },
    { CMSG_SEND_PLAYER_PREFS,                                319 },
    { CMSG_PING,                                             320 },
    { SMSG_PONG,                                             321 },
    { SMSG_SYSTEM_SHUTDOWN,                                  322 },
    { SMSG_SYSTEM_BROADCAST,                                 323 },
    { CMSG_LOAD_COMPLETE,                                    324 },
    { CMSG_NPC_INTERACT_CANCEL,                              325 },
    { CMSG_NPC_INTERACT_TALK_DIALOG,                         326 },
    { CMSG_NPC_INTERACT_PET_DISMISS,                         327 },
    { CMSG_NPC_INTERACT_CRAFT,                               328 },
    { CMSG_NPC_INTERACT_HIRE,                                329 },
    { CMSG_NPC_INTERACT_INVENTORY,                           330 },
    { CMSG_GAME_END_REQUEST,                                 331 },
    { SMSG_START_END_COUNTDOWN,                              332 },
    { CMSG_START_VOTE_KICK,                                  333 },
    { CMSG_TRY_VOTE_KICK,                                    334 },
    { SMSG_CAN_VOTE_KICK,                                    335 },
    { SMSG_VOTE_KICK_VOTE,                                   336 },
    { CMSG_VOTE_KICK_VOTE,                                   337 },
    { SMSG_VOTE_KICK_FAILED,                                 338 },
    { SMSG_VOTE_KICK_PASSED,                                 339 },
    { CMSG_REQUEST_PAUSE_STATE_CHANGE,                       340 },
    { SMSG_PAUSE_STATE_CHANGE,                               341 },
    { SMSG_SOFT_PAUSE_STATE_CHANGE,                            0 },
    { SMSG_HARDCORE_MODE_UNLOCKED,                           342 },
    { CMSG_TRIED_SALVAGE,                                    343 },
    { CMSG_POLL_MAIL,                                        344 },
    { CMSG_FETCH_MAIL,                                       345 },
    { CMSG_SEND_MAIL,                                        346 },
    { CMSG_MARK_READ_MAIL,                                   347 },
    { CMSG_RETRIEVE_MAIL_ATTACHMENTS,                        348 },
    { CMSG_DELETE_MAIL,                                      349 },
    { SMSG_MAIL_CONTENTS,                                    350 },
    { SMSG_MAIL_SENT,                                        351 },
    { SMSG_MAIL_READ,                                        352 },
    { SMSG_MAIL_RETRIEVED,                                   353 },
    { SMSG_MAIL_DELETED,                                     354 },
    { SMSG_PVP_KILL,                                         355 },
    { SMSG_PVP_ASSIST,                                       356 },
    { CMSG_TRY_REDEEM_PVP_TOKENS,                            357 },
    { SMSG_PVP_TOKEN_REDEMPTION_RESULTS,                     358 },
    { SMSG_SET_CAMERA_OBSERVER,                              359 },
    { SMSG_SET_CAMERA_ORBIT,                                 360 },
    { SMSG_SET_CAMERA_DEFAULTS,                              361 },
    { SMSG_CONSOLE_SET_CAMERA_DEFAULTS,                        0 },
    { SMSG_CONSOLE_VALIDATE_HERO,                              0 },
    { SMSG_CONSOLE_VALIDATE_ACCOUNT,                           0 },
    { SMSG_CONSOLE_SAVE,                                       0 },
    { SMSG_CONSOLE_SYNC_HERO_SAVED_QUESTS,                     0 },
    { SMSG_CONSOLE_SYNC_HERO_QUEST_HISTORY,                    0 },
    { SMSG_CONSOLE_SYNC_HERO_QUEST_REWARD_HISTORY,             0 },
    { SMSG_CONSOLE_SYNC_HERO_SAVED_CONVERSATIONS,              0 },
    { SMSG_CONSOLE_SYNC_HERO_ACTIVE_HIRELING,                  0 },
    { SMSG_CONSOLE_SYNC_HERO_TIME_PLAYED,                      0 },
    { SMSG_CONSOLE_SYNC_ACCOUNT_ACHIEVEMENT_CRITERIA_UPDATE,   0 },
    { SMSG_CONSOLE_COUNTER_PLAYER_MONSTERS_KILLED,             0 },
    { SMSG_CONSOLE_COUNTER_PLAYER_ELITES_KILLED,               0 },
    { SMSG_CONSOLE_COUNTER_PLAYER_GOLD_COLLECTED,              0 },
    { SMSG_CONSOLE_GAME_ENDED,                                 0 },
    { CMSG_SAVE_BANNER,                                      364 },
    { SMSG_SAVE_BANNER_RESPONSE,                             365 },
    { SMSG_ACHIEVEMENTS_UNAVAILABLE,                         366 },
    { SMSG_ACHIEVEMENT_AWARDED,                                0 },
    { SMSG_MULTIPLAYER_BUFF_ON,                              367 },
    { SMSG_MULTIPLAYER_BUFF_OFF,                             368 },
    { SMSG_DUEL_RESULT,                                      369 },
    { SMSG_SHRINE_GLOBE_TEXT_DISPLAY,                        370 },
    { CMSG_ITEM_JUNK_FLAG_CHANGED,                             0 },
    { CMSG_PARAGON_POINT_SPEND,                                0 },
    { CMSG_PARAGON_POINTS_RESET,                               0 },
    { CMSG_REQUEST_PROMOTE_TO_PARTY_GUIDE,                     0 },
    { SMSG_PLAYER_CLEAR_CLIENT_WALK_POWER,                   371 },
    { CMSG_WARP_DEAD_PLAYER,                                   0 },
    { CMSG_REQUEST_SOFT_PAUSE_STATE_CHANGE,                    0 },
    { XMSG_RELOAD_MAIL_MESSAGE,                              372 },
    { XMSG_SAVE_BANNER_COMPLETE,                             373 },
};

static_assert(sizeof(s_MessageTypeMappings) / sizeof(s_MessageTypeMappings[0]) == MSG_NUM_MESSAGES);

constexpr Attrib s_ConsoleOnlyAttributes[] = {
    ATTRIBUTE_DAMAGE_WEAPON_BONUS_FLAT,
    ATTRIBUTE_ITEM_LEGENDARY_ITEM_LEVEL_OVERRIDE,
    ATTRIBUTE_GIZMO_OPERATION_RADIUS_OVERRIDE,
    ATTRIBUTE_CORPSE_RESURRECTION_ALLOWED_GAMETIME,
    ATTRIBUTE_SPECIAL_INVENTORY_INDEX,
    ATTRIBUTE_PVP_PLAYER_REVEALED_ON_MAP,
    ATTRIBUTE_TARGETED_LEGENDARY_CHANCE,
    ATTRIBUTE_IN_COMBAT_WITH_PLAYER,
    ATTRIBUTE_ACTOR_FORWARDS_BUFFS,
    ATTRIBUTE_ITEM_FLAGGED_AS_JUNK,
    ATTRIBUTE_PARAGON_BONUS,
    ATTRIBUTE_PARAGON_BONUS_POINTS_AVAILABLE,
    ATTRIBUTE_TARGETED_RARE_CHANCE,
};

constexpr size_t kNumConsoleOnlyAttributes = sizeof(s_ConsoleOnlyAttributes) / sizeof(s_ConsoleOnlyAttributes[0]);

struct GbidMapping
{
    GBID gbidConsole;
    GBID gbidPC;
};

GbidMapping s_GbidMappings[] = {
    // other
    { 0x804E2322, 0x622256D4 }, // HealthPotionConsole -> HealthPotionMinor
    // unique items (a _1xx suffix was added to legendaries on consoles, and gbids are name hashes)
    { 0xBBD98ACE, 0x18908B6E },
    { 0xBBEBA34F, 0x18908B6F },
    { 0xBBFDBBD0, 0x18908B70 },
    { 0xBC0FD451, 0x18908B71 },
    { 0xBC21ECD2, 0x18908B72 },
    { 0xBC340553, 0x18908B73 },
    { 0xBC461DD4, 0x18908B74 },
    { 0xBC583655, 0x18908B75 },
    { 0xBC6A4ED6, 0x18908B76 },
    { 0xBE1C9AEE, 0x18908B8E },
    { 0xBE2EB36F, 0x18908B8F },
    { 0xBE40CBF0, 0x18908B90 },
    { 0xBE52E471, 0x18908B91 },
    { 0xBE64FCF2, 0x18908B92 },
    { 0xBE771573, 0x18908B93 },
    { 0xBE892DF4, 0x18908B94 },
    { 0x0809223C, 0xF2F19BDC },
    { 0x082D533E, 0xF2F19BDE },
    { 0x083F6BBF, 0xF2F19BDF },
    { 0x08518440, 0xF2F19BE0 },
    { 0x08639CC1, 0xF2F19BE1 },
    { 0x0875B542, 0xF2F19BE2 },
    { 0x0A827BDF, 0xF2F19BFF },
    { 0x0C13B35D, 0xF546C47D },
    { 0x0C37E45F, 0xF546C47F },
    { 0x0CA47765, 0xF546C485 },
    { 0x0E56C37D, 0xF546C49D },
    { 0x0E68DBFE, 0xF546C49E },
    { 0x1985A6A4, 0xB24C2C44 },
    { 0x1997BF25, 0xB24C2C45 },
    { 0x19A9D7A6, 0xB24C2C46 },
    { 0x19BBF027, 0xB24C2C47 },
    { 0x19CE08A8, 0xB24C2C48 },
    { 0x19E02129, 0xB24C2C49 },
    { 0x19F239AA, 0xB24C2C4A },
    { 0x1A04522B, 0xB24C2C4B },
    { 0x1A166AAC, 0xB24C2C4C },
    { 0x9AF9984D, 0xD89FB16D },
    { 0x9B0BB0CE, 0xD89FB16E },
    { 0x9B1DC94F, 0xD89FB16F },
    { 0x9B2FE1D0, 0xD89FB170 },
    { 0x9B41FA51, 0xD89FB171 },
    { 0x9B5412D2, 0xD89FB172 },
    { 0x9B662B53, 0xD89FB173 },
    { 0x9B7843D4, 0xD89FB174 },
    { 0x9B8A5C55, 0xD89FB175 },
    { 0x9D3CA86D, 0xD89FB18D },
    { 0x9D60D96F, 0xD89FB18F },
    { 0x9D72F1F0, 0xD89FB190 },
    { 0x9D850A71, 0xD89FB191 },
    { 0x9D9722F2, 0xD89FB192 },
    { 0xE815CCED, 0x0F9A960D },
    { 0xE85E2EF1, 0x0F9A9611 },
    { 0xE8825FF3, 0x0F9A9613 },
    { 0xE8947874, 0x0F9A9614 },
    { 0xE8A690F5, 0x0F9A9615 },
    { 0xEA58DD0D, 0x0F9A962D },
    { 0xEA6AF58E, 0x0F9A962E },
    { 0xEA7D0E0F, 0x0F9A962F },
    { 0xEA8F2690, 0x0F9A9630 },
    { 0xEAA13F11, 0x0F9A9631 },
    { 0xEAB35792, 0x0F9A9632 },
    { 0xEAD78894, 0x0F9A9634 },
    { 0xEAE9A115, 0x0F9A9635 },
    { 0xEAFBB996, 0x0F9A9636 },
    { 0x1020F10E, 0x1E9ED1AE },
    { 0x10695312, 0x1E9ED1B2 },
    { 0x108D8414, 0x1E9ED1B4 },
    { 0x109F9C95, 0x1E9ED1B5 },
    { 0x10B1B516, 0x1E9ED1B6 },
    { 0x1264012E, 0x1E9ED1CE },
    { 0x12BE7BB3, 0x1E9ED1D3 },
    { 0x17B66715, 0x38F45C35 },
    { 0x17C87F96, 0x38F45C36 },
    { 0x17DA9817, 0x38F45C37 },
    { 0x17ECB098, 0x38F45C38 },
    { 0x17FEC919, 0x38F45C39 },
    { 0x1810E19A, 0x38F45C3A },
    { 0x1822FA1B, 0x38F45C3B },
    { 0x18472B1D, 0x38F45C3D },
    { 0x19F97735, 0x38F45C55 },
    { 0x1A0B8FB6, 0x38F45C56 },
    { 0xB5E95F0F, 0x1786672F },
    { 0xB5FB7790, 0x17866730 },
    { 0xB60D9011, 0x17866731 },
    { 0xB61FA892, 0x17866732 },
    { 0xB643D994, 0x17866734 },
    { 0xB6680A96, 0x17866736 },
    { 0xB67A2317, 0x17866737 },
    { 0xB83E87B0, 0x17866750 },
    { 0x1D257087, 0x4B447CA7 },
    { 0x1BA0141D, 0x0A40C53D },
    { 0x1BB22C9E, 0x0A40C53E },
    { 0x1BFA8EA2, 0x0A40C542 },
    { 0x1DE3243D, 0x0A40C55D },
    { 0x1E07553F, 0x0A40C55F },
    { 0x1E196DC0, 0x0A40C560 },
    { 0x1E2B8641, 0x0A40C561 },
    { 0x1E3D9EC2, 0x0A40C562 },
    { 0x1E4FB743, 0x0A40C563 },
    { 0x1E73E845, 0x0A40C565 },
    { 0x1E8600C6, 0x0A40C566 },
    { 0x2092C763, 0x0A40C583 },
    { 0x20A4DFE4, 0x0A40C584 },
    { 0x20B6F865, 0x0A40C585 },
    { 0xB3EE70D0, 0x926EC070 },
    { 0xB4008951, 0x926EC071 },
    { 0xB436D2D4, 0x926EC074 },
    { 0xB448EB55, 0x926EC075 },
    { 0x6DF93089, 0xEC848BA9 },
    { 0x6E0B490A, 0xEC848BAA },
    { 0x6E1D618B, 0xEC848BAB },
    { 0x6E2F7A0C, 0xEC848BAC },
    { 0x6E41928D, 0xEC848BAD },
    { 0x6E65C38F, 0xEC848BAF },
    { 0x6E77DC10, 0xEC848BB0 },
    { 0x6E89F491, 0xEC848BB1 },
    { 0x84205691, 0x4239EDB1 },
    { 0x84326F12, 0x4239EDB2 },
    { 0x8468B895, 0x4239EDB5 },
    { 0x847AD116, 0x4239EDB6 },
    { 0x848CE997, 0x4239EDB7 },
    { 0x86514E30, 0x4239EDD0 },
    { 0x90A80BBE, 0xCDE4145E },
    { 0x90BA243F, 0xCDE4145F },
    { 0x90CC3CC0, 0xCDE41460 },
    { 0x90DE5541, 0xCDE41461 },
    { 0x90F06DC2, 0xCDE41462 },
    { 0x91028643, 0xCDE41463 },
    { 0x91149EC4, 0xCDE41464 },
    { 0x92C6EADC, 0xCDE4147C },
    { 0x92D9035D, 0xCDE4147D },
    { 0x92EB1BDE, 0xCDE4147E },
    { 0x92FD345F, 0xCDE4147F },
    { 0x93216561, 0xCDE41481 },
    { 0x6B6A4E56, 0x347CCAF6 },
    { 0x6B7C66D7, 0x347CCAF7 },
    { 0x6B8E7F58, 0x347CCAF8 },
    { 0x6BD6E15C, 0x347CCAFC },
    { 0x6BE8F9DD, 0x347CCAFD },
    { 0x6BFB125E, 0x347CCAFE },
    { 0x6DBF76F7, 0x347CCB17 },
    { 0x6DF5C07A, 0x347CCB1A },
    { 0x6E07D8FB, 0x347CCB1B },
    { 0x6E2C09FD, 0x347CCB1D },
    { 0x22EAA361, 0x1EBE5281 },
    { 0x22FCBBE2, 0x1EBE5282 },
    { 0x230ED463, 0x1EBE5283 },
    { 0x2320ECE4, 0x1EBE5284 },
    { 0x23330565, 0x1EBE5285 },
    { 0x23451DE6, 0x1EBE5286 },
    { 0x23573667, 0x1EBE5287 },
    { 0x2551E483, 0x1EBE52A3 },
    { 0x259A4687, 0x1EBE52A7 },
    { 0x9146B18C, 0x61AC032C },
    { 0x9158CA0D, 0x61AC032D },
    { 0x916AE28E, 0x61AC032E },
    { 0x917CFB0F, 0x61AC032F },
    { 0x91A12C11, 0x61AC0331 },
    { 0x91B34492, 0x61AC0332 },
    { 0x91C55D13, 0x61AC0333 },
    { 0x91D77594, 0x61AC0334 },
    { 0x9389C1AC, 0x61AC034C },
    { 0x939BDA2D, 0x61AC034D },
    { 0x93ADF2AE, 0x61AC034E },
    { 0x93D223B0, 0x61AC0350 },
    { 0x93E43C31, 0x61AC0351 },
    { 0x93F654B2, 0x61AC0352 },
    { 0x70136C94, 0x2A847A34 },
    { 0x70258515, 0x2A847A35 },
    { 0x70379D96, 0x2A847A36 },
    { 0x705BCE98, 0x2A847A38 },
    { 0x707FFF9A, 0x2A847A3A },
    { 0x7092181B, 0x2A847A3B },
    { 0x70A4309C, 0x2A847A3C },
    { 0x72567CB4, 0x2A847A54 },
    { 0x72689535, 0x2A847A55 },
    { 0x741DFDB5, 0x2CD9A2D5 },
    { 0x74301636, 0x2CD9A2D6 },
    { 0x74422EB7, 0x2CD9A2D7 },
    { 0x7478783A, 0x2CD9A2DA },
    { 0x74AEC1BD, 0x2CD9A2DD },
    { 0x76610DD5, 0x2CD9A2F5 },
    { 0x76853ED7, 0x2CD9A2F7 },
    { 0x60E153D0, 0x6B682370 },
    { 0x6129B5D4, 0x6B682374 },
    { 0x613BCE55, 0x6B682375 },
    { 0x632463F0, 0x6B682390 },
    { 0x63367C71, 0x6B682391 },
    { 0x634894F2, 0x6B682392 },
    { 0x637EDE75, 0x6B682395 },
    { 0x64EBE4F1, 0x6DBD4C11 },
    { 0x65222E74, 0x6DBD4C14 },
    { 0x65465F76, 0x6DBD4C16 },
    { 0x672EF511, 0x6DBD4C31 },
    { 0x67532613, 0x6DBD4C33 },
    { 0x9C9C713C, 0xFC356ADC },
    { 0x9CAE89BD, 0xFC356ADD },
    { 0x9CC0A23E, 0xFC356ADE },
    { 0x9D090442, 0xFC356AE2 },
    { 0x9D1B1CC3, 0xFC356AE3 },
    { 0x9ECD68DB, 0xFC356AFB },
    { 0x9EDF815C, 0xFC356AFC },
    { 0x8F26D83C, 0x93A451DC },
    { 0x53C093A9, 0x0CD75EC9 },
    { 0x53E4C4AB, 0x0CD75ECB },
    { 0x53F6DD2C, 0x0CD75ECC },
    { 0x5408F5AD, 0x0CD75ECD },
    { 0x5615BC4A, 0x0CD75EEA },
    { 0x5627D4CB, 0x0CD75EEB },
    { 0x0C9C816C, 0x35D4E30C },
    { 0x0CAE99ED, 0x35D4E30D },
    { 0x0CE4E370, 0x35D4E310 },
    { 0x0CF6FBF1, 0x35D4E311 },
    { 0x0D091472, 0x35D4E312 },
    { 0x0D1B2CF3, 0x35D4E313 },
    { 0x0D2D4574, 0x35D4E314 },
    { 0x0EDF918C, 0x35D4E32C },
    { 0x0F03C28E, 0x35D4E32E },
    { 0x0F15DB0F, 0x35D4E32F },
    { 0x0F27F390, 0x35D4E330 },
    { 0xB99AAB16, 0x3D7CC7B6 },
    { 0xB9ACC397, 0x3D7CC7B7 },
    { 0xB9BEDC18, 0x3D7CC7B8 },
    { 0xB9D0F499, 0x3D7CC7B9 },
    { 0xEC1342E2, 0xEBA95982 },
    { 0xEC255B63, 0xEBA95983 },
    { 0xEC3773E4, 0xEBA95984 },
    { 0xEC498C65, 0xEBA95985 },
    { 0xEC5BA4E6, 0xEBA95986 },
    { 0xEC6DBD67, 0xEBA95987 },
    { 0xEC7FD5E8, 0xEBA95988 },
    { 0xDD65A896, 0xD4650536 },
    { 0xDD77C117, 0xD4650537 },
    { 0xDD89D998, 0xD4650538 },
    { 0xDD9BF219, 0xD4650539 },
    { 0xDDAE0A9A, 0xD465053A },
    { 0xDDC0231B, 0xD465053B },
    { 0xDDD23B9C, 0xD465053C },
    { 0xDDE4541D, 0xD465053D },
    { 0xDDF66C9E, 0xD465053E },
    { 0xDFA8B8B6, 0xD4650556 },
    { 0xDFBAD137, 0xD4650557 },
    { 0xDFCCE9B8, 0xD4650558 },
    { 0xDFDF0239, 0xD4650559 },
    { 0xDFF11ABA, 0xD465055A },
    { 0xE003333B, 0xD465055B },
    { 0xE027643D, 0xD465055D },
    { 0xE0397CBE, 0xD465055E },
    { 0xE04B953F, 0xD465055F },
    { 0xE1FDE157, 0xD4650577 },
    { 0xE20FF9D8, 0xD4650578 },
    { 0xE2221259, 0xD4650579 },
    { 0xE2342ADA, 0xD465057A },
    { 0x3D2613A0, 0xFC257B40 },
    { 0x3D4A44A2, 0xFC257B42 },
    { 0x3D808E25, 0xFC257B45 },
    { 0x3D92A6A6, 0xFC257B46 },
    { 0x3DA4BF27, 0xFC257B47 },
    { 0x3F6923C0, 0xFC257B60 },
    { 0x3F7B3C41, 0xFC257B61 },
    { 0xF130492C, 0x0E3ACACC },
    { 0xF14261AD, 0x0E3ACACD },
    { 0xF1547A2E, 0x0E3ACACE },
    { 0xF18AC3B1, 0x0E3ACAD1 },
    { 0xF19CDC32, 0x0E3ACAD2 },
    { 0xF1AEF4B3, 0x0E3ACAD3 },
    { 0xF1C10D34, 0x0E3ACAD4 },
    { 0xF3F204D3, 0x0E3ACAF3 },
    { 0x677480E1, 0x89F57001 },
    { 0x67869962, 0x89F57002 },
    { 0x6798B1E3, 0x89F57003 },
    { 0x67AACA64, 0x89F57004 },
    { 0xE226DC6A, 0x421D6F0A },
    { 0xE238F4EB, 0x421D6F0B },
    { 0xE24B0D6C, 0x421D6F0C },
    { 0xE25D25ED, 0x421D6F0D },
    { 0xE26F3E6E, 0x421D6F0E },
    { 0xE28156EF, 0x421D6F0F },
    { 0xE2936F70, 0x421D6F10 },
    { 0xE2A587F1, 0x421D6F11 },
    { 0xE2B7A072, 0x421D6F12 },
    { 0xB42EAAFA, 0x11E4759A },
    { 0xB440C37B, 0x11E4759B },
    { 0xB452DBFC, 0x11E4759C },
    { 0xB489257F, 0x11E4759F },
    { 0xB49B3E00, 0x11E475A0 },
    { 0xB4AD5681, 0x11E475A1 },
    { 0xB4BF6F02, 0x11E475A2 },
    { 0x12D640ED, 0x24410A0D },
    { 0x12E8596E, 0x24410A0E },
    { 0x12FA71EF, 0x24410A0F },
    { 0x130C8A70, 0x24410A10 },
    { 0x1342D3F3, 0x24410A13 },
    { 0x1519510D, 0x24410A2D },
    { 0x152B698E, 0x24410A2E },
    { 0x153D820F, 0x24410A2F },
    { 0x1561B311, 0x24410A31 },
    { 0x1597FC94, 0x24410A34 },
    { 0x15AA1515, 0x24410A35 },
    { 0x15BC2D96, 0x24410A36 },
    { 0x1780922F, 0x24410A4F },
    { 0x16E0D20E, 0x269632AE },
    { 0x16F2EA8F, 0x269632AF },
    { 0x17050310, 0x269632B0 },
    { 0x17171B91, 0x269632B1 },
    { 0x174D6514, 0x269632B4 },
    { 0x175F7D95, 0x269632B5 },
    { 0x1923E22E, 0x269632CE },
    { 0x1935FAAF, 0x269632CF },
    { 0x19481330, 0x269632D0 },
    { 0x196C4432, 0x269632D2 },
    { 0x8B157728, 0x10205AC8 },
    { 0x8B278FA9, 0x10205AC9 },
    { 0x8B5DD92C, 0x10205ACC },
    { 0x8B6FF1AD, 0x10205ACD },
    { 0x8B820A2E, 0x10205ACE },
    { 0x8B9422AF, 0x10205ACF },
    { 0x49DD96F1, 0x09A5FE11 },
    { 0x49EFAF72, 0x09A5FE12 },
    { 0x4A25F8F5, 0x09A5FE15 },
    { 0x4A5C4278, 0x09A5FE18 },
    { 0x4C0E8E90, 0x09A5FE30 },
    { 0x4C32BF92, 0x09A5FE32 },
    { 0x4C44D813, 0x09A5FE33 },
    { 0x4C9F5298, 0x09A5FE38 },
    { 0xE24DDF54, 0x29F38CF4 },
    { 0xE2721056, 0x29F38CF6 },
    { 0xE28428D7, 0x29F38CF7 },
    { 0xA9628546, 0x468F09E6 },
    { 0xA9749DC7, 0x468F09E7 },
    { 0xA986B648, 0x468F09E8 },
    { 0xA998CEC9, 0x468F09E9 },
    { 0xA9BCFFCB, 0x468F09EB },
    { 0xABB7ADE7, 0x468F0A07 },
    { 0xABC9C668, 0x468F0A08 },
};

constexpr size_t kNumGbidMappings = sizeof(s_GbidMappings) / sizeof(s_GbidMappings[0]);

}

GameMessageType GameMessageTranslator::ConvertMessageTypeConsoleToPC(GameMessageType eConsoleType)
{
    return static_cast<GameMessageType>(s_MessageTypeMappings[eConsoleType - 1].PCType);
}

GameMessageType GameMessageTranslator::ConvertMessageTypePCToConsole(GameMessageType ePCType)
{
    // TODO: make this not horribly inefficient?
    for (int i = 0; i < MSG_NUM_MESSAGES; ++i)
    {
        if (s_MessageTypeMappings[i].PCType == ePCType)
            return static_cast<GameMessageType>(i + 1);
    }

    return MSG_INVALID;
}

Attrib GameMessageTranslator::ConvertAttribConsoleToPC(Attrib eConsoleAttrib)
{
    int offset = 0;

    for (int i = 0; i < kNumConsoleOnlyAttributes; ++i)
    {
        if (eConsoleAttrib == s_ConsoleOnlyAttributes[i])
            return ATTRIBUTE_AXEBADDATA;
        else if (eConsoleAttrib > s_ConsoleOnlyAttributes[i])
            offset--;
    }
    
    return static_cast<Attrib>(eConsoleAttrib + offset);
}

Attrib GameMessageTranslator::ConvertAttribPCToConsole(Attrib ePCAttrib)
{
    int nAttrib = ePCAttrib;

    for (int i = 0; i < kNumConsoleOnlyAttributes; ++i)
    {
        if (nAttrib >= s_ConsoleOnlyAttributes[i])
            nAttrib++;
    }

    return static_cast<Attrib>(nAttrib);
}

GBID GameMessageTranslator::ConvertGbidConsoleToPC(GBID gbidConsole)
{
    for (int i = 0; i < kNumGbidMappings; ++i)
    {
        if (gbidConsole == s_GbidMappings[i].gbidConsole)
            return s_GbidMappings[i].gbidPC;
    }

    return gbidConsole;
}

GBID GameMessageTranslator::ConvertGbidPCToConsole(GBID gbidPC)
{
    for (int i = 0; i < kNumGbidMappings; ++i)
    {
        if (gbidPC == s_GbidMappings[i].gbidPC)
            return s_GbidMappings[i].gbidConsole;
    }

    return gbidPC;
}

void GameMessageTranslator::TranslateMessageConsoleToPC(void* pMessage)
{
    RequiredMessageHeader* ptHeader = static_cast<RequiredMessageHeader*>(pMessage);
    GameMessageType eConsoleType = ptHeader->eType;
    GameMessageType ePCType = ConvertMessageTypeConsoleToPC(eConsoleType);

    ptHeader->eType = ePCType;

    switch (eConsoleType)
    {
        case SMSG_CONNECTION_ESTABLISHED:
        {
            ConnectionEstablishedMessage* connectionEstablishedMessage = static_cast<ConnectionEstablishedMessage*>(pMessage);
            connectionEstablishedMessage->dwSnoCoreDataHash = dwSNOCoreDataHashPC;
            break;
        }

        case SMSG_NEW_PLAYER:
        {
            NewPlayerMessage* newPlayerMessage = static_cast<NewPlayerMessage*>(pMessage);
            HotbarButtonData& ptPotionButton = newPlayerMessage->tHeroStateData.tSavedData.tPotionBtn;
            ptPotionButton.m_gbidItem = ConvertGbidConsoleToPC(ptPotionButton.m_gbidItem);
            break;
        }

        case SMSG_REVEAL_TEAM:
        {
            RevealTeamMessage* revealTeamMessage = static_cast<RevealTeamMessage*>(pMessage);
            if (revealTeamMessage->eTeamColoring == TEAM_COLOR_NEUTRAL)
                revealTeamMessage->eTeamColoring = TEAM_COLOR_NONE;
            break;
        }

        case SMSG_HERO_STATE:
        {
            HeroStateMessage* heroStateMessage = static_cast<HeroStateMessage*>(pMessage);
            HotbarButtonData& ptPotionButton = heroStateMessage->tStateData.tSavedData.tPotionBtn;
            ptPotionButton.m_gbidItem = ConvertGbidConsoleToPC(ptPotionButton.m_gbidItem);
            break;
        }

        case SMSG_HERO_STATE_SAVEDDATA:
        {
            PlayerSavedDataMessage* playerSavedDataMessage = static_cast<PlayerSavedDataMessage*>(pMessage);
            HotbarButtonData& ptPotionButton = playerSavedDataMessage->tSavedData.tPotionBtn;
            ptPotionButton.m_gbidItem = ConvertGbidConsoleToPC(ptPotionButton.m_gbidItem);
            break;
        }

        case SMSG_ACD_ENTER_KNOWN:
        {
            ACDEnterKnownMessage* acdEnterKnownMessage = static_cast<ACDEnterKnownMessage*>(pMessage);
            if (acdEnterKnownMessage->hGB.eType == GB_ITEMS)
                acdEnterKnownMessage->hGB.gbid = ConvertGbidConsoleToPC(acdEnterKnownMessage->hGB.gbid);
            break;
        }

        case SMSG_ATTRIBUTE_SET_VALUE:
        {
            AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pMessage);
            Attrib eConsoleAttrib = attributeSetValueMessage->tKeyVal.eKeyAttrib;
            attributeSetValueMessage->tKeyVal.eKeyAttrib = ConvertAttribConsoleToPC(eConsoleAttrib);
            break;
        }

        case SMSG_ATTRIBUTES_SET_VALUES:
        {
            AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pMessage);
            int nCount = attributesSetValuesMessage->nAttributeCount;
            for (int i = 0; i < nCount; ++i)
            {
                Attrib eConsoleAttrib = attributesSetValuesMessage->atKeyVals[i].eKeyAttrib;
                attributesSetValuesMessage->atKeyVals[i].eKeyAttrib = ConvertAttribConsoleToPC(eConsoleAttrib);
            }
            break;
        }

        case CMSG_PLAYER_CHANGE_POTION_BUTTON:
        {
            GBIDDataMessage* gbidDataMessage = static_cast<GBIDDataMessage*>(pMessage);
            gbidDataMessage->gbidData = ConvertGbidConsoleToPC(gbidDataMessage->gbidData);
            break;
        }

        default:
            break;
    }
}

void GameMessageTranslator::TranslateMessagePCToConsole(void* pMessage)
{
    RequiredMessageHeader* ptHeader = static_cast<RequiredMessageHeader*>(pMessage);
    GameMessageType ePCType = ptHeader->eType;
    GameMessageType eConsoleType = ConvertMessageTypePCToConsole(ePCType);

    ptHeader->eType = eConsoleType;

    // FIXME?: AXEBADDATA attribs data loss, eTeamColoring data loss, SNO hash not being reverted

    switch (eConsoleType)
    {
        case SMSG_NEW_PLAYER:
        {
            NewPlayerMessage* newPlayerMessage = static_cast<NewPlayerMessage*>(pMessage);
            GBID gbidPotion = newPlayerMessage->tHeroStateData.tSavedData.tPotionBtn.m_gbidItem;
            newPlayerMessage->tHeroStateData.tSavedData.tPotionBtn.m_gbidItem = ConvertGbidPCToConsole(gbidPotion);
            break;
        }

        case SMSG_HERO_STATE:
        {
            HeroStateMessage* heroStateMessage = static_cast<HeroStateMessage*>(pMessage);
            HotbarButtonData& ptPotionButton = heroStateMessage->tStateData.tSavedData.tPotionBtn;
            ptPotionButton.m_gbidItem = ConvertGbidPCToConsole(ptPotionButton.m_gbidItem);
            break;
        }

        case SMSG_HERO_STATE_SAVEDDATA:
        {
            PlayerSavedDataMessage* playerSavedDataMessage = static_cast<PlayerSavedDataMessage*>(pMessage);
            HotbarButtonData& ptPotionButton = playerSavedDataMessage->tSavedData.tPotionBtn;
            ptPotionButton.m_gbidItem = ConvertGbidPCToConsole(ptPotionButton.m_gbidItem);
            break;
        }

        case SMSG_ACD_ENTER_KNOWN:
        {
            ACDEnterKnownMessage* acdEnterKnownMessage = static_cast<ACDEnterKnownMessage*>(pMessage);
            if (acdEnterKnownMessage->hGB.eType == GB_ITEMS)
                acdEnterKnownMessage->hGB.gbid = ConvertGbidPCToConsole(acdEnterKnownMessage->hGB.gbid);
            break;
        }

        case SMSG_ATTRIBUTE_SET_VALUE:
        {
            AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pMessage);
            Attrib ePCAttrib = attributeSetValueMessage->tKeyVal.eKeyAttrib;
            attributeSetValueMessage->tKeyVal.eKeyAttrib = ConvertAttribPCToConsole(ePCAttrib);
            break;
        }

        case SMSG_ATTRIBUTES_SET_VALUES:
        {
            AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pMessage);
            int nCount = attributesSetValuesMessage->nAttributeCount;
            for (int i = 0; i < nCount; ++i)
            {
                Attrib ePCAttrib = attributesSetValuesMessage->atKeyVals[i].eKeyAttrib;
                attributesSetValuesMessage->atKeyVals[i].eKeyAttrib = ConvertAttribPCToConsole(ePCAttrib);
            }
            break;
        }

        case CMSG_PLAYER_CHANGE_POTION_BUTTON:
        {
            GBIDDataMessage* gbidDataMessage = static_cast<GBIDDataMessage*>(pMessage);
            gbidDataMessage->gbidData = ConvertGbidPCToConsole(gbidDataMessage->gbidData);
            break;
        }

        default:
            break;
    }
}

bool GameMessageTranslator::IsMessagePCCompatible(void* pMessage)
{
    RequiredMessageHeader* ptHeader = static_cast<RequiredMessageHeader*>(pMessage);
    GameMessageType eConsoleType = ptHeader->eType;

    if (ConvertMessageTypeConsoleToPC(eConsoleType) == MSG_INVALID)
        return false;

    if (eConsoleType == SMSG_ATTRIBUTE_SET_VALUE)
    {
        AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pMessage);
        Attrib eConsoleAttrib = attributeSetValueMessage->tKeyVal.eKeyAttrib;
        
        if (ConvertAttribConsoleToPC(eConsoleAttrib) == ATTRIBUTE_AXEBADDATA)
            return false;
    }

    return true;
}

bool GameMessageTranslator::IsFieldPCCompatible(u32 ptTypeDescriptor, const TypeDescriptorField& field)
{
    // TODO: clean this up
    switch (ptTypeDescriptor)
    {
        case DT_REQUIRED_MESSAGE_HEADER:
            if (field.nDataOffset == 2)
                return false;

        case DT_PRELOAD_SCENE_DATA_MESSAGE:
            if (field.nDataOffset == 16)    // snoLevelAreas
                return false;

            break;

        case DT_PRELOAD_ACD_DATA_MESSAGE:
            if (field.nDataOffset == 16)    // eWeaponClass
                return false;

            if (field.nDataOffset == 20)    // gbidMonsterAffixes
                return false;

            break;

        case DT_NEW_PLAYER_MESSAGE:
            if (field.nDataOffset == 17196) // usGamerTag
                return false;

            if (field.nDataOffset == 17328) // uAcceptedLicenseBitsHero
                return false;

            break;

        case DT_HIRELING_INFO_UPDATE_MESSAGE:
            if (field.nDataOffset >= 24 && field.nDataOffset <= 40) // arnPowerKeyParam
                return false;

            if (field.nDataOffset == 44)    // annItems
                return false;

            break;

        case DT_PLAYER_SET_CAMERA_OBSERVER_MESSAGE:
            if (field.nDataOffset == 12)    // wpToOrbit
                return false;

            break;

        case DT_PLAY_LINE_PARAMS:
            // not sure if it's this one, or one of the three flags before it that need to be skipped
            if (field.nDataOffset == 20)    // bPlayerInitiated
                return false;

            break;

        case DT_QUEST_HISTORY_ENTRY:
            if (field.nDataOffset == 4)     // nStepUID
                return false;

            break;

        case DT_HERO_STATE_DATA:
            if (field.nDataOffset == 17048) // uBossKillFlags
                return false;

            break;

        case DT_TARGET_MESSAGE:
            if (field.nDataOffset == 60)    // dwFlags
                return false;

            break;
    }

    return true;
}

u32 GameMessageTranslator::GetTypeDescriptorOverride(GameMessageType eConsoleType)
{
    switch (eConsoleType)
    {
        case CMSG_ACCEPTED_DEATH:
            return DT_SIMPLE_MESSAGE;

        case CMSG_REQUEST_EVENT_SKIP:
            return DT_SIMPLE_MESSAGE;

        default:
            return 0;
    }
}

int GameMessageTranslator::GetFieldBitCountOverride(u32 ptTypeDescriptor, const TypeDescriptorField& field)
{
    switch (ptTypeDescriptor)
    {
        case DT_CHAT_MESSAGE:
            if (field.nDataOffset == 12)    // nPlayerIndex
                return 4;

            break;

        case DT_CONNECTION_ESTABLISHED_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 3;

            break;

        case DT_DUEL_RESULT_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerVictimIndex
                return 3;

            if (field.nDataOffset == 12)    // nPlayerKillerIndex
                return 4;

            break;

        case DT_ENGAGED_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 3;

            break;

        case DT_GAME_SYNCED_DATA:
            if (field.nDataOffset == 0)     // dwGameSyncedFlags
                return 2;

            break;

        case DT_JOIN_BNET_GAME_MESSAGE:
            if (field.nDataOffset == 64)    // eXLocale
                return 4;

            break;

        case DT_JOIN_LAN_GAME_MESSAGE:
            if (field.nDataOffset == 192)   // eXLocale
                return 4;

            break;

        case DT_KILL_COUNT_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 3;

            break;

        case DT_NEW_PLAYER_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 3;

            break;

        case DT_PET_MESSAGE:
            if (field.nDataOffset == 8)     // nOwner
                return 3;

            break;

        case DT_PLAYER_ACTOR_SET_INITIAL_MESSAGE:
            if (field.nDataOffset == 12)    // nPlayerIndex
                return 3;

            break;

        case DT_PLAYER_ENTER_KNOWN_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 3;
            
            break;

        case DT_PLAYER_INDEX_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 4;

            break;

        case DT_PLAYER_LEVEL:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 3;

            break;

        case DT_PLAYER_QUEST_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 4;

            break;

        case DT_TRICKLE_MESSAGE:
            if (field.nDataOffset == 32)    // nPlayerIndexOwner
                return 4;

            if (field.nDataOffset == 56)    // dwTrickleFlags
                return 6;

            break;

        case DT_TRY_CHAT_MESSAGE:
            if (field.nDataOffset == 12)    // nPlayerTarget
                return 4;

            break;

        case DT_TRY_CONSOLE_COMMAND:
            if (field.nDataOffset == 8)     // nPlayerIndex
                return 4;

            break;

        case DT_UI_ELEMENT_MESSAGE:
            if (field.nDataOffset == 8)     // eElement
                return 4;

            break;

        case DT_VICTIM_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerVictimIndex
                return 3;

            if (field.nDataOffset == 16)    // nKillerPlayerIndex
                return 4;

            break;

        case DT_VOTE_KICK_MESSAGE:
            if (field.nDataOffset == 8)     // nPlayerIndexToKick
                return 4;

            if (field.nDataOffset == 12)    // nPlayerIndexInitiating
                return 4;

            break;
    }

    return -1;  // no override
}
