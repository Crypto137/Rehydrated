#include "recomp/network/game_message_translator.h"

#include <rex/logging.h>

#include "game/sigma/type_descriptor/type_descriptor.h"

namespace
{

struct GameMessageTypeMapping
{
    GameMessageType ConsoleType;
    int PCType;
};

constexpr GameMessageTypeMapping s_MessageTypeMappings[] = {
    { CMSG_TRY_CONSOLE_COMMAND,                                1 },
    { SMSG_TRY_CONSOLE_COMMAND,                                2 },
    { SMSG_QUIT,                                               3 },
    { SMSG_PRELOAD_ADD_SCENE,                                  6 },
    { SMSG_PRELOAD_ADD_ACD,                                    7 },
    { SMSG_PRELOAD_REMOVE_SCENE,                               8 },
    { SMSG_PRELOAD_REMOVE_ACD,                                 9 },
    { SMSG_PLAYER_WARPING,                                    10 },
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
    { SMSG_AFFIX,                                             93 },
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

}

// TODO: Individual message handling:
// (SMSG) PreloadSceneDataMessage: no snoLevelAreas array on PC
// (SMSG) PreloadACDDataMessage: No eWeaponClass and no gbidMonsterAffixes array on PC
// (SMSG) NewPlayerMessage: no usGamerTag and no uAcceptedLicenseBits hero on PC, but has 4 bytes of padding after ann instead
// (SMSG) HirelingInfoUpdateMessage: PC doesn't have a bunch of fields, including arnPowerKeyParam, annItems, nPlayerIndex?
// (SMSG) PlayerSetCameraObserverMessage: no optional WorldPlace wpToOrbit on PC
// (SMSG) SceneSpecification: no snoCombatMusic on X360
// (SMSG) PlayLineParams: extra bool flag on X360 (bPlayerInitiated?)

// (CMSG) JoinConsoleGameMessage: PC has extra data (but ir probably shouldn't send it anyway)
// (CMSG) TargetMessage: no optional dwFlags on PC
// (CMSG) CMSG_ACCEPTED_DEATH: PC -> X360 struct change (SimpleMessage -> IntDataMessage), default to 0?
// (CMSG) CMSG_REQUEST_EVENT_SKIP: PC -> X360 struct change (SimpleMessage -> BoolDataMessage), default to false?
// (CMSG) InventoryDropStackPortionMessage -> StackPortionMessage: same structure, just a name change, probably doesn't need handling

// handle structure changes by temporarily modifying and restoring type descriptors?

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
            return ATTRIBUTE_NONE;
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

void GameMessageTranslator::TranslateMessageConsoleToPC(void* pMessage)
{
    RequiredMessageHeader* ptHeader = static_cast<RequiredMessageHeader*>(pMessage);
    GameMessageType eConsoleType = ptHeader->eType;
    GameMessageType ePCType = ConvertMessageTypeConsoleToPC(eConsoleType);

    ptHeader->eType = ePCType;

    if (eConsoleType == SMSG_ATTRIBUTE_SET_VALUE)
    {
        AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pMessage);
        Attrib eConsoleAttrib = attributeSetValueMessage->tKeyVal.eKeyAttrib;
        attributeSetValueMessage->tKeyVal.eKeyAttrib = ConvertAttribConsoleToPC(eConsoleAttrib);
    }
    else if (eConsoleType == SMSG_ATTRIBUTES_SET_VALUES)
    {
        AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pMessage);
        int nCount = attributesSetValuesMessage->nAttributeCount;
        for (int i = 0; i < nCount; ++i)
        {
            Attrib eConsoleAttrib = attributesSetValuesMessage->atKeyVals[i].eKeyAttrib;
            attributesSetValuesMessage->atKeyVals[i].eKeyAttrib = ConvertAttribConsoleToPC(eConsoleAttrib);
        }
    }
}

void GameMessageTranslator::TranslateMessagePCToConsole(void* pMessage)
{
    RequiredMessageHeader* ptHeader = static_cast<RequiredMessageHeader*>(pMessage);
    GameMessageType ePCType = ptHeader->eType;
    GameMessageType eConsoleType = ConvertMessageTypePCToConsole(ePCType);

    ptHeader->eType = eConsoleType;

    if (eConsoleType == SMSG_ATTRIBUTE_SET_VALUE)
    {
        AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pMessage);
        Attrib ePCAttrib = attributeSetValueMessage->tKeyVal.eKeyAttrib;
        attributeSetValueMessage->tKeyVal.eKeyAttrib = ConvertAttribPCToConsole(ePCAttrib);
    }
    else if (eConsoleType == SMSG_ATTRIBUTES_SET_VALUES)
    {
        AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pMessage);
        int nCount = attributesSetValuesMessage->nAttributeCount;
        for (int i = 0; i < nCount; ++i)
        {
            Attrib ePCAttrib = attributesSetValuesMessage->atKeyVals[i].eKeyAttrib;
            attributesSetValuesMessage->atKeyVals[i].eKeyAttrib = ConvertAttribPCToConsole(ePCAttrib);
        }
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
        
        if (ConvertAttribConsoleToPC(eConsoleAttrib) == ATTRIBUTE_NONE)
            return false;
    }
    else if (eConsoleType == SMSG_ATTRIBUTES_SET_VALUES)
    {
        AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pMessage);
        int nCount = attributesSetValuesMessage->nAttributeCount;
        for (int i = 0; i < nCount; ++i)
        {
            Attrib eConsoleAttrib = attributesSetValuesMessage->atKeyVals[i].eKeyAttrib;
            if (ConvertAttribConsoleToPC(eConsoleAttrib) == ATTRIBUTE_NONE)
            {
                // TBD if this is a problem, we may need to modify AttributesSetValuesMessage to remove PC incompatible attribs
                REXLOG_WARN("Dropping AttributesSetValuesMessage because it has a console-only attribute");
                return false;
            }
        }
    }

    return true;
}

bool GameMessageTranslator::IsFieldPCCompatible(u32 ptTypeDescriptor, TypeDescriptorField& field)
{
    // TODO: clean this up
    switch (ptTypeDescriptor)
    {
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

        case 0x82FABCE0:    // PlayLineParams
            // not sure if it's this one, or one of the three flags before it that need to be skipped
            if (field.nDataOffset == 20)    // bPlayerInitiated
                return false;

            break;
    }

    return true;
}
