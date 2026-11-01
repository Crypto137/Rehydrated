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

constexpr SnoMapping s_ConversationSnoMappings[] = {
    { 275335, 275484 },    // Dueling1
    { 275341, 275485 },    // Dueling2
    { 275435, 275487 },    // Dueling4
};

constexpr size_t kNumConversationSnoMappings = sizeof(s_ConversationSnoMappings) / sizeof(s_ConversationSnoMappings[0]);

constexpr SnoMapping s_EncounterSnoMappings[] = {
    { 263839, 263822 },    // a3dun_Keep_Chest_Rare_25Chance
    { 306816, 306757 },    // DuneDervish_B_Unique_Uber
    { 306817, 306758 },    // GoatMutant_Ranged_A_Unique_Uber
    { 306818, 306759 },    // morluSpellcaster_A_Unique_Uber
    { 306819, 306760 },    // TerrorDemon_A_Unique_Uber
};

constexpr size_t kNumEncounterSnoMappings = sizeof(s_EncounterSnoMappings) / sizeof(s_EncounterSnoMappings[0]);

constexpr SnoMapping s_LevelAreaSnoMappings[] = {
    { 256080, 256132 },    // Uber_BossWorld2
    { 256734, 256745 },    // Uber_BossWorld3
    { 256766, 256768 },    // Uber_BossWorld1
    { 257115, 257118 },    // Uber_PortalWorld
    { 269860, 270071 },    // DuelWorld
};

constexpr size_t kNumLevelAreaSnoMappings = sizeof(s_LevelAreaSnoMappings) / sizeof(s_LevelAreaSnoMappings[0]);

constexpr SnoMapping s_MarkerSetSnoMappings[] = {
    { 256704, 256696 },    // Uber_Skeletal_Throne
    { 256703, 256698 },    // Uber_Skeletal_Throne (Encounters)
    { 256720, 256706 },    // a3dun_Keep_Gluttony_Room (UberBoss)
    { 256747, 256730 },    // a3_Battlefield_Exit_E01_S03 (UberBoss)
    { 256746, 256732 },    // a3_Battlefield_Exit_E01_S02 (UberBoss)
    { 257563, 257199 },    // Uber_Boss_PortalWorld (Foliage)
    { 257562, 257200 },    // Uber_Boss_PortalWorld (Environment)
    { 257566, 257201 },    // Uber_Boss_PortalWorld
    { 257564, 257202 },    // Uber_Boss_PortalWorld (Lighting)
    { 257565, 257203 },    // Uber_Boss_PortalWorld (Loot)
    { 257561, 257208 },    // Uber_Boss_PortalWorld (Encounters)
    { 257639, 257608 },    // Uber_BossWorld3 (World)
    { 258023, 257970 },    // trOut_Tristram_E10_S15 (Uber Boss Event)
    { 258388, 258379 },    // trOut_Tristram_E10_S15 (No Uber Boss Event)
    { 262101, 261092 },    // Uber_BossWorld2_Areana(Lighting)
    { 261808, 261218 },    // Uber_BossWorld1_Filler_Throne_Pillar_01
    { 261809, 261260 },    // Uber_BossWorld1_Markers01
    { 262540, 262350 },    // Uber_BossWorld3_W01_S02 (Lighting)
    { 262542, 262352 },    // Uber_BossWorld3_W01_S03 (Lighting)
    { 262534, 262353 },    // Uber_BossWorld3_E01_S03 (Lighting)
    { 262532, 262354 },    // Uber_BossWorld3_E01_S02 (Lighting)
    { 262531, 262355 },    // Uber_BossWorld3_E01_S02 (Interactives)
    { 262536, 262356 },    // Uber_BossWorld3_E02_S02 (Lighting)
    { 262538, 262357 },    // Uber_BossWorld3_E02_S03 (Lighting)
    { 262539, 262358 },    // Uber_BossWorld3_W01_S02 (Audio)
    { 262533, 262359 },    // Uber_BossWorld3_E01_S03 (Audio)
    { 262530, 262360 },    // Uber_BossWorld3_E01_S02 (Audio)
    { 262535, 262361 },    // Uber_BossWorld3_E02_S02 (Audio)
    { 262537, 262362 },    // Uber_BossWorld3_E02_S03 (Audio)
    { 262541, 262363 },    // Uber_BossWorld3_W01_S03 (Audio)
    { 265350, 265285 },    // a4dun_spire_SigilRoom_D (MastaBlastaSteedRare)
    { 265349, 265316 },    // a4dun_spire_SigilRoom_C (MastaBlastaRider)
    { 279714, 279102 },    // PvP_Duel_Small_Multi_E02_S01 (Foliage)
    { 279713, 279103 },    // PvP_Duel_Small_Multi_E02_S01 (Environment)
    { 279717, 279104 },    // PvP_Duel_Small_Multi_E02_S01
    { 279719, 279105 },    // PvP_Duel_Small_Multi_E02_S02 (Foliage)
    { 279727, 279106 },    // PvP_Duel_Small_Multi_W01_N01
    { 279699, 279107 },    // PvP_Duel_Small_Multi_E01_S01 (Foliage)
    { 279698, 279108 },    // PvP_Duel_Small_Multi_E01_S01 (Environment)
    { 279718, 279109 },    // PvP_Duel_Small_Multi_E02_S02 (Environment)
    { 279722, 279110 },    // PvP_Duel_Small_Multi_E02_S02
    { 279702, 279111 },    // PvP_Duel_Small_Multi_E01_S01
    { 279729, 279112 },    // PvP_Duel_Small_Multi_W01_S01 (Foliage)
    { 279704, 279113 },    // PvP_Duel_Small_Multi_E01_S02 (Foliage)
    { 279728, 279114 },    // PvP_Duel_Small_Multi_W01_S01 (Environment)
    { 279732, 279115 },    // PvP_Duel_Small_Multi_W01_S01
    { 279703, 279116 },    // PvP_Duel_Small_Multi_E01_S02 (Environment)
    { 279709, 279117 },    // PvP_Duel_Small_Multi_E02_N01 (Foliage)
    { 279708, 279118 },    // PvP_Duel_Small_Multi_E02_N01 (Environment)
    { 279707, 279119 },    // PvP_Duel_Small_Multi_E01_S02
    { 279712, 279120 },    // PvP_Duel_Small_Multi_E02_N01
    { 279693, 279121 },    // PvP_Duel_Small_Multi_E01_N01 (Foliage)
    { 279734, 279122 },    // PvP_Duel_Small_Multi_W01_S02 (Foliage)
    { 279692, 279123 },    // PvP_Duel_Small_Multi_E01_N01 (Environment)
    { 279696, 279124 },    // PvP_Duel_Small_Multi_E01_N01
    { 279724, 279125 },    // PvP_Duel_Small_Multi_W01_N01 (Foliage)
    { 279733, 279126 },    // PvP_Duel_Small_Multi_W01_S02 (Environment)
    { 279723, 279127 },    // PvP_Duel_Small_Multi_W01_N01 (Environment)
    { 279737, 279128 },    // PvP_Duel_Small_Multi_W01_S02
    { 279720, 279129 },    // PvP_Duel_Small_Multi_E02_S02 (Lighting)
    { 279721, 279130 },    // PvP_Duel_Small_Multi_E02_S02 (Loot)
    { 279705, 279132 },    // PvP_Duel_Small_Multi_E01_S02 (Lighting)
    { 279706, 279133 },    // PvP_Duel_Small_Multi_E01_S02 (Loot)
    { 279735, 279135 },    // PvP_Duel_Small_Multi_W01_S02 (Lighting)
    { 279736, 279136 },    // PvP_Duel_Small_Multi_W01_S02 (Loot)
    { 279700, 279138 },    // PvP_Duel_Small_Multi_E01_S01 (Lighting)
    { 279701, 279139 },    // PvP_Duel_Small_Multi_E01_S01 (Loot)
    { 279730, 279141 },    // PvP_Duel_Small_Multi_W01_S01 (Lighting)
    { 279731, 279142 },    // PvP_Duel_Small_Multi_W01_S01 (Loot)
    { 279710, 279144 },    // PvP_Duel_Small_Multi_E02_N01 (Lighting)
    { 279711, 279145 },    // PvP_Duel_Small_Multi_E02_N01 (Loot)
    { 279694, 279147 },    // PvP_Duel_Small_Multi_E01_N01 (Lighting)
    { 279695, 279148 },    // PvP_Duel_Small_Multi_E01_N01 (Loot)
    { 279725, 279150 },    // PvP_Duel_Small_Multi_W01_N01 (Lighting)
    { 279726, 279151 },    // PvP_Duel_Small_Multi_W01_N01 (Loot)
    { 279715, 279153 },    // PvP_Duel_Small_Multi_E02_S01 (Lighting)
    { 279716, 279154 },    // PvP_Duel_Small_Multi_E02_S01 (Loot)
    { 279697, 279442 },    // PvP_Duel_Small_Multi_E01_S01 (Encounters)
    { 317391, 283392 },    // PvP_Duel_Small_Multi_E01_S01 (Audio)
};

constexpr size_t kNumMarkerSetSnoMappings = sizeof(s_MarkerSetSnoMappings) / sizeof(s_MarkerSetSnoMappings[0]);

constexpr SnoMapping s_MonsterSnoMappings[] = {
    { 256135, 255931 },    // Uber_SkeletonKingRed
    { 256009, 255997 },    // GoatMutant_Ranged_A_Unique_Uber
    { 256031, 256001 },    // DuneDervish_B_Unique_Uber
    { 256050, 256016 },    // MorluSpellcaster_A_Unique_Uber
    { 256065, 256035 },    // TerrorDemon_A_Unique_Uber
    { 256579, 256188 },    // Uber_SiegebreakerDemon
    { 256578, 256190 },    // Uber_Maghda
    { 256580, 256509 },    // Uber_ZoltunKulle
    { 256722, 256710 },    // Uber_Gluttony
    { 256721, 256712 },    // Uber_Despair
    { 257963, 257927 },    // Uber_SoulRipper_Despair
    { 257961, 257931 },    // Uber_Berserker_MaghdaPet
    { 257962, 257936 },    // Uber_Gluttony_acidSlime
    { 260274, 258737 },    // creepMob_A_MedicalCamp_Unique
    { 260278, 258761 },    // FallenGrunt_C_RescueEscort_Unique
    { 260283, 258795 },    // Skeleton_D_Fire_BlacksmithEvent_Unique
    { 260281, 258821 },    // Ghoul_E_BlazeOfGlory_Unique
    { 260275, 258833 },    // demonTrooper_A_Reinforcements_Unique
    { 260279, 258917 },    // FleshPitFlyer_B_FarmhouseAmbush_Unique
    { 260276, 258956 },    // FallenChampion_B_PrisonersEvent_Unique
    { 260285, 259102 },    // TriuneCultist_A_VendorRescue_Unique
    { 260282, 259118 },    // Scavenger_B_MinerEvent_Unique
    { 260277, 259188 },    // FallenGrunt_A_Rakanishu_Unique
    { 260280, 259652 },    // Ghoul_A_NephMonument_Unique
    { 260284, 259678 },    // Triune_Berserker_B_RestlessSands_Unique
    { 262126, 262117 },    // DH_Companion_Melee_Boar
    { 262128, 262118 },    // DH_Companion_Melee_Wolf
    { 262127, 262119 },    // DH_Companion_Melee_Spider
    { 275527, 275524 },    // PvP_Dueling_NPC
};

constexpr size_t kNumMonsterSnoMappings = sizeof(s_MonsterSnoMappings) / sizeof(s_MonsterSnoMappings[0]);

constexpr SnoMapping s_PowerSnoMappings[] = {
    { 255360, 255297 },    // BugWingsBuff
    { 256136, 255937 },    // Uber_SkeletonKing_Summon_Skeleton
    { 256032, 256010 },    // Dervish_Whirlwind_Mortar_Prototype
    { 256051, 256021 },    // MorluSpellcaster_Meteor_GraspOfTheDead_Prototype
    { 256067, 256038 },    // Unique_Monster_TempestRush_Prototype
    { 256066, 256039 },    // Unique_Monster_Earthquake_Prototype
    { 257043, 256797 },    // PandemoniumPortal
    { 257587, 257585 },    // ItemPassive_Unique_Ring_024
    { 257641, 257635 },    // Templar_Heal_110
    { 257688, 257664 },    // Enchantress_MissileWard
    { 257964, 257925 },    // Uber_Despair_SummonMinion
    { 257966, 257929 },    // Uber_Maghda_Summon_Beserker
    { 257965, 257934 },    // Uber_Gluttony_Loogiespawn
    { 258200, 258083 },    // Multiplayer_Buff
    { 258645, 258591 },    // Uber_SkeletonKing_Whirlwind
    { 258644, 258593 },    // Uber_SkeletonKing_Cleave
    { 258646, 258603 },    // Uber_ZoltunKulle_Teleport
    { 258643, 258604 },    // Uber_SiegebreakerDemon_Stomp
    { 259852, 259759 },    // IdentifyWithCastLegendary
    { 259954, 259858 },    // Uber_SiegebreakerDemon_Pound
    { 259955, 259920 },    // Uber_ZoltunKulle_SlowTime
    { 260365, 260152 },    // Shrine_Desecrated_Reloaded
    { 260364, 260315 },    // Shrine_Desecrated_Hoarder
    { 260825, 260375 },    // Unique_Monster_IceTrail_Passive_Prototype
    { 260507, 260479 },    // GoatMutant_Ranged_A_Unique_Uber_Projectile
    { 260597, 260589 },    // TreasureGoblin_PlayAlertSound
    { 260871, 260749 },    // Uber_ZoltunKulle_CollapseCeiling
    { 260872, 260750 },    // Uber_ZoltunKulle_EnergyTwister
    { 260873, 260751 },    // Uber_ZoltunKulle_FieryBoulder
    { 260870, 260759 },    // Uber_Siegebreaker_Enrage
    { 260869, 260836 },    // Uber_Gluttony_Gas_Cloud
    { 260868, 260837 },    // Uber_Gluttony_Breath_Attack
    { 260865, 260839 },    // Uber_Despair_Teleport
    { 260864, 260840 },    // Uber_Despair_Melee_Cleave
    { 260866, 260841 },    // Uber_Despair_TeleportEnrage
    { 260867, 260842 },    // Uber_Despair_Volley
    { 260929, 260879 },    // Uber_Maghda_Shield
    { 260980, 260970 },    // Uber_Maghda_Punish
    { 260981, 260971 },    // Uber_Maghda_Punish_Shielded
    { 262448, 262402 },    // Uber_Maghda_Punish_Enrage
    { 263043, 263031 },    // Weapon_Melee_Instant_ShortEscape
    { 263305, 263270 },    // GoatMutant_Ranged_Projectile_uber
    { 263418, 263412 },    // MorluSpellcaster_BreathOfFrost
    { 264189, 263957 },    // MonsterAffix_IllusionistCast
    { 270075, 269869 },    // DuelBuff
    { 275137, 275046 },    // DuelDefeatBuff
    { 278370, 278297 },    // Uber_Maghda_MothDust
    { 285774, 285745 },    // MonsterAffix_ReflectsDamageCast
    { 290887, 289337 },    // Teleport_CheckPath_Passability
    { 293995, 293726 },    // IdentifyAllWithCast
    { 308829, 308189 },    // Witchdoctor_Gargantuan_PoisonCloud
    { 309102, 309004 },    // Witchdoctor_ZombieDog_FireAoE
    { 310073, 309415 },    // Witchdoctor_ZombieDog_PoisonDoT
};

constexpr size_t kNumPowerSnoMappings = sizeof(s_PowerSnoMappings) / sizeof(s_PowerSnoMappings[0]);

constexpr SnoMapping s_SceneSnoMappings[] = {
    { 256705, 256695 },    // Uber_Skeletal_Throne
    { 257211, 257179 },    // Uber_BossWorld2_Arena
    { 257567, 257204 },    // Uber_Boss_PortalWorld
    { 258159, 258127 },    // Uber_BossWorld3_E01_S03
    { 258158, 258128 },    // Uber_BossWorld3_E01_S02
    { 258162, 258135 },    // Uber_BossWorld3_W01_S02
    { 258160, 258136 },    // Uber_BossWorld3_E02_S02
    { 258163, 258137 },    // Uber_BossWorld3_W01_S03
    { 258161, 258139 },    // Uber_BossWorld3_E02_S03
    { 258157, 258140 },    // Uber_BossWorld3_E01_S01
    { 261811, 261217 },    // Uber_BossWorld1_Filler_Throne_Pillar_01
    { 263213, 263208 },    // a3dun_Keep_Gluttony_Hall_01_Uber
    { 279744, 279131 },    // PvP_Duel_Small_Multi_E02_S02
    { 279741, 279134 },    // PvP_Duel_Small_Multi_E01_S02
    { 279747, 279137 },    // PvP_Duel_Small_Multi_W01_S02
    { 279740, 279140 },    // PvP_Duel_Small_Multi_E01_S01
    { 279746, 279143 },    // PvP_Duel_Small_Multi_W01_S01
    { 279742, 279146 },    // PvP_Duel_Small_Multi_E02_N01
    { 279739, 279149 },    // PvP_Duel_Small_Multi_E01_N01
    { 279745, 279152 },    // PvP_Duel_Small_Multi_W01_N01
    { 279743, 279155 },    // PvP_Duel_Small_Multi_E02_S01
};

constexpr size_t kNumSceneSnoMappings = sizeof(s_SceneSnoMappings) / sizeof(s_SceneSnoMappings[0]);

constexpr SnoMapping s_StringListSnoMappings[] = {
    { 255912, 255909 },    // PvPLoadscreenTips
    { 261007, 260990 },    // Mail
    { 261485, 261481 },    // ColorPicker
    { 275497, 275336 },    // Conv_Dueling1
    { 275498, 275342 },    // Conv_Dueling2
    { 275500, 275436 },    // Conv_Dueling4
};

constexpr size_t kNumStringListSnoMappings = sizeof(s_StringListSnoMappings) / sizeof(s_StringListSnoMappings[0]);

constexpr SnoMapping s_WeatherSnoMappings[] = {
    { 257175, 257163 },    // Uber_BossWorld2
    { 257571, 257205 },    // Uber_Boss_PortalWorld
    { 263082, 263067 },    // Uber_BossWorld2_Sun
    { 263512, 263495 },    // Uber_BossWorld1_B
    { 317463, 282301 },    // PvP_GraveYard_Weather
};

constexpr size_t kNumWeatherSnoMappings = sizeof(s_WeatherSnoMappings) / sizeof(s_WeatherSnoMappings[0]);

constexpr SnoMapping s_WorldSnoMappings[] = {
    { 256072, 256137 },    // Uber_BossWorld1
    { 256078, 256138 },    // Uber_BossWorld2
    { 256592, 256600 },    // Uber_BossWorld3
    { 257114, 257119 },    // Uber_PortalWorld
    { 275156, 275194 },    // PvP_Duel_Small
};

constexpr size_t kNumWorldSnoMappings = sizeof(s_WorldSnoMappings) / sizeof(s_WorldSnoMappings[0]);

constexpr SnoMapping s_RecipeSnoMappings[] = {
    { 255903, 255827 },    // Smith_RedPortalDevice
    { 255901, 255828 },    // Jeweler_ShardRing_Red
    { 255899, 255829 },    // Jeweler_ShardRing_Green
    { 255900, 255831 },    // Jeweler_ShardRing_Purple
    { 255902, 255838 },    // Jeweler_ShardRing_Yellow
    { 255993, 255982 },    // Convert_Tier_02_Tier_03_Smith
    { 255995, 255983 },    // Convert_Tier_03_Tier_04_Smith
    { 255992, 255984 },    // Convert_Tier_02_Tier_03_Jeweler
    { 255994, 255985 },    // Convert_Tier_03_Tier_04_Jeweler
    { 283136, 283087 },    // GemCombine_Amethyst_14_15
    { 283137, 283088 },    // GemCombine_Emerald_14_15
    { 283138, 283089 },    // GemCombine_Ruby_14_15
    { 283139, 283090 },    // GemCombine_Topaz_14_15
    { 283237, 283140 },    // T11_Armor_Gloves_Str
    { 283235, 283141 },    // T11_Armor_Gloves_Dex
    { 283236, 283142 },    // T11_Armor_Gloves_Int
    { 283238, 283143 },    // T11_Armor_Gloves_Vit
    { 283241, 283144 },    // T11_Armor_Shoulders_Str
    { 283239, 283145 },    // T11_Armor_Shoulders_Dex
    { 283240, 283146 },    // T11_Armor_Shoulders_Int
    { 283242, 283147 },    // T11_Armor_Shoulders_Vit
    { 283233, 283148 },    // T11_Armor_Chest_Str
    { 283231, 283149 },    // T11_Armor_Chest_Dex
    { 283232, 283150 },    // T11_Armor_Chest_Int
    { 283234, 283151 },    // T11_Armor_Chest_Vit
    { 283229, 283152 },    // T11_Armor_Bracers_Str
    { 283227, 283153 },    // T11_Armor_Bracers_Dex
    { 283228, 283154 },    // T11_Armor_Bracers_Int
    { 283230, 283155 },    // T11_Armor_Bracers_Vit
    { 283223, 283167 },    // T11_Amulet_Dex
    { 283224, 283168 },    // T11_Amulet_Int
    { 283225, 283169 },    // T11_Amulet_Str
    { 283226, 283170 },    // T11_Amulet_Vit
};

constexpr size_t kNumRecipeSnoMappings = sizeof(s_RecipeSnoMappings) / sizeof(s_RecipeSnoMappings[0]);

constexpr SnoMapping s_ConditionSnoMappings[] = {
    { 260574, 260445 },    // MonsterPowerLevelOne
    { 260579, 260446 },    // MonsterPowerLevelTwo
    { 260578, 260447 },    // MonsterPowerLevelThree
    { 260572, 260448 },    // MonsterPowerLevelFour
    { 260571, 260449 },    // MonsterPowerLevelFive
    { 260576, 260450 },    // MonsterPowerLevelSix
    { 260575, 260451 },    // MonsterPowerLevelSeven
    { 260570, 260452 },    // MonsterPowerLevelEight
    { 260573, 260453 },    // MonsterPowerLevelNine
    { 260577, 260454 },    // MonsterPowerLevelTen
    { 260580, 260455 },    // MonsterPowerLevelZero
};

constexpr size_t kNumConditionSnoMappings = sizeof(s_ConditionSnoMappings) / sizeof(s_ConditionSnoMappings[0]);

constexpr SnoMapping s_QuestRangeSnoMappings[] = {
    { 258387, 258358 },    // A1_Uber_BossQuestRange
    { 258629, 258626 },    // AzmodanBreach
    { 258634, 258631 },    // A3-Cold
    { 263287, 263273 },    // Uber_NoPortalRoomAllowed
    { 263288, 263282 },    // Uber_PortalRoomAllowed
    { 305610, 305589 },    // A3_InnStart_Quest_Location
};

constexpr size_t kNumQuestRangeSnoMappings = sizeof(s_QuestRangeSnoMappings) / sizeof(s_QuestRangeSnoMappings[0]);

constexpr SnoMapping s_MusicSnoMappings[] = {
    { 259791, 259691 },    // Music_Ax_UberPortalCellar_int
};

constexpr size_t kNumMusicSnoMappings = sizeof(s_MusicSnoMappings) / sizeof(s_MusicSnoMappings[0]);

constexpr SnoMapping s_BossEncounterSnoMappings[] = {
    { 258238, 258172 },    // Uber_Portal0
    { 258239, 258184 },    // Uber_Portal1
    { 258240, 258185 },    // Uber_Portal2
};

constexpr size_t kNumBossEncounterSnoMappings = sizeof(s_BossEncounterSnoMappings) / sizeof(s_BossEncounterSnoMappings[0]);

static inline void GetSnoMappings(SNOGroup snoGroup, const SnoMapping*& mappings, size_t& count)
{
    switch (snoGroup)
    {
        case ACTOR_SNO:
            mappings = s_ActorSnoMappings;
            count = kNumActorSnoMappings;
            break;

        case CONVERSATION_SNO:
            mappings = s_ConversationSnoMappings;
            count = kNumConversationSnoMappings;
            break;

        case ENCOUNTER_SNO:
            mappings = s_EncounterSnoMappings;
            count = kNumEncounterSnoMappings;
            break;

        case LEVELAREA_SNO:
            mappings = s_LevelAreaSnoMappings;
            count = kNumLevelAreaSnoMappings;
            break;
        
        case MARKERSET_SNO:
            mappings = s_MarkerSetSnoMappings;
            count = kNumMarkerSetSnoMappings;
            break;

        case MONSTER_SNO:
            mappings = s_MonsterSnoMappings;
            count = kNumMonsterSnoMappings;
            break;

        case POWER_SNO:
            mappings = s_PowerSnoMappings;
            count = kNumPowerSnoMappings;
            break;

        case SCENE_SNO:
            mappings = s_SceneSnoMappings;
            count = kNumSceneSnoMappings;
            break;

        case STRINGLIST_SNO:
            mappings = s_StringListSnoMappings;
            count = kNumStringListSnoMappings;
            break;

        case WEATHER_SNO:
            mappings = s_WeatherSnoMappings;
            count = kNumWeatherSnoMappings;
            break;

        case WORLD_SNO:
            mappings = s_WorldSnoMappings;
            count = kNumWorldSnoMappings;
            break;

        case RECIPE_SNO:
            mappings = s_RecipeSnoMappings;
            count = kNumRecipeSnoMappings;
            break;

        case CONDITION_SNO:
            mappings = s_ConditionSnoMappings;
            count = kNumConditionSnoMappings;
            break;

        case QUESTRANGE_SNO:
            mappings = s_QuestRangeSnoMappings;
            count = kNumQuestRangeSnoMappings;
            break;

        case MUSIC_SNO:
            mappings = s_MusicSnoMappings;
            count = kNumMusicSnoMappings;            
            break;

        case BOSS_ENCOUNTER_SNO:
            mappings = s_BossEncounterSnoMappings;
            count = kNumBossEncounterSnoMappings;
            break;

        default:
            mappings = nullptr;
            count = 0;
            break;
    }
}
