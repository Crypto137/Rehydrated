#include "game/network/game_message_type.h"

bool GetGameMessageTypeAndSize(GameMessageType eMessageType, unsigned int& pTypeDescriptor, unsigned int& dwSize, const char*& pszMessageLabel)
{
    switch (eMessageType)
    {
        case CMSG_TRY_CONSOLE_COMMAND:
            pTypeDescriptor = DT_TRY_CONSOLE_COMMAND;
            dwSize = 1056;
            pszMessageLabel = "CMSG_TRY_CONSOLE_COMMAND";
            return true;
        case SMSG_TRY_CONSOLE_COMMAND:
            pTypeDescriptor = DT_TRY_CONSOLE_COMMAND;
            dwSize = 1056;
            pszMessageLabel = "SMSG_TRY_CONSOLE_COMMAND";
            return true;
        case SMSG_QUIT:
            pTypeDescriptor = DT_QUIT_GAME_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_QUIT";
            return true;
        case SMSG_PRELOAD_ADD_SCENE:
            pTypeDescriptor = DT_PRELOAD_SCENE_DATA_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_PRELOAD_ADD_SCENE";
            return true;
        case SMSG_PRELOAD_ADD_ACD:
            pTypeDescriptor = DT_PRELOAD_ACD_DATA_MESSAGE;
            dwSize = 52;
            pszMessageLabel = "SMSG_PRELOAD_ADD_ACD";
            return true;
        case SMSG_PRELOAD_REMOVE_SCENE:
            pTypeDescriptor = DT_PRELOAD_SCENE_DATA_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_PRELOAD_REMOVE_SCENE";
            return true;
        case SMSG_PRELOAD_REMOVE_ACD:
            pTypeDescriptor = DT_PRELOAD_ACD_DATA_MESSAGE;
            dwSize = 52;
            pszMessageLabel = "SMSG_PRELOAD_REMOVE_ACD";
            return true;
        case SMSG_PLAYER_WARPING:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_PLAYER_WARPING";
            return true;
        case CMSG_REQUEST_LAN_GAME_PARAMS:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_REQUEST_LAN_GAME_PARAMS";
            return true;
        case SMSG_NET_LOUNGE_ADVERTIZE_GAME:
            // NOTE: This is not included in the original implementation of GetGameMessageTypeAndSize().
            pTypeDescriptor = DT_ADVERTIZE_PACKET;
            dwSize = 416;
            pszMessageLabel = "SMSG_NET_LOUNGE_ADVERTIZE_GAME";
            return true;
        case CMSG_JOIN_BNET_GAME:
            pTypeDescriptor = DT_JOIN_BNET_GAME_MESSAGE;
            dwSize = 80;
            pszMessageLabel = "CMSG_JOIN_BNET_GAME";
            return true;
        case CMSG_JOIN_LAN_GAME:
            pTypeDescriptor = DT_JOIN_LAN_GAME_MESSAGE;
            dwSize = 196;
            pszMessageLabel = "CMSG_JOIN_LAN_GAME";
            return true;
        case CMSG_JOIN_CONSOLE_GAME:
            pTypeDescriptor = DT_JOIN_CONSOLE_GAME_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "CMSG_JOIN_CONSOLE_GAME";
            return true;
        case CMSG_LEAVE_CONSOLE_GAME:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_LEAVE_CONSOLE_GAME";
            return true;
        case SMSG_VERSIONS:
            pTypeDescriptor = DT_VERSIONS_MESSAGE;
            dwSize = 48;
            pszMessageLabel = "SMSG_VERSIONS";
            return true;
        case SMSG_CRAFTER_OPEN:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTER_OPEN";
            return true;
        case CMSG_VENDOR_CLOSE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_VENDOR_CLOSE";
            return true;
        case SMSG_SHOP_OPEN:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SHOP_OPEN";
            return true;
        case CMSG_SHOP_TRY_BUY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_SHOP_TRY_BUY";
            return true;
        case CMSG_SHOP_TRY_SELL:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_SHOP_TRY_SELL";
            return true;
        case CMSG_SHOP_TRY_SELL_STACK_PORTION:
            pTypeDescriptor = DT_STACK_PORTION_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "CMSG_SHOP_TRY_SELL_STACK_PORTION";
            return true;
        case SMSG_SHOP_BUYBACK_NOTIFY:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_SHOP_BUYBACK_NOTIFY";
            return true;
        case CMSG_START_LOGOUT_TIMER:
            pTypeDescriptor = DT_LOGOUT_CONTEXT_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_START_LOGOUT_TIMER";
            return true;
        case SMSG_LOGOUT_TIMER_STARTED:
            pTypeDescriptor = DT_LOGOUT_TICK_TIME_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_LOGOUT_TIMER_STARTED";
            return true;
        case CMSG_LOGOUT_NOW:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_LOGOUT_NOW";
            return true;
        case CMSG_CANCEL_LOGOUT:
            pTypeDescriptor = DT_LOGOUT_CONTEXT_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_CANCEL_LOGOUT";
            return true;
        case SMSG_PLAYER_DELETE:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAYER_DELETE";
            return true;
        case SMSG_PLAYER_HAS_DIED:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAYER_HAS_DIED";
            return true;
        case CMSG_ACCEPTED_DEATH:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_ACCEPTED_DEATH";
            return true;
        case SMSG_ACCEPTED_DEATH_ACK:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_ACCEPTED_DEATH_ACK";
            return true;
        case SMSG_TUTORIAL:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_TUTORIAL";
            return true;
        case SMSG_TUTORIAL_STATE:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_TUTORIAL_STATE";
            return true;
        case SMSG_STASH_ICON_STATE:
            pTypeDescriptor = DT_STASH_ICON_STATE_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_STASH_ICON_STATE";
            return true;
        case CMSG_STASH_ICON_STATE:
            pTypeDescriptor = DT_STASH_ICON_STATE_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_STASH_ICON_STATE";
            return true;
        case SMSG_COMBAT_LOG_ENTRY:
            pTypeDescriptor = DT_COMBAT_LOG_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "SMSG_COMBAT_LOG_ENTRY";
            return true;
        case CMSG_COMBAT_LOG_TOGGLE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_COMBAT_LOG_TOGGLE";
            return true;
        case SMSG_CONNECTION_ESTABLISHED:
            pTypeDescriptor = DT_CONNECTION_ESTABLISHED_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_CONNECTION_ESTABLISHED";
            return true;
        case SMSG_CONNECTION_ADD_PLAYER:
            pTypeDescriptor = DT_CONNECTION_ESTABLISHED_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_CONNECTION_ADD_PLAYER";
            return true;
        case SMSG_GAME_SETUP:
            pTypeDescriptor = DT_GAME_SETUP_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_GAME_SETUP";
            return true;
        case CMSG_FINISHED_GAME_SETUP:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_FINISHED_GAME_SETUP";
            return true;
        case SMSG_NEW_PLAYER:
            pTypeDescriptor = DT_NEW_PLAYER_MESSAGE;
            dwSize = 17336;
            pszMessageLabel = "SMSG_NEW_PLAYER";
            return true;
        case SMSG_PLAYER_KICK_TIMERS:
            pTypeDescriptor = DT_PLAYER_KICK_TIMER_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_KICK_TIMERS";
            return true;
        case SMSG_PLAYER_BANNER:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAYER_BANNER";
            return true;
        case SMSG_ENTER_WORLD:
            pTypeDescriptor = DT_ENTER_WORLD_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_ENTER_WORLD";
            return true;
        case SMSG_REVEAL_SCENE:
            pTypeDescriptor = DT_REVEAL_SCENE_MESSAGE;
            dwSize = 1288;
            pszMessageLabel = "SMSG_REVEAL_SCENE";
            return true;
        case SMSG_DESTROY_SCENE:
            pTypeDescriptor = DT_DESTROY_SCENE_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_DESTROY_SCENE";
            return true;
        case SMSG_SWAP_SCENE:
            pTypeDescriptor = DT_SWAP_SCENE_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_SWAP_SCENE";
            return true;
        case SMSG_REVEAL_WORLD:
            pTypeDescriptor = DT_REVEAL_WORLD_MESSAGE;
            dwSize = 40;
            pszMessageLabel = "SMSG_REVEAL_WORLD";
            return true;
        case SMSG_REVEAL_TEAM:
            pTypeDescriptor = DT_REVEAL_TEAM_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_REVEAL_TEAM";
            return true;
        case SMSG_PLAYER_ACTOR_SET:
            pTypeDescriptor = DT_PLAYER_ACTOR_SET_INITIAL_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_ACTOR_SET";
            return true;
        case SMSG_HERO_STATE:
            pTypeDescriptor = DT_HERO_STATE_MESSAGE;
            dwSize = 17076;
            pszMessageLabel = "SMSG_HERO_STATE";
            return true;
        case SMSG_HERO_STATE_SAVEDDATA:
            pTypeDescriptor = DT_PLAYER_SAVED_DATA_MESSAGE;
            dwSize = 2428;
            pszMessageLabel = "SMSG_HERO_STATE_SAVEDDATA";
            return true;
        case SMSG_HERO_STATE_PLAYERFLAGS:
            pTypeDescriptor = DT_PLAYER_DWORD_DATA_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_HERO_STATE_PLAYERFLAGS";
            return true;
        case SMSG_HERO_STATE_WAYPOINTS:
            pTypeDescriptor = DT_PLAYER_DWORD_DATA_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_HERO_STATE_WAYPOINTS";
            return true;
        case SMSG_HERO_STATE_LASTSAVEPOINT:
            pTypeDescriptor = DT_SAVE_POINT_DATA_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "SMSG_HERO_STATE_LASTSAVEPOINT";
            return true;
        case SMSG_ACD_ENTER_KNOWN:
            pTypeDescriptor = DT_ACD_ENTER_KNOWN_MESSAGE;
            dwSize = 140;
            pszMessageLabel = "SMSG_ACD_ENTER_KNOWN";
            return true;
        case SMSG_ACD_EXIT_KNOWN:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_ACD_EXIT_KNOWN";
            return true;
        case SMSG_PLAYER_ENTER_KNOWN:
            pTypeDescriptor = DT_PLAYER_ENTER_KNOWN_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_ENTER_KNOWN";
            return true;
        case SMSG_UI_ENTER_KNOWN:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_UI_ENTER_KNOWN";
            return true;
        case SMSG_ACD_WORLD_POSITION:
            pTypeDescriptor = DT_ACD_WORLD_POSITION_MESSAGE;
            dwSize = 48;
            pszMessageLabel = "SMSG_ACD_WORLD_POSITION";
            return true;
        case SMSG_ACD_INVENTORY_POSITION:
            pTypeDescriptor = DT_ACD_INVENTORY_POSITION_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_ACD_INVENTORY_POSITION";
            return true;
        case SMSG_ACD_INVENTORY_UPDATE_ACTOR_SNO:
            pTypeDescriptor = DT_ACD_INVENTORY_UPDATE_ACTOR_SNO;
            dwSize = 16;
            pszMessageLabel = "SMSG_ACD_INVENTORY_UPDATE_ACTOR_SNO";
            return true;
        case SMSG_TRICKLE_UPDATE:
            pTypeDescriptor = DT_TRICKLE_MESSAGE;
            dwSize = 140;
            pszMessageLabel = "SMSG_TRICKLE_UPDATE";
            return true;
        case SMSG_TRICKLE_REMOVE:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_TRICKLE_REMOVE";
            return true;
        case SMSG_MAP_REVEAL_SCENE:
            pTypeDescriptor = DT_MAP_REVEAL_SCENE_MESSAGE;
            dwSize = 52;
            pszMessageLabel = "SMSG_MAP_REVEAL_SCENE";
            return true;
        case SMSG_SAVEPOINT_INFO:
            pTypeDescriptor = DT_SAVE_POINT_INFO_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SAVEPOINT_INFO";
            return true;
        case SMSG_HEARTHPORTAL_INFO:
            pTypeDescriptor = DT_HEARTH_PORTAL_INFO_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_HEARTHPORTAL_INFO";
            return true;
        case SMSG_RETURNPOINT_INFO:
            pTypeDescriptor = DT_RETURN_POINT_INFO_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_RETURNPOINT_INFO";
            return true;
        case SMSG_AFFIX:
            pTypeDescriptor = DT_AFFIX_MESSAGE;
            dwSize = 148;
            pszMessageLabel = "SMSG_AFFIX";
            return true;
        case SMSG_RARE_MONSTER_NAMES:
            pTypeDescriptor = DT_RARE_MONSTER_NAMES_MESSAGE;
            dwSize = 52;
            pszMessageLabel = "SMSG_RARE_MONSTER_NAMES";
            return true;
        case SMSG_RARE_ITEM_NAME:
            pTypeDescriptor = DT_RARE_ITEM_NAME_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "SMSG_RARE_ITEM_NAME";
            return true;
        case SMSG_PORTAL_SPECIFIER:
            pTypeDescriptor = DT_PORTAL_SPECIFIER_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_PORTAL_SPECIFIER";
            return true;
        case SMSG_ATTRIBUTE_SET_VALUE:
            pTypeDescriptor = DT_ATTRIBUTE_SET_VALUE_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "SMSG_ATTRIBUTE_SET_VALUE";
            return true;
        case SMSG_ATTRIBUTES_SET_VALUES:
            pTypeDescriptor = DT_ATTRIBUTES_SET_VALUES_MESSAGE;
            dwSize = 256;
            pszMessageLabel = "SMSG_ATTRIBUTES_SET_VALUES";
            return true;
        case SMSG_VISUAL_INVENTORY:
            pTypeDescriptor = DT_VISUAL_INVENTORY_MESSAGE;
            dwSize = 140;
            pszMessageLabel = "SMSG_VISUAL_INVENTORY";
            return true;
        case SMSG_PROJECTILE_STICK:
            pTypeDescriptor = DT_PROJECTILE_STICK_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "SMSG_PROJECTILE_STICK";
            return true;
        case CMSG_TARGET:
            pTypeDescriptor = DT_TARGET_MESSAGE;
            dwSize = 68;
            pszMessageLabel = "CMSG_TARGET";
            return true;
        case CMSG_SECONDARY_ANIMATION_POWER:
            pTypeDescriptor = DT_SECONDARY_ANIMATION_POWER_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "CMSG_SECONDARY_ANIMATION_POWER";
            return true;
        case CMSG_LOOPING_ANIMATION_POWER:
            pTypeDescriptor = DT_LOOPING_ANIMATION_POWER_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "CMSG_LOOPING_ANIMATION_POWER";
            return true;
        case CMSG_EXECUTE_NON_PRIMARY_POWER:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_EXECUTE_NON_PRIMARY_POWER";
            return true;
        case CMSG_CHANNELLED_POWER_ABORTED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_CHANNELLED_POWER_ABORTED";
            return true;
        case CMSG_LOOPING_POWER_ABORTED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_LOOPING_POWER_ABORTED";
            return true;
        case CMSG_CLIENT_WALK_POWER_ABORTED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_CLIENT_WALK_POWER_ABORTED";
            return true;
        case CMSG_TRY_CHAT:
            pTypeDescriptor = DT_TRY_CHAT_MESSAGE;
            dwSize = 1040;
            pszMessageLabel = "CMSG_TRY_CHAT";
            return true;
        case SMSG_CHAT:
            pTypeDescriptor = DT_CHAT_MESSAGE;
            dwSize = 1040;
            pszMessageLabel = "SMSG_CHAT";
            return true;
        case CMSG_TRY_DROP:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_DROP";
            return true;
        case CMSG_TRY_INVENTORY_MOVE:
            pTypeDescriptor = DT_INVENTORY_REQUEST_MOVE_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "CMSG_TRY_INVENTORY_MOVE";
            return true;
        case CMSG_TRY_INVENTORY_QUICK_MOVE:
            pTypeDescriptor = DT_INVENTORY_REQUEST_QUICK_MOVE_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "CMSG_TRY_INVENTORY_QUICK_MOVE";
            return true;
        case CMSG_TRY_INVENTORY_SOCKET:
            pTypeDescriptor = DT_INVENTORY_REQUEST_SOCKET_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_TRY_INVENTORY_SOCKET";
            return true;
        case CMSG_TRY_INVENTORY_STACK:
            pTypeDescriptor = DT_INVENTORY_REQUEST_MOVE_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "CMSG_TRY_INVENTORY_STACK";
            return true;
        case CMSG_TRY_INVENTORY_SPLIT_STACK:
            pTypeDescriptor = DT_INVENTORY_SPLIT_STACK_MESSAGE;
            dwSize = 40;
            pszMessageLabel = "CMSG_TRY_INVENTORY_SPLIT_STACK";
            return true;
        case CMSG_TRY_INVENTORY_DROP_STACK_PORTION:
            pTypeDescriptor = DT_STACK_PORTION_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "CMSG_TRY_INVENTORY_DROP_STACK_PORTION";
            return true;
        case CMSG_TRY_INVENTORY_STACK_TRANSFER:
            pTypeDescriptor = DT_INVENTORY_STACK_TRANSFER_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "CMSG_TRY_INVENTORY_STACK_TRANSFER";
            return true;
        case CMSG_TRY_GOLD_TRANSFER:
            pTypeDescriptor = DT_GOLD_TRANSFER_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "CMSG_TRY_GOLD_TRANSFER";
            return true;
        case SMSG_STACK_NOTIFY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_STACK_NOTIFY";
            return true;
        case SMSG_STACK_DECREASE_NOTIFY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_STACK_DECREASE_NOTIFY";
            return true;
        case SMSG_IDENTIFY_NOTIFY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_IDENTIFY_NOTIFY";
            return true;
        case SMSG_ITEM_DELETE_NOTIFY:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_ITEM_DELETE_NOTIFY";
            return true;
        case CMSG_TRY_INVENTORY_SWAP_TO_BODY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_INVENTORY_SWAP_TO_BODY";
            return true;
        case CMSG_TRY_INVENTORY_USE:
            pTypeDescriptor = DT_INVENTORY_REQUEST_USE_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "CMSG_TRY_INVENTORY_USE";
            return true;
        case CMSG_HELPER_DETACH:
            pTypeDescriptor = DT_HELPER_DETACH_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_HELPER_DETACH";
            return true;
        case CMSG_TRY_ASSIGN_SKILL_TO_SLOT:
            pTypeDescriptor = DT_ASSIGN_SKILL_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "CMSG_TRY_ASSIGN_SKILL_TO_SLOT";
            return true;
        case CMSG_UNASSIGN_SKILL:
            pTypeDescriptor = DT_UNASSIGN_SKILL_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_UNASSIGN_SKILL";
            return true;
        case CMSG_TRY_ASSIGN_TRAITS:
            pTypeDescriptor = DT_ASSIGN_TRAITS_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "CMSG_TRY_ASSIGN_TRAITS";
            return true;
        case SMSG_ASSIGNED_SKILL_TO_SLOT:
            pTypeDescriptor = DT_ASSIGN_SKILL_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_ASSIGNED_SKILL_TO_SLOT";
            return true;
        case SMSG_ASSIGNED_TRAIT_TO_SLOT:
            pTypeDescriptor = DT_ASSIGN_SKILL_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_ASSIGNED_TRAIT_TO_SLOT";
            return true;
        case CMSG_TRY_CHOOSE_HIRELING_SKILL:
            pTypeDescriptor = DT_HIRELING_REQUEST_LEARN_SKILL_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_TRY_CHOOSE_HIRELING_SKILL";
            return true;
        case CMSG_TRY_PORTRAIT_DROP:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_PORTRAIT_DROP";
            return true;
        case CMSG_PLAYER_CHANGE_POTION_BUTTON:
            pTypeDescriptor = DT_GBID_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_PLAYER_CHANGE_POTION_BUTTON";
            return true;
        case SMSG_AUTOASSIGNED_TO_BUTTON:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_AUTOASSIGNED_TO_BUTTON";
            return true;
        case SMSG_PLAY_ANIMATION:
            pTypeDescriptor = DT_PLAY_ANIMATION_MESSAGE;
            dwSize = 84;
            pszMessageLabel = "SMSG_PLAY_ANIMATION";
            return true;
        case SMSG_PLAY_IDLE_ANIMATION:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAY_IDLE_ANIMATION";
            return true;
        case SMSG_ACD_TRANSLATE_NORMAL:
            pTypeDescriptor = DT_ACD_TRANSLATE_NORMAL_MESSAGE;
            dwSize = 100;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_NORMAL";
            return true;
        case SMSG_ACD_TRANSLATE_SNAPPED:
            pTypeDescriptor = DT_ACD_TRANSLATE_SNAPPED_MESSAGE;
            dwSize = 44;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_SNAPPED";
            return true;
        case SMSG_ACD_TRANSLATE_FACING:
            pTypeDescriptor = DT_ACD_TRANSLATE_FACING_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_FACING";
            return true;
        case SMSG_ACD_TRANSLATE_FIXED:
            pTypeDescriptor = DT_ACD_TRANSLATE_FIXED_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_FIXED";
            return true;
        case SMSG_ACD_TRANSLATE_ARC:
            pTypeDescriptor = DT_ACD_TRANSLATE_ARC_MESSAGE;
            dwSize = 64;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_ARC";
            return true;
        case SMSG_ACD_TRANSLATE_DETPATH:
            pTypeDescriptor = DT_ACD_TRANSLATE_DETPATH_MESSAGE;
            dwSize = 88;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_DETPATH";
            return true;
        case SMSG_ACD_TRANSLATE_DETPATH_SIN:
            pTypeDescriptor = DT_ACD_TRANSLATE_DETPATH_SIN_MESSAGE;
            dwSize = 100;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_DETPATH_SIN";
            return true;
        case SMSG_ACD_TRANSLATE_DETPATH_SPIRAL:
            pTypeDescriptor = DT_ACD_TRANSLATE_DETPATH_SPIRAL_MESSAGE;
            dwSize = 76;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_DETPATH_SPIRAL";
            return true;
        case SMSG_ACD_TRANSLATE_SYNC:
            pTypeDescriptor = DT_ACD_TRANSLATE_SYNC_MESSAGE;
            dwSize = 40;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_SYNC";
            return true;
        case SMSG_ACD_TRANSLATE_FIXED_UPDATE:
            pTypeDescriptor = DT_ACD_TRANSLATE_FIXED_UPDATE_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "SMSG_ACD_TRANSLATE_FIXED_UPDATE";
            return true;
        case CMSG_ACD_TRANSLATE_NORMAL:
            pTypeDescriptor = DT_ACD_CLIENT_TRANSLATE_MESSAGE;
            dwSize = 52;
            pszMessageLabel = "CMSG_ACD_TRANSLATE_NORMAL";
            return true;
        case CMSG_ACD_TRANSLATE_FACING:
            pTypeDescriptor = DT_ACD_TRANSLATE_FACING_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "CMSG_ACD_TRANSLATE_FACING";
            return true;
        case CMSG_ACD_TRANSLATE_ACK:
            pTypeDescriptor = DT_ACD_TRANSLATE_ACK_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_ACD_TRANSLATE_ACK";
            return true;
        case SMSG_PLAY_EFFECT:
            pTypeDescriptor = DT_PLAY_EFFECT_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_PLAY_EFFECT";
            return true;
        case SMSG_PLAY_HIT_EFFECT:
            pTypeDescriptor = DT_PLAY_HIT_EFFECT_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_PLAY_HIT_EFFECT";
            return true;
        case SMSG_PLAY_HIT_EFFECT_OVERRIDE:
            pTypeDescriptor = DT_PLAY_HIT_EFFECT_OVERRIDE_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_PLAY_HIT_EFFECT_OVERRIDE";
            return true;
        case SMSG_PLAY_NONPOSITIONAL_SOUND:
            pTypeDescriptor = DT_PLAY_NON_POSITIONAL_SOUND_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAY_NONPOSITIONAL_SOUND";
            return true;
        case SMSG_PLAY_ERROR_SOUND:
            pTypeDescriptor = DT_PLAY_ERROR_SOUND_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAY_ERROR_SOUND";
            return true;
        case SMSG_PLAY_MUSIC:
            pTypeDescriptor = DT_PLAY_MUSIC_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAY_MUSIC";
            return true;
        case SMSG_STOP_MUSIC_OVERLAY:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_STOP_MUSIC_OVERLAY";
            return true;
        case SMSG_PLAY_CUTSCENE:
            pTypeDescriptor = DT_PLAY_CUTSCENE_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PLAY_CUTSCENE";
            return true;
        case SMSG_SCOMPLEX_EFFECT_ADD:
            pTypeDescriptor = DT_COMPLEX_EFFECT_ADD_MESSAGE;
            dwSize = 40;
            pszMessageLabel = "SMSG_SCOMPLEX_EFFECT_ADD";
            return true;
        case SMSG_FLIPPY:
            pTypeDescriptor = DT_FLIPPY_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_FLIPPY";
            return true;
        case SMSG_ACTIVATE_WAYPOINT:
            pTypeDescriptor = DT_WAYPOINT_ACTIVATED_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_ACTIVATE_WAYPOINT";
            return true;
        case SMSG_OPERATE_WAYPOINT:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_OPERATE_WAYPOINT";
            return true;
        case SMSG_CONFIRM_OPERATION:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONFIRM_OPERATION";
            return true;
        case SMSG_OPEN_BANNER_CUSTOMIZATION:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_OPEN_BANNER_CUSTOMIZATION";
            return true;
        case CMSG_OPERATE_GIZMO:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_OPERATE_GIZMO";
            return true;
        case CMSG_ACCEPT_RESURRECT:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_ACCEPT_RESURRECT";
            return true;
        case SMSG_AIM_TARGET:
            pTypeDescriptor = DT_AIM_TARGET_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "SMSG_AIM_TARGET";
            return true;
        case SMSG_ACD_CHANGE_GB_HANDLE:
            pTypeDescriptor = DT_ACD_CHANGE_GB_HANDLE_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_ACD_CHANGE_GB_HANDLE";
            return true;
        case SMSG_HEARTBEAT:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_HEARTBEAT";
            return true;
        case SMSG_PVP_ARENA_WIN:
            pTypeDescriptor = DT_DATA_ID_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PVP_ARENA_WIN";
            return true;
        case SMSG_PVP_ARENA_LOSE:
            pTypeDescriptor = DT_DATA_ID_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PVP_ARENA_LOSE";
            return true;
        case CCMSG_END_OF_TICK:
            pTypeDescriptor = DT_END_OF_TICK_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CCMSG_END_OF_TICK";
            return true;
        case CMSG_TRY_WAYPOINT:
            pTypeDescriptor = DT_TRY_WAYPOINT_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_TRY_WAYPOINT";
            return true;
        case SMSG_NPC_INTERACT:
            pTypeDescriptor = DT_NPC_INTERACT_OPTIONS_MESSAGE;
            dwSize = 340;
            pszMessageLabel = "SMSG_NPC_INTERACT";
            return true;
        case CMSG_NPC_TALK_REQUEST:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_NPC_TALK_REQUEST";
            return true;
        case CMSG_NPC_VENDOR_REQUEST:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_NPC_VENDOR_REQUEST";
            return true;
        case SMSG_FORCE_NPC_INTERACT_CLOSE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_FORCE_NPC_INTERACT_CLOSE";
            return true;
        case SMSG_QUEST_UPDATE:
            pTypeDescriptor = DT_QUEST_UPDATE_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "SMSG_QUEST_UPDATE";
            return true;
        case SMSG_QUEST_METER:
            pTypeDescriptor = DT_QUEST_METER_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_QUEST_METER";
            return true;
        case SMSG_QUEST_COUNTER:
            pTypeDescriptor = DT_QUEST_COUNTER_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_QUEST_COUNTER";
            return true;
        case SMSG_QUEST_REWARD:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_QUEST_REWARD";
            return true;
        case SMSG_PLAYER_LEVEL:
            pTypeDescriptor = DT_PLAYER_LEVEL;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_LEVEL";
            return true;
        case SMSG_PLAYER_ALT_LEVEL:
            pTypeDescriptor = DT_PLAYER_LEVEL;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_ALT_LEVEL";
            return true;
        case SMSG_SHARED_STASH_OPEN:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SHARED_STASH_OPEN";
            return true;
        case SMSG_ACD_PICKUP_FAILED:
            pTypeDescriptor = DT_ACD_PICKUP_FAILED_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_ACD_PICKUP_FAILED";
            return true;
        case SMSG_ATTACH_PET:
            pTypeDescriptor = DT_PET_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_ATTACH_PET";
            return true;
        case SMSG_DETACH_PET:
            pTypeDescriptor = DT_PET_DETACH_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_DETACH_PET";
            return true;
        case SMSG_SET_HIRELING_DEAD:
            pTypeDescriptor = DT_HIRELING_INFO_UPDATE_MESSAGE;
            dwSize = 72;
            pszMessageLabel = "SMSG_SET_HIRELING_DEAD";
            return true;
        case SMSG_UI_ELEMENT_ACTION:
            pTypeDescriptor = DT_UI_ELEMENT_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_UI_ELEMENT_ACTION";
            return true;
        case CMSG_PLAYER_BUSY:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_PLAYER_BUSY";
            return true;
        case CMSG_TRADE:
            pTypeDescriptor = DT_TRADE_MESSAGE;
            dwSize = 56;
            pszMessageLabel = "CMSG_TRADE";
            return true;
        case SMSG_TRADE:
            pTypeDescriptor = DT_TRADE_MESSAGE;
            dwSize = 56;
            pszMessageLabel = "SMSG_TRADE";
            return true;
        case CMSG_INSPECT_START:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_INSPECT_START";
            return true;
        case CMSG_INSPECT_END:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_INSPECT_END";
            return true;
        case SMSG_INSPECT:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_INSPECT";
            return true;
        case SMSG_ACD_SET_IDLE_ANIM:
            pTypeDescriptor = DT_SET_IDLE_ANIMATION_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_ACD_SET_IDLE_ANIM";
            return true;
        case SMSG_ACD_COLL_FLAGS:
            pTypeDescriptor = DT_ACD_COLL_FLAGS_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_ACD_COLL_FLAGS";
            return true;
        case SMSG_GOLD_MODIFIED:
            pTypeDescriptor = DT_GOLD_MODIFIED_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_GOLD_MODIFIED";
            return true;
        case SMSG_ACT:
            pTypeDescriptor = DT_ACT_TRANSITION_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_ACT";
            return true;
        case SMSG_INTERSTITIAL:
            pTypeDescriptor = DT_INTERSTITIAL_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_INTERSTITIAL";
            return true;
        case SMSG_EFFECT_GROUP_ACD_TO_ACD:
            pTypeDescriptor = DT_EFFECT_GROUP_ACD_TO_ACD_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_EFFECT_GROUP_ACD_TO_ACD";
            return true;
        case SMSG_ROPE_EFFECT_ACD_TO_ACD:
            pTypeDescriptor = DT_ROPE_EFFECT_MESSAGE_ACD_TO_ACD;
            dwSize = 32;
            pszMessageLabel = "SMSG_ROPE_EFFECT_ACD_TO_ACD";
            return true;
        case SMSG_ROPE_EFFECT_ACD_TO_PLACE:
            pTypeDescriptor = DT_ROPE_EFFECT_MESSAGE_ACD_TO_PLACE;
            dwSize = 40;
            pszMessageLabel = "SMSG_ROPE_EFFECT_ACD_TO_PLACE";
            return true;
        case SMSG_INVENTORY_CREATE:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_INVENTORY_CREATE";
            return true;
        case SMSG_SHRINE_TEXT_DISPLAY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SHRINE_TEXT_DISPLAY";
            return true;
        case SMSG_GAME_SYNCED_DATA:
            pTypeDescriptor = DT_GAME_SYNCED_DATA_MESSAGE;
            dwSize = 120;
            pszMessageLabel = "SMSG_GAME_SYNCED_DATA";
            return true;
        case SMSG_CHANGE_ACTOR:
            pTypeDescriptor = DT_ACD_CHANGE_ACTOR_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_CHANGE_ACTOR";
            return true;
        case SMSG_PLAYER_WARPED:
            pTypeDescriptor = DT_PLAYER_WARPED_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_WARPED";
            return true;
        case SMSG_VICTIM:
            pTypeDescriptor = DT_VICTIM_MESSAGE;
            dwSize = 44;
            pszMessageLabel = "SMSG_VICTIM";
            return true;
        case SMSG_MONSTER_ENGAGED:
            pTypeDescriptor = DT_ENGAGED_MESSAGE;
            dwSize = 28;
            pszMessageLabel = "SMSG_MONSTER_ENGAGED";
            return true;
        case SMSG_KILLCOUNT:
            pTypeDescriptor = DT_KILL_COUNT_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_KILLCOUNT";
            return true;
        case SMSG_WORLD_STATUS:
            pTypeDescriptor = DT_WORLD_STATUS_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_WORLD_STATUS";
            return true;
        case SMSG_WEATHER_OVERRIDE:
            pTypeDescriptor = DT_WEATHER_OVERRIDE_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_WEATHER_OVERRIDE";
            return true;
        case SMSG_TRIGGER_LIGHTNING:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_TRIGGER_LIGHTNING";
            return true;
        case SMSG_SHEAR:
            pTypeDescriptor = DT_ACD_SHEAR_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_SHEAR";
            return true;
        case SMSG_GROUP:
            pTypeDescriptor = DT_ACD_GROUP_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_GROUP";
            return true;
        case CMSG_KEEPALIVE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_KEEPALIVE";
            return true;
        case SMSG_PLAY_CONV_LINE:
            pTypeDescriptor = DT_PLAY_CONV_LINE_MESSAGE;
            dwSize = 128;
            pszMessageLabel = "SMSG_PLAY_CONV_LINE";
            return true;
        case SMSG_STOP_CONV_LINE:
            pTypeDescriptor = DT_STOP_CONV_LINE_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_STOP_CONV_LINE";
            return true;
        case CMSG_REQUEST_CONV_ADVANCE:
            pTypeDescriptor = DT_ADVANCE_CONV_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_REQUEST_CONV_ADVANCE";
            return true;
        case CMSG_UPDATE_CONV_AUTO_ADVANCE:
            pTypeDescriptor = DT_UPDATE_CONV_AUTO_ADVANCE_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "CMSG_UPDATE_CONV_AUTO_ADVANCE";
            return true;
        case CMSG_REQUEST_CONV_CANCEL:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_REQUEST_CONV_CANCEL";
            return true;
        case SMSG_END_CONV:
            pTypeDescriptor = DT_END_CONVERSATION_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_END_CONV";
            return true;
        case SMSG_CONFIRM_HIRELING_SWAP:
            pTypeDescriptor = DT_HIRELING_SWAP_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONFIRM_HIRELING_SWAP";
            return true;
        case SMSG_HIRELING_AUTO_DISMISS:
            pTypeDescriptor = DT_HIRELING_SWAP_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_HIRELING_AUTO_DISMISS";
            return true;
        case CMSG_REQUEST_HIRELING_SWAP:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_REQUEST_HIRELING_SWAP";
            return true;
        case SMSG_SET_DEATH_FADE_TIMES:
            pTypeDescriptor = DT_DEATH_FADE_TIME_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_SET_DEATH_FADE_TIMES";
            return true;
        case SMSG_RESET_DEATH_FADE_TIMES:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_RESET_DEATH_FADE_TIMES";
            return true;
        case SMSG_REMOVE_FROM_SPHERE_LIST:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_REMOVE_FROM_SPHERE_LIST";
            return true;
        case SMSG_DISPLAY_GAME_TEXT:
            pTypeDescriptor = DT_DISPLAY_GAME_TEXT_MESSAGE;
            dwSize = 1048;
            pszMessageLabel = "SMSG_DISPLAY_GAME_TEXT";
            return true;
        case SMSG_DISPLAY_ERROR:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_DISPLAY_ERROR";
            return true;
        case SMSG_DISPLAY_VAGUE_LOCKED_ERROR:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_DISPLAY_VAGUE_LOCKED_ERROR";
            return true;
        case SMSG_DISPLAY_ITEM_REQUIRED_ERROR:
            pTypeDescriptor = DT_GBID_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_DISPLAY_ITEM_REQUIRED_ERROR";
            return true;
        case SMSG_CANCEL_ACD_TARGET:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CANCEL_ACD_TARGET";
            return true;
        case SMSG_RESET_ACD_EFFECTS:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_RESET_ACD_EFFECTS";
            return true;
        case SMSG_LOOK_AT_ACD:
            pTypeDescriptor = DT_ACD_LOOK_AT_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_LOOK_AT_ACD";
            return true;
        case SMSG_KILL_COUNTER_UPDATE:
            pTypeDescriptor = DT_KILL_COUNTER_UPDATE_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_KILL_COUNTER_UPDATE";
            return true;
        case SMSG_LOW_HEALTH_COMBAT:
            pTypeDescriptor = DT_LOW_HEALTH_COMBAT_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_LOW_HEALTH_COMBAT";
            return true;
        case SMSG_SAVIOR:
            pTypeDescriptor = DT_SAVIOR_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_SAVIOR";
            return true;
        case SMSG_FLOATING_NUMBER:
            pTypeDescriptor = DT_FLOATING_NUMBER_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_FLOATING_NUMBER";
            return true;
        case SMSG_FLOATING_AMOUNT:
            pTypeDescriptor = DT_FLOATING_AMOUNT_MESSAGE;
            dwSize = 40;
            pszMessageLabel = "SMSG_FLOATING_AMOUNT";
            return true;
        case SMSG_REMOVE_NEAREST_RAGDOLL:
            pTypeDescriptor = DT_REMOVE_RAGDOLL_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_REMOVE_NEAREST_RAGDOLL";
            return true;
        case SMSG_PREFETCH:
            pTypeDescriptor = DT_SNO_NAME_DATA_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PREFETCH";
            return true;
        case SMSG_PREFETCH_AND_SCAN_CHILDREN:
            pTypeDescriptor = DT_SNO_NAME_DATA_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PREFETCH_AND_SCAN_CHILDREN";
            return true;
        case SMSG_LORE_LEARNED:
            pTypeDescriptor = DT_LORE_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_LORE_LEARNED";
            return true;
        case CMSG_AV_CAMERA_MODE_TOGGLE:
            pTypeDescriptor = DT_PR_TRANSFORM_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "CMSG_AV_CAMERA_MODE_TOGGLE";
            return true;
        case CMSG_AV_CAMERA_LOCATION:
            pTypeDescriptor = DT_PR_TRANSFORM_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "CMSG_AV_CAMERA_LOCATION";
            return true;
        case SMSG_TRIAL_OVER:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_TRIAL_OVER";
            return true;
        case SMSG_DEMO_OVER:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_DEMO_OVER";
            return true;
        case SMSG_WORLD_DELETED:
            pTypeDescriptor = DT_WORLD_DELETED_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_WORLD_DELETED";
            return true;
        case SMSG_PVP_ARENA_RESTART:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_PVP_ARENA_RESTART";
            return true;
        case SMSG_SET_SCREENSHOT_VIEW:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SET_SCREENSHOT_VIEW";
            return true;
        case SMSG_TIMED_EVENT_STARTED:
            pTypeDescriptor = DT_TIMED_EVENT_STARTED_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_TIMED_EVENT_STARTED";
            return true;
        case SMSG_TIMED_EVENT_FINISHED:
            pTypeDescriptor = DT_SNO_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_TIMED_EVENT_FINISHED";
            return true;
        case SMSG_ACT_TRANSITION_STARTED:
            pTypeDescriptor = DT_ACT_TRANSITION_STARTED_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_ACT_TRANSITION_STARTED";
            return true;
        case SMSG_ACT_TRANSITION_ENDED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_ACT_TRANSITION_ENDED";
            return true;
        case CMSG_SHARED_STASH_TRY_BUY:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_SHARED_STASH_TRY_BUY";
            return true;
        case SMSG_PLAYER_ACTIVATED_QUEST:
            pTypeDescriptor = DT_PLAYER_QUEST_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_ACTIVATED_QUEST";
            return true;
        case SMSG_PLAYER_COMPLETED_QUEST:
            pTypeDescriptor = DT_PLAYER_QUEST_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_COMPLETED_QUEST";
            return true;
        case SMSG_PLAYER_DESYNC_SNAP:
            pTypeDescriptor = DT_PLAYER_DE_SYNC_SNAP_MESSAGE;
            dwSize = 36;
            pszMessageLabel = "SMSG_PLAYER_DESYNC_SNAP";
            return true;
        case CMSG_TRY_SALVAGE:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_SALVAGE";
            return true;
        case SMSG_SALVAGE_RESULT:
            pTypeDescriptor = DT_SALVAGE_RESULTS_MESSAGE;
            dwSize = 60;
            pszMessageLabel = "SMSG_SALVAGE_RESULT";
            return true;
        case SMSG_RETURNED_GEMS_NOTIFICATION:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_RETURNED_GEMS_NOTIFICATION";
            return true;
        case SMSG_MAP_MARKER:
            pTypeDescriptor = DT_MAP_MARKER_INFO_MESSAGE;
            dwSize = 76;
            pszMessageLabel = "SMSG_MAP_MARKER";
            return true;
        case SMSG_CRAFTING_DATA_BLACKSMITH:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTING_DATA_BLACKSMITH";
            return true;
        case SMSG_CRAFTING_DATA_JEWELER:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTING_DATA_JEWELER";
            return true;
        case SMSG_CRAFTING_DATA_MYSTIC:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTING_DATA_MYSTIC";
            return true;
        case SMSG_CRAFTING_DATA_BLACKSMITH_INITIAL:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTING_DATA_BLACKSMITH_INITIAL";
            return true;
        case SMSG_CRAFTING_DATA_JEWELER_INITIAL:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTING_DATA_JEWELER_INITIAL";
            return true;
        case SMSG_CRAFTING_DATA_MYSTIC_INITIAL:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CRAFTING_DATA_MYSTIC_INITIAL";
            return true;
        case CMSG_REQUEST_DEBUG_ACTOR_TOOLTIP:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_REQUEST_DEBUG_ACTOR_TOOLTIP";
            return true;
        case SMSG_DISPLAY_DEBUG_ACTOR_TOOLTIP:
            pTypeDescriptor = DT_DEBUG_ACTOR_TOOLTIP_MESSAGE;
            dwSize = 1036;
            pszMessageLabel = "SMSG_DISPLAY_DEBUG_ACTOR_TOOLTIP";
            return true;
        case SMSG_BOSS_JOIN_ENCOUNTER:
            pTypeDescriptor = DT_BOSS_ENCOUNTER_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_BOSS_JOIN_ENCOUNTER";
            return true;
        case CMSG_BOSS_JOIN_ACCEPTED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_BOSS_JOIN_ACCEPTED";
            return true;
        case CMSG_BOSS_START_ACCEPTED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_BOSS_START_ACCEPTED";
            return true;
        case SMSG_BOSS_START_ENCOUNTER:
            pTypeDescriptor = DT_BOSS_ENCOUNTER_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_BOSS_START_ENCOUNTER";
            return true;
        case CMSG_BOSS_START_DECLINED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_BOSS_START_DECLINED";
            return true;
        case CMSG_BOSS_JOIN_DECLINED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_BOSS_JOIN_DECLINED";
            return true;
        case SMSG_BOSS_ENCOUNTER_INVITE_STATE:
            pTypeDescriptor = DT_ENCOUNTER_INVITE_STATE_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_BOSS_ENCOUNTER_INVITE_STATE";
            return true;
        case SMSG_BOSS_ENCOUNTER_STARTED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_BOSS_ENCOUNTER_STARTED";
            return true;
        case SMSG_BOSS_ENCOUNTER_CANCELED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_BOSS_ENCOUNTER_CANCELED";
            return true;
        case SMSG_BOSS_ENCOUNTER_ONE_DECLINED:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_BOSS_ENCOUNTER_ONE_DECLINED";
            return true;
        case CMSG_BOSS_VOTE_CONTINUE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_BOSS_VOTE_CONTINUE";
            return true;
        case CMSG_BOSS_VOTE_CANCEL:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_BOSS_VOTE_CANCEL";
            return true;
        case SMSG_CAMERA_SCRIPTED_SEQUENCE_START:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_CAMERA_SCRIPTED_SEQUENCE_START";
            return true;
        case SMSG_CAMERA_SCRIPTED_SEQUENCE_STOP:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_CAMERA_SCRIPTED_SEQUENCE_STOP";
            return true;
        case SMSG_CAMERA_FOCUS_ACD:
            pTypeDescriptor = DT_CAMERA_FOCUS_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_CAMERA_FOCUS_ACD";
            return true;
        case SMSG_CAMERA_ZOOM:
            pTypeDescriptor = DT_CAMERA_ZOOM_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_CAMERA_ZOOM";
            return true;
        case SMSG_CAMERA_YAW:
            pTypeDescriptor = DT_CAMERA_YAW_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_CAMERA_YAW";
            return true;
        case SMSG_CAMERA_TRIGGER_FADE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_CAMERA_TRIGGER_FADE";
            return true;
        case SMSG_CAMERA_TRIGGER_FADE_TO_BLACK:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CAMERA_TRIGGER_FADE_TO_BLACK";
            return true;
        case SMSG_CAMERA_TRIGGER_INSTANT_FADE_TO_BLACK:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_CAMERA_TRIGGER_INSTANT_FADE_TO_BLACK";
            return true;
        case SMSG_BOSS_ZOOM:
            pTypeDescriptor = DT_BOSS_ZOOM_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_BOSS_ZOOM";
            return true;
        case CMSG_TRY_ENHANCE:
            pTypeDescriptor = DT_ENCHANT_ITEM_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_TRY_ENHANCE";
            return true;
        case CMSG_TRY_REPAIR:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_REPAIR";
            return true;
        case CMSG_TRY_REPAIR_ALL:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_TRY_REPAIR_ALL";
            return true;
        case CMSG_TRY_REPAIR_EQUIPPED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_TRY_REPAIR_EQUIPPED";
            return true;
        case SMSG_REPAIR_ACK:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_REPAIR_ACK";
            return true;
        case CMSG_VENDOR_TRY_TRAIN:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_VENDOR_TRY_TRAIN";
            return true;
        case SMSG_VENDOR_TRAIN_RESULTS:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_VENDOR_TRAIN_RESULTS";
            return true;
        case SMSG_DEBUG_DRAW_PRIM:
            pTypeDescriptor = DT_DEBUG_DRAW_PRIM_MESSAGE;
            dwSize = 188;
            pszMessageLabel = "SMSG_DEBUG_DRAW_PRIM";
            return true;
        case CMSG_TRY_CRAFT_ITEM:
            pTypeDescriptor = DT_GBID_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_CRAFT_ITEM";
            return true;
        case SMSG_CRAFTING_RESULT:
            pTypeDescriptor = DT_CRAFTING_RESULTS_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_CRAFTING_RESULT";
            return true;
        case SMSG_VENDOR_LEVEL_UP:
            pTypeDescriptor = DT_CRAFTER_LEVEL_UP_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_VENDOR_LEVEL_UP";
            return true;
        case CMSG_TRY_IDENTIFY_WITH_CAST:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_IDENTIFY_WITH_CAST";
            return true;
        case CMSG_TRY_IDENTIFY_ALL_WITH_CAST:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_TRY_IDENTIFY_ALL_WITH_CAST";
            return true;
        case CMSG_TRY_REMOVE_GEMS:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_REMOVE_GEMS";
            return true;
        case SMSG_CALLOUT_EVENT:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CALLOUT_EVENT";
            return true;
        case SMSG_HIGHEST_UNLOCKED_DIFFICULTY_LEVEL:
            pTypeDescriptor = DT_UNLOCK_DIFFICULTY_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_HIGHEST_UNLOCKED_DIFFICULTY_LEVEL";
            return true;
        case SMSG_CURRENT_DIFFICULTY_AND_HANDICAP_LEVEL:
            pTypeDescriptor = DT_DIFFICULTY_AND_HANDICAP_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_CURRENT_DIFFICULTY_AND_HANDICAP_LEVEL";
            return true;
        case CMSG_FOLLOWER_RETRAIN_REQUEST:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_FOLLOWER_RETRAIN_REQUEST";
            return true;
        case SMSG_GAME_TESTING_DONE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_GAME_TESTING_DONE";
            return true;
        case SMSG_GAME_TESTING_START_SAMPLING:
            pTypeDescriptor = DT_GAME_TESTING_SAMPLING_START_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_GAME_TESTING_START_SAMPLING";
            return true;
        case SMSG_GAME_TESTING_STOP_SAMPLING:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_GAME_TESTING_STOP_SAMPLING";
            return true;
        case CMSG_SHOWN_TUTORIAL:
            pTypeDescriptor = DT_SNO_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_SHOWN_TUTORIAL";
            return true;
        case CMSG_REQUEST_BUFF_CANCEL:
            pTypeDescriptor = DT_REQUEST_BUFF_CANCEL_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_REQUEST_BUFF_CANCEL";
            return true;
        case CMSG_REQUEST_EVENT_SKIP:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_REQUEST_EVENT_SKIP";
            return true;
        case SMSG_HANDLE_EVENT_SKIP:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_HANDLE_EVENT_SKIP";
            return true;
        case CMSG_REQUEST_PROMOTE_GAME_TO_PUBLIC:
            pTypeDescriptor = DT_OPEN_GAME_TO_PUBLIC_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "CMSG_REQUEST_PROMOTE_GAME_TO_PUBLIC";
            return true;
        case SMSG_GAME_PROMOTED_TO_PUBLIC:
            pTypeDescriptor = DT_OPEN_GAME_TO_PUBLIC_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_GAME_PROMOTED_TO_PUBLIC";
            return true;
        case CMSG_SEND_PLAYER_PREFS:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_SEND_PLAYER_PREFS";
            return true;
        case CMSG_PING:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_PING";
            return true;
        case SMSG_PONG:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PONG";
            return true;
        case SMSG_SYSTEM_SHUTDOWN:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SYSTEM_SHUTDOWN";
            return true;
        case SMSG_SYSTEM_BROADCAST:
            pTypeDescriptor = DT_BROADCAST_TEXT_MESSAGE;
            dwSize = 1032;
            pszMessageLabel = "SMSG_SYSTEM_BROADCAST";
            return true;
        case CMSG_LOAD_COMPLETE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_LOAD_COMPLETE";
            return true;
        case CMSG_NPC_INTERACT_CANCEL:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_NPC_INTERACT_CANCEL";
            return true;
        case CMSG_NPC_INTERACT_TALK_DIALOG:
            pTypeDescriptor = DT_SNO_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_NPC_INTERACT_TALK_DIALOG";
            return true;
        case CMSG_NPC_INTERACT_PET_DISMISS:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_NPC_INTERACT_PET_DISMISS";
            return true;
        case CMSG_NPC_INTERACT_CRAFT:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_NPC_INTERACT_CRAFT";
            return true;
        case CMSG_NPC_INTERACT_HIRE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_NPC_INTERACT_HIRE";
            return true;
        case CMSG_NPC_INTERACT_INVENTORY:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_NPC_INTERACT_INVENTORY";
            return true;
        case CMSG_GAME_END_REQUEST:
            pTypeDescriptor = DT_SNO_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_GAME_END_REQUEST";
            return true;
        case SMSG_START_END_COUNTDOWN:
            pTypeDescriptor = DT_ACT_TRANSITION_STARTED_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_START_END_COUNTDOWN";
            return true;
        case CMSG_START_VOTE_KICK:
            pTypeDescriptor = DT_VOTE_KICK_MESSAGE;
            dwSize = 1040;
            pszMessageLabel = "CMSG_START_VOTE_KICK";
            return true;
        case CMSG_TRY_VOTE_KICK:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_TRY_VOTE_KICK";
            return true;
        case SMSG_CAN_VOTE_KICK:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CAN_VOTE_KICK";
            return true;
        case SMSG_VOTE_KICK_VOTE:
            pTypeDescriptor = DT_VOTE_KICK_MESSAGE;
            dwSize = 1040;
            pszMessageLabel = "SMSG_VOTE_KICK_VOTE";
            return true;
        case CMSG_VOTE_KICK_VOTE:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_VOTE_KICK_VOTE";
            return true;
        case SMSG_VOTE_KICK_FAILED:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_VOTE_KICK_FAILED";
            return true;
        case SMSG_VOTE_KICK_PASSED:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_VOTE_KICK_PASSED";
            return true;
        case CMSG_REQUEST_PAUSE_STATE_CHANGE:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_REQUEST_PAUSE_STATE_CHANGE";
            return true;
        case SMSG_PAUSE_STATE_CHANGE:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PAUSE_STATE_CHANGE";
            return true;
        case SMSG_SOFT_PAUSE_STATE_CHANGE:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SOFT_PAUSE_STATE_CHANGE";
            return true;
        case SMSG_HARDCORE_MODE_UNLOCKED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_HARDCORE_MODE_UNLOCKED";
            return true;
        case CMSG_TRIED_SALVAGE:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_TRIED_SALVAGE";
            return true;
        case CMSG_POLL_MAIL:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_POLL_MAIL";
            return true;
        case CMSG_FETCH_MAIL:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_FETCH_MAIL";
            return true;
        case CMSG_SEND_MAIL:
            pTypeDescriptor = DT_MAIL_SEND_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_SEND_MAIL";
            return true;
        case CMSG_MARK_READ_MAIL:
            pTypeDescriptor = DT_MAIL_READ_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_MARK_READ_MAIL";
            return true;
        case CMSG_RETRIEVE_MAIL_ATTACHMENTS:
            pTypeDescriptor = DT_MAIL_RETRIEVE_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_RETRIEVE_MAIL_ATTACHMENTS";
            return true;
        case CMSG_DELETE_MAIL:
            pTypeDescriptor = DT_MAIL_DELETE_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_DELETE_MAIL";
            return true;
        case SMSG_MAIL_CONTENTS:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_MAIL_CONTENTS";
            return true;
        case SMSG_MAIL_SENT:
            pTypeDescriptor = DT_MAIL_SENT_RESPONSE_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_MAIL_SENT";
            return true;
        case SMSG_MAIL_READ:
            pTypeDescriptor = DT_MAIL_READ_RESPONSE_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_MAIL_READ";
            return true;
        case SMSG_MAIL_RETRIEVED:
            pTypeDescriptor = DT_MAIL_RETRIEVE_RESPONSE_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_MAIL_RETRIEVED";
            return true;
        case SMSG_MAIL_DELETED:
            pTypeDescriptor = DT_MAIL_DELETE_RESPONSE_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_MAIL_DELETED";
            return true;
        case SMSG_PVP_KILL:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PVP_KILL";
            return true;
        case SMSG_PVP_ASSIST:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_PVP_ASSIST";
            return true;
        case CMSG_TRY_REDEEM_PVP_TOKENS:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "CMSG_TRY_REDEEM_PVP_TOKENS";
            return true;
        case SMSG_PVP_TOKEN_REDEMPTION_RESULTS:
            pTypeDescriptor = DT_PVP_TOKEN_REDEMPTION_MESSAGE;
            dwSize = 60;
            pszMessageLabel = "SMSG_PVP_TOKEN_REDEMPTION_RESULTS";
            return true;
        case SMSG_SET_CAMERA_OBSERVER:
            pTypeDescriptor = DT_PLAYER_SET_CAMERA_OBSERVER_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_SET_CAMERA_OBSERVER";
            return true;
        case SMSG_SET_CAMERA_ORBIT:
            pTypeDescriptor = DT_PLAYER_SET_CAMERA_ORBIT_MESSAGE;
            dwSize = 24;
            pszMessageLabel = "SMSG_SET_CAMERA_ORBIT";
            return true;
        case SMSG_SET_CAMERA_DEFAULTS:
            pTypeDescriptor = DT_PLAYER_SET_CAMERA_DEFAULTS_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_SET_CAMERA_DEFAULTS";
            return true;
        case SMSG_CONSOLE_SET_CAMERA_DEFAULTS:
            pTypeDescriptor = DT_PLAYER_CONSOLE_SET_CAMERA_DEFAULTS_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_SET_CAMERA_DEFAULTS";
            return true;
        case SMSG_CONSOLE_VALIDATE_HERO:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_VALIDATE_HERO";
            return true;
        case SMSG_CONSOLE_VALIDATE_ACCOUNT:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_VALIDATE_ACCOUNT";
            return true;
        case SMSG_CONSOLE_SAVE:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_SAVE";
            return true;
        case SMSG_CONSOLE_SYNC_HERO_SAVED_QUESTS:
            pTypeDescriptor = DT_PLAYER_SAVED_QUEST_UPDATE_MESSAGE;
            dwSize = 11036;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_HERO_SAVED_QUESTS";
            return true;
        case SMSG_CONSOLE_SYNC_HERO_QUEST_HISTORY:
            pTypeDescriptor = DT_PLAYER_QUEST_HISTORY_UPDATE_MESSAGE;
            dwSize = 2412;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_HERO_QUEST_HISTORY";
            return true;
        case SMSG_CONSOLE_SYNC_HERO_QUEST_REWARD_HISTORY:
            pTypeDescriptor = DT_PLAYER_QUEST_REWARD_HISTORY_UPDATE_MESSAGE;
            dwSize = 1212;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_HERO_QUEST_REWARD_HISTORY";
            return true;
        case SMSG_CONSOLE_SYNC_HERO_SAVED_CONVERSATIONS:
            pTypeDescriptor = DT_PLAYER_SAVED_CONVERSATIONS_UPDATE_MESSAGE;
            dwSize = 1068;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_HERO_SAVED_CONVERSATIONS";
            return true;
        case SMSG_CONSOLE_SYNC_HERO_ACTIVE_HIRELING:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_HERO_ACTIVE_HIRELING";
            return true;
        case SMSG_CONSOLE_SYNC_HERO_TIME_PLAYED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_HERO_TIME_PLAYED";
            return true;
        case SMSG_CONSOLE_SYNC_ACCOUNT_ACHIEVEMENT_CRITERIA_UPDATE:
            pTypeDescriptor = DT_CONSOLE_ACHIEVEMENT_CRITERIA_UPDATE_MESSAGE;
            dwSize = 524;
            pszMessageLabel = "SMSG_CONSOLE_SYNC_ACCOUNT_ACHIEVEMENT_CRITERIA_UPDATE";
            return true;
        case SMSG_CONSOLE_COUNTER_PLAYER_MONSTERS_KILLED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_COUNTER_PLAYER_MONSTERS_KILLED";
            return true;
        case SMSG_CONSOLE_COUNTER_PLAYER_ELITES_KILLED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_COUNTER_PLAYER_ELITES_KILLED";
            return true;
        case SMSG_CONSOLE_COUNTER_PLAYER_GOLD_COLLECTED:
            pTypeDescriptor = DT_DWORD_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_CONSOLE_COUNTER_PLAYER_GOLD_COLLECTED";
            return true;
        case SMSG_CONSOLE_GAME_ENDED:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_CONSOLE_GAME_ENDED";
            return true;
        case CMSG_SAVE_BANNER:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_SAVE_BANNER";
            return true;
        case SMSG_SAVE_BANNER_RESPONSE:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SAVE_BANNER_RESPONSE";
            return true;
        case SMSG_ACHIEVEMENTS_UNAVAILABLE:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_ACHIEVEMENTS_UNAVAILABLE";
            return true;
        case SMSG_ACHIEVEMENT_AWARDED:
            pTypeDescriptor = DT_CONSOLE_ACHIEVEMENT_AWARDED_MESSAGE;
            dwSize = 32;
            pszMessageLabel = "SMSG_ACHIEVEMENT_AWARDED";
            return true;
        case SMSG_MULTIPLAYER_BUFF_ON:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_MULTIPLAYER_BUFF_ON";
            return true;
        case SMSG_MULTIPLAYER_BUFF_OFF:
            pTypeDescriptor = DT_SIMPLE_MESSAGE;
            dwSize = 8;
            pszMessageLabel = "SMSG_MULTIPLAYER_BUFF_OFF";
            return true;
        case SMSG_DUEL_RESULT:
            pTypeDescriptor = DT_DUEL_RESULT_MESSAGE;
            dwSize = 20;
            pszMessageLabel = "SMSG_DUEL_RESULT";
            return true;
        case SMSG_SHRINE_GLOBE_TEXT_DISPLAY:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "SMSG_SHRINE_GLOBE_TEXT_DISPLAY";
            return true;
        case CMSG_ITEM_JUNK_FLAG_CHANGED:
            pTypeDescriptor = DT_ITEM_JUNK_FLAG_CHANGED_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_ITEM_JUNK_FLAG_CHANGED";
            return true;
        case CMSG_PARAGON_POINT_SPEND:
            pTypeDescriptor = DT_SPEND_PARAGON_POINTS_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "CMSG_PARAGON_POINT_SPEND";
            return true;
        case CMSG_PARAGON_POINTS_RESET:
            pTypeDescriptor = DT_INT_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_PARAGON_POINTS_RESET";
            return true;
        case CMSG_REQUEST_PROMOTE_TO_PARTY_GUIDE:
            pTypeDescriptor = DT_ANN_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_REQUEST_PROMOTE_TO_PARTY_GUIDE";
            return true;
        case SMSG_PLAYER_CLEAR_CLIENT_WALK_POWER:
            pTypeDescriptor = DT_PLAYER_CLEAR_CLIENT_WALK_POWER_MESSAGE;
            dwSize = 16;
            pszMessageLabel = "SMSG_PLAYER_CLEAR_CLIENT_WALK_POWER";
            return true;
        case CMSG_WARP_DEAD_PLAYER:
            pTypeDescriptor = DT_PLAYER_INDEX_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_WARP_DEAD_PLAYER";
            return true;
        case CMSG_REQUEST_SOFT_PAUSE_STATE_CHANGE:
            pTypeDescriptor = DT_BOOL_DATA_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "CMSG_REQUEST_SOFT_PAUSE_STATE_CHANGE";
            return true;
        case XMSG_RELOAD_MAIL_MESSAGE:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "XMSG_RELOAD_MAIL_MESSAGE";
            return true;
        case XMSG_SAVE_BANNER_COMPLETE:
            pTypeDescriptor = DT_GENERIC_BLOB_MESSAGE;
            dwSize = 12;
            pszMessageLabel = "XMSG_SAVE_BANNER_COMPLETE";
            return true;
        default:
            pTypeDescriptor = 0;
            dwSize = 0;
            pszMessageLabel = nullptr;
            return false;
    }
}

const char* GameMessageTypeToName(GameMessageType eMessageType)
{
    unsigned int pTypeDescriptor;
    unsigned int dwSize;
    const char* pszMessageLabel;

    if (GetGameMessageTypeAndSize(eMessageType, pTypeDescriptor, dwSize, pszMessageLabel))
        return pszMessageLabel;
    else
        return "Unknown GameMessageType";
}
