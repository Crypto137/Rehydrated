#pragma once

#include "game/types.h"

struct SnoMapping
{
    SNO snoConsole;
    SNO snoPC;

    constexpr SnoMapping(int nConsole, int nPC) :
        snoConsole(static_cast<SNO>(nConsole)),
        snoPC(static_cast<SNO>(nPC))
    {
    }
};

constexpr SnoMapping s_ActorSnoMappings[] = {
    { 255340, 255289 },    // hero_bugWings_barbF
    { 255737, 255668 },    // hero_bugWings_barbM
    { 255738, 255669 },    // hero_bugWings_DHF
    { 255739, 255670 },    // hero_bugWings_DHM
    { 255740, 255671 },    // hero_bugWings_monkF
    { 255741, 255672 },    // hero_bugWings_monkM
    { 255742, 255673 },    // hero_bugWings_WDF
    { 255743, 255674 },    // hero_bugWings_WDM
    { 255745, 255675 },    // hero_bugWings_wizM
    { 255744, 255676 },    // hero_bugWings_wizF
    { 255893, 255807 },    // DemonKey_Hate
    { 255894, 255808 },    // DemonKey_Terror
    { 255892, 255809 },    // DemonKey_Destruction
    { 256120, 255929 },    // Uber_SkeletonKingRed
    { 256114, 255948 },    // Uber_Shield_Skeleton_Red
    { 256116, 255950 },    // Uber_skeleton_twoHander_Red
    { 256118, 255952 },    // Uber_SkeletonArcher_Red
    { 256006, 255996 },    // GoatMutant_Ranged_A_Unique_Uber
    { 256028, 256000 },    // DuneDervish_B_Unique_Uber
    { 256046, 256015 },    // morluSpellcaster_A_Unique_Uber
    { 256061, 256034 },    // TerrorDemon_A_Unique_Uber
    { 256572, 256187 },    // Uber_SiegebreakerDemon
    { 256571, 256189 },    // Uber_Maghda
    { 256573, 256508 },    // Uber_ZoltunKulle
    { 256719, 256709 },    // Uber_Gluttony
    { 256718, 256711 },    // Uber_Despair
    { 257171, 257063 },    // Uber_BossWorld1_Gate_B
    { 257307, 257207 },    // arcaneEnchantedDummy_spawn
    { 257752, 257667 },    // Quest_InfernalMachine_Flippy
    { 257753, 257691 },    // Quest_Vengeful_eye
    { 257754, 257699 },    // Quest_Writhing_Spine_Flippy
    { 257751, 257704 },    // Quest_Devils_fang_Flippy
    { 257955, 257926 },    // Uber_SoulRipper_Despair
    { 257953, 257930 },    // Uber_Berserker_MaghdaPet
    { 257954, 257935 },    // Uber_Gluttony_slime
    { 257974, 257971 },    // Unique_Monster_Earthquake_Prototype
    { 258070, 258061 },    // Uber_BossPortal_Door
    { 258078, 258063 },    // Uber_BossPortal_Door_Static
    { 258395, 258337 },    // Uber_Portal0
    { 258396, 258338 },    // Uber_Portal1
    { 258397, 258339 },    // Uber_Portal2
    { 258389, 258340 },    // Uber_PortalSpot0
    { 258390, 258341 },    // Uber_PortalSpot1
    { 258391, 258342 },    // Uber_PortalSpot2
    { 260286, 258736 },    // creepMob_A_MedicalCamp_Unique
    { 260290, 258760 },    // FallenGrunt_C_RescueEscort_Unique
    { 260295, 258794 },    // Skeleton_D_Fire_BlacksmithEvent_Unique
    { 260299, 258819 },    // Spawner_Ghoul_E_ClimbShort
    { 260293, 258820 },    // Ghoul_E_BlazeOfGlory_Unique
    { 260287, 258832 },    // demonTrooper_A_Reinforcements_Unique
    { 260291, 258916 },    // FleshPitFlyer_B_FarmhouseAmbush_Unique
    { 260288, 258955 },    // FallenChampion_B_PrisonersEvent_Unique
    { 260297, 259101 },    // TriuneCultist_A_VendorRescue_Unique
    { 260294, 259107 },    // Scavenger_B_MinerEvent_Unique
    { 260289, 259187 },    // FallenGrunt_A_Rakanishu_Unique
    { 260298, 259643 },    // a2dun_Aqd_Chest_Special_GreedyMiner
    { 260292, 259651 },    // Ghoul_A_NephMonument_Unique
    { 260296, 259677 },    // Triune_Berserker_B_RestlessSands_Unique
    { 260042, 259735 },    // ItemPassive_unique_ring_024_projectile
    { 260041, 259792 },    // ItemPassive_unique_ring_024_groundImpact
    { 260329, 260326 },    // Ring_norm_unique_024
    { 260363, 260330 },    // Shrine_Global_Reloaded
    { 260362, 260331 },    // Shrine_Global_Hoarder
    { 260358, 260332 },    // a4_Heaven_Shrine_Global_DemonCorrupted_Hoarder
    { 260359, 260333 },    // a4_Heaven_Shrine_Global_DemonCorrupted_Reloaded
    { 260360, 260338 },    // a4_Heaven_Shrine_Global_Hoarder
    { 260361, 260339 },    // a4_Heaven_Shrine_Global_Reloaded
    { 260822, 260377 },    // Unique_Monster_IceTrail
    { 260786, 260414 },    // Uber_Morlu_GroundBomb_Pending
    { 260807, 260429 },    // Uber_Morlu_Frozen_corpseZombie
    { 260737, 260494 },    // GoatMutant_Ranged_A_Unique_Uber_projectile
    { 260785, 260515 },    // Uber_Morlu_FrozenZombie_proxyActor
    { 260736, 260634 },    // GoatMutant_Ranged_A_Unique_Uber_impact
    { 260784, 260752 },    // Uber_Morlu_Frozen_Linger_proxyActor
    { 260956, 260880 },    // a4dun_Garden_Purification_Well_Reloaded
    { 260955, 260881 },    // a4dun_Garden_Purification_Well_Hoarder
    { 261173, 261038 },    // terrorDemon_uber_rush_domeActorHook
    { 261176, 261058 },    // infernalMachine_terrorDemon_rush_model
    { 261667, 261090 },    // DH_strafe_buff_firepool
    { 262104, 261093 },    // Uber_BossWorld2_WallTorch
    { 261411, 261097 },    // Wizard_stormArmor_proc
    { 261412, 261193 },    // Wizard_stormArmor_proc_golden
    { 261807, 261200 },    // Uber_BossWorld1_Pillar_nonBreakable
    { 261413, 261207 },    // Wizard_stormArmor_proc_indigo
    { 261414, 261221 },    // Wizard_stormArmor_proc_obsidian
    { 261806, 261258 },    // Uber_BossWorld1_Brazier_01
    { 262279, 261530 },    // FanOfKnives_Emitter
    { 261636, 261573 },    // Wizard_stormArmor_proc_alabaster
    { 261637, 261592 },    // Wizard_stormArmor_proc_crimson
    { 262278, 262185 },    // FanOfKnives_Emitter_Crimson
    { 262274, 262209 },    // FanOfKnives_Emiter_Alabaster
    { 262275, 262211 },    // FanOfKnives_Emitter_Golden
    { 262276, 262226 },    // FanOfKnives_Emitter_Obsidian
    { 262277, 262246 },    // FanOfKnives_Emitter_Indigo
    { 262785, 262576 },    // Uber_BossWorld3_SiegebreakerGate_Columns_A
    { 262786, 262614 },    // Uber_BossWorld_SiegebreakerGate_A
    { 262784, 262630 },    // Uber_BossWorld3_Siegebreaker_DestructibleColumn
    { 262904, 262789 },    // Uber_BossWorld3_Siegebreaker_DestructibleColumn_Base
    { 263081, 263014 },    // Uber_BossWorld3_st_Demon_ChainPylon_Fire_Azmodan
    { 263304, 263269 },    // GoatMutant_Ranged_Spear_Uber
    { 264049, 264037 },    // Double_Crane_a_caout_MiningEvent_Chest_MiniEvent
    { 266005, 265992 },    // Spawner_MastaBlastaRider_A
    { 272562, 272556 },    // PVP_Dueling_NPC
    { 278369, 278286 },    // UberMaghda_Punish_projectile
    { 283134, 282085 },    // Ruby_15
    { 283133, 282086 },    // Emerald_15
    { 283135, 282089 },    // Topaz_15
    { 283132, 282090 },    // Amethyst_15
    { 283103, 283091 },    // Crafting_Demonic_Reagent
    { 304613, 304566 },    // Banner_waypoint_ringGlow_partyLeader
    { 304612, 304584 },    // Banner_waypoint_partyLeaderRings
    { 306754, 306751 },    // Maghda_caOut_coals
};

constexpr size_t kNumActorSnoMappings = sizeof(s_ActorSnoMappings) / sizeof(s_ActorSnoMappings[0]);