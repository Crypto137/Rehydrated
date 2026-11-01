#pragma once

#include "game/types.h"

// GBID are lowercase hashes of names, so renaming a table row causes a GBID change.
// Many item and affix rows got the 1xx prefix/suffix added to their name on consoles,
// most likely to differentiate them from RoS Loot 2.0 items/affixes that were being made.
// When possible, we map GBIDs to the direct equivalents.

// In addition to this, the console port added higher tiers for existing affixes.
// We handle these by clamping them to highest tier available on PC.

// Some new legendary affixes were introduces on consoles. We map them to -1 (no affix).

// A unified health potion that heals for a percentage value was introduced on consoles.
// We map it to the lowest level PC potion to keep it usable at level 1.

struct GbidMapping
{
    GBID gbidConsole;
    GBID gbidPC;
};

constexpr GbidMapping s_ItemGbidMappings[] = {
    { 0x804E2322, 0x622256D4 },    // HealthPotionConsole -> HealthPotionMinor

    { 0xBBD98ACE, 0x18908B6E },    // Unique_Amulet_001_1xx -> Unique_Amulet_001
    { 0xBBEBA34F, 0x18908B6F },    // Unique_Amulet_002_1xx -> Unique_Amulet_002
    { 0xBBFDBBD0, 0x18908B70 },    // Unique_Amulet_003_1xx -> Unique_Amulet_003
    { 0xBC0FD451, 0x18908B71 },    // Unique_Amulet_004_1xx -> Unique_Amulet_004
    { 0xBC21ECD2, 0x18908B72 },    // Unique_Amulet_005_1xx -> Unique_Amulet_005
    { 0xBC340553, 0x18908B73 },    // Unique_Amulet_006_1xx -> Unique_Amulet_006
    { 0xBC461DD4, 0x18908B74 },    // Unique_Amulet_007_1xx -> Unique_Amulet_007
    { 0xBC583655, 0x18908B75 },    // Unique_Amulet_008_1xx -> Unique_Amulet_008
    { 0xBC6A4ED6, 0x18908B76 },    // Unique_Amulet_009_1xx -> Unique_Amulet_009
    { 0xBE1C9AEE, 0x18908B8E },    // Unique_Amulet_010_1xx -> Unique_Amulet_010
    { 0xBE2EB36F, 0x18908B8F },    // Unique_Amulet_011_1xx -> Unique_Amulet_011
    { 0xBE40CBF0, 0x18908B90 },    // Unique_Amulet_012_1xx -> Unique_Amulet_012
    { 0xBE52E471, 0x18908B91 },    // Unique_Amulet_013_1xx -> Unique_Amulet_013
    { 0xBE64FCF2, 0x18908B92 },    // Unique_Amulet_014_1xx -> Unique_Amulet_014
    { 0xBE771573, 0x18908B93 },    // Unique_Amulet_015_1xx -> Unique_Amulet_015
    { 0xBE892DF4, 0x18908B94 },    // Unique_Amulet_016_1xx -> Unique_Amulet_016
    { 0x0809223C, 0xF2F19BDC },    // Unique_Axe_1H_001_1xx -> Unique_Axe_1H_001
    { 0x082D533E, 0xF2F19BDE },    // Unique_Axe_1H_003_1xx -> Unique_Axe_1H_003
    { 0x083F6BBF, 0xF2F19BDF },    // Unique_Axe_1H_004_1xx -> Unique_Axe_1H_004
    { 0x08518440, 0xF2F19BE0 },    // Unique_Axe_1H_005_1xx -> Unique_Axe_1H_005
    { 0x08639CC1, 0xF2F19BE1 },    // Unique_Axe_1H_006_1xx -> Unique_Axe_1H_006
    { 0x0875B542, 0xF2F19BE2 },    // Unique_Axe_1H_007_1xx -> Unique_Axe_1H_007
    { 0x0A827BDF, 0xF2F19BFF },    // Unique_Axe_1H_013_1xx -> Unique_Axe_1H_013
    { 0x0C13B35D, 0xF546C47D },    // Unique_Axe_2H_001_1xx -> Unique_Axe_2H_001
    { 0x0C37E45F, 0xF546C47F },    // Unique_Axe_2H_003_1xx -> Unique_Axe_2H_003
    { 0x0CA47765, 0xF546C485 },    // Unique_Axe_2H_009_1xx -> Unique_Axe_2H_009
    { 0x0E56C37D, 0xF546C49D },    // Unique_Axe_2H_010_1xx -> Unique_Axe_2H_010
    { 0x0E68DBFE, 0xF546C49E },    // Unique_Axe_2H_011_1xx -> Unique_Axe_2H_011
    { 0x1985A6A4, 0xB24C2C44 },    // Unique_BarbBelt_001_1xx -> Unique_BarbBelt_001
    { 0x1997BF25, 0xB24C2C45 },    // Unique_BarbBelt_002_1xx -> Unique_BarbBelt_002
    { 0x19A9D7A6, 0xB24C2C46 },    // Unique_BarbBelt_003_1xx -> Unique_BarbBelt_003
    { 0x19BBF027, 0xB24C2C47 },    // Unique_BarbBelt_004_1xx -> Unique_BarbBelt_004
    { 0x19CE08A8, 0xB24C2C48 },    // Unique_BarbBelt_005_1xx -> Unique_BarbBelt_005
    { 0x19E02129, 0xB24C2C49 },    // Unique_BarbBelt_006_1xx -> Unique_BarbBelt_006
    { 0x19F239AA, 0xB24C2C4A },    // Unique_BarbBelt_007_1xx -> Unique_BarbBelt_007
    { 0x1A04522B, 0xB24C2C4B },    // Unique_BarbBelt_008_1xx -> Unique_BarbBelt_008
    { 0x1A166AAC, 0xB24C2C4C },    // Unique_BarbBelt_009_1xx -> Unique_BarbBelt_009
    { 0x9AF9984D, 0xD89FB16D },    // Unique_Belt_001_1xx -> Unique_Belt_001
    { 0x9B0BB0CE, 0xD89FB16E },    // Unique_Belt_002_1xx -> Unique_Belt_002
    { 0x9B1DC94F, 0xD89FB16F },    // Unique_Belt_003_1xx -> Unique_Belt_003
    { 0x9B2FE1D0, 0xD89FB170 },    // Unique_Belt_004_1xx -> Unique_Belt_004
    { 0x9B41FA51, 0xD89FB171 },    // Unique_Belt_005_1xx -> Unique_Belt_005
    { 0x9B5412D2, 0xD89FB172 },    // Unique_Belt_006_1xx -> Unique_Belt_006
    { 0x9B662B53, 0xD89FB173 },    // Unique_Belt_007_1xx -> Unique_Belt_007
    { 0x9B7843D4, 0xD89FB174 },    // Unique_Belt_008_1xx -> Unique_Belt_008
    { 0x9B8A5C55, 0xD89FB175 },    // Unique_Belt_009_1xx -> Unique_Belt_009
    { 0x9D3CA86D, 0xD89FB18D },    // Unique_Belt_010_1xx -> Unique_Belt_010
    { 0x9D60D96F, 0xD89FB18F },    // Unique_Belt_012_1xx -> Unique_Belt_012
    { 0x9D72F1F0, 0xD89FB190 },    // Unique_Belt_013_1xx -> Unique_Belt_013
    { 0x9D850A71, 0xD89FB191 },    // Unique_Belt_014_1xx -> Unique_Belt_014
    { 0x9D9722F2, 0xD89FB192 },    // Unique_Belt_015_1xx -> Unique_Belt_015
    { 0xE815CCED, 0x0F9A960D },    // Unique_Boots_001_1xx -> Unique_Boots_001
    { 0xE85E2EF1, 0x0F9A9611 },    // Unique_Boots_005_1xx -> Unique_Boots_005
    { 0xE8825FF3, 0x0F9A9613 },    // Unique_Boots_007_1xx -> Unique_Boots_007
    { 0xE8947874, 0x0F9A9614 },    // Unique_Boots_008_1xx -> Unique_Boots_008
    { 0xE8A690F5, 0x0F9A9615 },    // Unique_Boots_009_1xx -> Unique_Boots_009
    { 0xEA58DD0D, 0x0F9A962D },    // Unique_Boots_010_1xx -> Unique_Boots_010
    { 0xEA6AF58E, 0x0F9A962E },    // Unique_Boots_011_1xx -> Unique_Boots_011
    { 0xEA7D0E0F, 0x0F9A962F },    // Unique_Boots_012_1xx -> Unique_Boots_012
    { 0xEA8F2690, 0x0F9A9630 },    // Unique_Boots_013_1xx -> Unique_Boots_013
    { 0xEAA13F11, 0x0F9A9631 },    // Unique_Boots_014_1xx -> Unique_Boots_014
    { 0xEAB35792, 0x0F9A9632 },    // Unique_Boots_015_1xx -> Unique_Boots_015
    { 0xEAD78894, 0x0F9A9634 },    // Unique_Boots_017_1xx -> Unique_Boots_017
    { 0xEAE9A115, 0x0F9A9635 },    // Unique_Boots_018_1xx -> Unique_Boots_018
    { 0xEAFBB996, 0x0F9A9636 },    // Unique_Boots_019_1xx -> Unique_Boots_019
    { 0x1020F10E, 0x1E9ED1AE },    // Unique_Bow_001_1xx -> Unique_Bow_001
    { 0x10695312, 0x1E9ED1B2 },    // Unique_Bow_005_1xx -> Unique_Bow_005
    { 0x108D8414, 0x1E9ED1B4 },    // Unique_Bow_007_1xx -> Unique_Bow_007
    { 0x109F9C95, 0x1E9ED1B5 },    // Unique_Bow_008_1xx -> Unique_Bow_008
    { 0x10B1B516, 0x1E9ED1B6 },    // Unique_Bow_009_1xx -> Unique_Bow_009
    { 0x1264012E, 0x1E9ED1CE },    // Unique_Bow_010_1xx -> Unique_Bow_010
    { 0x12BE7BB3, 0x1E9ED1D3 },    // Unique_Bow_015_1xx -> Unique_Bow_015
    { 0x17B66715, 0x38F45C35 },    // Unique_Bracer_001_1xx -> Unique_Bracer_001
    { 0x17C87F96, 0x38F45C36 },    // Unique_Bracer_002_1xx -> Unique_Bracer_002
    { 0x17DA9817, 0x38F45C37 },    // Unique_Bracer_003_1xx -> Unique_Bracer_003
    { 0x17ECB098, 0x38F45C38 },    // Unique_Bracer_004_1xx -> Unique_Bracer_004
    { 0x17FEC919, 0x38F45C39 },    // Unique_Bracer_005_1xx -> Unique_Bracer_005
    { 0x1810E19A, 0x38F45C3A },    // Unique_Bracer_006_1xx -> Unique_Bracer_006
    { 0x1822FA1B, 0x38F45C3B },    // Unique_Bracer_007_1xx -> Unique_Bracer_007
    { 0x18472B1D, 0x38F45C3D },    // Unique_Bracer_009_1xx -> Unique_Bracer_009
    { 0x19F97735, 0x38F45C55 },    // Unique_Bracer_010_1xx -> Unique_Bracer_010
    { 0x1A0B8FB6, 0x38F45C56 },    // Unique_Bracer_011_1xx -> Unique_Bracer_011
    { 0xB5E95F0F, 0x1786672F },    // Unique_CeremonialDagger_001_1xx -> Unique_CeremonialDagger_001
    { 0xB5FB7790, 0x17866730 },    // Unique_CeremonialDagger_002_1xx -> Unique_CeremonialDagger_002
    { 0xB60D9011, 0x17866731 },    // Unique_CeremonialDagger_003_1xx -> Unique_CeremonialDagger_003
    { 0xB61FA892, 0x17866732 },    // Unique_CeremonialDagger_004_1xx -> Unique_CeremonialDagger_004
    { 0xB643D994, 0x17866734 },    // Unique_CeremonialDagger_006_1xx -> Unique_CeremonialDagger_006
    { 0xB6680A96, 0x17866736 },    // Unique_CeremonialDagger_008_1xx -> Unique_CeremonialDagger_008
    { 0xB67A2317, 0x17866737 },    // Unique_CeremonialDagger_009_1xx -> Unique_CeremonialDagger_009
    { 0xB83E87B0, 0x17866750 },    // Unique_CeremonialDagger_011_1xx -> Unique_CeremonialDagger_011
    { 0x1D257087, 0x4B447CA7 },    // Unique_ChestArmor_028_1xx -> Unique_ChestArmor_028
    { 0x1BA0141D, 0x0A40C53D },    // Unique_Chest_001_1xx -> Unique_Chest_001
    { 0x1BB22C9E, 0x0A40C53E },    // Unique_Chest_002_1xx -> Unique_Chest_002
    { 0x1BFA8EA2, 0x0A40C542 },    // Unique_Chest_006_1xx -> Unique_Chest_006
    { 0x1DE3243D, 0x0A40C55D },    // Unique_Chest_010_1xx -> Unique_Chest_010
    { 0x1E07553F, 0x0A40C55F },    // Unique_Chest_012_1xx -> Unique_Chest_012
    { 0x1E196DC0, 0x0A40C560 },    // Unique_Chest_013_1xx -> Unique_Chest_013
    { 0x1E2B8641, 0x0A40C561 },    // Unique_Chest_014_1xx -> Unique_Chest_014
    { 0x1E3D9EC2, 0x0A40C562 },    // Unique_Chest_015_1xx -> Unique_Chest_015
    { 0x1E4FB743, 0x0A40C563 },    // Unique_Chest_016_1xx -> Unique_Chest_016
    { 0x1E73E845, 0x0A40C565 },    // Unique_Chest_018_1xx -> Unique_Chest_018
    { 0x1E8600C6, 0x0A40C566 },    // Unique_Chest_019_1xx -> Unique_Chest_019
    { 0x2092C763, 0x0A40C583 },    // Unique_Chest_025_1xx -> Unique_Chest_025
    { 0x20A4DFE4, 0x0A40C584 },    // Unique_Chest_026_1xx -> Unique_Chest_026
    { 0x20B6F865, 0x0A40C585 },    // Unique_Chest_027_1xx -> Unique_Chest_027
    { 0xB3EE70D0, 0x926EC070 },    // Unique_Cloak_001_1xx -> Unique_Cloak_001
    { 0xB4008951, 0x926EC071 },    // Unique_Cloak_002_1xx -> Unique_Cloak_002
    { 0xB436D2D4, 0x926EC074 },    // Unique_Cloak_005_1xx -> Unique_Cloak_005
    { 0xB448EB55, 0x926EC075 },    // Unique_Cloak_006_1xx -> Unique_Cloak_006
    { 0x6DF93089, 0xEC848BA9 },    // Unique_CombatStaff_2H_001_1xx -> Unique_CombatStaff_2H_001
    { 0x6E0B490A, 0xEC848BAA },    // Unique_CombatStaff_2H_002_1xx -> Unique_CombatStaff_2H_002
    { 0x6E1D618B, 0xEC848BAB },    // Unique_CombatStaff_2H_003_1xx -> Unique_CombatStaff_2H_003
    { 0x6E2F7A0C, 0xEC848BAC },    // Unique_CombatStaff_2H_004_1xx -> Unique_CombatStaff_2H_004
    { 0x6E41928D, 0xEC848BAD },    // Unique_CombatStaff_2H_005_1xx -> Unique_CombatStaff_2H_005
    { 0x6E65C38F, 0xEC848BAF },    // Unique_CombatStaff_2H_007_1xx -> Unique_CombatStaff_2H_007
    { 0x6E77DC10, 0xEC848BB0 },    // Unique_CombatStaff_2H_008_1xx -> Unique_CombatStaff_2H_008
    { 0x6E89F491, 0xEC848BB1 },    // Unique_CombatStaff_2H_009_1xx -> Unique_CombatStaff_2H_009
    { 0x84205691, 0x4239EDB1 },    // Unique_Dagger_002_1xx -> Unique_Dagger_002
    { 0x84326F12, 0x4239EDB2 },    // Unique_Dagger_003_1xx -> Unique_Dagger_003
    { 0x8468B895, 0x4239EDB5 },    // Unique_Dagger_006_1xx -> Unique_Dagger_006
    { 0x847AD116, 0x4239EDB6 },    // Unique_Dagger_007_1xx -> Unique_Dagger_007
    { 0x848CE997, 0x4239EDB7 },    // Unique_Dagger_008_1xx -> Unique_Dagger_008
    { 0x86514E30, 0x4239EDD0 },    // Unique_Dagger_010_1xx -> Unique_Dagger_010
    { 0x90A80BBE, 0xCDE4145E },    // Unique_Fist_003_1xx -> Unique_Fist_003
    { 0x90BA243F, 0xCDE4145F },    // Unique_Fist_004_1xx -> Unique_Fist_004
    { 0x90CC3CC0, 0xCDE41460 },    // Unique_Fist_005_1xx -> Unique_Fist_005
    { 0x90DE5541, 0xCDE41461 },    // Unique_Fist_006_1xx -> Unique_Fist_006
    { 0x90F06DC2, 0xCDE41462 },    // Unique_Fist_007_1xx -> Unique_Fist_007
    { 0x91028643, 0xCDE41463 },    // Unique_Fist_008_1xx -> Unique_Fist_008
    { 0x91149EC4, 0xCDE41464 },    // Unique_Fist_009_1xx -> Unique_Fist_009
    { 0x92C6EADC, 0xCDE4147C },    // Unique_Fist_010_1xx -> Unique_Fist_010
    { 0x92D9035D, 0xCDE4147D },    // Unique_Fist_011_1xx -> Unique_Fist_011
    { 0x92EB1BDE, 0xCDE4147E },    // Unique_Fist_012_1xx -> Unique_Fist_012
    { 0x92FD345F, 0xCDE4147F },    // Unique_Fist_013_1xx -> Unique_Fist_013
    { 0x93216561, 0xCDE41481 },    // Unique_Fist_015_1xx -> Unique_Fist_015
    { 0x6B6A4E56, 0x347CCAF6 },    // Unique_Gloves_001_1xx -> Unique_Gloves_001
    { 0x6B7C66D7, 0x347CCAF7 },    // Unique_Gloves_002_1xx -> Unique_Gloves_002
    { 0x6B8E7F58, 0x347CCAF8 },    // Unique_Gloves_003_1xx -> Unique_Gloves_003
    { 0x6BD6E15C, 0x347CCAFC },    // Unique_Gloves_007_1xx -> Unique_Gloves_007
    { 0x6BE8F9DD, 0x347CCAFD },    // Unique_Gloves_008_1xx -> Unique_Gloves_008
    { 0x6BFB125E, 0x347CCAFE },    // Unique_Gloves_009_1xx -> Unique_Gloves_009
    { 0x6DBF76F7, 0x347CCB17 },    // Unique_Gloves_011_1xx -> Unique_Gloves_011
    { 0x6DF5C07A, 0x347CCB1A },    // Unique_Gloves_014_1xx -> Unique_Gloves_014
    { 0x6E07D8FB, 0x347CCB1B },    // Unique_Gloves_015_1xx -> Unique_Gloves_015
    { 0x6E2C09FD, 0x347CCB1D },    // Unique_Gloves_017_1xx -> Unique_Gloves_017
    { 0x22EAA361, 0x1EBE5281 },    // Unique_HandXBow_001_1xx -> Unique_HandXBow_001
    { 0x22FCBBE2, 0x1EBE5282 },    // Unique_HandXBow_002_1xx -> Unique_HandXBow_002
    { 0x230ED463, 0x1EBE5283 },    // Unique_HandXBow_003_1xx -> Unique_HandXBow_003
    { 0x2320ECE4, 0x1EBE5284 },    // Unique_HandXBow_004_1xx -> Unique_HandXBow_004
    { 0x23330565, 0x1EBE5285 },    // Unique_HandXBow_005_1xx -> Unique_HandXBow_005
    { 0x23451DE6, 0x1EBE5286 },    // Unique_HandXBow_006_1xx -> Unique_HandXBow_006
    { 0x23573667, 0x1EBE5287 },    // Unique_HandXBow_007_1xx -> Unique_HandXBow_007
    { 0x2551E483, 0x1EBE52A3 },    // Unique_HandXBow_012_1xx -> Unique_HandXBow_012
    { 0x259A4687, 0x1EBE52A7 },    // Unique_HandXBow_016_1xx -> Unique_HandXBow_016
    { 0x9146B18C, 0x61AC032C },    // Unique_Helm_001_1xx -> Unique_Helm_001
    { 0x9158CA0D, 0x61AC032D },    // Unique_Helm_002_1xx -> Unique_Helm_002
    { 0x916AE28E, 0x61AC032E },    // Unique_Helm_003_1xx -> Unique_Helm_003
    { 0x917CFB0F, 0x61AC032F },    // Unique_Helm_004_1xx -> Unique_Helm_004
    { 0x91A12C11, 0x61AC0331 },    // Unique_Helm_006_1xx -> Unique_Helm_006
    { 0x91B34492, 0x61AC0332 },    // Unique_Helm_007_1xx -> Unique_Helm_007
    { 0x91C55D13, 0x61AC0333 },    // Unique_Helm_008_1xx -> Unique_Helm_008
    { 0x91D77594, 0x61AC0334 },    // Unique_Helm_009_1xx -> Unique_Helm_009
    { 0x9389C1AC, 0x61AC034C },    // Unique_Helm_010_1xx -> Unique_Helm_010
    { 0x939BDA2D, 0x61AC034D },    // Unique_Helm_011_1xx -> Unique_Helm_011
    { 0x93ADF2AE, 0x61AC034E },    // Unique_Helm_012_1xx -> Unique_Helm_012
    { 0x93D223B0, 0x61AC0350 },    // Unique_Helm_014_1xx -> Unique_Helm_014
    { 0x93E43C31, 0x61AC0351 },    // Unique_Helm_015_1xx -> Unique_Helm_015
    { 0x93F654B2, 0x61AC0352 },    // Unique_Helm_016_1xx -> Unique_Helm_016
    { 0x70136C94, 0x2A847A34 },    // Unique_Mace_1H_001_1xx -> Unique_Mace_1H_001
    { 0x70258515, 0x2A847A35 },    // Unique_Mace_1H_002_1xx -> Unique_Mace_1H_002
    { 0x70379D96, 0x2A847A36 },    // Unique_Mace_1H_003_1xx -> Unique_Mace_1H_003
    { 0x705BCE98, 0x2A847A38 },    // Unique_Mace_1H_005_1xx -> Unique_Mace_1H_005
    { 0x707FFF9A, 0x2A847A3A },    // Unique_Mace_1H_007_1xx -> Unique_Mace_1H_007
    { 0x7092181B, 0x2A847A3B },    // Unique_Mace_1H_008_1xx -> Unique_Mace_1H_008
    { 0x70A4309C, 0x2A847A3C },    // Unique_Mace_1H_009_1xx -> Unique_Mace_1H_009
    { 0x72567CB4, 0x2A847A54 },    // Unique_Mace_1H_010_1xx -> Unique_Mace_1H_010
    { 0x72689535, 0x2A847A55 },    // Unique_Mace_1H_011_1xx -> Unique_Mace_1H_011
    { 0x741DFDB5, 0x2CD9A2D5 },    // Unique_Mace_2H_001_1xx -> Unique_Mace_2H_001
    { 0x74301636, 0x2CD9A2D6 },    // Unique_Mace_2H_002_1xx -> Unique_Mace_2H_002
    { 0x74422EB7, 0x2CD9A2D7 },    // Unique_Mace_2H_003_1xx -> Unique_Mace_2H_003
    { 0x7478783A, 0x2CD9A2DA },    // Unique_Mace_2H_006_1xx -> Unique_Mace_2H_006
    { 0x74AEC1BD, 0x2CD9A2DD },    // Unique_Mace_2H_009_1xx -> Unique_Mace_2H_009
    { 0x76610DD5, 0x2CD9A2F5 },    // Unique_Mace_2H_010_1xx -> Unique_Mace_2H_010
    { 0x76853ED7, 0x2CD9A2F7 },    // Unique_Mace_2H_012_1xx -> Unique_Mace_2H_012
    { 0x60E153D0, 0x6B682370 },    // Unique_Mighty_1H_001_1xx -> Unique_Mighty_1H_001
    { 0x6129B5D4, 0x6B682374 },    // Unique_Mighty_1H_005_1xx -> Unique_Mighty_1H_005
    { 0x613BCE55, 0x6B682375 },    // Unique_Mighty_1H_006_1xx -> Unique_Mighty_1H_006
    { 0x632463F0, 0x6B682390 },    // Unique_Mighty_1H_010_1xx -> Unique_Mighty_1H_010
    { 0x63367C71, 0x6B682391 },    // Unique_Mighty_1H_011_1xx -> Unique_Mighty_1H_011
    { 0x634894F2, 0x6B682392 },    // Unique_Mighty_1H_012_1xx -> Unique_Mighty_1H_012
    { 0x637EDE75, 0x6B682395 },    // Unique_Mighty_1H_015_1xx -> Unique_Mighty_1H_015
    { 0x64EBE4F1, 0x6DBD4C11 },    // Unique_Mighty_2H_001_1xx -> Unique_Mighty_2H_001
    { 0x65222E74, 0x6DBD4C14 },    // Unique_Mighty_2H_004_1xx -> Unique_Mighty_2H_004
    { 0x65465F76, 0x6DBD4C16 },    // Unique_Mighty_2H_006_1xx -> Unique_Mighty_2H_006
    { 0x672EF511, 0x6DBD4C31 },    // Unique_Mighty_2H_010_1xx -> Unique_Mighty_2H_010
    { 0x67532613, 0x6DBD4C33 },    // Unique_Mighty_2H_012_1xx -> Unique_Mighty_2H_012
    { 0x9C9C713C, 0xFC356ADC },    // Unique_Mojo_002_1xx -> Unique_Mojo_002
    { 0x9CAE89BD, 0xFC356ADD },    // Unique_Mojo_003_1xx -> Unique_Mojo_003
    { 0x9CC0A23E, 0xFC356ADE },    // Unique_Mojo_004_1xx -> Unique_Mojo_004
    { 0x9D090442, 0xFC356AE2 },    // Unique_Mojo_008_1xx -> Unique_Mojo_008
    { 0x9D1B1CC3, 0xFC356AE3 },    // Unique_Mojo_009_1xx -> Unique_Mojo_009
    { 0x9ECD68DB, 0xFC356AFB },    // Unique_Mojo_010_1xx -> Unique_Mojo_010
    { 0x9EDF815C, 0xFC356AFC },    // Unique_Mojo_011_1xx -> Unique_Mojo_011
    { 0x8F26D83C, 0x93A451DC },    // Unique_Offhand_001_1xx -> Unique_Offhand_001
    { 0x53C093A9, 0x0CD75EC9 },    // Unique_Orb_001_1xx -> Unique_Orb_001
    { 0x53E4C4AB, 0x0CD75ECB },    // Unique_Orb_003_1xx -> Unique_Orb_003
    { 0x53F6DD2C, 0x0CD75ECC },    // Unique_Orb_004_1xx -> Unique_Orb_004
    { 0x5408F5AD, 0x0CD75ECD },    // Unique_Orb_005_1xx -> Unique_Orb_005
    { 0x5615BC4A, 0x0CD75EEA },    // Unique_Orb_011_1xx -> Unique_Orb_011
    { 0x5627D4CB, 0x0CD75EEB },    // Unique_Orb_012_1xx -> Unique_Orb_012
    { 0x0C9C816C, 0x35D4E30C },    // Unique_Pants_001_1xx -> Unique_Pants_001
    { 0x0CAE99ED, 0x35D4E30D },    // Unique_Pants_002_1xx -> Unique_Pants_002
    { 0x0CE4E370, 0x35D4E310 },    // Unique_Pants_005_1xx -> Unique_Pants_005
    { 0x0CF6FBF1, 0x35D4E311 },    // Unique_Pants_006_1xx -> Unique_Pants_006
    { 0x0D091472, 0x35D4E312 },    // Unique_Pants_007_1xx -> Unique_Pants_007
    { 0x0D1B2CF3, 0x35D4E313 },    // Unique_Pants_008_1xx -> Unique_Pants_008
    { 0x0D2D4574, 0x35D4E314 },    // Unique_Pants_009_1xx -> Unique_Pants_009
    { 0x0EDF918C, 0x35D4E32C },    // Unique_Pants_010_1xx -> Unique_Pants_010
    { 0x0F03C28E, 0x35D4E32E },    // Unique_Pants_012_1xx -> Unique_Pants_012
    { 0x0F15DB0F, 0x35D4E32F },    // Unique_Pants_013_1xx -> Unique_Pants_013
    { 0x0F27F390, 0x35D4E330 },    // Unique_Pants_014_1xx -> Unique_Pants_014
    { 0xB99AAB16, 0x3D7CC7B6 },    // Unique_Polearm_001_1xx -> Unique_Polearm_001
    { 0xB9ACC397, 0x3D7CC7B7 },    // Unique_Polearm_002_1xx -> Unique_Polearm_002
    { 0xB9BEDC18, 0x3D7CC7B8 },    // Unique_Polearm_003_1xx -> Unique_Polearm_003
    { 0xB9D0F499, 0x3D7CC7B9 },    // Unique_Polearm_004_1xx -> Unique_Polearm_004
    { 0xEC1342E2, 0xEBA95982 },    // Unique_Quiver_001_1xx -> Unique_Quiver_001
    { 0xEC255B63, 0xEBA95983 },    // Unique_Quiver_002_1xx -> Unique_Quiver_002
    { 0xEC3773E4, 0xEBA95984 },    // Unique_Quiver_003_1xx -> Unique_Quiver_003
    { 0xEC498C65, 0xEBA95985 },    // Unique_Quiver_004_1xx -> Unique_Quiver_004
    { 0xEC5BA4E6, 0xEBA95986 },    // Unique_Quiver_005_1xx -> Unique_Quiver_005
    { 0xEC6DBD67, 0xEBA95987 },    // Unique_Quiver_006_1xx -> Unique_Quiver_006
    { 0xEC7FD5E8, 0xEBA95988 },    // Unique_Quiver_007_1xx -> Unique_Quiver_007
    { 0xDD65A896, 0xD4650536 },    // Unique_Ring_001_1xx -> Unique_Ring_001
    { 0xDD77C117, 0xD4650537 },    // Unique_Ring_002_1xx -> Unique_Ring_002
    { 0xDD89D998, 0xD4650538 },    // Unique_Ring_003_1xx -> Unique_Ring_003
    { 0xDD9BF219, 0xD4650539 },    // Unique_Ring_004_1xx -> Unique_Ring_004
    { 0xDDAE0A9A, 0xD465053A },    // Unique_Ring_005_1xx -> Unique_Ring_005
    { 0xDDC0231B, 0xD465053B },    // Unique_Ring_006_1xx -> Unique_Ring_006
    { 0xDDD23B9C, 0xD465053C },    // Unique_Ring_007_1xx -> Unique_Ring_007
    { 0xDDE4541D, 0xD465053D },    // Unique_Ring_008_1xx -> Unique_Ring_008
    { 0xDDF66C9E, 0xD465053E },    // Unique_Ring_009_1xx -> Unique_Ring_009
    { 0xDFA8B8B6, 0xD4650556 },    // Unique_Ring_010_1xx -> Unique_Ring_010
    { 0xDFBAD137, 0xD4650557 },    // Unique_Ring_011_1xx -> Unique_Ring_011
    { 0xDFCCE9B8, 0xD4650558 },    // Unique_Ring_012_1xx -> Unique_Ring_012
    { 0xDFDF0239, 0xD4650559 },    // Unique_Ring_013_1xx -> Unique_Ring_013
    { 0xDFF11ABA, 0xD465055A },    // Unique_Ring_014_1xx -> Unique_Ring_014
    { 0xE003333B, 0xD465055B },    // Unique_Ring_015_1xx -> Unique_Ring_015
    { 0xE027643D, 0xD465055D },    // Unique_Ring_017_1xx -> Unique_Ring_017
    { 0xE0397CBE, 0xD465055E },    // Unique_Ring_018_1xx -> Unique_Ring_018
    { 0xE04B953F, 0xD465055F },    // Unique_Ring_019_1xx -> Unique_Ring_019
    { 0xE1FDE157, 0xD4650577 },    // Unique_Ring_020_1xx -> Unique_Ring_020
    { 0xE20FF9D8, 0xD4650578 },    // Unique_Ring_021_1xx -> Unique_Ring_021
    { 0xE2221259, 0xD4650579 },    // Unique_Ring_022_1xx -> Unique_Ring_022
    { 0xE2342ADA, 0xD465057A },    // Unique_Ring_023_1xx -> Unique_Ring_023
    { 0x3D2613A0, 0xFC257B40 },    // Unique_Shield_002_1xx -> Unique_Shield_002
    { 0x3D4A44A2, 0xFC257B42 },    // Unique_Shield_004_1xx -> Unique_Shield_004
    { 0x3D808E25, 0xFC257B45 },    // Unique_Shield_007_1xx -> Unique_Shield_007
    { 0x3D92A6A6, 0xFC257B46 },    // Unique_Shield_008_1xx -> Unique_Shield_008
    { 0x3DA4BF27, 0xFC257B47 },    // Unique_Shield_009_1xx -> Unique_Shield_009
    { 0x3F6923C0, 0xFC257B60 },    // Unique_Shield_011_1xx -> Unique_Shield_011
    { 0x3F7B3C41, 0xFC257B61 },    // Unique_Shield_012_1xx -> Unique_Shield_012
    { 0xF130492C, 0x0E3ACACC },    // Unique_Shoulder_001_1xx -> Unique_Shoulder_001
    { 0xF14261AD, 0x0E3ACACD },    // Unique_Shoulder_002_1xx -> Unique_Shoulder_002
    { 0xF1547A2E, 0x0E3ACACE },    // Unique_Shoulder_003_1xx -> Unique_Shoulder_003
    { 0xF18AC3B1, 0x0E3ACAD1 },    // Unique_Shoulder_006_1xx -> Unique_Shoulder_006
    { 0xF19CDC32, 0x0E3ACAD2 },    // Unique_Shoulder_007_1xx -> Unique_Shoulder_007
    { 0xF1AEF4B3, 0x0E3ACAD3 },    // Unique_Shoulder_008_1xx -> Unique_Shoulder_008
    { 0xF1C10D34, 0x0E3ACAD4 },    // Unique_Shoulder_009_1xx -> Unique_Shoulder_009
    { 0xF3F204D3, 0x0E3ACAF3 },    // Unique_Shoulder_017_1xx -> Unique_Shoulder_017
    { 0x677480E1, 0x89F57001 },    // Unique_Spear_001_1xx -> Unique_Spear_001
    { 0x67869962, 0x89F57002 },    // Unique_Spear_002_1xx -> Unique_Spear_002
    { 0x6798B1E3, 0x89F57003 },    // Unique_Spear_003_1xx -> Unique_Spear_003
    { 0x67AACA64, 0x89F57004 },    // Unique_Spear_004_1xx -> Unique_Spear_004
    { 0xE226DC6A, 0x421D6F0A },    // Unique_SpiritStone_001_1xx -> Unique_SpiritStone_001
    { 0xE238F4EB, 0x421D6F0B },    // Unique_SpiritStone_002_1xx -> Unique_SpiritStone_002
    { 0xE24B0D6C, 0x421D6F0C },    // Unique_SpiritStone_003_1xx -> Unique_SpiritStone_003
    { 0xE25D25ED, 0x421D6F0D },    // Unique_SpiritStone_004_1xx -> Unique_SpiritStone_004
    { 0xE26F3E6E, 0x421D6F0E },    // Unique_SpiritStone_005_1xx -> Unique_SpiritStone_005
    { 0xE28156EF, 0x421D6F0F },    // Unique_SpiritStone_006_1xx -> Unique_SpiritStone_006
    { 0xE2936F70, 0x421D6F10 },    // Unique_SpiritStone_007_1xx -> Unique_SpiritStone_007
    { 0xE2A587F1, 0x421D6F11 },    // Unique_SpiritStone_008_1xx -> Unique_SpiritStone_008
    { 0xE2B7A072, 0x421D6F12 },    // Unique_SpiritStone_009_1xx -> Unique_SpiritStone_009
    { 0xB42EAAFA, 0x11E4759A },    // Unique_Staff_001_1xx -> Unique_Staff_001
    { 0xB440C37B, 0x11E4759B },    // Unique_Staff_002_1xx -> Unique_Staff_002
    { 0xB452DBFC, 0x11E4759C },    // Unique_Staff_003_1xx -> Unique_Staff_003
    { 0xB489257F, 0x11E4759F },    // Unique_Staff_006_1xx -> Unique_Staff_006
    { 0xB49B3E00, 0x11E475A0 },    // Unique_Staff_007_1xx -> Unique_Staff_007
    { 0xB4AD5681, 0x11E475A1 },    // Unique_Staff_008_1xx -> Unique_Staff_008
    { 0xB4BF6F02, 0x11E475A2 },    // Unique_Staff_009_1xx -> Unique_Staff_009
    { 0x12D640ED, 0x24410A0D },    // Unique_Sword_1H_001_1xx -> Unique_Sword_1H_001
    { 0x12E8596E, 0x24410A0E },    // Unique_Sword_1H_002_1xx -> Unique_Sword_1H_002
    { 0x12FA71EF, 0x24410A0F },    // Unique_Sword_1H_003_1xx -> Unique_Sword_1H_003
    { 0x130C8A70, 0x24410A10 },    // Unique_Sword_1H_004_1xx -> Unique_Sword_1H_004
    { 0x1342D3F3, 0x24410A13 },    // Unique_Sword_1H_007_1xx -> Unique_Sword_1H_007
    { 0x1519510D, 0x24410A2D },    // Unique_Sword_1H_010_1xx -> Unique_Sword_1H_010
    { 0x152B698E, 0x24410A2E },    // Unique_Sword_1H_011_1xx -> Unique_Sword_1H_011
    { 0x153D820F, 0x24410A2F },    // Unique_Sword_1H_012_1xx -> Unique_Sword_1H_012
    { 0x1561B311, 0x24410A31 },    // Unique_Sword_1H_014_1xx -> Unique_Sword_1H_014
    { 0x1597FC94, 0x24410A34 },    // Unique_Sword_1H_017_1xx -> Unique_Sword_1H_017
    { 0x15AA1515, 0x24410A35 },    // Unique_Sword_1H_018_1xx -> Unique_Sword_1H_018
    { 0x15BC2D96, 0x24410A36 },    // Unique_Sword_1H_019_1xx -> Unique_Sword_1H_019
    { 0x1780922F, 0x24410A4F },    // Unique_Sword_1H_021_1xx -> Unique_Sword_1H_021
    { 0x16E0D20E, 0x269632AE },    // Unique_Sword_2H_001_1xx -> Unique_Sword_2H_001
    { 0x16F2EA8F, 0x269632AF },    // Unique_Sword_2H_002_1xx -> Unique_Sword_2H_002
    { 0x17050310, 0x269632B0 },    // Unique_Sword_2H_003_1xx -> Unique_Sword_2H_003
    { 0x17171B91, 0x269632B1 },    // Unique_Sword_2H_004_1xx -> Unique_Sword_2H_004
    { 0x174D6514, 0x269632B4 },    // Unique_Sword_2H_007_1xx -> Unique_Sword_2H_007
    { 0x175F7D95, 0x269632B5 },    // Unique_Sword_2H_008_1xx -> Unique_Sword_2H_008
    { 0x1923E22E, 0x269632CE },    // Unique_Sword_2H_010_1xx -> Unique_Sword_2H_010
    { 0x1935FAAF, 0x269632CF },    // Unique_Sword_2H_011_1xx -> Unique_Sword_2H_011
    { 0x19481330, 0x269632D0 },    // Unique_Sword_2H_012_1xx -> Unique_Sword_2H_012
    { 0x196C4432, 0x269632D2 },    // Unique_Sword_2H_014_1xx -> Unique_Sword_2H_014
    { 0x8B157728, 0x10205AC8 },    // Unique_VoodooMask_001_1xx -> Unique_VoodooMask_001
    { 0x8B278FA9, 0x10205AC9 },    // Unique_VoodooMask_002_1xx -> Unique_VoodooMask_002
    { 0x8B5DD92C, 0x10205ACC },    // Unique_VoodooMask_005_1xx -> Unique_VoodooMask_005
    { 0x8B6FF1AD, 0x10205ACD },    // Unique_VoodooMask_006_1xx -> Unique_VoodooMask_006
    { 0x8B820A2E, 0x10205ACE },    // Unique_VoodooMask_007_1xx -> Unique_VoodooMask_007
    { 0x8B9422AF, 0x10205ACF },    // Unique_VoodooMask_008_1xx -> Unique_VoodooMask_008
    { 0x49DD96F1, 0x09A5FE11 },    // Unique_Wand_002_1xx -> Unique_Wand_002
    { 0x49EFAF72, 0x09A5FE12 },    // Unique_Wand_003_1xx -> Unique_Wand_003
    { 0x4A25F8F5, 0x09A5FE15 },    // Unique_Wand_006_1xx -> Unique_Wand_006
    { 0x4A5C4278, 0x09A5FE18 },    // Unique_Wand_009_1xx -> Unique_Wand_009
    { 0x4C0E8E90, 0x09A5FE30 },    // Unique_Wand_010_1xx -> Unique_Wand_010
    { 0x4C32BF92, 0x09A5FE32 },    // Unique_Wand_012_1xx -> Unique_Wand_012
    { 0x4C44D813, 0x09A5FE33 },    // Unique_Wand_013_1xx -> Unique_Wand_013
    { 0x4C9F5298, 0x09A5FE38 },    // Unique_Wand_018_1xx -> Unique_Wand_018
    { 0xE24DDF54, 0x29F38CF4 },    // Unique_WizardHat_001_1xx -> Unique_WizardHat_001
    { 0xE2721056, 0x29F38CF6 },    // Unique_WizardHat_003_1xx -> Unique_WizardHat_003
    { 0xE28428D7, 0x29F38CF7 },    // Unique_WizardHat_004_1xx -> Unique_WizardHat_004
    { 0xA9628546, 0x468F09E6 },    // Unique_XBow_001_1xx -> Unique_XBow_001
    { 0xA9749DC7, 0x468F09E7 },    // Unique_XBow_002_1xx -> Unique_XBow_002
    { 0xA986B648, 0x468F09E8 },    // Unique_XBow_003_1xx -> Unique_XBow_003
    { 0xA998CEC9, 0x468F09E9 },    // Unique_XBow_004_1xx -> Unique_XBow_004
    { 0xA9BCFFCB, 0x468F09EB },    // Unique_XBow_006_1xx -> Unique_XBow_006
    { 0xABB7ADE7, 0x468F0A07 },    // Unique_XBow_011_1xx -> Unique_XBow_011
    { 0xABC9C668, 0x468F0A08 },    // Unique_XBow_012_1xx -> Unique_XBow_012
};

constexpr size_t kNumItemGbidMappings = sizeof(s_ItemGbidMappings) / sizeof(s_ItemGbidMappings[0]);

constexpr GbidMapping s_AffixGbidMappings[] = {
    /* Disabled until crashes are fixed
    { 0xFCC58E94, 0xB45F71B4 },    // 1xx_AllStats 1 Legendary -> AllStats 1 Legendary
    { 0x94AF69E4, 0x3F85B104 },    // 1xx_AllStats 10 Legendary -> AllStats 10 Legendary
    { 0x1A0C1F25, 0xC4E26645 },    // 1xx_AllStats 11 Legendary -> AllStats 11 Legendary
    { 0x9F68D466, 0x4A3F1B86 },    // 1xx_AllStats 12 Legendary -> AllStats 12 Legendary
    { 0x24C589A7, 0xCF9BD0C7 },    // 1xx_AllStats 13 Legendary -> AllStats 13 Legendary
    { 0xAA223EE8, 0x54F88608 },    // 1xx_AllStats 14 Legendary -> AllStats 14 Legendary
    { 0x2F7EF429, 0xDA553B49 },    // 1xx_AllStats 15 Legendary -> AllStats 15 Legendary
    { 0xB4DBA96A, 0x5FB1F08A },    // 1xx_AllStats 16 Legendary -> AllStats 16 Legendary
    { 0x3A385EAB, 0x5FB1F08A },    // 1xx_AllStats 17 Legendary -> AllStats 16 Legendary
    { 0x822243D5, 0x39BC26F5 },    // 1xx_AllStats 2 Legendary -> AllStats 2 Legendary
    { 0x077EF916, 0xBF18DC36 },    // 1xx_AllStats 3 Legendary -> AllStats 3 Legendary
    { 0x8CDBAE57, 0x44759177 },    // 1xx_AllStats 4 Legendary -> AllStats 4 Legendary
    { 0x12386398, 0xC9D246B8 },    // 1xx_AllStats 5 Legendary -> AllStats 5 Legendary
    { 0x979518D9, 0x4F2EFBF9 },    // 1xx_AllStats 6 Legendary -> AllStats 6 Legendary
    { 0x1CF1CE1A, 0xD48BB13A },    // 1xx_AllStats 7 Legendary -> AllStats 7 Legendary
    { 0xA24E835B, 0x59E8667B },    // 1xx_AllStats 8 Legendary -> AllStats 8 Legendary
    { 0x27AB389C, 0xDF451BBC },    // 1xx_AllStats 9 Legendary -> AllStats 9 Legendary
    { 0x9CAA6CCD, 0xA24997ED },    // 1xx_AllStats1H 1 Legendary -> AllStats1H 1 Legendary
    { 0x31300F3D, 0xEAB49E5D },    // 1xx_AllStats1H 10 Legendary -> AllStats1H 10 Legendary
    { 0xB68CC47E, 0x7011539E },    // 1xx_AllStats1H 11 Legendary -> AllStats1H 11 Legendary
    { 0x3BE979BF, 0xF56E08DF },    // 1xx_AllStats1H 12 Legendary -> AllStats1H 12 Legendary
    { 0xC1462F00, 0x7ACABE20 },    // 1xx_AllStats1H 13 Legendary -> AllStats1H 13 Legendary
    { 0x46A2E441, 0x00277361 },    // 1xx_AllStats1H 14 Legendary -> AllStats1H 14 Legendary
    { 0xCBFF9982, 0x858428A2 },    // 1xx_AllStats1H 15 Legendary -> AllStats1H 15 Legendary
    { 0x515C4EC3, 0x0AE0DDE3 },    // 1xx_AllStats1H 16 Legendary -> AllStats1H 16 Legendary
    { 0xD6B90404, 0x0AE0DDE3 },    // 1xx_AllStats1H 17 Legendary -> AllStats1H 16 Legendary
    { 0x2207220E, 0x27A64D2E },    // 1xx_AllStats1H 2 Legendary -> AllStats1H 2 Legendary
    { 0xA763D74F, 0xAD03026F },    // 1xx_AllStats1H 3 Legendary -> AllStats1H 3 Legendary
    { 0x2CC08C90, 0x325FB7B0 },    // 1xx_AllStats1H 4 Legendary -> AllStats1H 4 Legendary
    { 0xB21D41D1, 0xB7BC6CF1 },    // 1xx_AllStats1H 5 Legendary -> AllStats1H 5 Legendary
    { 0x3779F712, 0x3D192232 },    // 1xx_AllStats1H 6 Legendary -> AllStats1H 6 Legendary
    { 0xBCD6AC53, 0xC275D773 },    // 1xx_AllStats1H 7 Legendary -> AllStats1H 7 Legendary
    { 0x42336194, 0x47D28CB4 },    // 1xx_AllStats1H 8 Legendary -> AllStats1H 8 Legendary
    { 0xC79016D5, 0xCD2F41F5 },    // 1xx_AllStats1H 9 Legendary -> AllStats1H 9 Legendary
    { 0xD7EAA66E, 0xDD89D18E },    // 1xx_AllStats2H 1 Legendary -> AllStats2H 1 Legendary
    { 0xD4777CFE, 0x8DFC0C1E },    // 1xx_AllStats2H 10 Legendary -> AllStats2H 10 Legendary
    { 0x59D4323F, 0x1358C15F },    // 1xx_AllStats2H 11 Legendary -> AllStats2H 11 Legendary
    { 0xDF30E780, 0x98B576A0 },    // 1xx_AllStats2H 12 Legendary -> AllStats2H 12 Legendary
    { 0x648D9CC1, 0x1E122BE1 },    // 1xx_AllStats2H 13 Legendary -> AllStats2H 13 Legendary
    { 0xE9EA5202, 0xA36EE122 },    // 1xx_AllStats2H 14 Legendary -> AllStats2H 14 Legendary
    { 0x6F470743, 0x28CB9663 },    // 1xx_AllStats2H 15 Legendary -> AllStats2H 15 Legendary
    { 0xF4A3BC84, 0xAE284BA4 },    // 1xx_AllStats2H 16 Legendary -> AllStats2H 16 Legendary
    { 0x7A0071C5, 0xAE284BA4 },    // 1xx_AllStats2H 17 Legendary -> AllStats2H 16 Legendary
    { 0x5D475BAF, 0x62E686CF },    // 1xx_AllStats2H 2 Legendary -> AllStats2H 2 Legendary
    { 0xE2A410F0, 0xE8433C10 },    // 1xx_AllStats2H 3 Legendary -> AllStats2H 3 Legendary
    { 0x6800C631, 0x6D9FF151 },    // 1xx_AllStats2H 4 Legendary -> AllStats2H 4 Legendary
    { 0xED5D7B72, 0xF2FCA692 },    // 1xx_AllStats2H 5 Legendary -> AllStats2H 5 Legendary
    { 0x72BA30B3, 0x78595BD3 },    // 1xx_AllStats2H 6 Legendary -> AllStats2H 6 Legendary
    { 0xF816E5F4, 0xFDB61114 },    // 1xx_AllStats2H 7 Legendary -> AllStats2H 7 Legendary
    { 0x7D739B35, 0x8312C655 },    // 1xx_AllStats2H 8 Legendary -> AllStats2H 8 Legendary
    { 0x02D05076, 0x086F7B96 },    // 1xx_AllStats2H 9 Legendary -> AllStats2H 9 Legendary
    { 0x2E26817F, 0x0781189F },    // 1xx_ArcaneD 1 -> ArcaneD 1
    { 0x0A1AF38D, 0x5150FEAD },    // 1xx_ArcaneD 1 Fast -> ArcaneD 1 Fast
    { 0xCDA1F4EA, 0x853BD80A },    // 1xx_ArcaneD 1 Two-Handed -> ArcaneD 1 Two-Handed
    { 0xF2F6B18F, 0xF7A42CAF },    // 1xx_ArcaneD 10 -> ArcaneD 10
    { 0x6DDBAD9D, 0x9BD31CBD },    // 1xx_ArcaneD 10 Fast -> ArcaneD 10 Fast
    { 0xA129FAFA, 0x4C00421A },    // 1xx_ArcaneD 10 Two-Handed -> ArcaneD 10 Two-Handed
    { 0xF2F6B190, 0xF7A42CB0 },    // 1xx_ArcaneD 11 -> ArcaneD 11
    { 0x7030D63E, 0x9E28455E },    // 1xx_ArcaneD 11 Fast -> ArcaneD 11 Fast
    { 0xD21D585B, 0x7CF39F7B },    // 1xx_ArcaneD 11 Two-Handed -> ArcaneD 11 Two-Handed
    { 0xF2F6B191, 0xF7A42CB1 },    // 1xx_ArcaneD 12 -> ArcaneD 12
    { 0x7285FEDF, 0xA07D6DFF },    // 1xx_ArcaneD 12 Fast -> ArcaneD 12 Fast
    { 0x0310B5BC, 0xADE6FCDC },    // 1xx_ArcaneD 12 Two-Handed -> ArcaneD 12 Two-Handed
    { 0xF2F6B192, 0xF7A42CB2 },    // 1xx_ArcaneD 13 -> ArcaneD 13
    { 0x74DB2780, 0xA2D296A0 },    // 1xx_ArcaneD 13 Fast -> ArcaneD 13 Fast
    { 0x3404131D, 0xDEDA5A3D },    // 1xx_ArcaneD 13 Two-Handed -> ArcaneD 13 Two-Handed
    { 0xF2F6B193, 0xF7A42CB3 },    // 1xx_ArcaneD 14 -> ArcaneD 14
    { 0x77305021, 0xA527BF41 },    // 1xx_ArcaneD 14 Fast -> ArcaneD 14 Fast
    { 0x64F7707E, 0x0FCDB79E },    // 1xx_ArcaneD 14 Two-Handed -> ArcaneD 14 Two-Handed
    { 0xF2F6B194, 0xF7A42CB3 },    // 1xx_ArcaneD 15 -> ArcaneD 14
    { 0x798578C2, 0xA527BF41 },    // 1xx_ArcaneD 15 Fast -> ArcaneD 14 Fast
    { 0x95EACDDF, 0x0FCDB79E },    // 1xx_ArcaneD 15 Two-Handed -> ArcaneD 14 Two-Handed
    { 0xF2F6B195, 0xF7A42CB3 },    // 1xx_ArcaneD 16 -> ArcaneD 14
    { 0x7BDAA163, 0xA527BF41 },    // 1xx_ArcaneD 16 Fast -> ArcaneD 14 Fast
    { 0xC6DE2B40, 0x0FCDB79E },    // 1xx_ArcaneD 16 Two-Handed -> ArcaneD 14 Two-Handed
    { 0x2E268180, 0x078118A0 },    // 1xx_ArcaneD 2 -> ArcaneD 2
    { 0x0C701C2E, 0x53A6274E },    // 1xx_ArcaneD 2 Fast -> ArcaneD 2 Fast
    { 0xFE95524B, 0xB62F356B },    // 1xx_ArcaneD 2 Two-Handed -> ArcaneD 2 Two-Handed
    { 0x2E268181, 0x078118A1 },    // 1xx_ArcaneD 3 -> ArcaneD 3
    { 0x0EC544CF, 0x55FB4FEF },    // 1xx_ArcaneD 3 Fast -> ArcaneD 3 Fast
    { 0x2F88AFAC, 0xE72292CC },    // 1xx_ArcaneD 3 Two-Handed -> ArcaneD 3 Two-Handed
    { 0x2E268182, 0x078118A2 },    // 1xx_ArcaneD 4 -> ArcaneD 4
    { 0x111A6D70, 0x58507890 },    // 1xx_ArcaneD 4 Fast -> ArcaneD 4 Fast
    { 0x607C0D0D, 0x1815F02D },    // 1xx_ArcaneD 4 Two-Handed -> ArcaneD 4 Two-Handed
    { 0x2E268183, 0x078118A3 },    // 1xx_ArcaneD 5 -> ArcaneD 5
    { 0x136F9611, 0x5AA5A131 },    // 1xx_ArcaneD 5 Fast -> ArcaneD 5 Fast
    { 0x916F6A6E, 0x49094D8E },    // 1xx_ArcaneD 5 Two-Handed -> ArcaneD 5 Two-Handed
    { 0x2E268184, 0x078118A4 },    // 1xx_ArcaneD 6 -> ArcaneD 6
    { 0x15C4BEB2, 0x5CFAC9D2 },    // 1xx_ArcaneD 6 Fast -> ArcaneD 6 Fast
    { 0xC262C7CF, 0x79FCAAEF },    // 1xx_ArcaneD 6 Two-Handed -> ArcaneD 6 Two-Handed
    { 0x2E268185, 0x078118A5 },    // 1xx_ArcaneD 7 -> ArcaneD 7
    { 0x1819E753, 0x5F4FF273 },    // 1xx_ArcaneD 7 Fast -> ArcaneD 7 Fast
    { 0xF3562530, 0xAAF00850 },    // 1xx_ArcaneD 7 Two-Handed -> ArcaneD 7 Two-Handed
    { 0x2E268186, 0x078118A6 },    // 1xx_ArcaneD 8 -> ArcaneD 8
    { 0x1A6F0FF4, 0x61A51B14 },    // 1xx_ArcaneD 8 Fast -> ArcaneD 8 Fast
    { 0x24498291, 0xDBE365B1 },    // 1xx_ArcaneD 8 Two-Handed -> ArcaneD 8 Two-Handed
    { 0x2E268187, 0x078118A7 },    // 1xx_ArcaneD 9 -> ArcaneD 9
    { 0x1CC43895, 0x63FA43B5 },    // 1xx_ArcaneD 9 Fast -> ArcaneD 9 Fast
    { 0x553CDFF2, 0x0CD6C312 },    // 1xx_ArcaneD 9 Two-Handed -> ArcaneD 9 Two-Handed
    { 0xABC1A137, 0xD81BA057 },    // 1xx_ArcanePowerOnCrit 1 -> ArcanePowerOnCrit 1
    { 0xABC1A138, 0xD81BA058 },    // 1xx_ArcanePowerOnCrit 2 -> ArcanePowerOnCrit 2
    { 0xABC1A139, 0xD81BA059 },    // 1xx_ArcanePowerOnCrit 3 -> ArcanePowerOnCrit 3
    { 0xABC1A13A, 0xD81BA05A },    // 1xx_ArcanePowerOnCrit 4 -> ArcanePowerOnCrit 4
    { 0xABC1A13B, 0xD81BA05B },    // 1xx_ArcanePowerOnCrit 5 -> ArcanePowerOnCrit 5
    { 0xABC1A13C, 0xD81BA05C },    // 1xx_ArcanePowerOnCrit 6 -> ArcanePowerOnCrit 6
    { 0xABC1A13D, 0xD81BA05D },    // 1xx_ArcanePowerOnCrit 7 -> ArcanePowerOnCrit 7
    { 0xABC1A13E, 0xD81BA05E },    // 1xx_ArcanePowerOnCrit 8 -> ArcanePowerOnCrit 8
    { 0xABC1A13F, 0xD81BA05F },    // 1xx_ArcanePowerOnCrit 9 -> ArcanePowerOnCrit 9
    { 0x91C9AB6E, 0x5B49668E },    // 1xx_ArcaneResist 0.1 Legendary -> ArcaneResist 0.1 Legendary
    { 0x172660AF, 0xE0A61BCF },    // 1xx_ArcaneResist 0.2 Legendary -> ArcaneResist 0.2 Legendary
    { 0x9C8315F0, 0x6602D110 },    // 1xx_ArcaneResist 0.3 Legendary -> ArcaneResist 0.3 Legendary
    { 0x544BD52D, 0x9B81E04D },    // 1xx_ArcaneResist I -> ArcaneResist I
    { 0xDDC67B36, 0x0BBDEA56 },    // 1xx_ArcaneResist II -> ArcaneResist II
    { 0x9695E25F, 0x837B357F },    // 1xx_ArcaneResist III -> ArcaneResist III
    { 0xDDC67B43, 0x0BBDEA63 },    // 1xx_ArcaneResist IV -> ArcaneResist IV
    { 0xDDC67B45, 0x0BBDEA65 },    // 1xx_ArcaneResist IX -> ArcaneResist IX
    { 0x544BD53A, 0x9B81E05A },    // 1xx_ArcaneResist V -> ArcaneResist V
    { 0xDDC67CE3, 0x0BBDEC03 },    // 1xx_ArcaneResist VI -> ArcaneResist VI
    { 0x969619AC, 0x837B6CCC },    // 1xx_ArcaneResist VII -> ArcaneResist VII
    { 0x69594F95, 0xF2E906B5 },    // 1xx_ArcaneResist VIII -> ArcaneResist VIII
    { 0x544BD53C, 0x9B81E05C },    // 1xx_ArcaneResist X -> ArcaneResist X
    { 0xDB212EDE, 0xFFFFFFFF },    // 1xx_BindOnEquip -> (none)
    { 0xE5D04C06, 0xFFFFFFFF },    // 1xx_Bleed 0.1 Legendary -> (none)
    { 0xDC8199AE, 0xFFFFFFFF },    // 1xx_Bleed 0.1 Secondary Legendary -> (none)
    { 0x2D8AD18D, 0x7B1520AD },    // 1xx_Bleed 1 -> Bleed 1
    { 0x20F6EFB5, 0xAA86A6D5 },    // 1xx_Bleed 1 Secondary -> Bleed 1 Secondary
    { 0xDEE5035D, 0xDDB9367D },    // 1xx_Bleed 10 -> Bleed 10
    { 0xE4D5A585, 0xA05C40A5 },    // 1xx_Bleed 10 Secondary -> Bleed 10 Secondary
    { 0xDEE5035E, 0xDDB9367E },    // 1xx_Bleed 11 -> Bleed 11
    { 0x6A325AC6, 0x25B8F5E6 },    // 1xx_Bleed 11 Secondary -> Bleed 11 Secondary
    { 0xDEE5035F, 0xDDB9367F },    // 1xx_Bleed 12 -> Bleed 12
    { 0xEF8F1007, 0xAB15AB27 },    // 1xx_Bleed 12 Secondary -> Bleed 12 Secondary
    { 0xDEE50360, 0xDDB9367F },    // 1xx_Bleed 13 -> Bleed 12
    { 0x74EBC548, 0xAB15AB27 },    // 1xx_Bleed 13 Secondary -> Bleed 12 Secondary
    { 0xDEE50361, 0xDDB9367F },    // 1xx_Bleed 14 -> Bleed 12
    { 0xFA487A89, 0xAB15AB27 },    // 1xx_Bleed 14 Secondary -> Bleed 12 Secondary
    { 0xDEE50362, 0xDDB9367F },    // 1xx_Bleed 15 -> Bleed 12
    { 0x7FA52FCA, 0xAB15AB27 },    // 1xx_Bleed 15 Secondary -> Bleed 12 Secondary
    { 0xDEE50363, 0xDDB9367F },    // 1xx_Bleed 16 -> Bleed 12
    { 0x0501E50B, 0xAB15AB27 },    // 1xx_Bleed 16 Secondary -> Bleed 12 Secondary
    { 0x2D8AD18E, 0x7B1520AE },    // 1xx_Bleed 2 -> Bleed 2
    { 0xA653A4F6, 0x2FE35C16 },    // 1xx_Bleed 2 Secondary -> Bleed 2 Secondary
    { 0x2D8AD18F, 0x7B1520AF },    // 1xx_Bleed 3 -> Bleed 3
    { 0x2BB05A37, 0xB5401157 },    // 1xx_Bleed 3 Secondary -> Bleed 3 Secondary
    { 0x2D8AD190, 0x7B1520B0 },    // 1xx_Bleed 4 -> Bleed 4
    { 0xB10D0F78, 0x3A9CC698 },    // 1xx_Bleed 4 Secondary -> Bleed 4 Secondary
    { 0x2D8AD191, 0x7B1520B1 },    // 1xx_Bleed 5 -> Bleed 5
    { 0x3669C4B9, 0xBFF97BD9 },    // 1xx_Bleed 5 Secondary -> Bleed 5 Secondary
    { 0x2D8AD192, 0x7B1520B2 },    // 1xx_Bleed 6 -> Bleed 6
    { 0xBBC679FA, 0x4556311A },    // 1xx_Bleed 6 Secondary -> Bleed 6 Secondary
    { 0x2D8AD193, 0x7B1520B3 },    // 1xx_Bleed 7 -> Bleed 7
    { 0x41232F3B, 0xCAB2E65B },    // 1xx_Bleed 7 Secondary -> Bleed 7 Secondary
    { 0x2D8AD194, 0x7B1520B4 },    // 1xx_Bleed 8 -> Bleed 8
    { 0xC67FE47C, 0x500F9B9C },    // 1xx_Bleed 8 Secondary -> Bleed 8 Secondary
    { 0x2D8AD195, 0x7B1520B5 },    // 1xx_Bleed 9 -> Bleed 9
    { 0x4BDC99BD, 0xD56C50DD },    // 1xx_Bleed 9 Secondary -> Bleed 9 Secondary
    { 0x2E3ECB9C, 0x7BC91ABC },    // 1xx_Block 1 -> Block 1
    { 0x36DA0884, 0xC069BFA4 },    // 1xx_Block 1 Secondary -> Block 1 Secondary
    { 0xF6183F4C, 0x7BC91AC4 },    // 1xx_Block 10 -> Block 9
    { 0xB71BD834, 0xEB4F69AC },    // 1xx_Block 10 Secondary -> Block 9 Secondary
    { 0xF6183F4D, 0x7BC91AC4 },    // 1xx_Block 11 -> Block 9
    { 0x3C788D75, 0xEB4F69AC },    // 1xx_Block 11 Secondary -> Block 9 Secondary
    { 0xC1D542B6, 0xEB4F69AC },    // 1xx_Block 12 Secondary -> Block 9 Secondary
    { 0x2E3ECB9D, 0x7BC91ABD },    // 1xx_Block 2 -> Block 2
    { 0xBC36BDC5, 0x45C674E5 },    // 1xx_Block 2 Secondary -> Block 2 Secondary
    { 0x2E3ECB9E, 0x7BC91ABE },    // 1xx_Block 3 -> Block 3
    { 0x41937306, 0xCB232A26 },    // 1xx_Block 3 Secondary -> Block 3 Secondary
    { 0x2E3ECB9F, 0x7BC91ABF },    // 1xx_Block 4 -> Block 4
    { 0xC6F02847, 0x507FDF67 },    // 1xx_Block 4 Secondary -> Block 4 Secondary
    { 0x2E3ECBA0, 0x7BC91AC0 },    // 1xx_Block 5 -> Block 5
    { 0x4C4CDD88, 0xD5DC94A8 },    // 1xx_Block 5 Secondary -> Block 5 Secondary
    { 0x2E3ECBA1, 0x7BC91AC1 },    // 1xx_Block 6 -> Block 6
    { 0xD1A992C9, 0x5B3949E9 },    // 1xx_Block 6 Secondary -> Block 6 Secondary
    { 0x2E3ECBA2, 0x7BC91AC2 },    // 1xx_Block 7 -> Block 7
    { 0x5706480A, 0xE095FF2A },    // 1xx_Block 7 Secondary -> Block 7 Secondary
    { 0x2E3ECBA3, 0x7BC91AC3 },    // 1xx_Block 8 -> Block 8
    { 0xDC62FD4B, 0x65F2B46B },    // 1xx_Block 8 Secondary -> Block 8 Secondary
    { 0x2E3ECBA4, 0x7BC91AC4 },    // 1xx_Block 9 -> Block 9
    { 0x61BFB28C, 0xEB4F69AC },    // 1xx_Block 9 Secondary -> Block 9 Secondary
    { 0x1B9B7A3D, 0x4880515D },    // 1xx_CCReduction 0.1 Legendary -> CCReduction 0.1 Legendary
    { 0xA0F82F7E, 0xCDDD069E },    // 1xx_CCReduction 0.2 Legendary -> CCReduction 0.2 Legendary
    { 0x2654E4BF, 0x5339BBDF },    // 1xx_CCReduction 0.3 Legendary -> CCReduction 0.3 Legendary
    { 0x4BF9B544, 0xF10ADC64 },    // 1xx_CCReduction 1 -> CCReduction 1
    { 0x4BF9B545, 0xF10ADC65 },    // 1xx_CCReduction 2 -> CCReduction 2
    { 0x4BF9B546, 0xF10ADC66 },    // 1xx_CCReduction 3 -> CCReduction 3
    { 0x4BF9B547, 0xF10ADC67 },    // 1xx_CCReduction 4 -> CCReduction 4
    { 0x4BF9B548, 0xF10ADC68 },    // 1xx_CCReduction 5 -> CCReduction 5
    { 0x4BF9B549, 0xF10ADC69 },    // 1xx_CCReduction 6 -> CCReduction 6
    { 0x4BF9B54A, 0xF10ADC69 },    // 1xx_CCReduction 7 -> CCReduction 6
    { 0x4BF9B54B, 0xF10ADC69 },    // 1xx_CCReduction 8 -> CCReduction 6
    { 0xC4AB3D13, 0xF1053C33 },    // 1xx_Charged Bolt Cast I -> Charged Bolt Cast I
    { 0x8202A757, 0xCF8CF677 },    // 1xx_ColdD 1 -> ColdD 1
    { 0x6E308065, 0x54294385 },    // 1xx_ColdD 1 Fast -> ColdD 1 Fast
    { 0xF9D3C3C2, 0xB55A5EE2 },    // 1xx_ColdD 1 Two-Handed -> ColdD 1 Two-Handed
    { 0xC2579267, 0xC12BC587 },    // 1xx_ColdD 10 -> ColdD 10
    { 0x54A2D575, 0xF9B3FC95 },    // 1xx_ColdD 10 Fast -> ColdD 10 Fast
    { 0x5395A4D2, 0x7FEFA3F2 },    // 1xx_ColdD 10 Two-Handed -> ColdD 10 Two-Handed
    { 0xC2579268, 0xC12BC588 },    // 1xx_ColdD 11 -> ColdD 11
    { 0x56F7FE16, 0xFC092536 },    // 1xx_ColdD 11 Fast -> ColdD 11 Fast
    { 0x84890233, 0xB0E30153 },    // 1xx_ColdD 11 Two-Handed -> ColdD 11 Two-Handed
    { 0xC2579269, 0xC12BC589 },    // 1xx_ColdD 12 -> ColdD 12
    { 0x594D26B7, 0xFE5E4DD7 },    // 1xx_ColdD 12 Fast -> ColdD 12 Fast
    { 0xB57C5F94, 0xE1D65EB4 },    // 1xx_ColdD 12 Two-Handed -> ColdD 12 Two-Handed
    { 0xC257926A, 0xC12BC58A },    // 1xx_ColdD 13 -> ColdD 13
    { 0x5BA24F58, 0x00B37678 },    // 1xx_ColdD 13 Fast -> ColdD 13 Fast
    { 0xE66FBCF5, 0x12C9BC15 },    // 1xx_ColdD 13 Two-Handed -> ColdD 13 Two-Handed
    { 0xC257926B, 0xC12BC58B },    // 1xx_ColdD 14 -> ColdD 14
    { 0x5DF777F9, 0x03089F19 },    // 1xx_ColdD 14 Fast -> ColdD 14 Fast
    { 0x17631A56, 0x43BD1976 },    // 1xx_ColdD 14 Two-Handed -> ColdD 14 Two-Handed
    { 0xC257926C, 0xC12BC58B },    // 1xx_ColdD 15 -> ColdD 14
    { 0x604CA09A, 0x03089F19 },    // 1xx_ColdD 15 Fast -> ColdD 14 Fast
    { 0x485677B7, 0x43BD1976 },    // 1xx_ColdD 15 Two-Handed -> ColdD 14 Two-Handed
    { 0xC257926D, 0xC12BC58B },    // 1xx_ColdD 16 -> ColdD 14
    { 0x62A1C93B, 0x03089F19 },    // 1xx_ColdD 16 Fast -> ColdD 14 Fast
    { 0x7949D518, 0x43BD1976 },    // 1xx_ColdD 16 Two-Handed -> ColdD 14 Two-Handed
    { 0x8202A758, 0xCF8CF678 },    // 1xx_ColdD 2 -> ColdD 2
    { 0x7085A906, 0x567E6C26 },    // 1xx_ColdD 2 Fast -> ColdD 2 Fast
    { 0x2AC72123, 0xE64DBC43 },    // 1xx_ColdD 2 Two-Handed -> ColdD 2 Two-Handed
    { 0x8202A759, 0xCF8CF679 },    // 1xx_ColdD 3 -> ColdD 3
    { 0x72DAD1A7, 0x58D394C7 },    // 1xx_ColdD 3 Fast -> ColdD 3 Fast
    { 0x5BBA7E84, 0x174119A4 },    // 1xx_ColdD 3 Two-Handed -> ColdD 3 Two-Handed
    { 0x8202A75A, 0xCF8CF67A },    // 1xx_ColdD 4 -> ColdD 4
    { 0x752FFA48, 0x5B28BD68 },    // 1xx_ColdD 4 Fast -> ColdD 4 Fast
    { 0x8CADDBE5, 0x48347705 },    // 1xx_ColdD 4 Two-Handed -> ColdD 4 Two-Handed
    { 0x8202A75B, 0xCF8CF67B },    // 1xx_ColdD 5 -> ColdD 5
    { 0x778522E9, 0x5D7DE609 },    // 1xx_ColdD 5 Fast -> ColdD 5 Fast
    { 0xBDA13946, 0x7927D466 },    // 1xx_ColdD 5 Two-Handed -> ColdD 5 Two-Handed
    { 0x8202A75C, 0xCF8CF67C },    // 1xx_ColdD 6 -> ColdD 6
    { 0x79DA4B8A, 0x5FD30EAA },    // 1xx_ColdD 6 Fast -> ColdD 6 Fast
    { 0xEE9496A7, 0xAA1B31C7 },    // 1xx_ColdD 6 Two-Handed -> ColdD 6 Two-Handed
    { 0x8202A75D, 0xCF8CF67D },    // 1xx_ColdD 7 -> ColdD 7
    { 0x7C2F742B, 0x6228374B },    // 1xx_ColdD 7 Fast -> ColdD 7 Fast
    { 0x1F87F408, 0xDB0E8F28 },    // 1xx_ColdD 7 Two-Handed -> ColdD 7 Two-Handed
    { 0x8202A75E, 0xCF8CF67E },    // 1xx_ColdD 8 -> ColdD 8
    { 0x7E849CCC, 0x647D5FEC },    // 1xx_ColdD 8 Fast -> ColdD 8 Fast
    { 0x507B5169, 0x0C01EC89 },    // 1xx_ColdD 8 Two-Handed -> ColdD 8 Two-Handed
    { 0x8202A75F, 0xCF8CF67F },    // 1xx_ColdD 9 -> ColdD 9
    { 0x80D9C56D, 0x66D2888D },    // 1xx_ColdD 9 Fast -> ColdD 9 Fast
    { 0x816EAECA, 0x3CF549EA },    // 1xx_ColdD 9 Two-Handed -> ColdD 9 Two-Handed
    { 0xAEC13C46, 0x98D7AF66 },    // 1xx_ColdResist 0.1 Legendary -> ColdResist 0.1 Legendary
    { 0x341DF187, 0x1E3464A7 },    // 1xx_ColdResist 0.2 Legendary -> ColdResist 0.2 Legendary
    { 0xB97AA6C8, 0xA39119E8 },    // 1xx_ColdResist 0.3 Legendary -> ColdResist 0.3 Legendary
    { 0xB8616205, 0x9E5A2525 },    // 1xx_ColdResist I -> ColdResist I
    { 0xC48DA30E, 0x699ECA2E },    // 1xx_ColdResist II -> ColdResist II
    { 0x56420537, 0x9D781057 },    // 1xx_ColdResist III -> ColdResist III
    { 0xC48DA31B, 0x699ECA3B },    // 1xx_ColdResist IV -> ColdResist IV
    { 0xC48DA31D, 0x699ECA3D },    // 1xx_ColdResist IX -> ColdResist IX
    { 0xB8616212, 0x9E5A2532 },    // 1xx_ColdResist V -> ColdResist V
    { 0xC48DA4BB, 0x699ECBDB },    // 1xx_ColdResist VI -> ColdResist VI
    { 0x56423C84, 0x9D7847A4 },    // 1xx_ColdResist VII -> ColdResist VII
    { 0x1E89CD6D, 0x4C813C8D },    // 1xx_ColdResist VIII -> ColdResist VIII
    { 0xB8616214, 0x9E5A2534 },    // 1xx_ColdResist X -> ColdResist X
    { 0xE9688877, 0x11C38B97 },    // 1xx_CriticalChance 0.1 Legendary -> CriticalChance 0.1 Legendary
    { 0xD680D75F, 0xFFFFFFFF },    // 1xx_CriticalChance 0.1 Secondary Legendary -> (none)
    { 0xA66C1CB6, 0x93516FD6 },    // 1xx_CriticalChance I -> CriticalChance I
    { 0x6C0B021E, 0x358ABD3E },    // 1xx_CriticalChance I Secondary -> CriticalChance I Secondary
    { 0x73EFB3DF, 0xFD7F6AFF },    // 1xx_CriticalChance II -> CriticalChance II
    { 0x44106087, 0x3D877FA7 },    // 1xx_CriticalChance II Secondary -> CriticalChance II Secondary
    { 0xF1E63028, 0xAD6CCB48 },    // 1xx_CriticalChance III -> CriticalChance III
    { 0x1CC18C10, 0x451C8F30 },    // 1xx_CriticalChance III Secondary -> CriticalChance III Secondary
    { 0x73EFB3EC, 0xFD7F6B0C },    // 1xx_CriticalChance IV -> CriticalChance IV
    { 0x09C594D4, 0x033CB3F4 },    // 1xx_CriticalChance IV Secondary -> CriticalChance IV Secondary
    { 0x73EFB3EE, 0xFD7F6B0E },    // 1xx_CriticalChance IX -> CriticalChance IX
    { 0x147EFF56, 0x0DF61E76 },    // 1xx_CriticalChance IX Secondary -> CriticalChance IX Secondary
    { 0xA66C1CC3, 0x93516FE3 },    // 1xx_CriticalChance V -> CriticalChance V
    { 0x31C0366B, 0xFB3FF18B },    // 1xx_CriticalChance V Secondary -> CriticalChance V Secondary
    { 0x73EFB58C, 0xFD7F6CAC },    // 1xx_CriticalChance VI -> CriticalChance VI
    { 0xC06C1E74, 0xB9E33D94 },    // 1xx_CriticalChance VI Secondary -> CriticalChance VI Secondary
    { 0xF1E66775, 0xAD6D0295 },    // 1xx_CriticalChance VII -> CriticalChance VII
    { 0x2495079D, 0x4CF00ABD },    // 1xx_CriticalChance VII Secondary -> CriticalChance VII Secondary
    { 0x2EB3567E, 0x5B0D559E },    // 1xx_CriticalChance VIII -> CriticalChance VIII
    { 0x0DDB15E6, 0x41967D06 },    // 1xx_CriticalChance VIII Secondary -> CriticalChance VIII Secondary
    { 0xA66C1CC5, 0xFD7F6B0E },    // 1xx_CriticalChance X -> CriticalChance IX
    { 0x3C79A0ED, 0x0DF61E76 },    // 1xx_CriticalChance X Secondary -> CriticalChance IX Secondary
    { 0x176D38F9, 0xD0F1C819 },    // 1xx_CriticalD 0.1 Legendary -> CriticalD 0.1 Legendary
    { 0xEAE2CC24, 0x397BA744 },    // 1xx_CriticalD 0.1 Legendary Two-Handed -> CriticalD 0.1 Legendary Two-Handed
    { 0xCF359261, 0xB28F8981 },    // 1xx_CriticalD 0.1 Secondary Legendary -> CriticalD 0.1 Secondary Legendary
    { 0x9CC9EE3A, 0x564E7D5A },    // 1xx_CriticalD 0.2 Legendary -> CriticalD 0.2 Legendary
    { 0x5D8F16C5, 0xAC27F1E5 },    // 1xx_CriticalD 0.2 Legendary Two-Handed -> CriticalD 0.2 Legendary Two-Handed
    { 0x20428CE2, 0x039C8402 },    // 1xx_CriticalD 0.2 Secondary Legendary -> CriticalD 0.2 Secondary Legendary
    { 0x2226A37B, 0xDBAB329B },    // 1xx_CriticalD 0.3 Legendary -> CriticalD 0.3 Legendary
    { 0xD03B6166, 0x1ED43C86 },    // 1xx_CriticalD 0.3 Legendary Two-Handed -> CriticalD 0.3 Legendary Two-Handed
    { 0x714F8763, 0x54A97E83 },    // 1xx_CriticalD 0.3 Secondary Legendary -> CriticalD 0.3 Secondary Legendary
    { 0x1ABA7A38, 0xB5175958 },    // 1xx_CriticalD I -> CriticalD I
    { 0x80C5AA20, 0x2B9BF140 },    // 1xx_CriticalD I Secondary -> CriticalD I Secondary
    { 0xFAA96803, 0x00489323 },    // 1xx_CriticalD I Two-Handed -> CriticalD I Two-Handed
    { 0x7209C1A1, 0x580284C1 },    // 1xx_CriticalD II -> CriticalD II
    { 0xF02008C9, 0xF5BF33E9 },    // 1xx_CriticalD II Secondary -> CriticalD II Secondary
    { 0x554F9BCC, 0x0ED42AEC },    // 1xx_CriticalD II Two-Handed -> CriticalD II Two-Handed
    { 0xB341F62A, 0x58531D4A },    // 1xx_CriticalD III -> CriticalD III
    { 0x4AC63C92, 0x044ACBB2 },    // 1xx_CriticalD III Secondary -> CriticalD III Secondary
    { 0x04BC48B5, 0xEED2BBD5 },    // 1xx_CriticalD III Two-Handed -> CriticalD III Two-Handed
    { 0x7209C1AE, 0x580284CE },    // 1xx_CriticalD IV -> CriticalD IV
    { 0xB5D53D16, 0xBB746836 },    // 1xx_CriticalD IV Secondary -> CriticalD IV Secondary
    { 0xD1AB59B9, 0x8B2FE8D9 },    // 1xx_CriticalD IV Two-Handed -> CriticalD IV Two-Handed
    { 0x7209C1B0, 0x580284D0 },    // 1xx_CriticalD IX -> CriticalD IX
    { 0xC08EA798, 0xC62DD2B8 },    // 1xx_CriticalD IX Secondary -> CriticalD IX Secondary
    { 0x3392147B, 0xED16A39B },    // 1xx_CriticalD IX Two-Handed -> CriticalD IX Two-Handed
    { 0x1ABA7A45, 0xB5175965 },    // 1xx_CriticalD V -> CriticalD V
    { 0x467ADE6D, 0xF151258D },    // 1xx_CriticalD V Secondary -> CriticalD V Secondary
    { 0x770525F0, 0x7CA45110 },    // 1xx_CriticalD V Two-Handed -> CriticalD V Two-Handed
    { 0x7209C34E, 0x5802866E },    // 1xx_CriticalD VI -> CriticalD VI
    { 0x6C7BC6B6, 0x721AF1D6 },    // 1xx_CriticalD VI Secondary -> CriticalD VI Secondary
    { 0x5D231759, 0x16A7A679 },    // 1xx_CriticalD VI Two-Handed -> CriticalD VI Two-Handed
    { 0xB3422D77, 0x58535497 },    // 1xx_CriticalD VII -> CriticalD VII
    { 0x5299B81F, 0x0C1E473F },    // 1xx_CriticalD VII Secondary -> CriticalD VII Secondary
    { 0x06FF35E2, 0xF115A902 },    // 1xx_CriticalD VII Two-Handed -> CriticalD VII Two-Handed
    { 0x1B87DCC0, 0x62BDE7E0 },    // 1xx_CriticalD VIII -> CriticalD VIII
    { 0xFC75D6A8, 0xE68C49C8 },    // 1xx_CriticalD VIII Secondary -> CriticalD VIII Secondary
    { 0xEC5F258B, 0x1943FCAB },    // 1xx_CriticalD VIII Two-Handed -> CriticalD VIII Two-Handed
    { 0x1ABA7A47, 0xB5175967 },    // 1xx_CriticalD X -> CriticalD X
    { 0x513448EF, 0xFC0A900F },    // 1xx_CriticalD X Secondary -> CriticalD X Secondary
    { 0xD8EBE0B2, 0xDE8B0BD2 },    // 1xx_CriticalD X Two-Handed -> CriticalD X Two-Handed
    { 0x7209C390, 0xB5175967 },    // 1xx_CriticalD XI -> CriticalD X
    { 0xCE628178, 0xFC0A900F },    // 1xx_CriticalD XI Secondary -> CriticalD X Secondary
    { 0xFBE12A5B, 0xDE8B0BD2 },    // 1xx_CriticalD XI Two-Handed -> CriticalD X Two-Handed
    { 0xC7647349, 0x7EFE5669 },    // 1xx_Damage 0.1 Legendary -> Damage 0.1 Legendary
    { 0x4CC1288A, 0x045B0BAA },    // 1xx_Damage 0.2 Legendary -> Damage 0.2 Legendary
    { 0xD21DDDCB, 0x89B7C0EB },    // 1xx_Damage 0.3 Legendary -> Damage 0.3 Legendary
    { 0x7B0BBC88, 0x79DFEFA8 },    // 1xx_Damage I -> Damage I
    { 0xDC834DF1, 0xB5DDE511 },    // 1xx_Damage II -> Damage II
    { 0x6CED0C7A, 0x719A879A },    // 1xx_Damage III -> Damage III
    { 0xDC834DFE, 0xB5DDE51E },    // 1xx_Damage IV -> Damage IV
    { 0x7B0BBC95, 0x79DFEFB5 },    // 1xx_Damage V -> Damage V
    { 0xDC834F9E, 0xB5DDE6BE },    // 1xx_Damage VI -> Damage VI
    { 0x6CED43C7, 0x719ABEE7 },    // 1xx_Damage VII -> Damage VII
    { 0x0A95BD10, 0x719ABEE7 },    // 1xx_Damage VIII -> Damage VII
    { 0x4910535C, 0x7CCBBA7C },    // 1xx_DamageBonusArcane 1 Legendary -> DamageBonusArcane 1 Legendary
    { 0xCE6D089D, 0x02286FBD },    // 1xx_DamageBonusArcane 2 Legendary -> DamageBonusArcane 2 Legendary
    { 0x53C9BDDE, 0x878524FE },    // 1xx_DamageBonusArcane 3 Legendary -> DamageBonusArcane 3 Legendary
    { 0xD926731F, 0x0CE1DA3F },    // 1xx_DamageBonusArcane 4 Legendary -> DamageBonusArcane 4 Legendary
    { 0x3A1E8AB4, 0x3395A9D4 },    // 1xx_DamageBonusCold 1 Legendary -> DamageBonusCold 1 Legendary
    { 0xBF7B3FF5, 0xB8F25F15 },    // 1xx_DamageBonusCold 2 Legendary -> DamageBonusCold 2 Legendary
    { 0x44D7F536, 0x3E4F1456 },    // 1xx_DamageBonusCold 3 Legendary -> DamageBonusCold 3 Legendary
    { 0xCA34AA77, 0xC3ABC997 },    // 1xx_DamageBonusCold 4 Legendary -> DamageBonusCold 4 Legendary
    { 0x3DF1CD18, 0x3768EC38 },    // 1xx_DamageBonusFire 1 Legendary -> DamageBonusFire 1 Legendary
    { 0xC34E8259, 0xBCC5A179 },    // 1xx_DamageBonusFire 2 Legendary -> DamageBonusFire 2 Legendary
    { 0x48AB379A, 0x422256BA },    // 1xx_DamageBonusFire 3 Legendary -> DamageBonusFire 3 Legendary
    { 0xCE07ECDB, 0xC77F0BFB },    // 1xx_DamageBonusFire 4 Legendary -> DamageBonusFire 4 Legendary
    { 0xF9F40FAE, 0xF36B2ECE },    // 1xx_DamageBonusHoly 1 Legendary -> DamageBonusHoly 1 Legendary
    { 0x7F50C4EF, 0x78C7E40F },    // 1xx_DamageBonusHoly 2 Legendary -> DamageBonusHoly 2 Legendary
    { 0x04AD7A30, 0xFE249950 },    // 1xx_DamageBonusHoly 3 Legendary -> DamageBonusHoly 3 Legendary
    { 0x8A0A2F71, 0x83814E91 },    // 1xx_DamageBonusHoly 4 Legendary -> DamageBonusHoly 4 Legendary
    { 0xD3FECA96, 0xEA665DB6 },    // 1xx_DamageBonusLightning 1 Legendary -> DamageBonusLightning 1 Legendary
    { 0x595B7FD7, 0x6FC312F7 },    // 1xx_DamageBonusLightning 2 Legendary -> DamageBonusLightning 2 Legendary
    { 0xDEB83518, 0xF51FC838 },    // 1xx_DamageBonusLightning 3 Legendary -> DamageBonusLightning 3 Legendary
    { 0x6414EA59, 0x7A7C7D79 },    // 1xx_DamageBonusLightning 4 Legendary -> DamageBonusLightning 4 Legendary
    { 0x4DAAD74A, 0x81663E6A },    // 1xx_DamageBonusPoison 1 Legendary -> DamageBonusPoison 1 Legendary
    { 0xD3078C8B, 0x06C2F3AB },    // 1xx_DamageBonusPoison 2 Legendary -> DamageBonusPoison 2 Legendary
    { 0x586441CC, 0x8C1FA8EC },    // 1xx_DamageBonusPoison 3 Legendary -> DamageBonusPoison 3 Legendary
    { 0xDDC0F70D, 0x117C5E2D },    // 1xx_DamageBonusPoison 4 Legendary -> DamageBonusPoison 4 Legendary
    { 0x1258AA00, 0xFFFFFFFF },    // 1xx_DamageReductionArcane 0.1 Legendary -> (none)
    { 0x1072E887, 0xC9F777A7 },    // 1xx_DamageReductionArcane 1 -> DamageReductionArcane 1
    { 0x1ECFF997, 0x08E66CB7 },    // 1xx_DamageReductionArcane 10 -> DamageReductionArcane 10
    { 0x1ECFF998, 0x08E66CB8 },    // 1xx_DamageReductionArcane 11 -> DamageReductionArcane 11
    { 0x1ECFF999, 0x08E66CB9 },    // 1xx_DamageReductionArcane 12 -> DamageReductionArcane 12
    { 0x1ECFF99A, 0x08E66CB9 },    // 1xx_DamageReductionArcane 13 -> DamageReductionArcane 12
    { 0x1072E888, 0xC9F777A8 },    // 1xx_DamageReductionArcane 2 -> DamageReductionArcane 2
    { 0x1072E889, 0xC9F777A9 },    // 1xx_DamageReductionArcane 3 -> DamageReductionArcane 3
    { 0x1072E88A, 0xC9F777AA },    // 1xx_DamageReductionArcane 4 -> DamageReductionArcane 4
    { 0x1072E88B, 0xC9F777AB },    // 1xx_DamageReductionArcane 5 -> DamageReductionArcane 5
    { 0x1072E88C, 0xC9F777AC },    // 1xx_DamageReductionArcane 6 -> DamageReductionArcane 6
    { 0x1072E88D, 0xC9F777AD },    // 1xx_DamageReductionArcane 7 -> DamageReductionArcane 7
    { 0x1072E88E, 0xC9F777AE },    // 1xx_DamageReductionArcane 8 -> DamageReductionArcane 8
    { 0x1072E88F, 0xC9F777AF },    // 1xx_DamageReductionArcane 9 -> DamageReductionArcane 9
    { 0x938D9DD8, 0xFFFFFFFF },    // 1xx_DamageReductionCold 0.1 Legendary -> (none)
    { 0xDB59585F, 0x862F9F7F },    // 1xx_DamageReductionCold 1 -> DamageReductionCold 1
    { 0x4684646F, 0x4C238F8F },    // 1xx_DamageReductionCold 10 -> DamageReductionCold 10
    { 0x46846470, 0x4C238F90 },    // 1xx_DamageReductionCold 11 -> DamageReductionCold 11
    { 0x46846471, 0x4C238F91 },    // 1xx_DamageReductionCold 12 -> DamageReductionCold 12
    { 0x46846472, 0x4C238F91 },    // 1xx_DamageReductionCold 13 -> DamageReductionCold 12
    { 0xDB595860, 0x862F9F80 },    // 1xx_DamageReductionCold 2 -> DamageReductionCold 2
    { 0xDB595861, 0x862F9F81 },    // 1xx_DamageReductionCold 3 -> DamageReductionCold 3
    { 0xDB595862, 0x862F9F82 },    // 1xx_DamageReductionCold 4 -> DamageReductionCold 4
    { 0xDB595863, 0x862F9F83 },    // 1xx_DamageReductionCold 5 -> DamageReductionCold 5
    { 0xDB595864, 0x862F9F84 },    // 1xx_DamageReductionCold 6 -> DamageReductionCold 6
    { 0xDB595865, 0x862F9F85 },    // 1xx_DamageReductionCold 7 -> DamageReductionCold 7
    { 0xDB595866, 0x862F9F86 },    // 1xx_DamageReductionCold 8 -> DamageReductionCold 8
    { 0xDB595867, 0x862F9F87 },    // 1xx_DamageReductionCold 9 -> DamageReductionCold 9
    { 0xD93B093C, 0xFFFFFFFF },    // 1xx_DamageReductionFire 0.1 Legendary -> (none)
    { 0xE1EF8DC3, 0x8CC5D4E3 },    // 1xx_DamageReductionFire 1 -> DamageReductionFire 1
    { 0x1FE14653, 0x25807173 },    // 1xx_DamageReductionFire 10 -> DamageReductionFire 10
    { 0x1FE14654, 0x25807174 },    // 1xx_DamageReductionFire 11 -> DamageReductionFire 11
    { 0x1FE14655, 0x25807175 },    // 1xx_DamageReductionFire 12 -> DamageReductionFire 12
    { 0x1FE14656, 0x25807175 },    // 1xx_DamageReductionFire 13 -> DamageReductionFire 12
    { 0xE1EF8DC4, 0x8CC5D4E4 },    // 1xx_DamageReductionFire 2 -> DamageReductionFire 2
    { 0xE1EF8DC5, 0x8CC5D4E5 },    // 1xx_DamageReductionFire 3 -> DamageReductionFire 3
    { 0xE1EF8DC6, 0x8CC5D4E6 },    // 1xx_DamageReductionFire 4 -> DamageReductionFire 4
    { 0xE1EF8DC7, 0x8CC5D4E7 },    // 1xx_DamageReductionFire 5 -> DamageReductionFire 5
    { 0xE1EF8DC8, 0x8CC5D4E8 },    // 1xx_DamageReductionFire 6 -> DamageReductionFire 6
    { 0xE1EF8DC9, 0x8CC5D4E9 },    // 1xx_DamageReductionFire 7 -> DamageReductionFire 7
    { 0xE1EF8DCA, 0x8CC5D4EA },    // 1xx_DamageReductionFire 8 -> DamageReductionFire 8
    { 0xE1EF8DCB, 0x8CC5D4EB },    // 1xx_DamageReductionFire 9 -> DamageReductionFire 9
    { 0x9ED84952, 0xFFFFFFFF },    // 1xx_DamageReductionHoly 0.1 Legendary -> (none)
    { 0xE7037CD9, 0x91D9C3F9 },    // 1xx_DamageReductionHoly 1 -> DamageReductionHoly 1
    { 0xC7731829, 0xCD124349 },    // 1xx_DamageReductionHoly 10 -> DamageReductionHoly 10
    { 0xC773182A, 0xCD12434A },    // 1xx_DamageReductionHoly 11 -> DamageReductionHoly 11
    { 0xC773182B, 0xCD12434B },    // 1xx_DamageReductionHoly 12 -> DamageReductionHoly 12
    { 0xC773182C, 0xCD12434B },    // 1xx_DamageReductionHoly 13 -> DamageReductionHoly 12
    { 0xE7037CDA, 0x91D9C3FA },    // 1xx_DamageReductionHoly 2 -> DamageReductionHoly 2
    { 0xE7037CDB, 0x91D9C3FB },    // 1xx_DamageReductionHoly 3 -> DamageReductionHoly 3
    { 0xE7037CDC, 0x91D9C3FC },    // 1xx_DamageReductionHoly 4 -> DamageReductionHoly 4
    { 0xE7037CDD, 0x91D9C3FD },    // 1xx_DamageReductionHoly 5 -> DamageReductionHoly 5
    { 0xE7037CDE, 0x91D9C3FE },    // 1xx_DamageReductionHoly 6 -> DamageReductionHoly 6
    { 0xE7037CDF, 0x91D9C3FF },    // 1xx_DamageReductionHoly 7 -> DamageReductionHoly 7
    { 0xE7037CE0, 0x91D9C400 },    // 1xx_DamageReductionHoly 8 -> DamageReductionHoly 8
    { 0xE7037CE1, 0x91D9C401 },    // 1xx_DamageReductionHoly 9 -> DamageReductionHoly 9
    { 0x56E441FA, 0xFFFFFFFF },    // 1xx_DamageReductionLightning 0.1 Legendary -> (none)
    { 0xD9373981, 0xA2B6F4A1 },    // 1xx_DamageReductionLightning 1 -> DamageReductionLightning 1
    { 0x001E69D1, 0xF99588F1 },    // 1xx_DamageReductionLightning 10 -> DamageReductionLightning 10
    { 0x001E69D2, 0xF99588F2 },    // 1xx_DamageReductionLightning 11 -> DamageReductionLightning 11
    { 0x001E69D3, 0xF99588F3 },    // 1xx_DamageReductionLightning 12 -> DamageReductionLightning 12
    { 0x001E69D4, 0xF99588F3 },    // 1xx_DamageReductionLightning 13 -> DamageReductionLightning 12
    { 0xD9373982, 0xA2B6F4A2 },    // 1xx_DamageReductionLightning 2 -> DamageReductionLightning 2
    { 0xD9373983, 0xA2B6F4A3 },    // 1xx_DamageReductionLightning 3 -> DamageReductionLightning 3
    { 0xD9373984, 0xA2B6F4A4 },    // 1xx_DamageReductionLightning 4 -> DamageReductionLightning 4
    { 0xD9373985, 0xA2B6F4A5 },    // 1xx_DamageReductionLightning 5 -> DamageReductionLightning 5
    { 0xD9373986, 0xA2B6F4A6 },    // 1xx_DamageReductionLightning 6 -> DamageReductionLightning 6
    { 0xD9373987, 0xA2B6F4A7 },    // 1xx_DamageReductionLightning 7 -> DamageReductionLightning 7
    { 0xD9373988, 0xA2B6F4A8 },    // 1xx_DamageReductionLightning 8 -> DamageReductionLightning 8
    { 0xD9373989, 0xA2B6F4A9 },    // 1xx_DamageReductionLightning 9 -> DamageReductionLightning 9
    { 0xA7A3E16E, 0xFFFFFFFF },    // 1xx_DamageReductionPoison 0.1 Legendary -> (none)
    { 0x10A50AF5, 0xCA299A15 },    // 1xx_DamageReductionPoison 1 -> DamageReductionPoison 1
    { 0x254669C5, 0x0F5CDCE5 },    // 1xx_DamageReductionPoison 10 -> DamageReductionPoison 10
    { 0x254669C6, 0x0F5CDCE6 },    // 1xx_DamageReductionPoison 11 -> DamageReductionPoison 11
    { 0x254669C7, 0x0F5CDCE7 },    // 1xx_DamageReductionPoison 12 -> DamageReductionPoison 12
    { 0x254669C8, 0x0F5CDCE7 },    // 1xx_DamageReductionPoison 13 -> DamageReductionPoison 12
    { 0x10A50AF6, 0xCA299A16 },    // 1xx_DamageReductionPoison 2 -> DamageReductionPoison 2
    { 0x10A50AF7, 0xCA299A17 },    // 1xx_DamageReductionPoison 3 -> DamageReductionPoison 3
    { 0x10A50AF8, 0xCA299A18 },    // 1xx_DamageReductionPoison 4 -> DamageReductionPoison 4
    { 0x10A50AF9, 0xCA299A19 },    // 1xx_DamageReductionPoison 5 -> DamageReductionPoison 5
    { 0x10A50AFA, 0xCA299A1A },    // 1xx_DamageReductionPoison 6 -> DamageReductionPoison 6
    { 0x10A50AFB, 0xCA299A1B },    // 1xx_DamageReductionPoison 7 -> DamageReductionPoison 7
    { 0x10A50AFC, 0xCA299A1C },    // 1xx_DamageReductionPoison 8 -> DamageReductionPoison 8
    { 0x10A50AFD, 0xCA299A1D },    // 1xx_DamageReductionPoison 9 -> DamageReductionPoison 9
    { 0xD2748285, 0xFFFFFFFF },    // 1xx_DamageVsElite 0.1 Legendary -> (none)
    { 0x9D5F3AED, 0xFFFFFFFF },    // 1xx_DamageVsElite 0.1 Secondary Legendary -> (none)
    { 0xDAAE118C, 0x08A580AC },    // 1xx_DamageVsElite 1 -> DamageVsElite 1
    { 0x7DCD7A74, 0xAAB25194 },    // 1xx_DamageVsElite 1 Secondary -> DamageVsElite 1 Secondary
    { 0x6C93A7E7, 0xB0B6ADC6 },    // 1xx_DamageVsElite 13 Secondary -> DamageVsElite 12 Secondary
    { 0xF1F05D28, 0xB0B6ADC6 },    // 1xx_DamageVsElite 14 Secondary -> DamageVsElite 12 Secondary
    { 0x774D1269, 0xB0B6ADC6 },    // 1xx_DamageVsElite 15 Secondary -> DamageVsElite 12 Secondary
    { 0xFCA9C7AA, 0xB0B6ADC6 },    // 1xx_DamageVsElite 16 Secondary -> DamageVsElite 12 Secondary
    { 0xDAAE118D, 0x08A580AD },    // 1xx_DamageVsElite 2 -> DamageVsElite 2
    { 0x032A2FB5, 0x300F06D5 },    // 1xx_DamageVsElite 2 Secondary -> DamageVsElite 2 Secondary
    { 0xDAAE118E, 0x08A580AE },    // 1xx_DamageVsElite 3 -> DamageVsElite 3
    { 0x8886E4F6, 0xB56BBC16 },    // 1xx_DamageVsElite 3 Secondary -> DamageVsElite 3 Secondary
    { 0xDAAE118F, 0x08A580AF },    // 1xx_DamageVsElite 4 -> DamageVsElite 4
    { 0xDAAE1190, 0x08A580B0 },    // 1xx_DamageVsElite 5 -> DamageVsElite 5
    { 0xDAAE1191, 0x08A580B1 },    // 1xx_DamageVsElite 6 -> DamageVsElite 6
    { 0xDAAE1192, 0x08A580B2 },    // 1xx_DamageVsElite 7 -> DamageVsElite 7
    { 0x9774636B, 0xEF45CE8B },    // 1xx_DamageVsMonsterTypeBeast 0.1 Legendary -> DamageVsMonsterTypeBeast 0.1 Legendary
    { 0xFC50E972, 0xC5D0A492 },    // 1xx_DamageVsMonsterTypeBeast 1 -> DamageVsMonsterTypeBeast 1
    { 0xFC50E973, 0xC5D0A493 },    // 1xx_DamageVsMonsterTypeBeast 2 -> DamageVsMonsterTypeBeast 2
    { 0xFC50E974, 0xC5D0A494 },    // 1xx_DamageVsMonsterTypeBeast 3 -> DamageVsMonsterTypeBeast 3
    { 0xFC50E975, 0xC5D0A495 },    // 1xx_DamageVsMonsterTypeBeast 4 -> DamageVsMonsterTypeBeast 4
    { 0xFC50E976, 0xC5D0A496 },    // 1xx_DamageVsMonsterTypeBeast 5 -> DamageVsMonsterTypeBeast 5
    { 0xFC50E977, 0xC5D0A497 },    // 1xx_DamageVsMonsterTypeBeast 6 -> DamageVsMonsterTypeBeast 6
    { 0xD6DE9DEF, 0x2EB0090F },    // 1xx_DamageVsMonsterTypeDemon 0.1 Legendary -> DamageVsMonsterTypeDemon 0.1 Legendary
    { 0x971C3DF6, 0x609BF916 },    // 1xx_DamageVsMonsterTypeDemon 1 -> DamageVsMonsterTypeDemon 1
    { 0x971C3DF7, 0x609BF917 },    // 1xx_DamageVsMonsterTypeDemon 2 -> DamageVsMonsterTypeDemon 2
    { 0x971C3DF8, 0x609BF918 },    // 1xx_DamageVsMonsterTypeDemon 3 -> DamageVsMonsterTypeDemon 3
    { 0x971C3DF9, 0x609BF919 },    // 1xx_DamageVsMonsterTypeDemon 4 -> DamageVsMonsterTypeDemon 4
    { 0x971C3DFA, 0x609BF91A },    // 1xx_DamageVsMonsterTypeDemon 5 -> DamageVsMonsterTypeDemon 5
    { 0x971C3DFB, 0x609BF91B },    // 1xx_DamageVsMonsterTypeDemon 6 -> DamageVsMonsterTypeDemon 6
    { 0xD0C246B5, 0x2893B1D5 },    // 1xx_DamageVsMonsterTypeHuman 0.1 Legendary -> DamageVsMonsterTypeHuman 0.1 Legendary
    { 0xF0500DBC, 0xB9CFC8DC },    // 1xx_DamageVsMonsterTypeHuman 1 -> DamageVsMonsterTypeHuman 1
    { 0xF0500DBD, 0xB9CFC8DD },    // 1xx_DamageVsMonsterTypeHuman 2 -> DamageVsMonsterTypeHuman 2
    { 0xF0500DBE, 0xB9CFC8DE },    // 1xx_DamageVsMonsterTypeHuman 3 -> DamageVsMonsterTypeHuman 3
    { 0xF0500DBF, 0xB9CFC8DF },    // 1xx_DamageVsMonsterTypeHuman 4 -> DamageVsMonsterTypeHuman 4
    { 0xF0500DC0, 0xB9CFC8E0 },    // 1xx_DamageVsMonsterTypeHuman 5 -> DamageVsMonsterTypeHuman 5
    { 0xF0500DC1, 0xB9CFC8E1 },    // 1xx_DamageVsMonsterTypeHuman 6 -> DamageVsMonsterTypeHuman 6
    { 0xFA6B5B0D, 0x4C6A2A2D },    // 1xx_DamageVsMonsterTypeUndead 0.1 Legendary -> DamageVsMonsterTypeUndead 0.1 Legendary
    { 0xCA15DE14, 0xC38CFD34 },    // 1xx_DamageVsMonsterTypeUndead 1 -> DamageVsMonsterTypeUndead 1
    { 0xCA15DE15, 0xC38CFD35 },    // 1xx_DamageVsMonsterTypeUndead 2 -> DamageVsMonsterTypeUndead 2
    { 0xCA15DE16, 0xC38CFD36 },    // 1xx_DamageVsMonsterTypeUndead 3 -> DamageVsMonsterTypeUndead 3
    { 0xCA15DE17, 0xC38CFD37 },    // 1xx_DamageVsMonsterTypeUndead 4 -> DamageVsMonsterTypeUndead 4
    { 0xCA15DE18, 0xC38CFD38 },    // 1xx_DamageVsMonsterTypeUndead 5 -> DamageVsMonsterTypeUndead 5
    { 0xCA15DE19, 0xC38CFD39 },    // 1xx_DamageVsMonsterTypeUndead 6 -> DamageVsMonsterTypeUndead 6
    { 0x3E506925, 0xFFFFFFFF },    // 1xx_DamReductionVsElite 0.1 Legendary -> (none)
    { 0xBA03082C, 0x64D94F4C },    // 1xx_DamReductionVsElite 1 -> DamReductionVsElite 1
    { 0xBA03082D, 0x64D94F4D },    // 1xx_DamReductionVsElite 2 -> DamReductionVsElite 2
    { 0xBA03082E, 0x64D94F4E },    // 1xx_DamReductionVsElite 3 -> DamReductionVsElite 3
    { 0xBA03082F, 0x64D94F4F },    // 1xx_DamReductionVsElite 4 -> DamReductionVsElite 4
    { 0xBA030830, 0x64D94F50 },    // 1xx_DamReductionVsElite 5 -> DamReductionVsElite 5
    { 0xBA030831, 0x64D94F51 },    // 1xx_DamReductionVsElite 6 -> DamReductionVsElite 6
    { 0xBA030832, 0x64D94F52 },    // 1xx_DamReductionVsElite 7 -> DamReductionVsElite 7
    { 0xFE543F2C, 0xFFFFFFFF },    // 1xx_DefenseMelee 0.1 Legendary -> (none)
    { 0x4D545BB3, 0x948A66D3 },    // 1xx_DefenseMelee 1 -> DefenseMelee 1
    { 0x4D545BB4, 0x948A66D4 },    // 1xx_DefenseMelee 2 -> DefenseMelee 2
    { 0x4D545BB5, 0x948A66D5 },    // 1xx_DefenseMelee 3 -> DefenseMelee 3
    { 0x4D545BB6, 0x948A66D6 },    // 1xx_DefenseMelee 4 -> DefenseMelee 4
    { 0x4D545BB7, 0x948A66D7 },    // 1xx_DefenseMelee 5 -> DefenseMelee 5
    { 0x4D545BB8, 0x948A66D8 },    // 1xx_DefenseMelee 6 -> DefenseMelee 6
    { 0x4D545BB9, 0x948A66D9 },    // 1xx_DefenseMelee 7 -> DefenseMelee 7
    { 0x4D545BBA, 0x948A66DA },    // 1xx_DefenseMelee 8 -> DefenseMelee 8
    { 0x252992DA, 0xFFFFFFFF },    // 1xx_DefenseMissile 0.1 Legendary -> (none)
    { 0xE0D43A61, 0xCDB98D81 },    // 1xx_DefenseMissile 1 -> DefenseMissile 1
    { 0xE0D43A62, 0xCDB98D82 },    // 1xx_DefenseMissile 2 -> DefenseMissile 2
    { 0xE0D43A63, 0xCDB98D83 },    // 1xx_DefenseMissile 3 -> DefenseMissile 3
    { 0xE0D43A64, 0xCDB98D84 },    // 1xx_DefenseMissile 4 -> DefenseMissile 4
    { 0xE0D43A65, 0xCDB98D85 },    // 1xx_DefenseMissile 5 -> DefenseMissile 5
    { 0xE0D43A66, 0xCDB98D86 },    // 1xx_DefenseMissile 6 -> DefenseMissile 6
    { 0xE0D43A67, 0xCDB98D87 },    // 1xx_DefenseMissile 7 -> DefenseMissile 7
    { 0xE0D43A68, 0xCDB98D88 },    // 1xx_DefenseMissile 8 -> DefenseMissile 8
    { 0x04DEF052, 0x074AF772 },    // 1xx_Dex 1 -> Dex 1
    { 0xAEE008BA, 0xDCD777DA },    // 1xx_Dex 1 Secondary -> Dex 1 Secondary
    { 0xEC0F99DD, 0xD8F4ECFD },    // 1xx_Dex 1 Two-Handed -> Dex 1 Two-Handed
    { 0xA0BCFAC2, 0xF0A9E5E2 },    // 1xx_Dex 10 -> Dex 10
    { 0x2FE1DF2A, 0x1CC7324A },    // 1xx_Dex 10 Secondary -> Dex 10 Secondary
    { 0x8D4C3E4D, 0x16DBF56D },    // 1xx_Dex 10 Two-Handed -> Dex 10 Two-Handed
    { 0xA0BCFAC3, 0xF0A9E5E3 },    // 1xx_Dex 11 -> Dex 11
    { 0xB53E946B, 0xA223E78B },    // 1xx_Dex 11 Secondary -> Dex 11 Secondary
    { 0xBE3F9BAE, 0x47CF52CE },    // 1xx_Dex 11 Two-Handed -> Dex 11 Two-Handed
    { 0xA0BCFAC4, 0xF0A9E5E4 },    // 1xx_Dex 12 -> Dex 12
    { 0x3A9B49AC, 0x27809CCC },    // 1xx_Dex 12 Secondary -> Dex 12 Secondary
    { 0xEF32F90F, 0x78C2B02F },    // 1xx_Dex 12 Two-Handed -> Dex 12 Two-Handed
    { 0xA0BCFAC5, 0xF0A9E5E5 },    // 1xx_Dex 13 -> Dex 13
    { 0xBFF7FEED, 0xACDD520D },    // 1xx_Dex 13 Secondary -> Dex 13 Secondary
    { 0x20265670, 0xA9B60D90 },    // 1xx_Dex 13 Two-Handed -> Dex 13 Two-Handed
    { 0xA0BCFAC6, 0xF0A9E5E6 },    // 1xx_Dex 14 -> Dex 14
    { 0x4554B42E, 0x323A074E },    // 1xx_Dex 14 Secondary -> Dex 14 Secondary
    { 0x5119B3D1, 0xDAA96AF1 },    // 1xx_Dex 14 Two-Handed -> Dex 14 Two-Handed
    { 0x75724CC0, 0xFFFFFFFF },    // 1xx_Dex 14_Archon -> (none)
    { 0xA0BCFAC7, 0xF0A9E5E7 },    // 1xx_Dex 15 -> Dex 15
    { 0xCAB1696F, 0xB796BC8F },    // 1xx_Dex 15 Secondary -> Dex 15 Secondary
    { 0x820D1132, 0x0B9CC852 },    // 1xx_Dex 15 Two-Handed -> Dex 15 Two-Handed
    { 0xA0BCFAC8, 0xF0A9E5E8 },    // 1xx_Dex 16 -> Dex 16
    { 0x500E1EB0, 0x3CF371D0 },    // 1xx_Dex 16 Secondary -> Dex 16 Secondary
    { 0xB3006E93, 0x3C9025B3 },    // 1xx_Dex 16 Two-Handed -> Dex 16 Two-Handed
    { 0xA0BCFAC9, 0xF0A9E5E9 },    // 1xx_Dex 17 -> Dex 17
    { 0xD56AD3F1, 0xC2502711 },    // 1xx_Dex 17 Secondary -> Dex 17 Secondary
    { 0xE3F3CBF4, 0x3C9025B3 },    // 1xx_Dex 17 Two-Handed -> Dex 16 Two-Handed
    { 0x04DEF053, 0x074AF773 },    // 1xx_Dex 2 -> Dex 2
    { 0x343CBDFB, 0x62342D1B },    // 1xx_Dex 2 Secondary -> Dex 2 Secondary
    { 0x1D02F73E, 0x09E84A5E },    // 1xx_Dex 2 Two-Handed -> Dex 2 Two-Handed
    { 0x04DEF054, 0x074AF774 },    // 1xx_Dex 3 -> Dex 3
    { 0xB999733C, 0xE790E25C },    // 1xx_Dex 3 Secondary -> Dex 3 Secondary
    { 0x4DF6549F, 0x3ADBA7BF },    // 1xx_Dex 3 Two-Handed -> Dex 3 Two-Handed
    { 0x04DEF055, 0x074AF775 },    // 1xx_Dex 4 -> Dex 4
    { 0x3EF6287D, 0x6CED979D },    // 1xx_Dex 4 Secondary -> Dex 4 Secondary
    { 0x7EE9B200, 0x6BCF0520 },    // 1xx_Dex 4 Two-Handed -> Dex 4 Two-Handed
    { 0x04DEF056, 0x074AF776 },    // 1xx_Dex 5 -> Dex 5
    { 0xC452DDBE, 0xF24A4CDE },    // 1xx_Dex 5 Secondary -> Dex 5 Secondary
    { 0xAFDD0F61, 0x9CC26281 },    // 1xx_Dex 5 Two-Handed -> Dex 5 Two-Handed
    { 0x04DEF057, 0x074AF777 },    // 1xx_Dex 6 -> Dex 6
    { 0x49AF92FF, 0x77A7021F },    // 1xx_Dex 6 Secondary -> Dex 6 Secondary
    { 0xE0D06CC2, 0xCDB5BFE2 },    // 1xx_Dex 6 Two-Handed -> Dex 6 Two-Handed
    { 0x04DEF058, 0x074AF778 },    // 1xx_Dex 7 -> Dex 7
    { 0xCF0C4840, 0xFD03B760 },    // 1xx_Dex 7 Secondary -> Dex 7 Secondary
    { 0x11C3CA23, 0xFEA91D43 },    // 1xx_Dex 7 Two-Handed -> Dex 7 Two-Handed
    { 0x04DEF059, 0x074AF779 },    // 1xx_Dex 8 -> Dex 8
    { 0x5468FD81, 0x82606CA1 },    // 1xx_Dex 8 Secondary -> Dex 8 Secondary
    { 0x42B72784, 0x2F9C7AA4 },    // 1xx_Dex 8 Two-Handed -> Dex 8 Two-Handed
    { 0x04DEF05A, 0x074AF77A },    // 1xx_Dex 9 -> Dex 9
    { 0xD9C5B2C2, 0x07BD21E2 },    // 1xx_Dex 9 Secondary -> Dex 9 Secondary
    { 0x73AA84E5, 0x608FD805 },    // 1xx_Dex 9 Two-Handed -> Dex 9 Two-Handed
    { 0x43340B36, 0xFFFFFFFF },    // 1xx_DexInt 0.1 Legendary -> (none)
    { 0xBE4214DE, 0xFFFFFFFF },    // 1xx_DexInt 0.1 Secondary Legendary -> (none)
    { 0xC9E92EE1, 0xFFFFFFFF },    // 1xx_DexInt 0.1 Two-Handed Legendary -> (none)
    { 0xC93248F5, 0xC8067C15 },    // 1xx_DexInt I -> DexInt I
    { 0xFF48C91D, 0xBACF643D },    // 1xx_DexInt I Secondary -> DexInt I Secondary
    { 0x499066A0, 0x75EA65C0 },    // 1xx_DexInt I Two-Handed -> DexInt I Two-Handed
    { 0xEF7B67FE, 0xC8D5FF1E },    // 1xx_DexInt II -> DexInt II
    { 0x3F070766, 0x6B610686 },    // 1xx_DexInt II Secondary -> DexInt II Secondary
    { 0x81166E09, 0x38B05129 },    // 1xx_DexInt II Two-Handed -> DexInt II Two-Handed
    { 0xDEE86827, 0xE395E347 },    // 1xx_DexInt III -> DexInt III
    { 0x768D0ECF, 0x2E26F1EF },    // 1xx_DexInt III Secondary -> DexInt III Secondary
    { 0xA95D6292, 0x5433A9B2 },    // 1xx_DexInt III Two-Handed -> DexInt III Two-Handed
    { 0xEF7B680B, 0xC8D5FF2B },    // 1xx_DexInt IV -> DexInt IV
    { 0x04BC3BB3, 0x31163AD3 },    // 1xx_DexInt IV Secondary -> DexInt IV Secondary
    { 0xFD722BF6, 0xB50C0F16 },    // 1xx_DexInt IV Two-Handed -> DexInt IV Two-Handed
    { 0xEF7B680D, 0xC8D5FF2D },    // 1xx_DexInt IX -> DexInt IX
    { 0x0F75A635, 0x3BCFA555 },    // 1xx_DexInt IX Secondary -> DexInt IX Secondary
    { 0x5F58E6B8, 0x16F2C9D8 },    // 1xx_DexInt IX Two-Handed -> DexInt IX Two-Handed
    { 0xC9324902, 0xC8067C22 },    // 1xx_DexInt V -> DexInt V
    { 0xC4FDFD6A, 0x8084988A },    // 1xx_DexInt V Secondary -> DexInt V Secondary
    { 0xC5EC248D, 0xF24623AD },    // 1xx_DexInt V Two-Handed -> DexInt V Two-Handed
    { 0xEF7B69AB, 0xC8D600CB },    // 1xx_DexInt VI -> DexInt VI
    { 0xBB62C553, 0xE7BCC473 },    // 1xx_DexInt VI Secondary -> DexInt VI Secondary
    { 0x88E9E996, 0x4083CCB6 },    // 1xx_DexInt VI Two-Handed -> DexInt VI Two-Handed
    { 0xDEE89F74, 0xE3961A94 },    // 1xx_DexInt VII -> DexInt VII
    { 0x7E608A5C, 0x35FA6D7C },    // 1xx_DexInt VII Secondary -> DexInt VII Secondary
    { 0xABA04FBF, 0x567696DF },    // 1xx_DexInt VII Two-Handed -> DexInt VII Two-Handed
    { 0xBBFC8E5D, 0x56596D7D },    // 1xx_DexInt VIII -> DexInt VIII
    { 0xA116F085, 0x4BED37A5 },    // 1xx_DexInt VIII Secondary -> DexInt VIII Secondary
    { 0x25237B08, 0x2AC2A628 },    // 1xx_DexInt VIII Two-Handed -> DexInt VIII Two-Handed
    { 0xC9324904, 0xC8067C24 },    // 1xx_DexInt X -> DexInt X
    { 0xCFB767EC, 0x8B3E030C },    // 1xx_DexInt X Secondary -> DexInt X Secondary
    { 0x27D2DF4F, 0x542CDE6F },    // 1xx_DexInt X Two-Handed -> DexInt X Two-Handed
    { 0xEF7B69ED, 0xC8D6010D },    // 1xx_DexInt XI -> DexInt XI
    { 0x1D498015, 0x49A37F35 },    // 1xx_DexInt XI Secondary -> DexInt XI Secondary
    { 0x27A7FC98, 0xDF41DFB8 },    // 1xx_DexInt XI Two-Handed -> DexInt XI Two-Handed
    { 0xDEE8A7F6, 0xE3962316 },    // 1xx_DexInt XII -> DexInt XII
    { 0x1D1E9D5E, 0xD4B8807E },    // 1xx_DexInt XII Secondary -> DexInt XII Secondary
    { 0x2220C301, 0xCCF70A21 },    // 1xx_DexInt XII Two-Handed -> DexInt XII Two-Handed
    { 0x7B3AC7DE, 0xFFFFFFFF },    // 1xx_DexVit 0.1 Legendary -> (none)
    { 0xCFBAC386, 0xFFFFFFFF },    // 1xx_DexVit 0.1 Secondary Legendary -> (none)
    { 0x0A77B289, 0xFFFFFFFF },    // 1xx_DexVit 0.1 Two-Handed Legendary -> (none)
    { 0xCA1AC99D, 0xC8EEFCBD },    // 1xx_DexVit I -> DexVit I
    { 0x21A83BC5, 0xDD2ED6E5 },    // 1xx_DexVit I Secondary -> DexVit I Secondary
    { 0xB7DE2E48, 0xE4382D68 },    // 1xx_DexVit I Two-Handed -> DexVit I Two-Handed
    { 0x0D73FDA6, 0xE6CE94C6 },    // 1xx_DexVit II -> DexVit II
    { 0xAD54CF0E, 0xD9AECE2E },    // 1xx_DexVit II Secondary -> DexVit II Secondary
    { 0xB91D2AB1, 0x70B70DD1 },    // 1xx_DexVit II Two-Handed -> DexVit II Two-Handed
    { 0xBBF3B2CF, 0xC0A12DEF },    // 1xx_DexVit III -> DexVit III
    { 0xAE93CB77, 0x662DAE97 },    // 1xx_DexVit III Secondary -> DexVit III Secondary
    { 0xE23BB43A, 0x8D11FB5A },    // 1xx_DexVit III Two-Handed -> DexVit III Two-Handed
    { 0x0D73FDB3, 0xE6CE94D3 },    // 1xx_DexVit IV -> DexVit IV
    { 0x730A035B, 0x9F64027B },    // 1xx_DexVit IV Secondary -> DexVit IV Secondary
    { 0x3578E89E, 0xED12CBBE },    // 1xx_DexVit IV Two-Handed -> DexVit IV Two-Handed
    { 0x0D73FDB5, 0xE6CE94D5 },    // 1xx_DexVit IX -> DexVit IX
    { 0x7DC36DDD, 0xAA1D6CFD },    // 1xx_DexVit IX Secondary -> DexVit IX Secondary
    { 0x975FA360, 0x4EF98680 },    // 1xx_DexVit IX Two-Handed -> DexVit IX Two-Handed
    { 0xCA1AC9AA, 0xC8EEFCCA },    // 1xx_DexVit V -> DexVit V
    { 0xE75D7012, 0xA2E40B32 },    // 1xx_DexVit V Secondary -> DexVit V Secondary
    { 0x3439EC35, 0x6093EB55 },    // 1xx_DexVit V Two-Handed -> DexVit V Two-Handed
    { 0x0D73FF53, 0xE6CE9673 },    // 1xx_DexVit VI -> DexVit VI
    { 0x29B08CFB, 0x560A8C1B },    // 1xx_DexVit VI Secondary -> DexVit VI Secondary
    { 0xC0F0A63E, 0x788A895E },    // 1xx_DexVit VI Two-Handed -> DexVit VI Two-Handed
    { 0xBBF3EA1C, 0xC0A1653C },    // 1xx_DexVit VII -> DexVit VII
    { 0xB6674704, 0x6E012A24 },    // 1xx_DexVit VII Secondary -> DexVit VII Secondary
    { 0xE47EA167, 0x8F54E887 },    // 1xx_DexVit VII Two-Handed -> DexVit VII Two-Handed
    { 0x3A712E05, 0xD4CE0D25 },    // 1xx_DexVit VIII -> DexVit VIII
    { 0xD9F5422D, 0x84CB894D },    // 1xx_DexVit VIII Secondary -> DexVit VIII Secondary
    { 0x79CC01B0, 0x7F6B2CD0 },    // 1xx_DexVit VIII Two-Handed -> DexVit VIII Two-Handed
    { 0xCA1AC9AC, 0xC8EEFCCC },    // 1xx_DexVit X -> DexVit X
    { 0xF216DA94, 0xAD9D75B4 },    // 1xx_DexVit X Secondary -> DexVit X Secondary
    { 0x9620A6F7, 0xC27AA617 },    // 1xx_DexVit X Two-Handed -> DexVit X Two-Handed
    { 0x0D73FF95, 0xE6CE96B5 },    // 1xx_DexVit XI -> DexVit XI
    { 0x8B9747BD, 0xB7F146DD },    // 1xx_DexVit XI Secondary -> DexVit XI Secondary
    { 0x5FAEB940, 0x17489C60 },    // 1xx_DexVit XI Two-Handed -> DexVit XI Two-Handed
    { 0xBBF3F29E, 0xC0A16DBE },    // 1xx_DexVit XII -> DexVit XII
    { 0x55255A06, 0x0CBF3D26 },    // 1xx_DexVit XII Secondary -> DexVit XII Secondary
    { 0x5AFF14A9, 0x05D55BC9 },    // 1xx_DexVit XII Two-Handed -> DexVit XII Two-Handed
    { 0x6CC11C07, 0x0038BF27 },    // 1xx_DR 1 -> DR 1
    { 0xB6401AAF, 0xFD7625CF },    // 1xx_DR 1 Secondary -> DR 1 Secondary
    { 0x04E49D17, 0x0750A437 },    // 1xx_DR 10 -> DR 10
    { 0x23442FBF, 0x513B9EDF },    // 1xx_DR 10 Secondary -> DR 10 Secondary
    { 0x04E49D18, 0x0750A438 },    // 1xx_DR 11 -> DR 11
    { 0xA8A0E500, 0xD6985420 },    // 1xx_DR 11 Secondary -> DR 11 Secondary
    { 0x04E49D19, 0x0750A439 },    // 1xx_DR 12 -> DR 12
    { 0x2DFD9A41, 0x5BF50961 },    // 1xx_DR 12 Secondary -> DR 12 Secondary
    { 0x04E49D1A, 0x0750A43A },    // 1xx_DR 13 -> DR 13
    { 0xB35A4F82, 0xE151BEA2 },    // 1xx_DR 13 Secondary -> DR 13 Secondary
    { 0x04E49D1B, 0x0750A43B },    // 1xx_DR 14 -> DR 14
    { 0x38B704C3, 0x66AE73E3 },    // 1xx_DR 14 Secondary -> DR 14 Secondary
    { 0x04E49D1C, 0x0750A43C },    // 1xx_DR 15 -> DR 15
    { 0xBE13BA04, 0xEC0B2924 },    // 1xx_DR 15 Secondary -> DR 15 Secondary
    { 0x04E49D1D, 0x0750A43D },    // 1xx_DR 16 -> DR 16
    { 0x43706F45, 0x7167DE65 },    // 1xx_DR 16 Secondary -> DR 16 Secondary
    { 0x04E49D1E, 0x0750A43E },    // 1xx_DR 17 -> DR 17
    { 0xC8CD2486, 0xF6C493A6 },    // 1xx_DR 17 Secondary -> DR 17 Secondary
    { 0x04E49D1F, 0x0750A43F },    // 1xx_DR 18 -> DR 18
    { 0x4E29D9C7, 0x7C2148E7 },    // 1xx_DR 18 Secondary -> DR 18 Secondary
    { 0x04E49D20, 0x0750A440 },    // 1xx_DR 19 -> DR 19
    { 0xD3868F08, 0x017DFE28 },    // 1xx_DR 19 Secondary -> DR 19 Secondary
    { 0x6CC11C08, 0x0038BF28 },    // 1xx_DR 2 -> DR 2
    { 0x3B9CCFF0, 0x82D2DB10 },    // 1xx_DR 2 Secondary -> DR 2 Secondary
    { 0x04E49D38, 0x0750A440 },    // 1xx_DR 20 -> DR 19
    { 0x54378D20, 0x017DFE28 },    // 1xx_DR 20 Secondary -> DR 19 Secondary
    { 0x6CC11C09, 0x0038BF29 },    // 1xx_DR 3 -> DR 3
    { 0xC0F98531, 0x082F9051 },    // 1xx_DR 3 Secondary -> DR 3 Secondary
    { 0x6CC11C0A, 0x0038BF2A },    // 1xx_DR 4 -> DR 4
    { 0x46563A72, 0x8D8C4592 },    // 1xx_DR 4 Secondary -> DR 4 Secondary
    { 0x6CC11C0B, 0x0038BF2B },    // 1xx_DR 5 -> DR 5
    { 0xCBB2EFB3, 0x12E8FAD3 },    // 1xx_DR 5 Secondary -> DR 5 Secondary
    { 0x6CC11C0C, 0x0038BF2C },    // 1xx_DR 6 -> DR 6
    { 0x510FA4F4, 0x9845B014 },    // 1xx_DR 6 Secondary -> DR 6 Secondary
    { 0x6CC11C0D, 0x0038BF2D },    // 1xx_DR 7 -> DR 7
    { 0xD66C5A35, 0x1DA26555 },    // 1xx_DR 7 Secondary -> DR 7 Secondary
    { 0x6CC11C0E, 0x0038BF2E },    // 1xx_DR 8 -> DR 8
    { 0x5BC90F76, 0xA2FF1A96 },    // 1xx_DR 8 Secondary -> DR 8 Secondary
    { 0x6CC11C0F, 0x0038BF2F },    // 1xx_DR 9 -> DR 9
    { 0xE125C4B7, 0x285BCFD7 },    // 1xx_DR 9 Secondary -> DR 9 Secondary
    { 0x62C36071, 0x48BC2391 },    // 1xx_Experience I -> Experience I
    { 0xBB2F6EFA, 0x6040961A },    // 1xx_Experience II -> Experience II
    { 0x211D4EA3, 0x685359C3 },    // 1xx_Experience III -> Experience III
    { 0xBB2F6F07, 0x60409627 },    // 1xx_Experience IV -> Experience IV
    { 0xBB2F6F09, 0x60409629 },    // 1xx_Experience IX -> Experience IX
    { 0x62C3607E, 0x48BC239E },    // 1xx_Experience V -> Experience V
    { 0xBB2F70A7, 0x604097C7 },    // 1xx_Experience VI -> Experience VI
    { 0x211D85F0, 0x68539110 },    // 1xx_Experience VII -> Experience VII
    { 0x44CE4459, 0x72C5B379 },    // 1xx_Experience VIII -> Experience VIII
    { 0x62C36080, 0x48BC23A0 },    // 1xx_Experience X -> Experience X
    { 0xBB2F70E9, 0x60409809 },    // 1xx_Experience XI -> Experience XI
    { 0x211D8E72, 0x68539992 },    // 1xx_Experience XII -> Experience XII
    { 0x5B5F893B, 0xA8E9D85B },    // 1xx_FireD 1 -> FireD 1
    { 0x6D9A30C9, 0x5392F3E9 },    // 1xx_FireD 1 Fast -> FireD 1 Fast
    { 0x3F812F26, 0xFB07CA46 },    // 1xx_FireD 1 Two-Handed -> FireD 1 Two-Handed
    { 0xC750B0CB, 0xC624E3EB },    // 1xx_FireD 10 -> FireD 10
    { 0x41429259, 0xE653B979 },    // 1xx_FireD 10 Fast -> FireD 10 Fast
    { 0x4EF07CB6, 0x7B4A7BD6 },    // 1xx_FireD 10 Two-Handed -> FireD 10 Two-Handed
    { 0xC750B0CC, 0xC624E3EC },    // 1xx_FireD 11 -> FireD 11
    { 0x4397BAFA, 0xE8A8E21A },    // 1xx_FireD 11 Fast -> FireD 11 Fast
    { 0x7FE3DA17, 0xAC3DD937 },    // 1xx_FireD 11 Two-Handed -> FireD 11 Two-Handed
    { 0xC750B0CD, 0xC624E3ED },    // 1xx_FireD 12 -> FireD 12
    { 0x45ECE39B, 0xEAFE0ABB },    // 1xx_FireD 12 Fast -> FireD 12 Fast
    { 0xB0D73778, 0xDD313698 },    // 1xx_FireD 12 Two-Handed -> FireD 12 Two-Handed
    { 0xC750B0CE, 0xC624E3EE },    // 1xx_FireD 13 -> FireD 13
    { 0x48420C3C, 0xED53335C },    // 1xx_FireD 13 Fast -> FireD 13 Fast
    { 0xE1CA94D9, 0x0E2493F9 },    // 1xx_FireD 13 Two-Handed -> FireD 13 Two-Handed
    { 0xC750B0CF, 0xC624E3EF },    // 1xx_FireD 14 -> FireD 14
    { 0x4A9734DD, 0xEFA85BFD },    // 1xx_FireD 14 Fast -> FireD 14 Fast
    { 0x12BDF23A, 0x3F17F15A },    // 1xx_FireD 14 Two-Handed -> FireD 14 Two-Handed
    { 0xC750B0D0, 0xC624E3EF },    // 1xx_FireD 15 -> FireD 14
    { 0x4CEC5D7E, 0xEFA85BFD },    // 1xx_FireD 15 Fast -> FireD 14 Fast
    { 0x43B14F9B, 0x3F17F15A },    // 1xx_FireD 15 Two-Handed -> FireD 14 Two-Handed
    { 0xC750B0D1, 0xC624E3EF },    // 1xx_FireD 16 -> FireD 14
    { 0x4F41861F, 0xEFA85BFD },    // 1xx_FireD 16 Fast -> FireD 14 Fast
    { 0x74A4ACFC, 0x3F17F15A },    // 1xx_FireD 16 Two-Handed -> FireD 14 Two-Handed
    { 0x5B5F893C, 0xA8E9D85C },    // 1xx_FireD 2 -> FireD 2
    { 0x6FEF596A, 0x55E81C8A },    // 1xx_FireD 2 Fast -> FireD 2 Fast
    { 0x70748C87, 0x2BFB27A7 },    // 1xx_FireD 2 Two-Handed -> FireD 2 Two-Handed
    { 0x5B5F893D, 0xA8E9D85D },    // 1xx_FireD 3 -> FireD 3
    { 0x7244820B, 0x583D452B },    // 1xx_FireD 3 Fast -> FireD 3 Fast
    { 0xA167E9E8, 0x5CEE8508 },    // 1xx_FireD 3 Two-Handed -> FireD 3 Two-Handed
    { 0x5B5F893E, 0xA8E9D85E },    // 1xx_FireD 4 -> FireD 4
    { 0x7499AAAC, 0x5A926DCC },    // 1xx_FireD 4 Fast -> FireD 4 Fast
    { 0xD25B4749, 0x8DE1E269 },    // 1xx_FireD 4 Two-Handed -> FireD 4 Two-Handed
    { 0x5B5F893F, 0xA8E9D85F },    // 1xx_FireD 5 -> FireD 5
    { 0x76EED34D, 0x5CE7966D },    // 1xx_FireD 5 Fast -> FireD 5 Fast
    { 0x034EA4AA, 0xBED53FCA },    // 1xx_FireD 5 Two-Handed -> FireD 5 Two-Handed
    { 0x5B5F8940, 0xA8E9D860 },    // 1xx_FireD 6 -> FireD 6
    { 0x7943FBEE, 0x5F3CBF0E },    // 1xx_FireD 6 Fast -> FireD 6 Fast
    { 0x3442020B, 0xEFC89D2B },    // 1xx_FireD 6 Two-Handed -> FireD 6 Two-Handed
    { 0x5B5F8941, 0xA8E9D861 },    // 1xx_FireD 7 -> FireD 7
    { 0x7B99248F, 0x6191E7AF },    // 1xx_FireD 7 Fast -> FireD 7 Fast
    { 0x65355F6C, 0x20BBFA8C },    // 1xx_FireD 7 Two-Handed -> FireD 7 Two-Handed
    { 0x5B5F8942, 0xA8E9D862 },    // 1xx_FireD 8 -> FireD 8
    { 0x7DEE4D30, 0x63E71050 },    // 1xx_FireD 8 Fast -> FireD 8 Fast
    { 0x9628BCCD, 0x51AF57ED },    // 1xx_FireD 8 Two-Handed -> FireD 8 Two-Handed
    { 0x5B5F8943, 0xA8E9D863 },    // 1xx_FireD 9 -> FireD 9
    { 0x804375D1, 0x663C38F1 },    // 1xx_FireD 9 Fast -> FireD 9 Fast
    { 0xC71C1A2E, 0x82A2B54E },    // 1xx_FireD 9 Two-Handed -> FireD 9 Two-Handed
    { 0x6B52A2AA, 0x556915CA },    // 1xx_FireResist 0.1 Legendary -> FireResist 0.1 Legendary
    { 0xF0AF57EB, 0xDAC5CB0B },    // 1xx_FireResist 0.2 Legendary -> FireResist 0.2 Legendary
    { 0x760C0D2C, 0x6022804C },    // 1xx_FireResist 0.3 Legendary -> FireResist 0.3 Legendary
    { 0xB7CB1269, 0x9DC3D589 },    // 1xx_FireResist I -> FireResist I
    { 0xB12D5FF2, 0x563E8712 },    // 1xx_FireResist II -> FireResist II
    { 0xD6D95E9B, 0x1E0F69BB },    // 1xx_FireResist III -> FireResist III
    { 0xB12D5FFF, 0x563E871F },    // 1xx_FireResist IV -> FireResist IV
    { 0xB12D6001, 0x563E8721 },    // 1xx_FireResist IX -> FireResist IX
    { 0xB7CB1276, 0x9DC3D596 },    // 1xx_FireResist V -> FireResist V
    { 0xB12D619F, 0x563E88BF },    // 1xx_FireResist VI -> FireResist VI
    { 0xD6D995E8, 0x1E0FA108 },    // 1xx_FireResist VII -> FireResist VII
    { 0xB20C5351, 0xE003C271 },    // 1xx_FireResist VIII -> FireResist VIII
    { 0xB7CB1278, 0x9DC3D598 },    // 1xx_FireResist X -> FireResist X
    { 0x2449C2E4, 0xBEA6A204 },    // 1xx_FuryHeals 1 -> FuryHeals 1
    { 0xAD821F94, 0x937AE2B4 },    // 1xx_FuryHeals 10 -> FuryHeals 10
    { 0xAD821F95, 0x937AE2B4 },    // 1xx_FuryHeals 11 -> FuryHeals 10
    { 0xAD821F96, 0x937AE2B4 },    // 1xx_FuryHeals 12 -> FuryHeals 10
    { 0xAD821F97, 0x937AE2B4 },    // 1xx_FuryHeals 13 -> FuryHeals 10
    { 0xAD821F98, 0x937AE2B4 },    // 1xx_FuryHeals 14 -> FuryHeals 10
    { 0x2449C2E5, 0xBEA6A205 },    // 1xx_FuryHeals 2 -> FuryHeals 2
    { 0x2449C2E6, 0xBEA6A206 },    // 1xx_FuryHeals 3 -> FuryHeals 3
    { 0x2449C2E7, 0xBEA6A207 },    // 1xx_FuryHeals 4 -> FuryHeals 4
    { 0x2449C2E8, 0xBEA6A208 },    // 1xx_FuryHeals 5 -> FuryHeals 5
    { 0x2449C2E9, 0xBEA6A209 },    // 1xx_FuryHeals 6 -> FuryHeals 6
    { 0x2449C2EA, 0xBEA6A20A },    // 1xx_FuryHeals 7 -> FuryHeals 7
    { 0x2449C2EB, 0xBEA6A20B },    // 1xx_FuryHeals 8 -> FuryHeals 8
    { 0x2449C2EC, 0xBEA6A20C },    // 1xx_FuryHeals 9 -> FuryHeals 9
    { 0xFBBF43E5, 0x42F54F05 },    // 1xx_FurySetPoint I -> FurySetPoint I
    { 0xA86BF46F, 0xF858DF8F },    // 1xx_Gold I -> Gold I
    { 0x75029517, 0x61E7E837 },    // 1xx_Gold I Secondary -> Gold I Secondary
    { 0xB5EA82B8, 0x0374D1D8 },    // 1xx_Gold II -> Gold II
    { 0x6BFA52A0, 0xF58A09C0 },    // 1xx_Gold II Secondary -> Gold II Secondary
    { 0x733ADA21, 0x720F0D41 },    // 1xx_Gold III -> Gold III
    { 0x41E9C149, 0xFD705C69 },    // 1xx_Gold III Secondary -> Gold III Secondary
    { 0xB5EA82C5, 0x0374D1E5 },    // 1xx_Gold IV -> Gold IV
    { 0x31AF86ED, 0xBB3F3E0D },    // 1xx_Gold IV Secondary -> Gold IV Secondary
    { 0xB5EA82C7, 0x0374D1E7 },    // 1xx_Gold IX -> Gold IX
    { 0x3C68F16F, 0xC5F8A88F },    // 1xx_Gold IX Secondary -> Gold IX Secondary
    { 0xA86BF47C, 0xF858DF9C },    // 1xx_Gold V -> Gold V
    { 0x3AB7C964, 0x279D1C84 },    // 1xx_Gold V Secondary -> Gold V Secondary
    { 0xB5EA8465, 0x0374D385 },    // 1xx_Gold VI -> Gold VI
    { 0xE856108D, 0x71E5C7AD },    // 1xx_Gold VI Secondary -> Gold VI Secondary
    { 0x733B116E, 0x720F448E },    // 1xx_Gold VII -> Gold VII
    { 0x49BD3CD6, 0x0543D7F6 },    // 1xx_Gold VII Secondary -> Gold VII Secondary
    { 0xDA9D3F97, 0xB3F7D6B7 },    // 1xx_Gold VIII -> Gold VIII
    { 0xD809F23F, 0x0463F15F },    // 1xx_Gold VIII Secondary -> Gold VIII Secondary
    { 0xF0778B6B, 0xABFE268B },    // 1xx_GoldPickUpRadius 1 -> GoldPickUpRadius 1
    { 0xFF68F8FB, 0xABFE2690 },    // 1xx_GoldPickUpRadius 10 -> GoldPickUpRadius 6
    { 0xF0778B6C, 0xABFE268C },    // 1xx_GoldPickUpRadius 2 -> GoldPickUpRadius 2
    { 0xF0778B6D, 0xABFE268D },    // 1xx_GoldPickUpRadius 3 -> GoldPickUpRadius 3
    { 0xF0778B6E, 0xABFE268E },    // 1xx_GoldPickUpRadius 4 -> GoldPickUpRadius 4
    { 0xF0778B6F, 0xABFE268F },    // 1xx_GoldPickUpRadius 5 -> GoldPickUpRadius 5
    { 0xF0778B70, 0xABFE2690 },    // 1xx_GoldPickUpRadius 6 -> GoldPickUpRadius 6
    { 0xF0778B71, 0xABFE2690 },    // 1xx_GoldPickUpRadius 7 -> GoldPickUpRadius 6
    { 0xF0778B72, 0xABFE2690 },    // 1xx_GoldPickUpRadius 8 -> GoldPickUpRadius 6
    { 0xF0778B73, 0xABFE2690 },    // 1xx_GoldPickUpRadius 9 -> GoldPickUpRadius 6
    { 0xE2C51426, 0x304F6346 },    // 1xx_Haste 1 -> Haste 1
    { 0xC1D4058E, 0x4B63BCAE },    // 1xx_Haste 1 Secondary -> Haste 1 Secondary
    { 0x3B679916, 0x3A3BCC36 },    // 1xx_Haste 10 -> Haste 10
    { 0xA155767E, 0xF0ECB175 },    // 1xx_Haste 10 Secondary -> Haste 8 Secondary
    { 0x3B679917, 0x3A3BCC36 },    // 1xx_Haste 11 -> Haste 10
    { 0x26B22BBF, 0xF0ECB175 },    // 1xx_Haste 11 Secondary -> Haste 8 Secondary
    { 0xE2C51427, 0x304F6347 },    // 1xx_Haste 2 -> Haste 2
    { 0x4730BACF, 0xD0C071EF },    // 1xx_Haste 2 Secondary -> Haste 2 Secondary
    { 0xE2C51428, 0x304F6348 },    // 1xx_Haste 3 -> Haste 3
    { 0xCC8D7010, 0x561D2730 },    // 1xx_Haste 3 Secondary -> Haste 3 Secondary
    { 0xE2C51429, 0x304F6349 },    // 1xx_Haste 4 -> Haste 4
    { 0x51EA2551, 0xDB79DC71 },    // 1xx_Haste 4 Secondary -> Haste 4 Secondary
    { 0xE2C5142A, 0x304F634A },    // 1xx_Haste 5 -> Haste 5
    { 0xD746DA92, 0x60D691B2 },    // 1xx_Haste 5 Secondary -> Haste 5 Secondary
    { 0xE2C5142B, 0x304F634B },    // 1xx_Haste 6 -> Haste 6
    { 0x5CA38FD3, 0xE63346F3 },    // 1xx_Haste 6 Secondary -> Haste 6 Secondary
    { 0xE2C5142C, 0x304F634C },    // 1xx_Haste 7 -> Haste 7
    { 0xE2004514, 0x6B8FFC34 },    // 1xx_Haste 7 Secondary -> Haste 7 Secondary
    { 0xE2C5142D, 0x304F634D },    // 1xx_Haste 8 -> Haste 8
    { 0x675CFA55, 0xF0ECB175 },    // 1xx_Haste 8 Secondary -> Haste 8 Secondary
    { 0xE2C5142E, 0x304F634E },    // 1xx_Haste 9 -> Haste 9
    { 0xECB9AF96, 0xF0ECB175 },    // 1xx_Haste 9 Secondary -> Haste 8 Secondary
    { 0xD9D0C25A, 0x7EE1E97A },    // 1xx_HatredRegen 1 -> HatredRegen 1
    { 0x13E90DCA, 0x5B1F18EA },    // 1xx_HatredRegen 10 -> HatredRegen 10
    { 0x13E90DCB, 0x5B1F18EA },    // 1xx_HatredRegen 11 -> HatredRegen 10
    { 0x13E90DCC, 0x5B1F18EA },    // 1xx_HatredRegen 12 -> HatredRegen 10
    { 0x13E90DCD, 0x5B1F18EA },    // 1xx_HatredRegen 13 -> HatredRegen 10
    { 0x13E90DCE, 0x5B1F18EA },    // 1xx_HatredRegen 14 -> HatredRegen 10
    { 0xD9D0C25B, 0x7EE1E97B },    // 1xx_HatredRegen 2 -> HatredRegen 2
    { 0xD9D0C25C, 0x7EE1E97C },    // 1xx_HatredRegen 3 -> HatredRegen 3
    { 0xD9D0C25D, 0x7EE1E97D },    // 1xx_HatredRegen 4 -> HatredRegen 4
    { 0xD9D0C25E, 0x7EE1E97E },    // 1xx_HatredRegen 5 -> HatredRegen 5
    { 0xD9D0C25F, 0x7EE1E97F },    // 1xx_HatredRegen 6 -> HatredRegen 6
    { 0xD9D0C260, 0x7EE1E980 },    // 1xx_HatredRegen 7 -> HatredRegen 7
    { 0xD9D0C261, 0x7EE1E981 },    // 1xx_HatredRegen 8 -> HatredRegen 8
    { 0xD9D0C262, 0x7EE1E982 },    // 1xx_HatredRegen 9 -> HatredRegen 9
    { 0x8D61C097, 0x48E85BB7 },    // 1xx_HealthGlobeBonus 1 -> HealthGlobeBonus 1
    { 0x3999D3A7, 0x65F3D2C7 },    // 1xx_HealthGlobeBonus 10 -> HealthGlobeBonus 10
    { 0x3999D3A8, 0x65F3D2C8 },    // 1xx_HealthGlobeBonus 11 -> HealthGlobeBonus 11
    { 0x3999D3A9, 0x65F3D2C9 },    // 1xx_HealthGlobeBonus 12 -> HealthGlobeBonus 12
    { 0x3999D3AA, 0x65F3D2C9 },    // 1xx_HealthGlobeBonus 13 -> HealthGlobeBonus 12
    { 0x3999D3AB, 0x65F3D2C9 },    // 1xx_HealthGlobeBonus 14 -> HealthGlobeBonus 12
    { 0x3999D3AC, 0x65F3D2C9 },    // 1xx_HealthGlobeBonus 15 -> HealthGlobeBonus 12
    { 0x8D61C098, 0x48E85BB8 },    // 1xx_HealthGlobeBonus 2 -> HealthGlobeBonus 2
    { 0x8D61C099, 0x48E85BB9 },    // 1xx_HealthGlobeBonus 3 -> HealthGlobeBonus 3
    { 0x8D61C09A, 0x48E85BBA },    // 1xx_HealthGlobeBonus 4 -> HealthGlobeBonus 4
    { 0x8D61C09B, 0x48E85BBB },    // 1xx_HealthGlobeBonus 5 -> HealthGlobeBonus 5
    { 0x8D61C09C, 0x48E85BBC },    // 1xx_HealthGlobeBonus 6 -> HealthGlobeBonus 6
    { 0x8D61C09D, 0x48E85BBD },    // 1xx_HealthGlobeBonus 7 -> HealthGlobeBonus 7
    { 0x8D61C09E, 0x48E85BBE },    // 1xx_HealthGlobeBonus 8 -> HealthGlobeBonus 8
    { 0x8D61C09F, 0x48E85BBF },    // 1xx_HealthGlobeBonus 9 -> HealthGlobeBonus 9
    { 0xEC2AA10A, 0x1884A02A },    // 1xx_HealthGlobeChance I -> HealthGlobeChance I
    { 0x1BE31138, 0xFFFFFFFF },    // 1xx_HitBlind 0.1 Legendary -> (none)
    { 0xEFDEBBBF, 0xF48C36DF },    // 1xx_HitBlind 1 -> HitBlind 1
    { 0xEBB633CF, 0x861312EF },    // 1xx_HitBlind 10 -> HitBlind 10
    { 0xEBB633D0, 0x861312F0 },    // 1xx_HitBlind 11 -> HitBlind 11
    { 0xEBB633D1, 0x861312F1 },    // 1xx_HitBlind 12 -> HitBlind 12
    { 0xEBB633D2, 0x861312F1 },    // 1xx_HitBlind 13 -> HitBlind 12
    { 0xEBB633D3, 0x861312F1 },    // 1xx_HitBlind 14 -> HitBlind 12
    { 0xEBB633D4, 0x861312F1 },    // 1xx_HitBlind 15 -> HitBlind 12
    { 0xEBB633D5, 0x861312F1 },    // 1xx_HitBlind 16 -> HitBlind 12
    { 0xEFDEBBC0, 0xF48C36E0 },    // 1xx_HitBlind 2 -> HitBlind 2
    { 0xEFDEBBC1, 0xF48C36E1 },    // 1xx_HitBlind 3 -> HitBlind 3
    { 0xEFDEBBC2, 0xF48C36E2 },    // 1xx_HitBlind 4 -> HitBlind 4
    { 0xEFDEBBC3, 0xF48C36E3 },    // 1xx_HitBlind 5 -> HitBlind 5
    { 0xEFDEBBC4, 0xF48C36E4 },    // 1xx_HitBlind 6 -> HitBlind 6
    { 0xEFDEBBC5, 0xF48C36E5 },    // 1xx_HitBlind 7 -> HitBlind 7
    { 0xEFDEBBC6, 0xF48C36E6 },    // 1xx_HitBlind 8 -> HitBlind 8
    { 0xEFDEBBC7, 0xF48C36E7 },    // 1xx_HitBlind 9 -> HitBlind 9
    { 0x1636113B, 0xFFFFFFFF },    // 1xx_HitChill 0.1 Legendary -> (none)
    { 0x33835F42, 0x3830DA62 },    // 1xx_HitChill 1 -> HitChill 1
    { 0xA3EF47B2, 0x3E4C26D2 },    // 1xx_HitChill 10 -> HitChill 10
    { 0xA3EF47B3, 0x3E4C26D3 },    // 1xx_HitChill 11 -> HitChill 11
    { 0xA3EF47B4, 0x3E4C26D4 },    // 1xx_HitChill 12 -> HitChill 12
    { 0xA3EF47B5, 0x3E4C26D4 },    // 1xx_HitChill 13 -> HitChill 12
    { 0xA3EF47B6, 0x3E4C26D4 },    // 1xx_HitChill 14 -> HitChill 12
    { 0xA3EF47B7, 0x3E4C26D4 },    // 1xx_HitChill 15 -> HitChill 12
    { 0xA3EF47B8, 0x3E4C26D4 },    // 1xx_HitChill 16 -> HitChill 12
    { 0x33835F43, 0x3830DA63 },    // 1xx_HitChill 2 -> HitChill 2
    { 0x33835F44, 0x3830DA64 },    // 1xx_HitChill 3 -> HitChill 3
    { 0x33835F45, 0x3830DA65 },    // 1xx_HitChill 4 -> HitChill 4
    { 0x33835F46, 0x3830DA66 },    // 1xx_HitChill 5 -> HitChill 5
    { 0x33835F47, 0x3830DA67 },    // 1xx_HitChill 6 -> HitChill 6
    { 0x33835F48, 0x3830DA68 },    // 1xx_HitChill 7 -> HitChill 7
    { 0x33835F49, 0x3830DA69 },    // 1xx_HitChill 8 -> HitChill 8
    { 0x33835F4A, 0x3830DA6A },    // 1xx_HitChill 9 -> HitChill 9
    { 0xA8959B0D, 0xFFFFFFFF },    // 1xx_HitFear 0.1 Legendary -> (none)
    { 0x36E01E14, 0x103AB534 },    // 1xx_HitFear 1 -> HitFear 1
    { 0x12E3E0C4, 0x17915BE4 },    // 1xx_HitFear 10 -> HitFear 10
    { 0x12E3E0C5, 0x17915BE5 },    // 1xx_HitFear 11 -> HitFear 11
    { 0x12E3E0C6, 0x17915BE6 },    // 1xx_HitFear 12 -> HitFear 12
    { 0x12E3E0C7, 0x17915BE6 },    // 1xx_HitFear 13 -> HitFear 12
    { 0x12E3E0C8, 0x17915BE6 },    // 1xx_HitFear 14 -> HitFear 12
    { 0x12E3E0C9, 0x17915BE6 },    // 1xx_HitFear 15 -> HitFear 12
    { 0x12E3E0CA, 0x17915BE6 },    // 1xx_HitFear 16 -> HitFear 12
    { 0x36E01E15, 0x103AB535 },    // 1xx_HitFear 2 -> HitFear 2
    { 0x36E01E16, 0x103AB536 },    // 1xx_HitFear 3 -> HitFear 3
    { 0x36E01E17, 0x103AB537 },    // 1xx_HitFear 4 -> HitFear 4
    { 0x36E01E18, 0x103AB538 },    // 1xx_HitFear 5 -> HitFear 5
    { 0x36E01E19, 0x103AB539 },    // 1xx_HitFear 6 -> HitFear 6
    { 0x36E01E1A, 0x103AB53A },    // 1xx_HitFear 7 -> HitFear 7
    { 0x36E01E1B, 0x103AB53B },    // 1xx_HitFear 8 -> HitFear 8
    { 0x36E01E1C, 0x103AB53C },    // 1xx_HitFear 9 -> HitFear 9
    { 0xF745D1F0, 0xFFFFFFFF },    // 1xx_HitFreeze 0.1 Legendary -> (none)
    { 0x60B0A877, 0xFB0D8797 },    // 1xx_HitFreeze 1 -> HitFreeze 1
    { 0x76C5B787, 0x5CBE7AA7 },    // 1xx_HitFreeze 10 -> HitFreeze 10
    { 0x76C5B788, 0x5CBE7AA8 },    // 1xx_HitFreeze 11 -> HitFreeze 11
    { 0x76C5B789, 0x5CBE7AA9 },    // 1xx_HitFreeze 12 -> HitFreeze 12
    { 0x76C5B78A, 0x5CBE7AA9 },    // 1xx_HitFreeze 13 -> HitFreeze 12
    { 0x76C5B78B, 0x5CBE7AA9 },    // 1xx_HitFreeze 14 -> HitFreeze 12
    { 0x76C5B78C, 0x5CBE7AA9 },    // 1xx_HitFreeze 15 -> HitFreeze 12
    { 0x76C5B78D, 0x5CBE7AA9 },    // 1xx_HitFreeze 16 -> HitFreeze 12
    { 0x60B0A878, 0xFB0D8798 },    // 1xx_HitFreeze 2 -> HitFreeze 2
    { 0x60B0A879, 0xFB0D8799 },    // 1xx_HitFreeze 3 -> HitFreeze 3
    { 0x60B0A87A, 0xFB0D879A },    // 1xx_HitFreeze 4 -> HitFreeze 4
    { 0x60B0A87B, 0xFB0D879B },    // 1xx_HitFreeze 5 -> HitFreeze 5
    { 0x60B0A87C, 0xFB0D879C },    // 1xx_HitFreeze 6 -> HitFreeze 6
    { 0x60B0A87D, 0xFB0D879D },    // 1xx_HitFreeze 7 -> HitFreeze 7
    { 0x60B0A87E, 0xFB0D879E },    // 1xx_HitFreeze 8 -> HitFreeze 8
    { 0x60B0A87F, 0xFB0D879F },    // 1xx_HitFreeze 9 -> HitFreeze 9
    { 0x52BC1080, 0xFFFFFFFF },    // 1xx_HitImmobilize 0.1 Legendary -> (none)
    { 0x89A88F07, 0xB79FFE27 },    // 1xx_HitImmobilize 1 -> HitImmobilize 1
    { 0xBEBA7017, 0xAB9FC337 },    // 1xx_HitImmobilize 10 -> HitImmobilize 10
    { 0xBEBA7018, 0xAB9FC338 },    // 1xx_HitImmobilize 11 -> HitImmobilize 11
    { 0xBEBA7019, 0xAB9FC339 },    // 1xx_HitImmobilize 12 -> HitImmobilize 12
    { 0xBEBA701A, 0xAB9FC339 },    // 1xx_HitImmobilize 13 -> HitImmobilize 12
    { 0xBEBA701B, 0xAB9FC339 },    // 1xx_HitImmobilize 14 -> HitImmobilize 12
    { 0xBEBA701C, 0xAB9FC339 },    // 1xx_HitImmobilize 15 -> HitImmobilize 12
    { 0xBEBA701D, 0xAB9FC339 },    // 1xx_HitImmobilize 16 -> HitImmobilize 12
    { 0x89A88F08, 0xB79FFE28 },    // 1xx_HitImmobilize 2 -> HitImmobilize 2
    { 0x89A88F09, 0xB79FFE29 },    // 1xx_HitImmobilize 3 -> HitImmobilize 3
    { 0x89A88F0A, 0xB79FFE2A },    // 1xx_HitImmobilize 4 -> HitImmobilize 4
    { 0x89A88F0B, 0xB79FFE2B },    // 1xx_HitImmobilize 5 -> HitImmobilize 5
    { 0x89A88F0C, 0xB79FFE2C },    // 1xx_HitImmobilize 6 -> HitImmobilize 6
    { 0x89A88F0D, 0xB79FFE2D },    // 1xx_HitImmobilize 7 -> HitImmobilize 7
    { 0x89A88F0E, 0xB79FFE2E },    // 1xx_HitImmobilize 8 -> HitImmobilize 8
    { 0x89A88F0F, 0xB79FFE2F },    // 1xx_HitImmobilize 9 -> HitImmobilize 9
    { 0xD0B2A796, 0xFFFFFFFF },    // 1xx_HitKnockback 0.1 Legendary -> (none)
    { 0xF91B551D, 0x4051603D },    // 1xx_HitKnockback 1 -> HitKnockback 1
    { 0x1C85F8ED, 0x4A7D680D },    // 1xx_HitKnockback 10 -> HitKnockback 10
    { 0x1C85F8EE, 0x4A7D680E },    // 1xx_HitKnockback 11 -> HitKnockback 11
    { 0x1C85F8EF, 0x4A7D680F },    // 1xx_HitKnockback 12 -> HitKnockback 12
    { 0x1C85F8F0, 0x4A7D680F },    // 1xx_HitKnockback 13 -> HitKnockback 12
    { 0x1C85F8F1, 0x4A7D680F },    // 1xx_HitKnockback 14 -> HitKnockback 12
    { 0x1C85F8F2, 0x4A7D680F },    // 1xx_HitKnockback 15 -> HitKnockback 12
    { 0x1C85F8F3, 0x4A7D680F },    // 1xx_HitKnockback 16 -> HitKnockback 12
    { 0xF91B551E, 0x4051603E },    // 1xx_HitKnockback 2 -> HitKnockback 2
    { 0xF91B551F, 0x4051603F },    // 1xx_HitKnockback 3 -> HitKnockback 3
    { 0xF91B5520, 0x40516040 },    // 1xx_HitKnockback 4 -> HitKnockback 4
    { 0xF91B5521, 0x40516041 },    // 1xx_HitKnockback 5 -> HitKnockback 5
    { 0xF91B5522, 0x40516042 },    // 1xx_HitKnockback 6 -> HitKnockback 6
    { 0xF91B5523, 0x40516043 },    // 1xx_HitKnockback 7 -> HitKnockback 7
    { 0xF91B5524, 0x40516044 },    // 1xx_HitKnockback 8 -> HitKnockback 8
    { 0xF91B5525, 0x40516045 },    // 1xx_HitKnockback 9 -> HitKnockback 9
    { 0x4529FA76, 0x1E849196 },    // 1xx_HitLife 1 -> HitLife 1
    { 0x69090FDE, 0x95630EFE },    // 1xx_HitLife 1 Secondary -> HitLife 1 Secondary
    { 0xEB598581, 0xA2F368A1 },    // 1xx_HitLife 1 Two-Handed -> HitLife 1 Two-Handed
    { 0xEA694966, 0xEF16C486 },    // 1xx_HitLife 10 -> HitLife 10
    { 0x2F2BCACE, 0xE6C5ADEE },    // 1xx_HitLife 10 Secondary -> HitLife 10 Secondary
    { 0x75D39E71, 0x20A9E591 },    // 1xx_HitLife 10 Two-Handed -> HitLife 10 Two-Handed
    { 0xEA694967, 0xEF16C487 },    // 1xx_HitLife 11 -> HitLife 11
    { 0xB488800F, 0x6C22632F },    // 1xx_HitLife 11 Secondary -> HitLife 11 Secondary
    { 0xA6C6FBD2, 0x519D42F2 },    // 1xx_HitLife 11 Two-Handed -> HitLife 11 Two-Handed
    { 0xEA694968, 0xEF16C488 },    // 1xx_HitLife 12 -> HitLife 12
    { 0x39E53550, 0xF17F1870 },    // 1xx_HitLife 12 Secondary -> HitLife 12 Secondary
    { 0xD7BA5933, 0x8290A053 },    // 1xx_HitLife 12 Two-Handed -> HitLife 12 Two-Handed
    { 0xEA694969, 0xEF16C489 },    // 1xx_HitLife 13 -> HitLife 13
    { 0xBF41EA91, 0x76DBCDB1 },    // 1xx_HitLife 13 Secondary -> HitLife 13 Secondary
    { 0x08ADB694, 0xB383FDB4 },    // 1xx_HitLife 13 Two-Handed -> HitLife 13 Two-Handed
    { 0xEA69496A, 0xEF16C48A },    // 1xx_HitLife 14 -> HitLife 14
    { 0x449E9FD2, 0xFC3882F2 },    // 1xx_HitLife 14 Secondary -> HitLife 14 Secondary
    { 0x39A113F5, 0xE4775B15 },    // 1xx_HitLife 14 Two-Handed -> HitLife 14 Two-Handed
    { 0xEA69496B, 0xEF16C48A },    // 1xx_HitLife 15 -> HitLife 14
    { 0xC9FB5513, 0xFC3882F2 },    // 1xx_HitLife 15 Secondary -> HitLife 14 Secondary
    { 0x6A947156, 0xE4775B15 },    // 1xx_HitLife 15 Two-Handed -> HitLife 14 Two-Handed
    { 0xEA69496C, 0xEF16C48A },    // 1xx_HitLife 16 -> HitLife 14
    { 0x4F580A54, 0xFC3882F2 },    // 1xx_HitLife 16 Secondary -> HitLife 14 Secondary
    { 0x9B87CEB7, 0xE4775B15 },    // 1xx_HitLife 16 Two-Handed -> HitLife 14 Two-Handed
    { 0x4529FA77, 0x1E849197 },    // 1xx_HitLife 2 -> HitLife 2
    { 0xEE65C51F, 0x1ABFC43F },    // 1xx_HitLife 2 Secondary -> HitLife 2 Secondary
    { 0x1C4CE2E2, 0xD3E6C602 },    // 1xx_HitLife 2 Two-Handed -> HitLife 2 Two-Handed
    { 0x4529FA78, 0x1E849198 },    // 1xx_HitLife 3 -> HitLife 3
    { 0x73C27A60, 0xA01C7980 },    // 1xx_HitLife 3 Secondary -> HitLife 3 Secondary
    { 0x4D404043, 0x04DA2363 },    // 1xx_HitLife 3 Two-Handed -> HitLife 3 Two-Handed
    { 0x4529FA79, 0x1E849199 },    // 1xx_HitLife 4 -> HitLife 4
    { 0xF91F2FA1, 0x25792EC1 },    // 1xx_HitLife 4 Secondary -> HitLife 4 Secondary
    { 0x7E339DA4, 0x35CD80C4 },    // 1xx_HitLife 4 Two-Handed -> HitLife 4 Two-Handed
    { 0x4529FA7A, 0x1E84919A },    // 1xx_HitLife 5 -> HitLife 5
    { 0x7E7BE4E2, 0xAAD5E402 },    // 1xx_HitLife 5 Secondary -> HitLife 5 Secondary
    { 0xAF26FB05, 0x66C0DE25 },    // 1xx_HitLife 5 Two-Handed -> HitLife 5 Two-Handed
    { 0x4529FA7B, 0x1E84919B },    // 1xx_HitLife 6 -> HitLife 6
    { 0x03D89A23, 0x30329943 },    // 1xx_HitLife 6 Secondary -> HitLife 6 Secondary
    { 0xE01A5866, 0x97B43B86 },    // 1xx_HitLife 6 Two-Handed -> HitLife 6 Two-Handed
    { 0x4529FA7C, 0x1E84919C },    // 1xx_HitLife 7 -> HitLife 7
    { 0x89354F64, 0xB58F4E84 },    // 1xx_HitLife 7 Secondary -> HitLife 7 Secondary
    { 0x110DB5C7, 0xC8A798E7 },    // 1xx_HitLife 7 Two-Handed -> HitLife 7 Two-Handed
    { 0x4529FA7D, 0x1E84919D },    // 1xx_HitLife 8 -> HitLife 8
    { 0x0E9204A5, 0x3AEC03C5 },    // 1xx_HitLife 8 Secondary -> HitLife 8 Secondary
    { 0x42011328, 0xF99AF648 },    // 1xx_HitLife 8 Two-Handed -> HitLife 8 Two-Handed
    { 0x4529FA7E, 0x1E84919E },    // 1xx_HitLife 9 -> HitLife 9
    { 0x93EEB9E6, 0xC048B906 },    // 1xx_HitLife 9 Secondary -> HitLife 9 Secondary
    { 0x72F47089, 0x2A8E53A9 },    // 1xx_HitLife 9 Two-Handed -> HitLife 9 Two-Handed
    { 0x46F2B113, 0x204D4833 },    // 1xx_HitMana 1 -> HitMana 1
    { 0x2548D3A3, 0x29F64EC3 },    // 1xx_HitMana 10 -> HitMana 10
    { 0x2548D3A4, 0x29F64EC4 },    // 1xx_HitMana 11 -> HitMana 11
    { 0x2548D3A5, 0x29F64EC5 },    // 1xx_HitMana 12 -> HitMana 12
    { 0x46F2B114, 0x204D4834 },    // 1xx_HitMana 2 -> HitMana 2
    { 0x46F2B115, 0x204D4835 },    // 1xx_HitMana 3 -> HitMana 3
    { 0x46F2B116, 0x204D4836 },    // 1xx_HitMana 4 -> HitMana 4
    { 0x46F2B117, 0x204D4837 },    // 1xx_HitMana 5 -> HitMana 5
    { 0x46F2B118, 0x204D4838 },    // 1xx_HitMana 6 -> HitMana 6
    { 0x46F2B119, 0x204D4839 },    // 1xx_HitMana 7 -> HitMana 7
    { 0x46F2B11A, 0x204D483A },    // 1xx_HitMana 8 -> HitMana 8
    { 0x46F2B11B, 0x204D483B },    // 1xx_HitMana 9 -> HitMana 9
    { 0x9EF7BBD4, 0xFFFFFFFF },    // 1xx_HitSlow 0.1 Legendary -> (none)
    { 0x55B99C5B, 0x2F14337B },    // 1xx_HitSlow 1 -> HitSlow 1
    { 0x0CED27EB, 0x119AA30B },    // 1xx_HitSlow 10 -> HitSlow 10
    { 0x0CED27EC, 0x119AA30C },    // 1xx_HitSlow 11 -> HitSlow 11
    { 0x0CED27ED, 0x119AA30D },    // 1xx_HitSlow 12 -> HitSlow 12
    { 0x0CED27EE, 0x119AA30D },    // 1xx_HitSlow 13 -> HitSlow 12
    { 0x0CED27EF, 0x119AA30D },    // 1xx_HitSlow 14 -> HitSlow 12
    { 0x0CED27F0, 0x119AA30D },    // 1xx_HitSlow 15 -> HitSlow 12
    { 0x0CED27F1, 0x119AA30D },    // 1xx_HitSlow 16 -> HitSlow 12
    { 0x55B99C5C, 0x2F14337C },    // 1xx_HitSlow 2 -> HitSlow 2
    { 0x55B99C5D, 0x2F14337D },    // 1xx_HitSlow 3 -> HitSlow 3
    { 0x55B99C5E, 0x2F14337E },    // 1xx_HitSlow 4 -> HitSlow 4
    { 0x55B99C5F, 0x2F14337F },    // 1xx_HitSlow 5 -> HitSlow 5
    { 0x55B99C60, 0x2F143380 },    // 1xx_HitSlow 6 -> HitSlow 6
    { 0x55B99C61, 0x2F143381 },    // 1xx_HitSlow 7 -> HitSlow 7
    { 0x55B99C62, 0x2F143382 },    // 1xx_HitSlow 8 -> HitSlow 8
    { 0x55B99C63, 0x2F143383 },    // 1xx_HitSlow 9 -> HitSlow 9
    { 0xC182D359, 0xFFFFFFFF },    // 1xx_HitStun 0.1 Legendary -> (none)
    { 0x564D8460, 0x2FA81B80 },    // 1xx_HitStun 1 -> HitStun 1
    { 0x1FFE1090, 0x24AB8BB0 },    // 1xx_HitStun 10 -> HitStun 10
    { 0x1FFE1091, 0x24AB8BB1 },    // 1xx_HitStun 11 -> HitStun 11
    { 0x1FFE1092, 0x24AB8BB2 },    // 1xx_HitStun 12 -> HitStun 12
    { 0x1FFE1093, 0x24AB8BB2 },    // 1xx_HitStun 13 -> HitStun 12
    { 0x1FFE1094, 0x24AB8BB2 },    // 1xx_HitStun 14 -> HitStun 12
    { 0x1FFE1095, 0x24AB8BB2 },    // 1xx_HitStun 15 -> HitStun 12
    { 0x1FFE1096, 0x24AB8BB2 },    // 1xx_HitStun 16 -> HitStun 12
    { 0x564D8461, 0x2FA81B81 },    // 1xx_HitStun 2 -> HitStun 2
    { 0x564D8462, 0x2FA81B82 },    // 1xx_HitStun 3 -> HitStun 3
    { 0x564D8463, 0x2FA81B83 },    // 1xx_HitStun 4 -> HitStun 4
    { 0x564D8464, 0x2FA81B84 },    // 1xx_HitStun 5 -> HitStun 5
    { 0x564D8465, 0x2FA81B85 },    // 1xx_HitStun 6 -> HitStun 6
    { 0x564D8466, 0x2FA81B86 },    // 1xx_HitStun 7 -> HitStun 7
    { 0x564D8467, 0x2FA81B87 },    // 1xx_HitStun 8 -> HitStun 8
    { 0x564D8468, 0x2FA81B88 },    // 1xx_HitStun 9 -> HitStun 9
    { 0x02F15B11, 0x507BAA31 },    // 1xx_HolyD 1 -> HolyD 1
    { 0xF126985F, 0xD71F5B7F },    // 1xx_HolyD 1 Fast -> HolyD 1 Fast
    { 0x051E6F3C, 0xC0A50A5C },    // 1xx_HolyD 1 Two-Handed -> HolyD 1 Two-Handed
    { 0x611CBD61, 0x5FF0F081 },    // 1xx_HolyD 10 -> HolyD 10
    { 0x365BECAF, 0xDB6D13CF },    // 1xx_HolyD 10 Fast -> HolyD 10 Fast
    { 0xC835BF8C, 0xF48FBEAC },    // 1xx_HolyD 10 Two-Handed -> HolyD 10 Two-Handed
    { 0x611CBD62, 0x5FF0F082 },    // 1xx_HolyD 11 -> HolyD 11
    { 0x38B11550, 0xDDC23C70 },    // 1xx_HolyD 11 Fast -> HolyD 11 Fast
    { 0xF9291CED, 0x25831C0D },    // 1xx_HolyD 11 Two-Handed -> HolyD 11 Two-Handed
    { 0x611CBD63, 0x5FF0F083 },    // 1xx_HolyD 12 -> HolyD 12
    { 0x3B063DF1, 0xE0176511 },    // 1xx_HolyD 12 Fast -> HolyD 12 Fast
    { 0x2A1C7A4E, 0x5676796E },    // 1xx_HolyD 12 Two-Handed -> HolyD 12 Two-Handed
    { 0x611CBD64, 0x5FF0F084 },    // 1xx_HolyD 13 -> HolyD 13
    { 0x3D5B6692, 0xE26C8DB2 },    // 1xx_HolyD 13 Fast -> HolyD 13 Fast
    { 0x5B0FD7AF, 0x8769D6CF },    // 1xx_HolyD 13 Two-Handed -> HolyD 13 Two-Handed
    { 0x611CBD65, 0x5FF0F085 },    // 1xx_HolyD 14 -> HolyD 14
    { 0x3FB08F33, 0xE4C1B653 },    // 1xx_HolyD 14 Fast -> HolyD 14 Fast
    { 0x8C033510, 0xB85D3430 },    // 1xx_HolyD 14 Two-Handed -> HolyD 14 Two-Handed
    { 0x611CBD66, 0x5FF0F085 },    // 1xx_HolyD 15 -> HolyD 14
    { 0x4205B7D4, 0xE4C1B653 },    // 1xx_HolyD 15 Fast -> HolyD 14 Fast
    { 0xBCF69271, 0xB85D3430 },    // 1xx_HolyD 15 Two-Handed -> HolyD 14 Two-Handed
    { 0x611CBD67, 0x5FF0F085 },    // 1xx_HolyD 16 -> HolyD 14
    { 0x445AE075, 0xE4C1B653 },    // 1xx_HolyD 16 Fast -> HolyD 14 Fast
    { 0xEDE9EFD2, 0xB85D3430 },    // 1xx_HolyD 16 Two-Handed -> HolyD 14 Two-Handed
    { 0x02F15B12, 0x507BAA32 },    // 1xx_HolyD 2 -> HolyD 2
    { 0xF37BC100, 0xD9748420 },    // 1xx_HolyD 2 Fast -> HolyD 2 Fast
    { 0x3611CC9D, 0xF19867BD },    // 1xx_HolyD 2 Two-Handed -> HolyD 2 Two-Handed
    { 0x02F15B13, 0x507BAA33 },    // 1xx_HolyD 3 -> HolyD 3
    { 0xF5D0E9A1, 0xDBC9ACC1 },    // 1xx_HolyD 3 Fast -> HolyD 3 Fast
    { 0x670529FE, 0x228BC51E },    // 1xx_HolyD 3 Two-Handed -> HolyD 3 Two-Handed
    { 0x02F15B14, 0x507BAA34 },    // 1xx_HolyD 4 -> HolyD 4
    { 0xF8261242, 0xDE1ED562 },    // 1xx_HolyD 4 Fast -> HolyD 4 Fast
    { 0x97F8875F, 0x537F227F },    // 1xx_HolyD 4 Two-Handed -> HolyD 4 Two-Handed
    { 0x02F15B15, 0x507BAA35 },    // 1xx_HolyD 5 -> HolyD 5
    { 0xFA7B3AE3, 0xE073FE03 },    // 1xx_HolyD 5 Fast -> HolyD 5 Fast
    { 0xC8EBE4C0, 0x84727FE0 },    // 1xx_HolyD 5 Two-Handed -> HolyD 5 Two-Handed
    { 0x02F15B16, 0x507BAA36 },    // 1xx_HolyD 6 -> HolyD 6
    { 0xFCD06384, 0xE2C926A4 },    // 1xx_HolyD 6 Fast -> HolyD 6 Fast
    { 0xF9DF4221, 0xB565DD41 },    // 1xx_HolyD 6 Two-Handed -> HolyD 6 Two-Handed
    { 0x02F15B17, 0x507BAA37 },    // 1xx_HolyD 7 -> HolyD 7
    { 0xFF258C25, 0xE51E4F45 },    // 1xx_HolyD 7 Fast -> HolyD 7 Fast
    { 0x2AD29F82, 0xE6593AA2 },    // 1xx_HolyD 7 Two-Handed -> HolyD 7 Two-Handed
    { 0x02F15B18, 0x507BAA38 },    // 1xx_HolyD 8 -> HolyD 8
    { 0x017AB4C6, 0xE77377E6 },    // 1xx_HolyD 8 Fast -> HolyD 8 Fast
    { 0x5BC5FCE3, 0x174C9803 },    // 1xx_HolyD 8 Two-Handed -> HolyD 8 Two-Handed
    { 0x02F15B19, 0x507BAA39 },    // 1xx_HolyD 9 -> HolyD 9
    { 0x03CFDD67, 0xE9C8A087 },    // 1xx_HolyD 9 Fast -> HolyD 9 Fast
    { 0x8CB95A44, 0x483FF564 },    // 1xx_HolyD 9 Two-Handed -> HolyD 9 Two-Handed
    { 0xC83B56CB, 0xFFFFFFFF },    // 1xx_Indestructible 0.1 Legendary -> (none)
    { 0x6307CCD2, 0x4FED1FF2 },    // 1xx_Indestructible 1 -> Indestructible 1
    { 0xC4016742, 0x4D911E62 },    // 1xx_Indestructible 10 -> Indestructible 10
    { 0x6307CCD3, 0x4FED1FF3 },    // 1xx_Indestructible 2 -> Indestructible 2
    { 0x6307CCD4, 0x4FED1FF4 },    // 1xx_Indestructible 3 -> Indestructible 3
    { 0x6307CCD5, 0x4FED1FF5 },    // 1xx_Indestructible 4 -> Indestructible 4
    { 0x6307CCD6, 0x4FED1FF6 },    // 1xx_Indestructible 5 -> Indestructible 5
    { 0x6307CCD7, 0x4FED1FF7 },    // 1xx_Indestructible 6 -> Indestructible 6
    { 0x6307CCD8, 0x4FED1FF8 },    // 1xx_Indestructible 7 -> Indestructible 7
    { 0x6307CCD9, 0x4FED1FF9 },    // 1xx_Indestructible 8 -> Indestructible 8
    { 0x6307CCDA, 0x4FED1FFA },    // 1xx_Indestructible 9 -> Indestructible 9
    { 0x5661231E, 0x0DFB063E },    // 1xx_Inferior Armor Def 0 -> Inferior Armor Def 0
    { 0x5661231F, 0x0DFB063F },    // 1xx_Inferior Armor Def 1 -> Inferior Armor Def 1
    { 0x56612320, 0x0DFB0640 },    // 1xx_Inferior Armor Def 2 -> Inferior Armor Def 2
    { 0x56612321, 0x0DFB0641 },    // 1xx_Inferior Armor Def 3 -> Inferior Armor Def 3
    { 0xE67EA50A, 0x9154EC2A },    // 1xx_Inferior Weapon Dam 0 -> Inferior Weapon Dam 0
    { 0xE67EA50B, 0x9154EC2B },    // 1xx_Inferior Weapon Dam 1 -> Inferior Weapon Dam 1
    { 0xE67EA50C, 0x9154EC2C },    // 1xx_Inferior Weapon Dam 2 -> Inferior Weapon Dam 2
    { 0xE67EA50D, 0x9154EC2D },    // 1xx_Inferior Weapon Dam 3 -> Inferior Weapon Dam 3
    { 0x053E493C, 0x07AA505C },    // 1xx_Int 1 -> Int 1
    { 0xB70B0E24, 0xE5027D44 },    // 1xx_Int 1 Secondary -> Int 1 Secondary
    { 0xF99B4C87, 0xE6809FA7 },    // 1xx_Int 1 Two-Handed -> Int 1 Two-Handed
    { 0xAD0770EC, 0xFCF45C0C },    // 1xx_Int 10 -> Int 10
    { 0x3D6D91D4, 0x2A52E4F4 },    // 1xx_Int 10 Secondary -> Int 10 Secondary
    { 0x4C4E4637, 0xD5DDFD57 },    // 1xx_Int 10 Two-Handed -> Int 10 Two-Handed
    { 0xAD0770ED, 0xFCF45C0D },    // 1xx_Int 11 -> Int 11
    { 0xC2CA4715, 0xAFAF9A35 },    // 1xx_Int 11 Secondary -> Int 11 Secondary
    { 0x7D41A398, 0x06D15AB8 },    // 1xx_Int 11 Two-Handed -> Int 11 Two-Handed
    { 0xAD0770EE, 0xFCF45C0E },    // 1xx_Int 12 -> Int 12
    { 0x4826FC56, 0x350C4F76 },    // 1xx_Int 12 Secondary -> Int 12 Secondary
    { 0xAE3500F9, 0x37C4B819 },    // 1xx_Int 12 Two-Handed -> Int 12 Two-Handed
    { 0xAD0770EF, 0xFCF45C0F },    // 1xx_Int 13 -> Int 13
    { 0xCD83B197, 0xBA6904B7 },    // 1xx_Int 13 Secondary -> Int 13 Secondary
    { 0xDF285E5A, 0x68B8157A },    // 1xx_Int 13 Two-Handed -> Int 13 Two-Handed
    { 0xAD0770F0, 0xFCF45C10 },    // 1xx_Int 14 -> Int 14
    { 0x52E066D8, 0x3FC5B9F8 },    // 1xx_Int 14 Secondary -> Int 14 Secondary
    { 0x101BBBBB, 0x99AB72DB },    // 1xx_Int 14 Two-Handed -> Int 14 Two-Handed
    { 0xA568EFAA, 0xFFFFFFFF },    // 1xx_Int 14_Archon -> (none)
    { 0xAD0770F1, 0xFCF45C11 },    // 1xx_Int 15 -> Int 15
    { 0xD83D1C19, 0xC5226F39 },    // 1xx_Int 15 Secondary -> Int 15 Secondary
    { 0x410F191C, 0xCA9ED03C },    // 1xx_Int 15 Two-Handed -> Int 15 Two-Handed
    { 0xAD0770F2, 0xFCF45C12 },    // 1xx_Int 16 -> Int 16
    { 0x5D99D15A, 0x4A7F247A },    // 1xx_Int 16 Secondary -> Int 16 Secondary
    { 0x7202767D, 0xFB922D9D },    // 1xx_Int 16 Two-Handed -> Int 16 Two-Handed
    { 0xAD0770F3, 0xFCF45C13 },    // 1xx_Int 17 -> Int 17
    { 0xE2F6869B, 0xCFDBD9BB },    // 1xx_Int 17 Secondary -> Int 17 Secondary
    { 0xA2F5D3DE, 0xFB922D9D },    // 1xx_Int 17 Two-Handed -> Int 16 Two-Handed
    { 0x053E493D, 0x07AA505D },    // 1xx_Int 2 -> Int 2
    { 0x3C67C365, 0x6A5F3285 },    // 1xx_Int 2 Secondary -> Int 2 Secondary
    { 0x2A8EA9E8, 0x1773FD08 },    // 1xx_Int 2 Two-Handed -> Int 2 Two-Handed
    { 0x053E493E, 0x07AA505E },    // 1xx_Int 3 -> Int 3
    { 0xC1C478A6, 0xEFBBE7C6 },    // 1xx_Int 3 Secondary -> Int 3 Secondary
    { 0x5B820749, 0x48675A69 },    // 1xx_Int 3 Two-Handed -> Int 3 Two-Handed
    { 0x053E493F, 0x07AA505F },    // 1xx_Int 4 -> Int 4
    { 0x47212DE7, 0x75189D07 },    // 1xx_Int 4 Secondary -> Int 4 Secondary
    { 0x8C7564AA, 0x795AB7CA },    // 1xx_Int 4 Two-Handed -> Int 4 Two-Handed
    { 0x053E4940, 0x07AA5060 },    // 1xx_Int 5 -> Int 5
    { 0xCC7DE328, 0xFA755248 },    // 1xx_Int 5 Secondary -> Int 5 Secondary
    { 0xBD68C20B, 0xAA4E152B },    // 1xx_Int 5 Two-Handed -> Int 5 Two-Handed
    { 0x053E4941, 0x07AA5061 },    // 1xx_Int 6 -> Int 6
    { 0x51DA9869, 0x7FD20789 },    // 1xx_Int 6 Secondary -> Int 6 Secondary
    { 0xEE5C1F6C, 0xDB41728C },    // 1xx_Int 6 Two-Handed -> Int 6 Two-Handed
    { 0x053E4942, 0x07AA5062 },    // 1xx_Int 7 -> Int 7
    { 0xD7374DAA, 0x052EBCCA },    // 1xx_Int 7 Secondary -> Int 7 Secondary
    { 0x1F4F7CCD, 0x0C34CFED },    // 1xx_Int 7 Two-Handed -> Int 7 Two-Handed
    { 0x053E4943, 0x07AA5063 },    // 1xx_Int 8 -> Int 8
    { 0x5C9402EB, 0x8A8B720B },    // 1xx_Int 8 Secondary -> Int 8 Secondary
    { 0x5042DA2E, 0x3D282D4E },    // 1xx_Int 8 Two-Handed -> Int 8 Two-Handed
    { 0x053E4944, 0x07AA5064 },    // 1xx_Int 9 -> Int 9
    { 0xE1F0B82C, 0x0FE8274C },    // 1xx_Int 9 Secondary -> Int 9 Secondary
    { 0x8136378F, 0x6E1B8AAF },    // 1xx_Int 9 Two-Handed -> Int 9 Two-Handed
    { 0xF753BF88, 0xFFFFFFFF },    // 1xx_IntVit 0.1 Legendary -> (none)
    { 0x4C44D7B0, 0xFFFFFFFF },    // 1xx_IntVit 0.1 Secondary Legendary -> (none)
    { 0x18444BF3, 0xFFFFFFFF },    // 1xx_IntVit 0.1 Two-Handed Legendary -> (none)
    { 0x12DB7247, 0x11AFA567 },    // 1xx_IntVit I -> IntVit I
    { 0xC0EB40EF, 0x7C71DC0F },    // 1xx_IntVit I Secondary -> IntVit I Secondary
    { 0x3F81D8B2, 0x6BDBD7D2 },    // 1xx_IntVit I Two-Handed -> IntVit I Two-Handed
    { 0x6E49BB90, 0x47A452B0 },    // 1xx_IntVit II -> IntVit II
    { 0x34F87978, 0x61527898 },    // 1xx_IntVit II Secondary -> IntVit II Secondary
    { 0x3536225B, 0xECD0057B },    // 1xx_IntVit II Two-Handed -> IntVit II Two-Handed
    { 0x37812DF9, 0x3C2EA919 },    // 1xx_IntVit III -> IntVit III
    { 0x2AACC321, 0xE246A641 },    // 1xx_IntVit III Secondary -> IntVit III Secondary
    { 0xE173A124, 0x8C49E844 },    // 1xx_IntVit III Two-Handed -> IntVit III Two-Handed
    { 0x6E49BB9D, 0x47A452BD },    // 1xx_IntVit IV -> IntVit IV
    { 0xFAADADC5, 0x2707ACE5 },    // 1xx_IntVit IV Secondary -> IntVit IV Secondary
    { 0xB191E048, 0x692BC368 },    // 1xx_IntVit IV Two-Handed -> IntVit IV Two-Handed
    { 0x6E49BB9F, 0x47A452BF },    // 1xx_IntVit IX -> IntVit IX
    { 0x05671847, 0x31C11767 },    // 1xx_IntVit IX Secondary -> IntVit IX Secondary
    { 0x13789B0A, 0xCB127E2A },    // 1xx_IntVit IX Two-Handed -> IntVit IX Two-Handed
    { 0x12DB7254, 0x11AFA574 },    // 1xx_IntVit V -> IntVit V
    { 0x86A0753C, 0x4227105C },    // 1xx_IntVit V Secondary -> IntVit V Secondary
    { 0xBBDD969F, 0xE83795BF },    // 1xx_IntVit V Two-Handed -> IntVit V Two-Handed
    { 0x6E49BD3D, 0x47A4545D },    // 1xx_IntVit VI -> IntVit VI
    { 0xB1543765, 0xDDAE3685 },    // 1xx_IntVit VI Secondary -> IntVit VI Secondary
    { 0x3D099DE8, 0xF4A38108 },    // 1xx_IntVit VI Two-Handed -> IntVit VI Two-Handed
    { 0x37816546, 0x3C2EE066 },    // 1xx_IntVit VII -> IntVit VII
    { 0x32803EAE, 0xEA1A21CE },    // 1xx_IntVit VII Secondary -> IntVit VII Secondary
    { 0xE3B68E51, 0x8E8CD571 },    // 1xx_IntVit VII Two-Handed -> IntVit VII Two-Handed
    { 0x27AE0E6F, 0xC20AED8F },    // 1xx_IntVit VIII -> IntVit VIII
    { 0xD92D2F17, 0x84037637 },    // 1xx_IntVit VIII Secondary -> IntVit VIII Secondary
    { 0x60018BDA, 0x65A0B6FA },    // 1xx_IntVit VIII Two-Handed -> IntVit VIII Two-Handed
    { 0x12DB7256, 0x11AFA576 },    // 1xx_IntVit X -> IntVit X
    { 0x9159DFBE, 0x4CE07ADE },    // 1xx_IntVit X Secondary -> IntVit X Secondary
    { 0x1DC45161, 0x4A1E5081 },    // 1xx_IntVit X Two-Handed -> IntVit X Two-Handed
    { 0x6E49BD7F, 0x47A4549F },    // 1xx_IntVit XI -> IntVit XI
    { 0x133AF227, 0x3F94F147 },    // 1xx_IntVit XI Secondary -> IntVit XI Secondary
    { 0xDBC7B0EA, 0x9361940A },    // 1xx_IntVit XI Two-Handed -> IntVit XI Two-Handed
    { 0x37816DC8, 0x3C2EE8E8 },    // 1xx_IntVit XII -> IntVit XII
    { 0xD13E51B0, 0x88D834D0 },    // 1xx_IntVit XII Secondary -> IntVit XII Secondary
    { 0x5A370193, 0x050D48B3 },    // 1xx_IntVit XII Two-Handed -> IntVit XII Two-Handed
    { 0x9BB1C8DD, 0xA05F43FD },    // 1xx_KillLife 1 -> KillLife 1
    { 0x16774B05, 0xCE112E25 },    // 1xx_KillLife 1 Secondary -> KillLife 1 Secondary
    { 0x468F2588, 0xF1656CA8 },    // 1xx_KillLife 1 Two-Handed -> KillLife 1 Two-Handed
    { 0x11EAE4AD, 0xAC47C3CD },    // 1xx_KillLife 10 -> KillLife 10
    { 0x8A616AD5, 0x3537B1F5 },    // 1xx_KillLife 10 Secondary -> KillLife 10 Secondary
    { 0x37BD3F58, 0x3D5C6A78 },    // 1xx_KillLife 10 Two-Handed -> KillLife 10 Two-Handed
    { 0x11EAE4AE, 0xAC47C3CE },    // 1xx_KillLife 11 -> KillLife 11
    { 0x0FBE2016, 0xBA946736 },    // 1xx_KillLife 11 Secondary -> KillLife 11 Secondary
    { 0x68B09CB9, 0x6E4FC7D9 },    // 1xx_KillLife 11 Two-Handed -> KillLife 11 Two-Handed
    { 0x11EAE4AF, 0xAC47C3CF },    // 1xx_KillLife 12 -> KillLife 12
    { 0x951AD557, 0x3FF11C77 },    // 1xx_KillLife 12 Secondary -> KillLife 12 Secondary
    { 0x99A3FA1A, 0x9F43253A },    // 1xx_KillLife 12 Two-Handed -> KillLife 12 Two-Handed
    { 0x11EAE4B0, 0xAC47C3D0 },    // 1xx_KillLife 13 -> KillLife 13
    { 0x1A778A98, 0xC54DD1B8 },    // 1xx_KillLife 13 Secondary -> KillLife 13 Secondary
    { 0xCA97577B, 0xD036829B },    // 1xx_KillLife 13 Two-Handed -> KillLife 13 Two-Handed
    { 0x11EAE4B1, 0xAC47C3D1 },    // 1xx_KillLife 14 -> KillLife 14
    { 0x9FD43FD9, 0x4AAA86F9 },    // 1xx_KillLife 14 Secondary -> KillLife 14 Secondary
    { 0xFB8AB4DC, 0x0129DFFC },    // 1xx_KillLife 14 Two-Handed -> KillLife 14 Two-Handed
    { 0x11EAE4B2, 0xAC47C3D1 },    // 1xx_KillLife 15 -> KillLife 14
    { 0x2530F51A, 0x4AAA86F9 },    // 1xx_KillLife 15 Secondary -> KillLife 14 Secondary
    { 0x2C7E123D, 0x0129DFFC },    // 1xx_KillLife 15 Two-Handed -> KillLife 14 Two-Handed
    { 0x11EAE4B3, 0xAC47C3D1 },    // 1xx_KillLife 16 -> KillLife 14
    { 0xAA8DAA5B, 0x4AAA86F9 },    // 1xx_KillLife 16 Secondary -> KillLife 14 Secondary
    { 0x5D716F9E, 0x0129DFFC },    // 1xx_KillLife 16 Two-Handed -> KillLife 14 Two-Handed
    { 0x9BB1C8DE, 0xA05F43FE },    // 1xx_KillLife 2 -> KillLife 2
    { 0x9BD40046, 0x536DE366 },    // 1xx_KillLife 2 Secondary -> KillLife 2 Secondary
    { 0x778282E9, 0x2258CA09 },    // 1xx_KillLife 2 Two-Handed -> KillLife 2 Two-Handed
    { 0x9BB1C8DF, 0xA05F43FF },    // 1xx_KillLife 3 -> KillLife 3
    { 0x2130B587, 0xD8CA98A7 },    // 1xx_KillLife 3 Secondary -> KillLife 3 Secondary
    { 0xA875E04A, 0x534C276A },    // 1xx_KillLife 3 Two-Handed -> KillLife 3 Two-Handed
    { 0x9BB1C8E0, 0xA05F4400 },    // 1xx_KillLife 4 -> KillLife 4
    { 0xA68D6AC8, 0x5E274DE8 },    // 1xx_KillLife 4 Secondary -> KillLife 4 Secondary
    { 0xD9693DAB, 0x843F84CB },    // 1xx_KillLife 4 Two-Handed -> KillLife 4 Two-Handed
    { 0x9BB1C8E1, 0xA05F4401 },    // 1xx_KillLife 5 -> KillLife 5
    { 0x2BEA2009, 0xE3840329 },    // 1xx_KillLife 5 Secondary -> KillLife 5 Secondary
    { 0x0A5C9B0C, 0xB532E22C },    // 1xx_KillLife 5 Two-Handed -> KillLife 5 Two-Handed
    { 0x9BB1C8E2, 0xA05F4402 },    // 1xx_KillLife 6 -> KillLife 6
    { 0xB146D54A, 0x68E0B86A },    // 1xx_KillLife 6 Secondary -> KillLife 6 Secondary
    { 0x3B4FF86D, 0xE6263F8D },    // 1xx_KillLife 6 Two-Handed -> KillLife 6 Two-Handed
    { 0x9BB1C8E3, 0xA05F4403 },    // 1xx_KillLife 7 -> KillLife 7
    { 0x36A38A8B, 0xEE3D6DAB },    // 1xx_KillLife 7 Secondary -> KillLife 7 Secondary
    { 0x6C4355CE, 0x17199CEE },    // 1xx_KillLife 7 Two-Handed -> KillLife 7 Two-Handed
    { 0x9BB1C8E4, 0xA05F4404 },    // 1xx_KillLife 8 -> KillLife 8
    { 0xBC003FCC, 0x739A22EC },    // 1xx_KillLife 8 Secondary -> KillLife 8 Secondary
    { 0x9D36B32F, 0x480CFA4F },    // 1xx_KillLife 8 Two-Handed -> KillLife 8 Two-Handed
    { 0x9BB1C8E5, 0xA05F4405 },    // 1xx_KillLife 9 -> KillLife 9
    { 0x415CF50D, 0xF8F6D82D },    // 1xx_KillLife 9 Secondary -> KillLife 9 Secondary
    { 0xCE2A1090, 0x790057B0 },    // 1xx_KillLife 9 Two-Handed -> KillLife 9 Two-Handed
    { 0x9D7A7F7A, 0xA227FA9A },    // 1xx_KillMana 1 -> KillMana 1
    { 0x4CCA6EEA, 0xE7274E0A },    // 1xx_KillMana 10 -> KillMana 10
    { 0x4CCA6EEB, 0xE7274E0B },    // 1xx_KillMana 11 -> KillMana 11
    { 0x4CCA6EEC, 0xE7274E0C },    // 1xx_KillMana 12 -> KillMana 12
    { 0x9D7A7F7B, 0xA227FA9B },    // 1xx_KillMana 2 -> KillMana 2
    { 0x9D7A7F7C, 0xA227FA9C },    // 1xx_KillMana 3 -> KillMana 3
    { 0x9D7A7F7D, 0xA227FA9D },    // 1xx_KillMana 4 -> KillMana 4
    { 0x9D7A7F7E, 0xA227FA9E },    // 1xx_KillMana 5 -> KillMana 5
    { 0x9D7A7F7F, 0xA227FA9F },    // 1xx_KillMana 6 -> KillMana 6
    { 0x9D7A7F80, 0xA227FAA0 },    // 1xx_KillMana 7 -> KillMana 7
    { 0x9D7A7F81, 0xA227FAA1 },    // 1xx_KillMana 8 -> KillMana 8
    { 0x9D7A7F82, 0xA227FAA2 },    // 1xx_KillMana 9 -> KillMana 9
    { 0x267E2A06, 0xFFFFFFFF },    // 1xx_Kings 0.1 Legendary -> (none)
    { 0xDBFBAFC5, 0x2985FEE5 },    // 1xx_Kings I -> Kings I
    { 0x5B71A8CE, 0x5A45DBEE },    // 1xx_Kings II -> Kings II
    { 0xC9A6C2F7, 0xA3015A17 },    // 1xx_Kings III -> Kings III
    { 0x5B71A8DB, 0x5A45DBFB },    // 1xx_Kings IV -> Kings IV
    { 0x5B71A8DD, 0xA3019164 },    // 1xx_Kings IX -> Kings VII
    { 0xDBFBAFD2, 0x2985FEF2 },    // 1xx_Kings V -> Kings V
    { 0x5B71AA7B, 0x5A45DD9B },    // 1xx_Kings VI -> Kings VI
    { 0xC9A6FA44, 0xA3019164 },    // 1xx_Kings VII -> Kings VII
    { 0xFE86432D, 0xA3019164 },    // 1xx_Kings VIII -> Kings VII
    { 0xDBFBAFD4, 0xA3019164 },    // 1xx_Kings X -> Kings VII
    { 0x5B71AABD, 0xA3019164 },    // 1xx_Kings XI -> Kings VII
    { 0x9DECA6CA, 0x597341EA },    // 1xx_Life 0.1 Legendary -> Life 0.1 Legendary
    { 0x1A513972, 0x42AC3C92 },    // 1xx_Life 0.1 Secondary Legendary -> Life 0.1 Secondary Legendary
    { 0x23495C0B, 0xDECFF72B },    // 1xx_Life 0.2 Legendary -> Life 0.2 Legendary
    { 0x6B5E33F3, 0x93B93713 },    // 1xx_Life 0.2 Secondary Legendary -> Life 0.2 Secondary Legendary
    { 0xA8A6114C, 0x642CAC6C },    // 1xx_Life 0.3 Legendary -> Life 0.3 Legendary
    { 0xBC6B2E74, 0xE4C63194 },    // 1xx_Life 0.3 Secondary Legendary -> Life 0.3 Secondary Legendary
    { 0xB3A5E689, 0x0392D1A9 },    // 1xx_Life I -> Life I
    { 0xCA3D6FB1, 0xB722C2D1 },    // 1xx_Life I Secondary -> Life I Secondary
    { 0x2862B812, 0x75ED0732 },    // 1xx_Life II -> Life II
    { 0x6890807A, 0xF220379A },    // 1xx_Life II Secondary -> Life II Secondary
    { 0x34B9BABB, 0x338DEDDB },    // 1xx_Life III -> Life III
    { 0xD145AA63, 0x8CCC4583 },    // 1xx_Life III Secondary -> Life III Secondary
    { 0x2862B81F, 0x75ED073F },    // 1xx_Life IV -> Life IV
    { 0x2E45B4C7, 0xB7D56BE7 },    // 1xx_Life IV Secondary -> Life IV Secondary
    { 0xB3A5E696, 0x0392D1B6 },    // 1xx_Life V -> Life V
    { 0x8FF2A3FE, 0x7CD7F71E },    // 1xx_Life V Secondary -> Life V Secondary
    { 0x2862B9BF, 0x75ED08DF },    // 1xx_Life VI -> Life VI
    { 0xE4EC3E67, 0x6E7BF587 },    // 1xx_Life VI Secondary -> Life VI Secondary
    { 0x34B9F208, 0x338E2528 },    // 1xx_Life VII -> Life VII
    { 0xD91925F0, 0x949FC110 },    // 1xx_Life VII Secondary -> Life VII Secondary
    { 0x28640F84, 0x75EE5EA4 },    // 1xx_LifeS 1 -> LifeS 1
    { 0xBA4B95CF, 0x75D230EF },    // 1xx_LifeS 1 Two-Handed -> LifeS 1 Two-Handed
    { 0x34E60034, 0x75EE5EAA },    // 1xx_LifeS 10 -> LifeS 7
    { 0x2307B87F, 0x9B866135 },    // 1xx_LifeS 10 Two-Handed -> LifeS 7 Two-Handed
    { 0x34E60035, 0x75EE5EAA },    // 1xx_LifeS 11 -> LifeS 7
    { 0x53FB15E0, 0x9B866135 },    // 1xx_LifeS 11 Two-Handed -> LifeS 7 Two-Handed
    { 0x28640F85, 0x75EE5EA5 },    // 1xx_LifeS 2 -> LifeS 2
    { 0xEB3EF330, 0xA6C58E50 },    // 1xx_LifeS 2 Two-Handed -> LifeS 2 Two-Handed
    { 0x28640F86, 0x75EE5EA6 },    // 1xx_LifeS 3 -> LifeS 3
    { 0x1C325091, 0xD7B8EBB1 },    // 1xx_LifeS 3 Two-Handed -> LifeS 3 Two-Handed
    { 0x28640F87, 0x75EE5EA7 },    // 1xx_LifeS 4 -> LifeS 4
    { 0x4D25ADF2, 0x08AC4912 },    // 1xx_LifeS 4 Two-Handed -> LifeS 4 Two-Handed
    { 0x28640F88, 0x75EE5EA8 },    // 1xx_LifeS 5 -> LifeS 5
    { 0x7E190B53, 0x399FA673 },    // 1xx_LifeS 5 Two-Handed -> LifeS 5 Two-Handed
    { 0x28640F89, 0x75EE5EA9 },    // 1xx_LifeS 6 -> LifeS 6
    { 0xAF0C68B4, 0x6A9303D4 },    // 1xx_LifeS 6 Two-Handed -> LifeS 6 Two-Handed
    { 0x28640F8A, 0x75EE5EAA },    // 1xx_LifeS 7 -> LifeS 7
    { 0xDFFFC615, 0x9B866135 },    // 1xx_LifeS 7 Two-Handed -> LifeS 7 Two-Handed
    { 0x28640F8B, 0x75EE5EAA },    // 1xx_LifeS 8 -> LifeS 7
    { 0x10F32376, 0x9B866135 },    // 1xx_LifeS 8 Two-Handed -> LifeS 7 Two-Handed
    { 0x28640F8C, 0x75EE5EAA },    // 1xx_LifeS 9 -> LifeS 7
    { 0x41E680D7, 0x9B866135 },    // 1xx_LifeS 9 Two-Handed -> LifeS 7 Two-Handed
    { 0x84D03139, 0x6AC8F459 },    // 1xx_LightningD 1 -> LightningD 1
    { 0xDB098787, 0x64993EA7 },    // 1xx_LightningD 1 Fast -> LightningD 1 Fast
    { 0xF6521C64, 0xAFD6AB84 },    // 1xx_LightningD 1 Two-Handed -> LightningD 1 Two-Handed
    { 0x1ED65889, 0xC3E77FA9 },    // 1xx_LightningD 10 -> LightningD 10
    { 0x5C9CC0D7, 0x18235BF7 },    // 1xx_LightningD 10 Fast -> LightningD 10 Fast
    { 0xDFDF11B4, 0xC9F584D4 },    // 1xx_LightningD 10 Two-Handed -> LightningD 10 Two-Handed
    { 0x1ED6588A, 0xC3E77FAA },    // 1xx_LightningD 11 -> LightningD 11
    { 0x5EF1E978, 0x1A788498 },    // 1xx_LightningD 11 Fast -> LightningD 11 Fast
    { 0x10D26F15, 0xFAE8E235 },    // 1xx_LightningD 11 Two-Handed -> LightningD 11 Two-Handed
    { 0x1ED6588B, 0xC3E77FAB },    // 1xx_LightningD 12 -> LightningD 12
    { 0x61471219, 0x1CCDAD39 },    // 1xx_LightningD 12 Fast -> LightningD 12 Fast
    { 0x41C5CC76, 0x2BDC3F96 },    // 1xx_LightningD 12 Two-Handed -> LightningD 12 Two-Handed
    { 0x1ED6588C, 0xC3E77FAC },    // 1xx_LightningD 13 -> LightningD 13
    { 0x639C3ABA, 0x1F22D5DA },    // 1xx_LightningD 13 Fast -> LightningD 13 Fast
    { 0x72B929D7, 0x5CCF9CF7 },    // 1xx_LightningD 13 Two-Handed -> LightningD 13 Two-Handed
    { 0x1ED6588D, 0xC3E77FAD },    // 1xx_LightningD 14 -> LightningD 14
    { 0x65F1635B, 0x2177FE7B },    // 1xx_LightningD 14 Fast -> LightningD 14 Fast
    { 0xA3AC8738, 0x8DC2FA58 },    // 1xx_LightningD 14 Two-Handed -> LightningD 14 Two-Handed
    { 0x1ED6588E, 0xC3E77FAD },    // 1xx_LightningD 15 -> LightningD 14
    { 0x68468BFC, 0x2177FE7B },    // 1xx_LightningD 15 Fast -> LightningD 14 Fast
    { 0xD49FE499, 0x8DC2FA58 },    // 1xx_LightningD 15 Two-Handed -> LightningD 14 Two-Handed
    { 0x1ED6588F, 0xC3E77FAD },    // 1xx_LightningD 16 -> LightningD 14
    { 0x6A9BB49D, 0x2177FE7B },    // 1xx_LightningD 16 Fast -> LightningD 14 Fast
    { 0x059341FA, 0x8DC2FA58 },    // 1xx_LightningD 16 Two-Handed -> LightningD 14 Two-Handed
    { 0x84D0313A, 0x6AC8F45A },    // 1xx_LightningD 2 -> LightningD 2
    { 0xDD5EB028, 0x66EE6748 },    // 1xx_LightningD 2 Fast -> LightningD 2 Fast
    { 0x274579C5, 0xE0CA08E5 },    // 1xx_LightningD 2 Two-Handed -> LightningD 2 Two-Handed
    { 0x84D0313B, 0x6AC8F45B },    // 1xx_LightningD 3 -> LightningD 3
    { 0xDFB3D8C9, 0x69438FE9 },    // 1xx_LightningD 3 Fast -> LightningD 3 Fast
    { 0x5838D726, 0x11BD6646 },    // 1xx_LightningD 3 Two-Handed -> LightningD 3 Two-Handed
    { 0x84D0313C, 0x6AC8F45C },    // 1xx_LightningD 4 -> LightningD 4
    { 0xE209016A, 0x6B98B88A },    // 1xx_LightningD 4 Fast -> LightningD 4 Fast
    { 0x892C3487, 0x42B0C3A7 },    // 1xx_LightningD 4 Two-Handed -> LightningD 4 Two-Handed
    { 0x84D0313D, 0x6AC8F45D },    // 1xx_LightningD 5 -> LightningD 5
    { 0xE45E2A0B, 0x6DEDE12B },    // 1xx_LightningD 5 Fast -> LightningD 5 Fast
    { 0xBA1F91E8, 0x73A42108 },    // 1xx_LightningD 5 Two-Handed -> LightningD 5 Two-Handed
    { 0x84D0313E, 0x6AC8F45E },    // 1xx_LightningD 6 -> LightningD 6
    { 0xE6B352AC, 0x704309CC },    // 1xx_LightningD 6 Fast -> LightningD 6 Fast
    { 0xEB12EF49, 0xA4977E69 },    // 1xx_LightningD 6 Two-Handed -> LightningD 6 Two-Handed
    { 0x84D0313F, 0x6AC8F45F },    // 1xx_LightningD 7 -> LightningD 7
    { 0xE9087B4D, 0x7298326D },    // 1xx_LightningD 7 Fast -> LightningD 7 Fast
    { 0x1C064CAA, 0xD58ADBCA },    // 1xx_LightningD 7 Two-Handed -> LightningD 7 Two-Handed
    { 0x84D03140, 0x6AC8F460 },    // 1xx_LightningD 8 -> LightningD 8
    { 0xEB5DA3EE, 0x74ED5B0E },    // 1xx_LightningD 8 Fast -> LightningD 8 Fast
    { 0x4CF9AA0B, 0x067E392B },    // 1xx_LightningD 8 Two-Handed -> LightningD 8 Two-Handed
    { 0x84D03141, 0x6AC8F461 },    // 1xx_LightningD 9 -> LightningD 9
    { 0xEDB2CC8F, 0x774283AF },    // 1xx_LightningD 9 Fast -> LightningD 9 Fast
    { 0x7DED076C, 0x3771968C },    // 1xx_LightningD 9 Two-Handed -> LightningD 9 Two-Handed
    { 0x4CFC0668, 0x80B76D88 },    // 1xx_LightningResist 0.1 Legendary -> LightningResist 0.1 Legendary
    { 0xD258BBA9, 0x061422C9 },    // 1xx_LightningResist 0.2 Legendary -> LightningResist 0.2 Legendary
    { 0x57B570EA, 0x8B70D80A },    // 1xx_LightningResist 0.3 Legendary -> LightningResist 0.3 Legendary
    { 0x253A6927, 0xAECA2047 },    // 1xx_LightningResist I -> LightningResist I
    { 0xCC878E70, 0x880E2990 },    // 1xx_LightningResist II -> LightningResist II
    { 0x5D795CD9, 0x89D35BF9 },    // 1xx_LightningResist III -> LightningResist III
    { 0xCC878E7D, 0x880E299D },    // 1xx_LightningResist IV -> LightningResist IV
    { 0xCC878E7F, 0x880E299F },    // 1xx_LightningResist IX -> LightningResist IX
    { 0x253A6934, 0xAECA2054 },    // 1xx_LightningResist V -> LightningResist V
    { 0xCC87901D, 0x880E2B3D },    // 1xx_LightningResist VI -> LightningResist VI
    { 0x5D799426, 0x89D39346 },    // 1xx_LightningResist VII -> LightningResist VII
    { 0x0CAC194F, 0xC445FC6F },    // 1xx_LightningResist VIII -> LightningResist VIII
    { 0x253A6936, 0xAECA2056 },    // 1xx_LightningResist X -> LightningResist X
    { 0x8310AE9F, 0x1D6D8DBF },    // 1xx_ManaRegen 1 -> ManaRegen 1
    { 0xE52682AF, 0xCB1F45CF },    // 1xx_ManaRegen 10 -> ManaRegen 10
    { 0xE52682B0, 0xCB1F45CF },    // 1xx_ManaRegen 11 -> ManaRegen 10
    { 0xE52682B1, 0xCB1F45CF },    // 1xx_ManaRegen 12 -> ManaRegen 10
    { 0xE52682B2, 0xCB1F45CF },    // 1xx_ManaRegen 13 -> ManaRegen 10
    { 0xE52682B3, 0xCB1F45CF },    // 1xx_ManaRegen 14 -> ManaRegen 10
    { 0x8310AEA0, 0x1D6D8DC0 },    // 1xx_ManaRegen 2 -> ManaRegen 2
    { 0x8310AEA1, 0x1D6D8DC1 },    // 1xx_ManaRegen 3 -> ManaRegen 3
    { 0x8310AEA2, 0x1D6D8DC2 },    // 1xx_ManaRegen 4 -> ManaRegen 4
    { 0x8310AEA3, 0x1D6D8DC3 },    // 1xx_ManaRegen 5 -> ManaRegen 5
    { 0x8310AEA4, 0x1D6D8DC4 },    // 1xx_ManaRegen 6 -> ManaRegen 6
    { 0x8310AEA5, 0x1D6D8DC5 },    // 1xx_ManaRegen 7 -> ManaRegen 7
    { 0x8310AEA6, 0x1D6D8DC6 },    // 1xx_ManaRegen 8 -> ManaRegen 8
    { 0x8310AEA7, 0x1D6D8DC7 },    // 1xx_ManaRegen 9 -> ManaRegen 9
    { 0xE0A018EE, 0xCD856C0E },    // 1xx_MaxArcanePower 1 -> MaxArcanePower 1
    { 0x9DDFEA09, 0x675FA529 },    // 1xx_MaxArcanePower 1 Legendary -> MaxArcanePower 1 Legendary
    { 0x591533F9, 0x528C5319 },    // 1xx_MaxArcanePower 10 Legendary -> MaxArcanePower 10 Legendary
    { 0xDE71E93A, 0x528C5319 },    // 1xx_MaxArcanePower 11 Legendary -> MaxArcanePower 10 Legendary
    { 0x63CE9E7B, 0x528C5319 },    // 1xx_MaxArcanePower 12 Legendary -> MaxArcanePower 10 Legendary
    { 0xE92B53BC, 0x528C5319 },    // 1xx_MaxArcanePower 13 Legendary -> MaxArcanePower 10 Legendary
    { 0x6E8808FD, 0x528C5319 },    // 1xx_MaxArcanePower 14 Legendary -> MaxArcanePower 10 Legendary
    { 0xE0A018EF, 0xCD856C0F },    // 1xx_MaxArcanePower 2 -> MaxArcanePower 2
    { 0x233C9F4A, 0xECBC5A6A },    // 1xx_MaxArcanePower 2 Legendary -> MaxArcanePower 2 Legendary
    { 0xE0A018F0, 0xCD856C10 },    // 1xx_MaxArcanePower 3 -> MaxArcanePower 3
    { 0xA899548B, 0x72190FAB },    // 1xx_MaxArcanePower 3 Legendary -> MaxArcanePower 3 Legendary
    { 0xE0A018F1, 0xCD856C11 },    // 1xx_MaxArcanePower 4 -> MaxArcanePower 4
    { 0x2DF609CC, 0xF775C4EC },    // 1xx_MaxArcanePower 4 Legendary -> MaxArcanePower 4 Legendary
    { 0xE0A018F2, 0xCD856C12 },    // 1xx_MaxArcanePower 5 -> MaxArcanePower 5
    { 0xB352BF0D, 0x7CD27A2D },    // 1xx_MaxArcanePower 5 Legendary -> MaxArcanePower 5 Legendary
    { 0xE0A018F3, 0xCD856C13 },    // 1xx_MaxArcanePower 6 -> MaxArcanePower 6
    { 0x38AF744E, 0x022F2F6E },    // 1xx_MaxArcanePower 6 Legendary -> MaxArcanePower 6 Legendary
    { 0xE0A018F4, 0xCD856C14 },    // 1xx_MaxArcanePower 7 -> MaxArcanePower 7
    { 0xBE0C298F, 0x878BE4AF },    // 1xx_MaxArcanePower 7 Legendary -> MaxArcanePower 7 Legendary
    { 0xE0A018F5, 0xCD856C15 },    // 1xx_MaxArcanePower 8 -> MaxArcanePower 8
    { 0x4368DED0, 0x0CE899F0 },    // 1xx_MaxArcanePower 8 Legendary -> MaxArcanePower 8 Legendary
    { 0xE0A018F6, 0xCD856C16 },    // 1xx_MaxArcanePower 9 -> MaxArcanePower 9
    { 0xC8C59411, 0x92454F31 },    // 1xx_MaxArcanePower 9 Legendary -> MaxArcanePower 9 Legendary
    { 0x465C667B, 0x7453D59B },    // 1xx_MaxDiscipline 1 -> MaxDiscipline 1
    { 0xB5304BD6, 0xE21522F6 },    // 1xx_MaxDiscipline 1 Legendary -> MaxDiscipline 1 Legendary
    { 0x5A71CF66, 0x23F18A86 },    // 1xx_MaxDiscipline 10 Legendary -> MaxDiscipline 10 Legendary
    { 0xDFCE84A7, 0x23F18A86 },    // 1xx_MaxDiscipline 11 Legendary -> MaxDiscipline 10 Legendary
    { 0x652B39E8, 0x23F18A86 },    // 1xx_MaxDiscipline 12 Legendary -> MaxDiscipline 10 Legendary
    { 0xEA87EF29, 0x23F18A86 },    // 1xx_MaxDiscipline 13 Legendary -> MaxDiscipline 10 Legendary
    { 0x6FE4A46A, 0x23F18A86 },    // 1xx_MaxDiscipline 14 Legendary -> MaxDiscipline 10 Legendary
    { 0x465C667C, 0x7453D59C },    // 1xx_MaxDiscipline 2 -> MaxDiscipline 2
    { 0x3A8D0117, 0x6771D837 },    // 1xx_MaxDiscipline 2 Legendary -> MaxDiscipline 2 Legendary
    { 0x465C667D, 0x7453D59D },    // 1xx_MaxDiscipline 3 -> MaxDiscipline 3
    { 0xBFE9B658, 0xECCE8D78 },    // 1xx_MaxDiscipline 3 Legendary -> MaxDiscipline 3 Legendary
    { 0x465C667E, 0x7453D59E },    // 1xx_MaxDiscipline 4 -> MaxDiscipline 4
    { 0x45466B99, 0x722B42B9 },    // 1xx_MaxDiscipline 4 Legendary -> MaxDiscipline 4 Legendary
    { 0x465C667F, 0x7453D59F },    // 1xx_MaxDiscipline 5 -> MaxDiscipline 5
    { 0xCAA320DA, 0xF787F7FA },    // 1xx_MaxDiscipline 5 Legendary -> MaxDiscipline 5 Legendary
    { 0x465C6680, 0x7453D5A0 },    // 1xx_MaxDiscipline 6 -> MaxDiscipline 6
    { 0x4FFFD61B, 0x7CE4AD3B },    // 1xx_MaxDiscipline 6 Legendary -> MaxDiscipline 6 Legendary
    { 0x465C6681, 0x7453D5A1 },    // 1xx_MaxDiscipline 7 -> MaxDiscipline 7
    { 0xD55C8B5C, 0x0241627C },    // 1xx_MaxDiscipline 7 Legendary -> MaxDiscipline 7 Legendary
    { 0x465C6682, 0x7453D5A2 },    // 1xx_MaxDiscipline 8 -> MaxDiscipline 8
    { 0x5AB9409D, 0x879E17BD },    // 1xx_MaxDiscipline 8 Legendary -> MaxDiscipline 8 Legendary
    { 0x465C6683, 0x7453D5A3 },    // 1xx_MaxDiscipline 9 -> MaxDiscipline 9
    { 0xE015F5DE, 0x0CFACCFE },    // 1xx_MaxDiscipline 9 Legendary -> MaxDiscipline 9 Legendary
    { 0x5053975D, 0x29AE2E7D },    // 1xx_MaxFury 1 -> MaxFury 1
    { 0xFDBB7F38, 0x2A157E58 },    // 1xx_MaxFury 1 Legendary -> MaxFury 1 Legendary
    { 0xB4636F08, 0x6BFD5228 },    // 1xx_MaxFury 10 Legendary -> MaxFury 10 Legendary
    { 0x39C02449, 0x6BFD5228 },    // 1xx_MaxFury 11 Legendary -> MaxFury 10 Legendary
    { 0xBF1CD98A, 0x6BFD5228 },    // 1xx_MaxFury 12 Legendary -> MaxFury 10 Legendary
    { 0x44798ECB, 0x6BFD5228 },    // 1xx_MaxFury 13 Legendary -> MaxFury 10 Legendary
    { 0xC9D6440C, 0x6BFD5228 },    // 1xx_MaxFury 14 Legendary -> MaxFury 10 Legendary
    { 0x5053975E, 0x29AE2E7E },    // 1xx_MaxFury 2 -> MaxFury 2
    { 0x83183479, 0xAF723399 },    // 1xx_MaxFury 2 Legendary -> MaxFury 2 Legendary
    { 0x5053975F, 0x29AE2E7F },    // 1xx_MaxFury 3 -> MaxFury 3
    { 0x0874E9BA, 0x34CEE8DA },    // 1xx_MaxFury 3 Legendary -> MaxFury 3 Legendary
    { 0x50539760, 0x29AE2E80 },    // 1xx_MaxFury 4 -> MaxFury 4
    { 0x8DD19EFB, 0xBA2B9E1B },    // 1xx_MaxFury 4 Legendary -> MaxFury 4 Legendary
    { 0x50539761, 0x29AE2E81 },    // 1xx_MaxFury 5 -> MaxFury 5
    { 0x132E543C, 0x3F88535C },    // 1xx_MaxFury 5 Legendary -> MaxFury 5 Legendary
    { 0x50539762, 0x29AE2E82 },    // 1xx_MaxFury 6 -> MaxFury 6
    { 0x988B097D, 0xC4E5089D },    // 1xx_MaxFury 6 Legendary -> MaxFury 6 Legendary
    { 0x50539763, 0x29AE2E83 },    // 1xx_MaxFury 7 -> MaxFury 7
    { 0x1DE7BEBE, 0x4A41BDDE },    // 1xx_MaxFury 7 Legendary -> MaxFury 7 Legendary
    { 0x50539764, 0x29AE2E84 },    // 1xx_MaxFury 8 -> MaxFury 8
    { 0xA34473FF, 0xCF9E731F },    // 1xx_MaxFury 8 Legendary -> MaxFury 8 Legendary
    { 0x50539765, 0x29AE2E85 },    // 1xx_MaxFury 9 -> MaxFury 9
    { 0x28A12940, 0x54FB2860 },    // 1xx_MaxFury 9 Legendary -> MaxFury 9 Legendary
    { 0x5F3B3214, 0x3895C934 },    // 1xx_MaxMana 1 -> MaxMana 1
    { 0x46A174C4, 0x4B4EEFE4 },    // 1xx_MaxMana 10 -> MaxMana 10
    { 0x46A174C5, 0x4B4EEFE4 },    // 1xx_MaxMana 11 -> MaxMana 10
    { 0x46A174C6, 0x4B4EEFE4 },    // 1xx_MaxMana 12 -> MaxMana 10
    { 0x46A174C7, 0x4B4EEFE4 },    // 1xx_MaxMana 13 -> MaxMana 10
    { 0x46A174C8, 0x4B4EEFE4 },    // 1xx_MaxMana 14 -> MaxMana 10
    { 0x5F3B3215, 0x3895C935 },    // 1xx_MaxMana 2 -> MaxMana 2
    { 0x5F3B3216, 0x3895C936 },    // 1xx_MaxMana 3 -> MaxMana 3
    { 0x5F3B3217, 0x3895C937 },    // 1xx_MaxMana 4 -> MaxMana 4
    { 0x5F3B3218, 0x3895C938 },    // 1xx_MaxMana 5 -> MaxMana 5
    { 0x5F3B3219, 0x3895C939 },    // 1xx_MaxMana 6 -> MaxMana 6
    { 0x5F3B321A, 0x3895C93A },    // 1xx_MaxMana 7 -> MaxMana 7
    { 0x5F3B321B, 0x3895C93B },    // 1xx_MaxMana 8 -> MaxMana 8
    { 0x5F3B321C, 0x3895C93C },    // 1xx_MaxMana 9 -> MaxMana 9
    { 0x6CC5D89C, 0x003D7BBC },    // 1xx_MF I -> MF I
    { 0x3F555584, 0x868B60A4 },    // 1xx_MF I Secondary -> MF I Secondary
    { 0x0580EC85, 0x07ECF3A5 },    // 1xx_MF II -> MF II
    { 0x80A520AD, 0xAE9C8FCD },    // 1xx_MF II Secondary -> MF II Secondary
    { 0xB59E7D8E, 0x058B68AE },    // 1xx_MF III -> MF III
    { 0xEBEE50F6, 0xD8D3A416 },    // 1xx_MF III Secondary -> MF III Secondary
    { 0x0580EC92, 0x07ECF3B2 },    // 1xx_MF IV -> MF IV
    { 0x465A54FA, 0x7451C41A },    // 1xx_MF IV Secondary -> MF IV Secondary
    { 0x0580EC94, 0x07ECF3B4 },    // 1xx_MF IX -> MF IX
    { 0x5113BF7C, 0x7F0B2E9C },    // 1xx_MF IX Secondary -> MF IX Secondary
    { 0x6CC5D8A9, 0x003D7BC9 },    // 1xx_MF V -> MF V
    { 0x050A89D1, 0x4C4094F1 },    // 1xx_MF V Secondary -> MF V Secondary
    { 0x0580EE32, 0x07ECF552 },    // 1xx_MF VI -> MF VI
    { 0xFD00DE9A, 0x2AF84DBA },    // 1xx_MF VI Secondary -> MF VI Secondary
    { 0xB59EB4DB, 0x058B9FFB },    // 1xx_MF VII -> MF VII
    { 0xF3C1CC83, 0xE0A71FA3 },    // 1xx_MF VII Secondary -> MF VII Secondary
    { 0x697550A4, 0xB6FF9FC4 },    // 1xx_MF VIII -> MF VIII
    { 0xC2A0778C, 0x4C302EAC },    // 1xx_MF VIII Secondary -> MF VIII Secondary
    { 0x6CC5D8AB, 0x003D7BCB },    // 1xx_MF X -> MF X
    { 0x0FC3F453, 0x56F9FF73 },    // 1xx_MF X Secondary -> MF X Secondary
    { 0xC5F6AE0D, 0x60538D2D },    // 1xx_MinMaxDam 1 -> MinMaxDam 1
    { 0xF22328DB, 0xDF087BFB },    // 1xx_MinMaxDam 1 Fast -> MinMaxDam 1 Fast
    { 0xD5406C35, 0x8016B355 },    // 1xx_MinMaxDam 1 Secondary -> MinMaxDam 1 Secondary
    { 0xDE7C6CB8, 0xE41B97D8 },    // 1xx_MinMaxDam 1 Two-Handed -> MinMaxDam 1 Two-Handed
    { 0x84CC6FDD, 0x6AC532FD },    // 1xx_MinMaxDam 10 -> MinMaxDam 10
    { 0x56EA8CAB, 0xE07A43CB },    // 1xx_MinMaxDam 10 Fast -> MinMaxDam 10 Fast
    { 0x224EB205, 0x27EDDD25 },    // 1xx_MinMaxDam 10 Secondary -> MinMaxDam 10 Secondary
    { 0xCD536C88, 0x86D7FBA8 },    // 1xx_MinMaxDam 10 Two-Handed -> MinMaxDam 10 Two-Handed
    { 0x84CC6FDE, 0x6AC532FE },    // 1xx_MinMaxDam 11 -> MinMaxDam 11
    { 0x593FB54C, 0xE2CF6C6C },    // 1xx_MinMaxDam 11 Fast -> MinMaxDam 11 Fast
    { 0xA7AB6746, 0xAD4A9266 },    // 1xx_MinMaxDam 11 Secondary -> MinMaxDam 11 Secondary
    { 0xFE46C9E9, 0xB7CB5909 },    // 1xx_MinMaxDam 11 Two-Handed -> MinMaxDam 11 Two-Handed
    { 0x84CC6FDF, 0x6AC532FF },    // 1xx_MinMaxDam 12 -> MinMaxDam 12
    { 0x5B94DDED, 0xE524950D },    // 1xx_MinMaxDam 12 Fast -> MinMaxDam 12 Fast
    { 0x2D081C87, 0x32A747A7 },    // 1xx_MinMaxDam 12 Secondary -> MinMaxDam 12 Secondary
    { 0x2F3A274A, 0xE8BEB66A },    // 1xx_MinMaxDam 12 Two-Handed -> MinMaxDam 12 Two-Handed
    { 0x84CC6FE0, 0x6AC53300 },    // 1xx_MinMaxDam 13 -> MinMaxDam 13
    { 0x5DEA068E, 0xE779BDAE },    // 1xx_MinMaxDam 13 Fast -> MinMaxDam 13 Fast
    { 0xB264D1C8, 0xB803FCE8 },    // 1xx_MinMaxDam 13 Secondary -> MinMaxDam 13 Secondary
    { 0x602D84AB, 0x19B213CB },    // 1xx_MinMaxDam 13 Two-Handed -> MinMaxDam 13 Two-Handed
    { 0x84CC6FE1, 0x6AC53301 },    // 1xx_MinMaxDam 14 -> MinMaxDam 14
    { 0x603F2F2F, 0xE9CEE64F },    // 1xx_MinMaxDam 14 Fast -> MinMaxDam 14 Fast
    { 0x37C18709, 0x3D60B229 },    // 1xx_MinMaxDam 14 Secondary -> MinMaxDam 14 Secondary
    { 0x9120E20C, 0x4AA5712C },    // 1xx_MinMaxDam 14 Two-Handed -> MinMaxDam 14 Two-Handed
    { 0x84CC6FE2, 0x6AC53301 },    // 1xx_MinMaxDam 15 -> MinMaxDam 14
    { 0x629457D0, 0xE9CEE64F },    // 1xx_MinMaxDam 15 Fast -> MinMaxDam 14 Fast
    { 0xBD1E3C4A, 0x3D60B229 },    // 1xx_MinMaxDam 15 Secondary -> MinMaxDam 14 Secondary
    { 0xC2143F6D, 0x4AA5712C },    // 1xx_MinMaxDam 15 Two-Handed -> MinMaxDam 14 Two-Handed
    { 0x84CC6FE3, 0x6AC53301 },    // 1xx_MinMaxDam 16 -> MinMaxDam 14
    { 0x64E98071, 0xE9CEE64F },    // 1xx_MinMaxDam 16 Fast -> MinMaxDam 14 Fast
    { 0x427AF18B, 0x3D60B229 },    // 1xx_MinMaxDam 16 Secondary -> MinMaxDam 14 Secondary
    { 0xF3079CCE, 0x4AA5712C },    // 1xx_MinMaxDam 16 Two-Handed -> MinMaxDam 14 Two-Handed
    { 0xC5F6AE0E, 0x60538D2E },    // 1xx_MinMaxDam 2 -> MinMaxDam 2
    { 0xF478517C, 0xE15DA49C },    // 1xx_MinMaxDam 2 Fast -> MinMaxDam 2 Fast
    { 0x5A9D2176, 0x05736896 },    // 1xx_MinMaxDam 2 Secondary -> MinMaxDam 2 Secondary
    { 0x0F6FCA19, 0x150EF539 },    // 1xx_MinMaxDam 2 Two-Handed -> MinMaxDam 2 Two-Handed
    { 0xC5F6AE0F, 0x60538D2F },    // 1xx_MinMaxDam 3 -> MinMaxDam 3
    { 0xF6CD7A1D, 0xE3B2CD3D },    // 1xx_MinMaxDam 3 Fast -> MinMaxDam 3 Fast
    { 0xDFF9D6B7, 0x8AD01DD7 },    // 1xx_MinMaxDam 3 Secondary -> MinMaxDam 3 Secondary
    { 0x4063277A, 0x4602529A },    // 1xx_MinMaxDam 3 Two-Handed -> MinMaxDam 3 Two-Handed
    { 0xC5F6AE10, 0x60538D30 },    // 1xx_MinMaxDam 4 -> MinMaxDam 4
    { 0xF922A2BE, 0xE607F5DE },    // 1xx_MinMaxDam 4 Fast -> MinMaxDam 4 Fast
    { 0x65568BF8, 0x102CD318 },    // 1xx_MinMaxDam 4 Secondary -> MinMaxDam 4 Secondary
    { 0x715684DB, 0x76F5AFFB },    // 1xx_MinMaxDam 4 Two-Handed -> MinMaxDam 4 Two-Handed
    { 0xC5F6AE11, 0x60538D31 },    // 1xx_MinMaxDam 5 -> MinMaxDam 5
    { 0xFB77CB5F, 0xE85D1E7F },    // 1xx_MinMaxDam 5 Fast -> MinMaxDam 5 Fast
    { 0xEAB34139, 0x95898859 },    // 1xx_MinMaxDam 5 Secondary -> MinMaxDam 5 Secondary
    { 0xA249E23C, 0xA7E90D5C },    // 1xx_MinMaxDam 5 Two-Handed -> MinMaxDam 5 Two-Handed
    { 0xC5F6AE12, 0x60538D32 },    // 1xx_MinMaxDam 6 -> MinMaxDam 6
    { 0xFDCCF400, 0xEAB24720 },    // 1xx_MinMaxDam 6 Fast -> MinMaxDam 6 Fast
    { 0x700FF67A, 0x1AE63D9A },    // 1xx_MinMaxDam 6 Secondary -> MinMaxDam 6 Secondary
    { 0xD33D3F9D, 0xD8DC6ABD },    // 1xx_MinMaxDam 6 Two-Handed -> MinMaxDam 6 Two-Handed
    { 0xC5F6AE13, 0x60538D33 },    // 1xx_MinMaxDam 7 -> MinMaxDam 7
    { 0x00221CA1, 0xED076FC1 },    // 1xx_MinMaxDam 7 Fast -> MinMaxDam 7 Fast
    { 0xF56CABBB, 0xA042F2DB },    // 1xx_MinMaxDam 7 Secondary -> MinMaxDam 7 Secondary
    { 0x04309CFE, 0x09CFC81E },    // 1xx_MinMaxDam 7 Two-Handed -> MinMaxDam 7 Two-Handed
    { 0xC5F6AE14, 0x60538D34 },    // 1xx_MinMaxDam 8 -> MinMaxDam 8
    { 0x02774542, 0xEF5C9862 },    // 1xx_MinMaxDam 8 Fast -> MinMaxDam 8 Fast
    { 0x7AC960FC, 0x259FA81C },    // 1xx_MinMaxDam 8 Secondary -> MinMaxDam 8 Secondary
    { 0x3523FA5F, 0x3AC3257F },    // 1xx_MinMaxDam 8 Two-Handed -> MinMaxDam 8 Two-Handed
    { 0xC5F6AE15, 0x60538D35 },    // 1xx_MinMaxDam 9 -> MinMaxDam 9
    { 0x04CC6DE3, 0xF1B1C103 },    // 1xx_MinMaxDam 9 Fast -> MinMaxDam 9 Fast
    { 0x0026163D, 0xAAFC5D5D },    // 1xx_MinMaxDam 9 Secondary -> MinMaxDam 9 Secondary
    { 0x661757C0, 0x6BB682E0 },    // 1xx_MinMaxDam 9 Two-Handed -> MinMaxDam 9 Two-Handed
    { 0x2637C481, 0x4E92C7A1 },    // 1xx_PhysicalResist 0.1 Legendary -> PhysicalResist 0.1 Legendary
    { 0xAB9479C2, 0xD3EF7CE2 },    // 1xx_PhysicalResist 0.2 Legendary -> PhysicalResist 0.2 Legendary
    { 0x30F12F03, 0x594C3223 },    // 1xx_PhysicalResist 0.3 Legendary -> PhysicalResist 0.3 Legendary
    { 0x639179C0, 0x5076CCE0 },    // 1xx_PhysicalResist I -> PhysicalResist I
    { 0xD5C0B229, 0x5F506949 },    // 1xx_PhysicalResist II -> PhysicalResist II
    { 0x8DD6F7B2, 0x495D92D2 },    // 1xx_PhysicalResist III -> PhysicalResist III
    { 0xD5C0B236, 0x5F506956 },    // 1xx_PhysicalResist IV -> PhysicalResist IV
    { 0xD5C0B238, 0x5F506958 },    // 1xx_PhysicalResist IX -> PhysicalResist IX
    { 0x639179CD, 0x5076CCED },    // 1xx_PhysicalResist V -> PhysicalResist V
    { 0xD5C0B3D6, 0x5F506AF6 },    // 1xx_PhysicalResist VI -> PhysicalResist VI
    { 0x8DD72EFF, 0x495DCA1F },    // 1xx_PhysicalResist VII -> PhysicalResist VII
    { 0x48BD0F48, 0x75170E68 },    // 1xx_PhysicalResist VIII -> PhysicalResist VIII
    { 0x639179CF, 0x5076CCEF },    // 1xx_PhysicalResist X -> PhysicalResist X
    { 0x349CF1AD, 0x0DF788CD },    // 1xx_PoisonD 1 -> PoisonD 1
    { 0x3764B07B, 0x7E9ABB9B },    // 1xx_PoisonD 1 Fast -> PoisonD 1 Fast
    { 0x62ED2C58, 0x1A870F78 },    // 1xx_PoisonD 1 Two-Handed -> PoisonD 1 Two-Handed
    { 0xC83B277D, 0xCCE8A29D },    // 1xx_PoisonD 10 -> PoisonD 10
    { 0x445D084B, 0x7254776B },    // 1xx_PoisonD 10 Fast -> PoisonD 10 Fast
    { 0xDFDC2028, 0x8AB26748 },    // 1xx_PoisonD 10 Two-Handed -> PoisonD 10 Two-Handed
    { 0xC83B277E, 0xCCE8A29E },    // 1xx_PoisonD 11 -> PoisonD 11
    { 0x46B230EC, 0x74A9A00C },    // 1xx_PoisonD 11 Fast -> PoisonD 11 Fast
    { 0x10CF7D89, 0xBBA5C4A9 },    // 1xx_PoisonD 11 Two-Handed -> PoisonD 11 Two-Handed
    { 0xC83B277F, 0xCCE8A29F },    // 1xx_PoisonD 12 -> PoisonD 12
    { 0x4907598D, 0x76FEC8AD },    // 1xx_PoisonD 12 Fast -> PoisonD 12 Fast
    { 0x41C2DAEA, 0xEC99220A },    // 1xx_PoisonD 12 Two-Handed -> PoisonD 12 Two-Handed
    { 0xC83B2780, 0xCCE8A2A0 },    // 1xx_PoisonD 13 -> PoisonD 13
    { 0x4B5C822E, 0x7953F14E },    // 1xx_PoisonD 13 Fast -> PoisonD 13 Fast
    { 0x72B6384B, 0x1D8C7F6B },    // 1xx_PoisonD 13 Two-Handed -> PoisonD 13 Two-Handed
    { 0xC83B2781, 0xCCE8A2A1 },    // 1xx_PoisonD 14 -> PoisonD 14
    { 0x4DB1AACF, 0x7BA919EF },    // 1xx_PoisonD 14 Fast -> PoisonD 14 Fast
    { 0xA3A995AC, 0x4E7FDCCC },    // 1xx_PoisonD 14 Two-Handed -> PoisonD 14 Two-Handed
    { 0xC83B2782, 0xCCE8A2A1 },    // 1xx_PoisonD 15 -> PoisonD 14
    { 0x5006D370, 0x7BA919EF },    // 1xx_PoisonD 15 Fast -> PoisonD 14 Fast
    { 0xD49CF30D, 0x4E7FDCCC },    // 1xx_PoisonD 15 Two-Handed -> PoisonD 14 Two-Handed
    { 0xC83B2783, 0xCCE8A2A1 },    // 1xx_PoisonD 16 -> PoisonD 14
    { 0x525BFC11, 0x7BA919EF },    // 1xx_PoisonD 16 Fast -> PoisonD 14 Fast
    { 0x0590506E, 0x4E7FDCCC },    // 1xx_PoisonD 16 Two-Handed -> PoisonD 14 Two-Handed
    { 0x349CF1AE, 0x0DF788CE },    // 1xx_PoisonD 2 -> PoisonD 2
    { 0x39B9D91C, 0x80EFE43C },    // 1xx_PoisonD 2 Fast -> PoisonD 2 Fast
    { 0x93E089B9, 0x4B7A6CD9 },    // 1xx_PoisonD 2 Two-Handed -> PoisonD 2 Two-Handed
    { 0x349CF1AF, 0x0DF788CF },    // 1xx_PoisonD 3 -> PoisonD 3
    { 0x3C0F01BD, 0x83450CDD },    // 1xx_PoisonD 3 Fast -> PoisonD 3 Fast
    { 0xC4D3E71A, 0x7C6DCA3A },    // 1xx_PoisonD 3 Two-Handed -> PoisonD 3 Two-Handed
    { 0x349CF1B0, 0x0DF788D0 },    // 1xx_PoisonD 4 -> PoisonD 4
    { 0x3E642A5E, 0x859A357E },    // 1xx_PoisonD 4 Fast -> PoisonD 4 Fast
    { 0xF5C7447B, 0xAD61279B },    // 1xx_PoisonD 4 Two-Handed -> PoisonD 4 Two-Handed
    { 0x349CF1B1, 0x0DF788D1 },    // 1xx_PoisonD 5 -> PoisonD 5
    { 0x40B952FF, 0x87EF5E1F },    // 1xx_PoisonD 5 Fast -> PoisonD 5 Fast
    { 0x26BAA1DC, 0xDE5484FC },    // 1xx_PoisonD 5 Two-Handed -> PoisonD 5 Two-Handed
    { 0x349CF1B2, 0x0DF788D2 },    // 1xx_PoisonD 6 -> PoisonD 6
    { 0x430E7BA0, 0x8A4486C0 },    // 1xx_PoisonD 6 Fast -> PoisonD 6 Fast
    { 0x57ADFF3D, 0x0F47E25D },    // 1xx_PoisonD 6 Two-Handed -> PoisonD 6 Two-Handed
    { 0x349CF1B3, 0x0DF788D3 },    // 1xx_PoisonD 7 -> PoisonD 7
    { 0x4563A441, 0x8C99AF61 },    // 1xx_PoisonD 7 Fast -> PoisonD 7 Fast
    { 0x88A15C9E, 0x403B3FBE },    // 1xx_PoisonD 7 Two-Handed -> PoisonD 7 Two-Handed
    { 0x349CF1B4, 0x0DF788D4 },    // 1xx_PoisonD 8 -> PoisonD 8
    { 0x47B8CCE2, 0x8EEED802 },    // 1xx_PoisonD 8 Fast -> PoisonD 8 Fast
    { 0xB994B9FF, 0x712E9D1F },    // 1xx_PoisonD 8 Two-Handed -> PoisonD 8 Two-Handed
    { 0x349CF1B5, 0x0DF788D5 },    // 1xx_PoisonD 9 -> PoisonD 9
    { 0x4A0DF583, 0x914400A3 },    // 1xx_PoisonD 9 Fast -> PoisonD 9 Fast
    { 0xEA881760, 0xA221FA80 },    // 1xx_PoisonD 9 Two-Handed -> PoisonD 9 Two-Handed
    { 0x89E83D5C, 0x5367F87C },    // 1xx_PoisonResist 0.1 Legendary -> PoisonResist 0.1 Legendary
    { 0x0F44F29D, 0xD8C4ADBD },    // 1xx_PoisonResist 0.2 Legendary -> PoisonResist 0.2 Legendary
    { 0x94A1A7DE, 0x5E2162FE },    // 1xx_PoisonResist 0.3 Legendary -> PoisonResist 0.3 Legendary
    { 0x8195921B, 0xC8CB9D3B },    // 1xx_PoisonResist I -> PoisonResist I
    { 0xB447D5E4, 0xE23F4504 },    // 1xx_PoisonResist II -> PoisonResist II
    { 0x3D4292CD, 0x2A27E5ED },    // 1xx_PoisonResist III -> PoisonResist III
    { 0xB447D5F1, 0xE23F4511 },    // 1xx_PoisonResist IV -> PoisonResist IV
    { 0xB447D5F3, 0xE23F4513 },    // 1xx_PoisonResist IX -> PoisonResist IX
    { 0x81959228, 0xC8CB9D48 },    // 1xx_PoisonResist V -> PoisonResist V
    { 0xB447D791, 0xE23F46B1 },    // 1xx_PoisonResist VI -> PoisonResist VI
    { 0x3D42CA1A, 0x2A281D3A },    // 1xx_PoisonResist VII -> PoisonResist VII
    { 0xE59C0DC3, 0x6F2BC4E3 },    // 1xx_PoisonResist VIII -> PoisonResist VIII
    { 0x8195922A, 0xC8CB9D4A },    // 1xx_PoisonResist X -> PoisonResist X
    { 0x29D32D24, 0x403AC044 },    // 1xx_PrimaryAttribute_Dex 1 Legendary -> PrimaryAttribute_Dex 1 Legendary
    { 0xD072800F, 0x9583DF2F },    // 1xx_PrimaryAttribute_Dex 1 Two-Handed Legendary -> PrimaryAttribute_Dex 1 Two-Handed Legendary
    { 0x6370DA74, 0x46CAD194 },    // 1xx_PrimaryAttribute_Dex 10 Legendary -> PrimaryAttribute_Dex 10 Legendary
    { 0x70173B5F, 0xD7547E7F },    // 1xx_PrimaryAttribute_Dex 10 Two-Handed Legendary -> PrimaryAttribute_Dex 10 Two-Handed Legendary
    { 0xE8CD8FB5, 0xCC2786D5 },    // 1xx_PrimaryAttribute_Dex 11 Legendary -> PrimaryAttribute_Dex 11 Legendary
    { 0xE2C38600, 0x4A00C920 },    // 1xx_PrimaryAttribute_Dex 11 Two-Handed Legendary -> PrimaryAttribute_Dex 11 Two-Handed Legendary
    { 0x6E2A44F6, 0x51843C16 },    // 1xx_PrimaryAttribute_Dex 12 Legendary -> PrimaryAttribute_Dex 12 Legendary
    { 0x556FD0A1, 0xBCAD13C1 },    // 1xx_PrimaryAttribute_Dex 12 Two-Handed Legendary -> PrimaryAttribute_Dex 12 Two-Handed Legendary
    { 0xF386FA37, 0xD6E0F157 },    // 1xx_PrimaryAttribute_Dex 13 Legendary -> PrimaryAttribute_Dex 13 Legendary
    { 0xC81C1B42, 0x2F595E62 },    // 1xx_PrimaryAttribute_Dex 13 Two-Handed Legendary -> PrimaryAttribute_Dex 13 Two-Handed Legendary
    { 0x78E3AF78, 0x5C3DA698 },    // 1xx_PrimaryAttribute_Dex 14 Legendary -> PrimaryAttribute_Dex 14 Legendary
    { 0x3AC865E3, 0xA205A903 },    // 1xx_PrimaryAttribute_Dex 14 Two-Handed Legendary -> PrimaryAttribute_Dex 14 Two-Handed Legendary
    { 0xFE4064B9, 0xE19A5BD9 },    // 1xx_PrimaryAttribute_Dex 15 Legendary -> PrimaryAttribute_Dex 15 Legendary
    { 0xAD74B084, 0x14B1F3A4 },    // 1xx_PrimaryAttribute_Dex 15 Two-Handed Legendary -> PrimaryAttribute_Dex 15 Two-Handed Legendary
    { 0x839D19FA, 0x66F7111A },    // 1xx_PrimaryAttribute_Dex 16 Legendary -> PrimaryAttribute_Dex 16 Legendary
    { 0x2020FB25, 0x875E3E45 },    // 1xx_PrimaryAttribute_Dex 16 Two-Handed Legendary -> PrimaryAttribute_Dex 16 Two-Handed Legendary
    { 0x08F9CF3B, 0x66F7111A },    // 1xx_PrimaryAttribute_Dex 17 Legendary -> PrimaryAttribute_Dex 16 Legendary
    { 0x92CD45C6, 0x875E3E45 },    // 1xx_PrimaryAttribute_Dex 17 Two-Handed Legendary -> PrimaryAttribute_Dex 16 Two-Handed Legendary
    { 0xAF2FE265, 0xC5977585 },    // 1xx_PrimaryAttribute_Dex 2 Legendary -> PrimaryAttribute_Dex 2 Legendary
    { 0x431ECAB0, 0x083029D0 },    // 1xx_PrimaryAttribute_Dex 2 Two-Handed Legendary -> PrimaryAttribute_Dex 2 Two-Handed Legendary
    { 0x348C97A6, 0x4AF42AC6 },    // 1xx_PrimaryAttribute_Dex 3 Legendary -> PrimaryAttribute_Dex 3 Legendary
    { 0xB5CB1551, 0x7ADC7471 },    // 1xx_PrimaryAttribute_Dex 3 Two-Handed Legendary -> PrimaryAttribute_Dex 3 Two-Handed Legendary
    { 0xB9E94CE7, 0xD050E007 },    // 1xx_PrimaryAttribute_Dex 4 Legendary -> PrimaryAttribute_Dex 4 Legendary
    { 0x28775FF2, 0xED88BF12 },    // 1xx_PrimaryAttribute_Dex 4 Two-Handed Legendary -> PrimaryAttribute_Dex 4 Two-Handed Legendary
    { 0x3F460228, 0x55AD9548 },    // 1xx_PrimaryAttribute_Dex 5 Legendary -> PrimaryAttribute_Dex 5 Legendary
    { 0x9B23AA93, 0x603509B3 },    // 1xx_PrimaryAttribute_Dex 5 Two-Handed Legendary -> PrimaryAttribute_Dex 5 Two-Handed Legendary
    { 0xC4A2B769, 0xDB0A4A89 },    // 1xx_PrimaryAttribute_Dex 6 Legendary -> PrimaryAttribute_Dex 6 Legendary
    { 0x0DCFF534, 0xD2E15454 },    // 1xx_PrimaryAttribute_Dex 6 Two-Handed Legendary -> PrimaryAttribute_Dex 6 Two-Handed Legendary
    { 0x49FF6CAA, 0x6066FFCA },    // 1xx_PrimaryAttribute_Dex 7 Legendary -> PrimaryAttribute_Dex 7 Legendary
    { 0x807C3FD5, 0x458D9EF5 },    // 1xx_PrimaryAttribute_Dex 7 Two-Handed Legendary -> PrimaryAttribute_Dex 7 Two-Handed Legendary
    { 0xCF5C21EB, 0xE5C3B50B },    // 1xx_PrimaryAttribute_Dex 8 Legendary -> PrimaryAttribute_Dex 8 Legendary
    { 0xF3288A76, 0xB839E996 },    // 1xx_PrimaryAttribute_Dex 8 Two-Handed Legendary -> PrimaryAttribute_Dex 8 Two-Handed Legendary
    { 0x54B8D72C, 0x6B206A4C },    // 1xx_PrimaryAttribute_Dex 9 Legendary -> PrimaryAttribute_Dex 9 Legendary
    { 0x65D4D517, 0x2AE63437 },    // 1xx_PrimaryAttribute_Dex 9 Two-Handed Legendary -> PrimaryAttribute_Dex 9 Two-Handed Legendary
    { 0x31FE328E, 0x4865C5AE },    // 1xx_PrimaryAttribute_Int 1 Legendary -> PrimaryAttribute_Int 1 Legendary
    { 0x8D550F39, 0x52666E59 },    // 1xx_PrimaryAttribute_Int 1 Two-Handed Legendary -> PrimaryAttribute_Int 1 Two-Handed Legendary
    { 0x70FC8D1E, 0x5456843E },    // 1xx_PrimaryAttribute_Int 10 Legendary -> PrimaryAttribute_Int 10 Legendary
    { 0xC94BAFC9, 0x3088F2E9 },    // 1xx_PrimaryAttribute_Int 10 Two-Handed Legendary -> PrimaryAttribute_Int 10 Two-Handed Legendary
    { 0xF659425F, 0xD9B3397F },    // 1xx_PrimaryAttribute_Int 11 Legendary -> PrimaryAttribute_Int 11 Legendary
    { 0x3BF7FA6A, 0xA3353D8A },    // 1xx_PrimaryAttribute_Int 11 Two-Handed Legendary -> PrimaryAttribute_Int 11 Two-Handed Legendary
    { 0x7BB5F7A0, 0x5F0FEEC0 },    // 1xx_PrimaryAttribute_Int 12 Legendary -> PrimaryAttribute_Int 12 Legendary
    { 0xAEA4450B, 0x15E1882B },    // 1xx_PrimaryAttribute_Int 12 Two-Handed Legendary -> PrimaryAttribute_Int 12 Two-Handed Legendary
    { 0x0112ACE1, 0xE46CA401 },    // 1xx_PrimaryAttribute_Int 13 Legendary -> PrimaryAttribute_Int 13 Legendary
    { 0x21508FAC, 0x888DD2CC },    // 1xx_PrimaryAttribute_Int 13 Two-Handed Legendary -> PrimaryAttribute_Int 13 Two-Handed Legendary
    { 0x866F6222, 0x69C95942 },    // 1xx_PrimaryAttribute_Int 14 Legendary -> PrimaryAttribute_Int 14 Legendary
    { 0x93FCDA4D, 0xFB3A1D6D },    // 1xx_PrimaryAttribute_Int 14 Two-Handed Legendary -> PrimaryAttribute_Int 14 Two-Handed Legendary
    { 0x0BCC1763, 0xEF260E83 },    // 1xx_PrimaryAttribute_Int 15 Legendary -> PrimaryAttribute_Int 15 Legendary
    { 0x06A924EE, 0x6DE6680E },    // 1xx_PrimaryAttribute_Int 15 Two-Handed Legendary -> PrimaryAttribute_Int 15 Two-Handed Legendary
    { 0x9128CCA4, 0x7482C3C4 },    // 1xx_PrimaryAttribute_Int 16 Legendary -> PrimaryAttribute_Int 16 Legendary
    { 0x79556F8F, 0xE092B2AF },    // 1xx_PrimaryAttribute_Int 16 Two-Handed Legendary -> PrimaryAttribute_Int 16 Two-Handed Legendary
    { 0x168581E5, 0x7482C3C4 },    // 1xx_PrimaryAttribute_Int 17 Legendary -> PrimaryAttribute_Int 16 Legendary
    { 0xEC01BA30, 0xE092B2AF },    // 1xx_PrimaryAttribute_Int 17 Two-Handed Legendary -> PrimaryAttribute_Int 16 Two-Handed Legendary
    { 0xB75AE7CF, 0xCDC27AEF },    // 1xx_PrimaryAttribute_Int 2 Legendary -> PrimaryAttribute_Int 2 Legendary
    { 0x000159DA, 0xC512B8FA },    // 1xx_PrimaryAttribute_Int 2 Two-Handed Legendary -> PrimaryAttribute_Int 2 Two-Handed Legendary
    { 0x3CB79D10, 0x531F3030 },    // 1xx_PrimaryAttribute_Int 3 Legendary -> PrimaryAttribute_Int 3 Legendary
    { 0x72ADA47B, 0x37BF039B },    // 1xx_PrimaryAttribute_Int 3 Two-Handed Legendary -> PrimaryAttribute_Int 3 Two-Handed Legendary
    { 0xC2145251, 0xD87BE571 },    // 1xx_PrimaryAttribute_Int 4 Legendary -> PrimaryAttribute_Int 4 Legendary
    { 0xE559EF1C, 0xAA6B4E3C },    // 1xx_PrimaryAttribute_Int 4 Two-Handed Legendary -> PrimaryAttribute_Int 4 Two-Handed Legendary
    { 0x47710792, 0x5DD89AB2 },    // 1xx_PrimaryAttribute_Int 5 Legendary -> PrimaryAttribute_Int 5 Legendary
    { 0x580639BD, 0x1D1798DD },    // 1xx_PrimaryAttribute_Int 5 Two-Handed Legendary -> PrimaryAttribute_Int 5 Two-Handed Legendary
    { 0xCCCDBCD3, 0xE3354FF3 },    // 1xx_PrimaryAttribute_Int 6 Legendary -> PrimaryAttribute_Int 6 Legendary
    { 0xCAB2845E, 0x8FC3E37E },    // 1xx_PrimaryAttribute_Int 6 Two-Handed Legendary -> PrimaryAttribute_Int 6 Two-Handed Legendary
    { 0x522A7214, 0x68920534 },    // 1xx_PrimaryAttribute_Int 7 Legendary -> PrimaryAttribute_Int 7 Legendary
    { 0x3D5ECEFF, 0x02702E1F },    // 1xx_PrimaryAttribute_Int 7 Two-Handed Legendary -> PrimaryAttribute_Int 7 Two-Handed Legendary
    { 0xD7872755, 0xEDEEBA75 },    // 1xx_PrimaryAttribute_Int 8 Legendary -> PrimaryAttribute_Int 8 Legendary
    { 0xB00B19A0, 0x751C78C0 },    // 1xx_PrimaryAttribute_Int 8 Two-Handed Legendary -> PrimaryAttribute_Int 8 Two-Handed Legendary
    { 0x5CE3DC96, 0x734B6FB6 },    // 1xx_PrimaryAttribute_Int 9 Legendary -> PrimaryAttribute_Int 9 Legendary
    { 0x22B76441, 0xE7C8C361 },    // 1xx_PrimaryAttribute_Int 9 Two-Handed Legendary -> PrimaryAttribute_Int 9 Two-Handed Legendary
    { 0x578BC2DC, 0x6DF355FC },    // 1xx_PrimaryAttribute_Str 1 Legendary -> PrimaryAttribute_Str 1 Legendary
    { 0xCF6F12C7, 0x948071E7 },    // 1xx_PrimaryAttribute_Str 1 Two-Handed Legendary -> PrimaryAttribute_Str 1 Two-Handed Legendary
    { 0x483C272C, 0x2B961E4C },    // 1xx_PrimaryAttribute_Str 10 Legendary -> PrimaryAttribute_Str 10 Legendary
    { 0x4EA62517, 0xB5E36837 },    // 1xx_PrimaryAttribute_Str 10 Two-Handed Legendary -> PrimaryAttribute_Str 10 Two-Handed Legendary
    { 0xCD98DC6D, 0xB0F2D38D },    // 1xx_PrimaryAttribute_Str 11 Legendary -> PrimaryAttribute_Str 11 Legendary
    { 0xC1526FB8, 0x288FB2D8 },    // 1xx_PrimaryAttribute_Str 11 Two-Handed Legendary -> PrimaryAttribute_Str 11 Two-Handed Legendary
    { 0x52F591AE, 0x364F88CE },    // 1xx_PrimaryAttribute_Str 12 Legendary -> PrimaryAttribute_Str 12 Legendary
    { 0x33FEBA59, 0x9B3BFD79 },    // 1xx_PrimaryAttribute_Str 12 Two-Handed Legendary -> PrimaryAttribute_Str 12 Two-Handed Legendary
    { 0xD85246EF, 0xBBAC3E0F },    // 1xx_PrimaryAttribute_Str 13 Legendary -> PrimaryAttribute_Str 13 Legendary
    { 0xA6AB04FA, 0x0DE8481A },    // 1xx_PrimaryAttribute_Str 13 Two-Handed Legendary -> PrimaryAttribute_Str 13 Two-Handed Legendary
    { 0x5DAEFC30, 0x4108F350 },    // 1xx_PrimaryAttribute_Str 14 Legendary -> PrimaryAttribute_Str 14 Legendary
    { 0x19574F9B, 0x809492BB },    // 1xx_PrimaryAttribute_Str 14 Two-Handed Legendary -> PrimaryAttribute_Str 14 Two-Handed Legendary
    { 0xE30BB171, 0xC665A891 },    // 1xx_PrimaryAttribute_Str 15 Legendary -> PrimaryAttribute_Str 15 Legendary
    { 0x8C039A3C, 0xF340DD5C },    // 1xx_PrimaryAttribute_Str 15 Two-Handed Legendary -> PrimaryAttribute_Str 15 Two-Handed Legendary
    { 0x686866B2, 0x4BC25DD2 },    // 1xx_PrimaryAttribute_Str 16 Legendary -> PrimaryAttribute_Str 16 Legendary
    { 0xFEAFE4DD, 0x65ED27FD },    // 1xx_PrimaryAttribute_Str 16 Two-Handed Legendary -> PrimaryAttribute_Str 16 Two-Handed Legendary
    { 0xEDC51BF3, 0x4BC25DD2 },    // 1xx_PrimaryAttribute_Str 17 Legendary -> PrimaryAttribute_Str 16 Legendary
    { 0x715C2F7E, 0x65ED27FD },    // 1xx_PrimaryAttribute_Str 17 Two-Handed Legendary -> PrimaryAttribute_Str 16 Two-Handed Legendary
    { 0xDCE8781D, 0xF3500B3D },    // 1xx_PrimaryAttribute_Str 2 Legendary -> PrimaryAttribute_Str 2 Legendary
    { 0x421B5D68, 0x072CBC88 },    // 1xx_PrimaryAttribute_Str 2 Two-Handed Legendary -> PrimaryAttribute_Str 2 Two-Handed Legendary
    { 0x62452D5E, 0x78ACC07E },    // 1xx_PrimaryAttribute_Str 3 Legendary -> PrimaryAttribute_Str 3 Legendary
    { 0xB4C7A809, 0x79D90729 },    // 1xx_PrimaryAttribute_Str 3 Two-Handed Legendary -> PrimaryAttribute_Str 3 Two-Handed Legendary
    { 0xE7A1E29F, 0xFE0975BF },    // 1xx_PrimaryAttribute_Str 4 Legendary -> PrimaryAttribute_Str 4 Legendary
    { 0x2773F2AA, 0xEC8551CA },    // 1xx_PrimaryAttribute_Str 4 Two-Handed Legendary -> PrimaryAttribute_Str 4 Two-Handed Legendary
    { 0x6CFE97E0, 0x83662B00 },    // 1xx_PrimaryAttribute_Str 5 Legendary -> PrimaryAttribute_Str 5 Legendary
    { 0x9A203D4B, 0x5F319C6B },    // 1xx_PrimaryAttribute_Str 5 Two-Handed Legendary -> PrimaryAttribute_Str 5 Two-Handed Legendary
    { 0xF25B4D21, 0x08C2E041 },    // 1xx_PrimaryAttribute_Str 6 Legendary -> PrimaryAttribute_Str 6 Legendary
    { 0x0CCC87EC, 0xD1DDE70C },    // 1xx_PrimaryAttribute_Str 6 Two-Handed Legendary -> PrimaryAttribute_Str 6 Two-Handed Legendary
    { 0x77B80262, 0x8E1F9582 },    // 1xx_PrimaryAttribute_Str 7 Legendary -> PrimaryAttribute_Str 7 Legendary
    { 0x7F78D28D, 0x448A31AD },    // 1xx_PrimaryAttribute_Str 7 Two-Handed Legendary -> PrimaryAttribute_Str 7 Two-Handed Legendary
    { 0xFD14B7A3, 0x137C4AC3 },    // 1xx_PrimaryAttribute_Str 8 Legendary -> PrimaryAttribute_Str 8 Legendary
    { 0xF2251D2E, 0xB7367C4E },    // 1xx_PrimaryAttribute_Str 8 Two-Handed Legendary -> PrimaryAttribute_Str 8 Two-Handed Legendary
    { 0x82716CE4, 0x98D90004 },    // 1xx_PrimaryAttribute_Str 9 Legendary -> PrimaryAttribute_Str 9 Legendary
    { 0x64D167CF, 0x29E2C6EF },    // 1xx_PrimaryAttribute_Str 9 Two-Handed Legendary -> PrimaryAttribute_Str 9 Two-Handed Legendary
    { 0x545DA536, 0x6AC53856 },    // 1xx_PrimaryAttribute_Vit 1 Legendary -> PrimaryAttribute_Vit 1 Legendary
    { 0xDF4A54C6, 0xC2A44BE6 },    // 1xx_PrimaryAttribute_Vit 10 Legendary -> PrimaryAttribute_Vit 10 Legendary
    { 0x64A70A07, 0x48010127 },    // 1xx_PrimaryAttribute_Vit 11 Legendary -> PrimaryAttribute_Vit 11 Legendary
    { 0xEA03BF48, 0xCD5DB668 },    // 1xx_PrimaryAttribute_Vit 12 Legendary -> PrimaryAttribute_Vit 12 Legendary
    { 0x6F607489, 0x52BA6BA9 },    // 1xx_PrimaryAttribute_Vit 13 Legendary -> PrimaryAttribute_Vit 13 Legendary
    { 0xF4BD29CA, 0xD81720EA },    // 1xx_PrimaryAttribute_Vit 14 Legendary -> PrimaryAttribute_Vit 14 Legendary
    { 0x7A19DF0B, 0x5D73D62B },    // 1xx_PrimaryAttribute_Vit 15 Legendary -> PrimaryAttribute_Vit 15 Legendary
    { 0xFF76944C, 0xE2D08B6C },    // 1xx_PrimaryAttribute_Vit 16 Legendary -> PrimaryAttribute_Vit 16 Legendary
    { 0x84D3498D, 0xE2D08B6C },    // 1xx_PrimaryAttribute_Vit 17 Legendary -> PrimaryAttribute_Vit 16 Legendary
    { 0xD9BA5A77, 0xF021ED97 },    // 1xx_PrimaryAttribute_Vit 2 Legendary -> PrimaryAttribute_Vit 2 Legendary
    { 0x5F170FB8, 0x757EA2D8 },    // 1xx_PrimaryAttribute_Vit 3 Legendary -> PrimaryAttribute_Vit 3 Legendary
    { 0xE473C4F9, 0xFADB5819 },    // 1xx_PrimaryAttribute_Vit 4 Legendary -> PrimaryAttribute_Vit 4 Legendary
    { 0x69D07A3A, 0x80380D5A },    // 1xx_PrimaryAttribute_Vit 5 Legendary -> PrimaryAttribute_Vit 5 Legendary
    { 0xEF2D2F7B, 0x0594C29B },    // 1xx_PrimaryAttribute_Vit 6 Legendary -> PrimaryAttribute_Vit 6 Legendary
    { 0x7489E4BC, 0x8AF177DC },    // 1xx_PrimaryAttribute_Vit 7 Legendary -> PrimaryAttribute_Vit 7 Legendary
    { 0xF9E699FD, 0x104E2D1D },    // 1xx_PrimaryAttribute_Vit 8 Legendary -> PrimaryAttribute_Vit 8 Legendary
    { 0x7F434F3E, 0x95AAE25E },    // 1xx_PrimaryAttribute_Vit 9 Legendary -> PrimaryAttribute_Vit 9 Legendary
    { 0xFE95F4CB, 0x32515BEB },    // 1xx_ProcPower_BloodMagicBladeOnly -> ProcPower_BloodMagicBladeOnly
    { 0xCAD650E3, 0x845AE003 },    // 1xx_ProcPower_CataclysmOnly -> ProcPower_CataclysmOnly
    { 0x9C591751, 0x65D8D271 },    // 1xx_ProcPower_EarthShatterOnly -> ProcPower_EarthShatterOnly
    { 0x174B64EF, 0xD0CFF40F },    // 1xx_ProcPower_FireBrandOnly -> ProcPower_FireBrandOnly
    { 0xBF65543D, 0x88E50F5D },    // 1xx_ProcPower_HellFireRingOnly -> ProcPower_HellFireRingOnly
    { 0x0367A82B, 0xED7E1B4B },    // 1xx_ProcPower_WallOfBoneOnly -> ProcPower_WallOfBoneOnly
    { 0xC2A59F98, 0xAF8AF2B8 },    // 1xx_RecognizedPrefix -> RecognizedPrefix
    { 0xC9DBEF5F, 0xB6C1427F },    // 1xx_RecognizedSuffix -> RecognizedSuffix
    { 0xECFEDCC2, 0x3A892BE2 },    // 1xx_Regen 1 -> Regen 1
    { 0x5966412A, 0xE2F5F84A },    // 1xx_Regen 1 Secondary -> Regen 1 Secondary
    { 0x8CDA7532, 0x8BAEA852 },    // 1xx_Regen 10 -> Regen 10
    { 0x2B2F259A, 0xE6B5C0BA },    // 1xx_Regen 10 Secondary -> Regen 10 Secondary
    { 0x8CDA7533, 0x8BAEA853 },    // 1xx_Regen 11 -> Regen 11
    { 0xB08BDADB, 0x6C1275FB },    // 1xx_Regen 11 Secondary -> Regen 11 Secondary
    { 0x8CDA7534, 0x8BAEA854 },    // 1xx_Regen 12 -> Regen 12
    { 0x35E8901C, 0xF16F2B3C },    // 1xx_Regen 12 Secondary -> Regen 12 Secondary
    { 0x8CDA7535, 0x8BAEA855 },    // 1xx_Regen 13 -> Regen 13
    { 0xBB45455D, 0x76CBE07D },    // 1xx_Regen 13 Secondary -> Regen 13 Secondary
    { 0x8CDA7536, 0x8BAEA856 },    // 1xx_Regen 14 -> Regen 14
    { 0x40A1FA9E, 0xFC2895BE },    // 1xx_Regen 14 Secondary -> Regen 14 Secondary
    { 0x8CDA7537, 0x8BAEA857 },    // 1xx_Regen 15 -> Regen 15
    { 0xC5FEAFDF, 0x81854AFF },    // 1xx_Regen 15 Secondary -> Regen 15 Secondary
    { 0x8CDA7538, 0x8BAEA858 },    // 1xx_Regen 16 -> Regen 16
    { 0x4B5B6520, 0x06E20040 },    // 1xx_Regen 16 Secondary -> Regen 16 Secondary
    { 0x8CDA7539, 0x8BAEA859 },    // 1xx_Regen 17 -> Regen 17
    { 0xD0B81A61, 0x8C3EB581 },    // 1xx_Regen 17 Secondary -> Regen 17 Secondary
    { 0x8CDA753A, 0x8BAEA85A },    // 1xx_Regen 18 -> Regen 18
    { 0x5614CFA2, 0x119B6AC2 },    // 1xx_Regen 18 Secondary -> Regen 18 Secondary
    { 0x8CDA753B, 0x8BAEA85A },    // 1xx_Regen 19 -> Regen 18
    { 0xDB7184E3, 0x119B6AC2 },    // 1xx_Regen 19 Secondary -> Regen 18 Secondary
    { 0xECFEDCC3, 0x3A892BE3 },    // 1xx_Regen 2 -> Regen 2
    { 0xDEC2F66B, 0x6852AD8B },    // 1xx_Regen 2 Secondary -> Regen 2 Secondary
    { 0x8CDA7553, 0x8BAEA85A },    // 1xx_Regen 20 -> Regen 18
    { 0x5C2282FB, 0x119B6AC2 },    // 1xx_Regen 20 Secondary -> Regen 18 Secondary
    { 0xECFEDCC4, 0x3A892BE4 },    // 1xx_Regen 3 -> Regen 3
    { 0x641FABAC, 0xEDAF62CC },    // 1xx_Regen 3 Secondary -> Regen 3 Secondary
    { 0xECFEDCC5, 0x3A892BE5 },    // 1xx_Regen 4 -> Regen 4
    { 0xE97C60ED, 0x730C180D },    // 1xx_Regen 4 Secondary -> Regen 4 Secondary
    { 0xECFEDCC6, 0x3A892BE6 },    // 1xx_Regen 5 -> Regen 5
    { 0x6ED9162E, 0xF868CD4E },    // 1xx_Regen 5 Secondary -> Regen 5 Secondary
    { 0xECFEDCC7, 0x3A892BE7 },    // 1xx_Regen 6 -> Regen 6
    { 0xF435CB6F, 0x7DC5828F },    // 1xx_Regen 6 Secondary -> Regen 6 Secondary
    { 0xECFEDCC8, 0x3A892BE8 },    // 1xx_Regen 7 -> Regen 7
    { 0x799280B0, 0x032237D0 },    // 1xx_Regen 7 Secondary -> Regen 7 Secondary
    { 0xECFEDCC9, 0x3A892BE9 },    // 1xx_Regen 8 -> Regen 8
    { 0xFEEF35F1, 0x887EED11 },    // 1xx_Regen 8 Secondary -> Regen 8 Secondary
    { 0xECFEDCCA, 0x3A892BEA },    // 1xx_Regen 9 -> Regen 9
    { 0x844BEB32, 0x0DDBA252 },    // 1xx_Regen 9 Secondary -> Regen 9 Secondary
    { 0x05DC2999, 0x084830B9 },    // 1xx_REQ 1 -> REQ 1
    { 0xC1615CED, 0x114E480D },    // 1xx_REQ 14 -> REQ 14
    { 0xC1615CEE, 0x114E480E },    // 1xx_REQ 15 -> REQ 15
    { 0xC1615CEF, 0x114E480F },    // 1xx_REQ 16 -> REQ 16
    { 0xC1615CF0, 0x114E4810 },    // 1xx_REQ 17 -> REQ 17
    { 0xC1615CF1, 0x114E4811 },    // 1xx_REQ 18 -> REQ 18
    { 0xC1615CF2, 0x114E4812 },    // 1xx_REQ 19 -> REQ 19
    { 0x05DC299A, 0x084830BA },    // 1xx_REQ 2 -> REQ 2
    { 0x05DC299B, 0x084830BB },    // 1xx_REQ 3 -> REQ 3
    { 0x05DC299C, 0x084830BC },    // 1xx_REQ 4 -> REQ 4
    { 0x05DC299D, 0x084830BD },    // 1xx_REQ 5 -> REQ 5
    { 0x05DC299E, 0x084830BE },    // 1xx_REQ 6 -> REQ 6
    { 0x05DC299F, 0x084830BF },    // 1xx_REQ 7 -> REQ 7
    { 0x05DC29A0, 0x084830C0 },    // 1xx_REQ 8 -> REQ 8
    { 0x05DC29A1, 0x084830C1 },    // 1xx_REQ 9 -> REQ 9
    { 0x36E037BD, 0xF064C6DD },    // 1xx_ResistAll 0.1 Legendary -> ResistAll 0.1 Legendary
    { 0xBC3CECFE, 0x75C17C1E },    // 1xx_ResistAll 0.2 Legendary -> ResistAll 0.2 Legendary
    { 0x4199A23F, 0xFB1E315F },    // 1xx_ResistAll 0.3 Legendary -> ResistAll 0.3 Legendary
    { 0x461632FC, 0xE073121C },    // 1xx_ResistAll I -> ResistAll I
    { 0x08DC92E5, 0xEED55605 },    // 1xx_ResistAll II -> ResistAll II
    { 0x246EEFEE, 0xC980170E },    // 1xx_ResistAll III -> ResistAll III
    { 0x08DC92F2, 0xEED55612 },    // 1xx_ResistAll IV -> ResistAll IV
    { 0x46163309, 0xE0731229 },    // 1xx_ResistAll V -> ResistAll V
    { 0x08DC9492, 0xEED557B2 },    // 1xx_ResistAll VI -> ResistAll VI
    { 0x246F273B, 0xC9804E5B },    // 1xx_ResistAll VII -> ResistAll VII
    { 0xB2540F04, 0xF98A1A24 },    // 1xx_ResistAll VIII -> ResistAll VIII
    { 0x1209392C, 0x593F444C },    // 1xx_ResistFreeze 1 -> ResistFreeze 1
    { 0x30BD8FEF, 0x16B6530F },    // 1xx_ResistRoot 1 -> ResistRoot 1
    { 0x337063D5, 0x196926F5 },    // 1xx_ResistStun 1 -> ResistStun 1
    { 0xEFB60CDA, 0xF55537FA },    // 1xx_ResistStunRootFreeze 1 -> ResistStunRootFreeze 1
    { 0x05E4E2E6, 0x0850EA06 },    // 1xx_Run 1 -> Run 1
    { 0x05E4E2E7, 0x0850EA07 },    // 1xx_Run 2 -> Run 2
    { 0x05E4E2E8, 0x0850EA08 },    // 1xx_Run 3 -> Run 3
    { 0x05E4E2E9, 0x0850EA09 },    // 1xx_Run 4 -> Run 4
    { 0x05E4E2EA, 0x0850EA0A },    // 1xx_Run 5 -> Run 5
    { 0x05E4E2EB, 0x0850EA0A },    // 1xx_Run 6 -> Run 5
    { 0x05E4E2EC, 0x0850EA0A },    // 1xx_Run 7 -> Run 5
    { 0x05E4E2ED, 0x0850EA0A },    // 1xx_Run 8 -> Run 5
    { 0x05E4E2EE, 0x0850EA0A },    // 1xx_Run 9 -> Run 5
    { 0x3DD6ADA7, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Bash 0.1 Legendary -> (none)
    { 0xB1D4F9AE, 0xB77424CE },    // 1xx_Skill_Barbarian_Bash 1 -> Skill_Barbarian_Bash 1
    { 0xEC742F9E, 0xB77424D5 },    // 1xx_Skill_Barbarian_Bash 10 -> Skill_Barbarian_Bash 8
    { 0xEC742F9F, 0xB77424D5 },    // 1xx_Skill_Barbarian_Bash 11 -> Skill_Barbarian_Bash 8
    { 0xEC742FA0, 0xB77424D5 },    // 1xx_Skill_Barbarian_Bash 12 -> Skill_Barbarian_Bash 8
    { 0xB1D4F9AF, 0xB77424CF },    // 1xx_Skill_Barbarian_Bash 2 -> Skill_Barbarian_Bash 2
    { 0xB1D4F9B0, 0xB77424D0 },    // 1xx_Skill_Barbarian_Bash 3 -> Skill_Barbarian_Bash 3
    { 0xB1D4F9B1, 0xB77424D1 },    // 1xx_Skill_Barbarian_Bash 4 -> Skill_Barbarian_Bash 4
    { 0xB1D4F9B2, 0xB77424D2 },    // 1xx_Skill_Barbarian_Bash 5 -> Skill_Barbarian_Bash 5
    { 0xB1D4F9B3, 0xB77424D3 },    // 1xx_Skill_Barbarian_Bash 6 -> Skill_Barbarian_Bash 6
    { 0xB1D4F9B4, 0xB77424D4 },    // 1xx_Skill_Barbarian_Bash 7 -> Skill_Barbarian_Bash 7
    { 0xB1D4F9B5, 0xB77424D5 },    // 1xx_Skill_Barbarian_Bash 8 -> Skill_Barbarian_Bash 8
    { 0xB1D4F9B6, 0xB77424D5 },    // 1xx_Skill_Barbarian_Bash 9 -> Skill_Barbarian_Bash 8
    { 0xCE40A319, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Cleave 0.1 Legendary -> (none)
    { 0x9505B420, 0x7F1C2740 },    // 1xx_Skill_Barbarian_Cleave 1 -> Skill_Barbarian_Cleave 1
    { 0x35BC3850, 0x7F1C2747 },    // 1xx_Skill_Barbarian_Cleave 10 -> Skill_Barbarian_Cleave 8
    { 0x35BC3851, 0x7F1C2747 },    // 1xx_Skill_Barbarian_Cleave 11 -> Skill_Barbarian_Cleave 8
    { 0x35BC3852, 0x7F1C2747 },    // 1xx_Skill_Barbarian_Cleave 12 -> Skill_Barbarian_Cleave 8
    { 0x9505B421, 0x7F1C2741 },    // 1xx_Skill_Barbarian_Cleave 2 -> Skill_Barbarian_Cleave 2
    { 0x9505B422, 0x7F1C2742 },    // 1xx_Skill_Barbarian_Cleave 3 -> Skill_Barbarian_Cleave 3
    { 0x9505B423, 0x7F1C2743 },    // 1xx_Skill_Barbarian_Cleave 4 -> Skill_Barbarian_Cleave 4
    { 0x9505B424, 0x7F1C2744 },    // 1xx_Skill_Barbarian_Cleave 5 -> Skill_Barbarian_Cleave 5
    { 0x9505B425, 0x7F1C2745 },    // 1xx_Skill_Barbarian_Cleave 6 -> Skill_Barbarian_Cleave 6
    { 0x9505B426, 0x7F1C2746 },    // 1xx_Skill_Barbarian_Cleave 7 -> Skill_Barbarian_Cleave 7
    { 0x9505B427, 0x7F1C2747 },    // 1xx_Skill_Barbarian_Cleave 8 -> Skill_Barbarian_Cleave 8
    { 0x9505B428, 0x7F1C2747 },    // 1xx_Skill_Barbarian_Cleave 9 -> Skill_Barbarian_Cleave 8
    { 0xBF4E3867, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Frenzy 0.1 Legendary -> (none)
    { 0x2896646E, 0x12ACD78E },    // 1xx_Skill_Barbarian_Frenzy 1 -> Skill_Barbarian_Frenzy 1
    { 0x3B62F25E, 0x12ACD795 },    // 1xx_Skill_Barbarian_Frenzy 10 -> Skill_Barbarian_Frenzy 8
    { 0x3B62F25F, 0x12ACD795 },    // 1xx_Skill_Barbarian_Frenzy 11 -> Skill_Barbarian_Frenzy 8
    { 0x3B62F260, 0x12ACD795 },    // 1xx_Skill_Barbarian_Frenzy 12 -> Skill_Barbarian_Frenzy 8
    { 0x2896646F, 0x12ACD78F },    // 1xx_Skill_Barbarian_Frenzy 2 -> Skill_Barbarian_Frenzy 2
    { 0x28966470, 0x12ACD790 },    // 1xx_Skill_Barbarian_Frenzy 3 -> Skill_Barbarian_Frenzy 3
    { 0x28966471, 0x12ACD791 },    // 1xx_Skill_Barbarian_Frenzy 4 -> Skill_Barbarian_Frenzy 4
    { 0x28966472, 0x12ACD792 },    // 1xx_Skill_Barbarian_Frenzy 5 -> Skill_Barbarian_Frenzy 5
    { 0x28966473, 0x12ACD793 },    // 1xx_Skill_Barbarian_Frenzy 6 -> Skill_Barbarian_Frenzy 6
    { 0x28966474, 0x12ACD794 },    // 1xx_Skill_Barbarian_Frenzy 7 -> Skill_Barbarian_Frenzy 7
    { 0x28966475, 0x12ACD795 },    // 1xx_Skill_Barbarian_Frenzy 8 -> Skill_Barbarian_Frenzy 8
    { 0x28966476, 0x12ACD795 },    // 1xx_Skill_Barbarian_Frenzy 9 -> Skill_Barbarian_Frenzy 8
    { 0x6F86FC15, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_HotA 0.1 Legendary -> (none)
    { 0xC0D1B31C, 0xC670DE3C },    // 1xx_Skill_Barbarian_HotA 1 -> Skill_Barbarian_HotA 1
    { 0xDB0816CC, 0xC670DE43 },    // 1xx_Skill_Barbarian_HotA 10 -> Skill_Barbarian_HotA 8
    { 0xDB0816CD, 0xC670DE43 },    // 1xx_Skill_Barbarian_HotA 11 -> Skill_Barbarian_HotA 8
    { 0xDB0816CE, 0xC670DE43 },    // 1xx_Skill_Barbarian_HotA 12 -> Skill_Barbarian_HotA 8
    { 0xC0D1B31D, 0xC670DE3D },    // 1xx_Skill_Barbarian_HotA 2 -> Skill_Barbarian_HotA 2
    { 0xC0D1B31E, 0xC670DE3E },    // 1xx_Skill_Barbarian_HotA 3 -> Skill_Barbarian_HotA 3
    { 0xC0D1B31F, 0xC670DE3F },    // 1xx_Skill_Barbarian_HotA 4 -> Skill_Barbarian_HotA 4
    { 0xC0D1B320, 0xC670DE40 },    // 1xx_Skill_Barbarian_HotA 5 -> Skill_Barbarian_HotA 5
    { 0xC0D1B321, 0xC670DE41 },    // 1xx_Skill_Barbarian_HotA 6 -> Skill_Barbarian_HotA 6
    { 0xC0D1B322, 0xC670DE42 },    // 1xx_Skill_Barbarian_HotA 7 -> Skill_Barbarian_HotA 7
    { 0xC0D1B323, 0xC670DE43 },    // 1xx_Skill_Barbarian_HotA 8 -> Skill_Barbarian_HotA 8
    { 0xC0D1B324, 0xC670DE43 },    // 1xx_Skill_Barbarian_HotA 9 -> Skill_Barbarian_HotA 8
    { 0xA84D7472, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Overpower 0.1 Legendary -> (none)
    { 0xFE86F7F9, 0xF7FE1719 },    // 1xx_Skill_Barbarian_Overpower 1 -> Skill_Barbarian_Overpower 1
    { 0xCF65F749, 0xF7FE1720 },    // 1xx_Skill_Barbarian_Overpower 10 -> Skill_Barbarian_Overpower 8
    { 0xCF65F74A, 0xF7FE1720 },    // 1xx_Skill_Barbarian_Overpower 11 -> Skill_Barbarian_Overpower 8
    { 0xCF65F74B, 0xF7FE1720 },    // 1xx_Skill_Barbarian_Overpower 12 -> Skill_Barbarian_Overpower 8
    { 0xFE86F7FA, 0xF7FE171A },    // 1xx_Skill_Barbarian_Overpower 2 -> Skill_Barbarian_Overpower 2
    { 0xFE86F7FB, 0xF7FE171B },    // 1xx_Skill_Barbarian_Overpower 3 -> Skill_Barbarian_Overpower 3
    { 0xFE86F7FC, 0xF7FE171C },    // 1xx_Skill_Barbarian_Overpower 4 -> Skill_Barbarian_Overpower 4
    { 0xFE86F7FD, 0xF7FE171D },    // 1xx_Skill_Barbarian_Overpower 5 -> Skill_Barbarian_Overpower 5
    { 0xFE86F7FE, 0xF7FE171E },    // 1xx_Skill_Barbarian_Overpower 6 -> Skill_Barbarian_Overpower 6
    { 0xFE86F7FF, 0xF7FE171F },    // 1xx_Skill_Barbarian_Overpower 7 -> Skill_Barbarian_Overpower 7
    { 0xFE86F800, 0xF7FE1720 },    // 1xx_Skill_Barbarian_Overpower 8 -> Skill_Barbarian_Overpower 8
    { 0xFE86F801, 0xF7FE1720 },    // 1xx_Skill_Barbarian_Overpower 9 -> Skill_Barbarian_Overpower 8
    { 0xA078E352, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Rend 0.1 Legendary -> (none)
    { 0xD76D16D9, 0xDD0C41F9 },    // 1xx_Skill_Barbarian_Rend 1 -> Skill_Barbarian_Rend 1
    { 0xC50FF229, 0xDD0C4200 },    // 1xx_Skill_Barbarian_Rend 10 -> Skill_Barbarian_Rend 8
    { 0xC50FF22A, 0xDD0C4200 },    // 1xx_Skill_Barbarian_Rend 11 -> Skill_Barbarian_Rend 8
    { 0xC50FF22B, 0xDD0C4200 },    // 1xx_Skill_Barbarian_Rend 12 -> Skill_Barbarian_Rend 8
    { 0xD76D16DA, 0xDD0C41FA },    // 1xx_Skill_Barbarian_Rend 2 -> Skill_Barbarian_Rend 2
    { 0xD76D16DB, 0xDD0C41FB },    // 1xx_Skill_Barbarian_Rend 3 -> Skill_Barbarian_Rend 3
    { 0xD76D16DC, 0xDD0C41FC },    // 1xx_Skill_Barbarian_Rend 4 -> Skill_Barbarian_Rend 4
    { 0xD76D16DD, 0xDD0C41FD },    // 1xx_Skill_Barbarian_Rend 5 -> Skill_Barbarian_Rend 5
    { 0xD76D16DE, 0xDD0C41FE },    // 1xx_Skill_Barbarian_Rend 6 -> Skill_Barbarian_Rend 6
    { 0xD76D16DF, 0xDD0C41FF },    // 1xx_Skill_Barbarian_Rend 7 -> Skill_Barbarian_Rend 7
    { 0xD76D16E0, 0xDD0C4200 },    // 1xx_Skill_Barbarian_Rend 8 -> Skill_Barbarian_Rend 8
    { 0xD76D16E1, 0xDD0C4200 },    // 1xx_Skill_Barbarian_Rend 9 -> Skill_Barbarian_Rend 8
    { 0x982FB195, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Revenge 0.1 Legendary -> (none)
    { 0xB89E289C, 0xE582FFBC },    // 1xx_Skill_Barbarian_Revenge 1 -> Skill_Barbarian_Revenge 1
    { 0xCC633C4C, 0xE582FFC3 },    // 1xx_Skill_Barbarian_Revenge 10 -> Skill_Barbarian_Revenge 8
    { 0xCC633C4D, 0xE582FFC3 },    // 1xx_Skill_Barbarian_Revenge 11 -> Skill_Barbarian_Revenge 8
    { 0xCC633C4E, 0xE582FFC3 },    // 1xx_Skill_Barbarian_Revenge 12 -> Skill_Barbarian_Revenge 8
    { 0xB89E289D, 0xE582FFBD },    // 1xx_Skill_Barbarian_Revenge 2 -> Skill_Barbarian_Revenge 2
    { 0xB89E289E, 0xE582FFBE },    // 1xx_Skill_Barbarian_Revenge 3 -> Skill_Barbarian_Revenge 3
    { 0xB89E289F, 0xE582FFBF },    // 1xx_Skill_Barbarian_Revenge 4 -> Skill_Barbarian_Revenge 4
    { 0xB89E28A0, 0xE582FFC0 },    // 1xx_Skill_Barbarian_Revenge 5 -> Skill_Barbarian_Revenge 5
    { 0xB89E28A1, 0xE582FFC1 },    // 1xx_Skill_Barbarian_Revenge 6 -> Skill_Barbarian_Revenge 6
    { 0xB89E28A2, 0xE582FFC2 },    // 1xx_Skill_Barbarian_Revenge 7 -> Skill_Barbarian_Revenge 7
    { 0xB89E28A3, 0xE582FFC3 },    // 1xx_Skill_Barbarian_Revenge 8 -> Skill_Barbarian_Revenge 8
    { 0xB89E28A4, 0xE582FFC3 },    // 1xx_Skill_Barbarian_Revenge 9 -> Skill_Barbarian_Revenge 8
    { 0xFC60CF83, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_SeismicSlam 0.1 Legendary -> (none)
    { 0x08C8718A, 0x3C83D8AA },    // 1xx_Skill_Barbarian_SeismicSlam 1 -> Skill_Barbarian_SeismicSlam 1
    { 0x21D6A2FA, 0x3C83D8B1 },    // 1xx_Skill_Barbarian_SeismicSlam 10 -> Skill_Barbarian_SeismicSlam 8
    { 0x21D6A2FB, 0x3C83D8B1 },    // 1xx_Skill_Barbarian_SeismicSlam 11 -> Skill_Barbarian_SeismicSlam 8
    { 0x21D6A2FC, 0x3C83D8B1 },    // 1xx_Skill_Barbarian_SeismicSlam 12 -> Skill_Barbarian_SeismicSlam 8
    { 0x08C8718B, 0x3C83D8AB },    // 1xx_Skill_Barbarian_SeismicSlam 2 -> Skill_Barbarian_SeismicSlam 2
    { 0x08C8718C, 0x3C83D8AC },    // 1xx_Skill_Barbarian_SeismicSlam 3 -> Skill_Barbarian_SeismicSlam 3
    { 0x08C8718D, 0x3C83D8AD },    // 1xx_Skill_Barbarian_SeismicSlam 4 -> Skill_Barbarian_SeismicSlam 4
    { 0x08C8718E, 0x3C83D8AE },    // 1xx_Skill_Barbarian_SeismicSlam 5 -> Skill_Barbarian_SeismicSlam 5
    { 0x08C8718F, 0x3C83D8AF },    // 1xx_Skill_Barbarian_SeismicSlam 6 -> Skill_Barbarian_SeismicSlam 6
    { 0x08C87190, 0x3C83D8B0 },    // 1xx_Skill_Barbarian_SeismicSlam 7 -> Skill_Barbarian_SeismicSlam 7
    { 0x08C87191, 0x3C83D8B1 },    // 1xx_Skill_Barbarian_SeismicSlam 8 -> Skill_Barbarian_SeismicSlam 8
    { 0x08C87192, 0x3C83D8B1 },    // 1xx_Skill_Barbarian_SeismicSlam 9 -> Skill_Barbarian_SeismicSlam 8
    { 0xB2491D47, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_WeaponThrow 0.1 Legendary -> (none)
    { 0x98EAF94E, 0xCCA6606E },    // 1xx_Skill_Barbarian_WeaponThrow 1 -> Skill_Barbarian_WeaponThrow 1
    { 0xB64A233E, 0xCCA66075 },    // 1xx_Skill_Barbarian_WeaponThrow 10 -> Skill_Barbarian_WeaponThrow 8
    { 0xB64A233F, 0xCCA66075 },    // 1xx_Skill_Barbarian_WeaponThrow 11 -> Skill_Barbarian_WeaponThrow 8
    { 0xB64A2340, 0xCCA66075 },    // 1xx_Skill_Barbarian_WeaponThrow 12 -> Skill_Barbarian_WeaponThrow 8
    { 0x98EAF94F, 0xCCA6606F },    // 1xx_Skill_Barbarian_WeaponThrow 2 -> Skill_Barbarian_WeaponThrow 2
    { 0x98EAF950, 0xCCA66070 },    // 1xx_Skill_Barbarian_WeaponThrow 3 -> Skill_Barbarian_WeaponThrow 3
    { 0x98EAF951, 0xCCA66071 },    // 1xx_Skill_Barbarian_WeaponThrow 4 -> Skill_Barbarian_WeaponThrow 4
    { 0x98EAF952, 0xCCA66072 },    // 1xx_Skill_Barbarian_WeaponThrow 5 -> Skill_Barbarian_WeaponThrow 5
    { 0x98EAF953, 0xCCA66073 },    // 1xx_Skill_Barbarian_WeaponThrow 6 -> Skill_Barbarian_WeaponThrow 6
    { 0x98EAF954, 0xCCA66074 },    // 1xx_Skill_Barbarian_WeaponThrow 7 -> Skill_Barbarian_WeaponThrow 7
    { 0x98EAF955, 0xCCA66075 },    // 1xx_Skill_Barbarian_WeaponThrow 8 -> Skill_Barbarian_WeaponThrow 8
    { 0x98EAF956, 0xCCA66075 },    // 1xx_Skill_Barbarian_WeaponThrow 9 -> Skill_Barbarian_WeaponThrow 8
    { 0x0E15B001, 0xFFFFFFFF },    // 1xx_Skill_Barbarian_Whirlwind 0.1 Legendary -> (none)
    { 0xA0922508, 0x9A094428 },    // 1xx_Skill_Barbarian_Whirlwind 1 -> Skill_Barbarian_Whirlwind 1
    { 0xB2D6C638, 0x9A09442F },    // 1xx_Skill_Barbarian_Whirlwind 10 -> Skill_Barbarian_Whirlwind 8
    { 0xB2D6C639, 0x9A09442F },    // 1xx_Skill_Barbarian_Whirlwind 11 -> Skill_Barbarian_Whirlwind 8
    { 0xB2D6C63A, 0x9A09442F },    // 1xx_Skill_Barbarian_Whirlwind 12 -> Skill_Barbarian_Whirlwind 8
    { 0xA0922509, 0x9A094429 },    // 1xx_Skill_Barbarian_Whirlwind 2 -> Skill_Barbarian_Whirlwind 2
    { 0xA092250A, 0x9A09442A },    // 1xx_Skill_Barbarian_Whirlwind 3 -> Skill_Barbarian_Whirlwind 3
    { 0xA092250B, 0x9A09442B },    // 1xx_Skill_Barbarian_Whirlwind 4 -> Skill_Barbarian_Whirlwind 4
    { 0xA092250C, 0x9A09442C },    // 1xx_Skill_Barbarian_Whirlwind 5 -> Skill_Barbarian_Whirlwind 5
    { 0xA092250D, 0x9A09442D },    // 1xx_Skill_Barbarian_Whirlwind 6 -> Skill_Barbarian_Whirlwind 6
    { 0xA092250E, 0x9A09442E },    // 1xx_Skill_Barbarian_Whirlwind 7 -> Skill_Barbarian_Whirlwind 7
    { 0xA092250F, 0x9A09442F },    // 1xx_Skill_Barbarian_Whirlwind 8 -> Skill_Barbarian_Whirlwind 8
    { 0xA0922510, 0x9A09442F },    // 1xx_Skill_Barbarian_Whirlwind 9 -> Skill_Barbarian_Whirlwind 8
    { 0x1596CF0C, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_BolaShot 0.1 Legendary -> (none)
    { 0xACD81B93, 0xD5331EB3 },    // 1xx_Skill_DemonHunter_BolaShot 1 -> Skill_DemonHunter_BolaShot 1
    { 0x47DB8E23, 0xD5331EBA },    // 1xx_Skill_DemonHunter_BolaShot 10 -> Skill_DemonHunter_BolaShot 8
    { 0x47DB8E24, 0xD5331EBA },    // 1xx_Skill_DemonHunter_BolaShot 11 -> Skill_DemonHunter_BolaShot 8
    { 0x47DB8E25, 0xD5331EBA },    // 1xx_Skill_DemonHunter_BolaShot 12 -> Skill_DemonHunter_BolaShot 8
    { 0xACD81B94, 0xD5331EB4 },    // 1xx_Skill_DemonHunter_BolaShot 2 -> Skill_DemonHunter_BolaShot 2
    { 0xACD81B95, 0xD5331EB5 },    // 1xx_Skill_DemonHunter_BolaShot 3 -> Skill_DemonHunter_BolaShot 3
    { 0xACD81B96, 0xD5331EB6 },    // 1xx_Skill_DemonHunter_BolaShot 4 -> Skill_DemonHunter_BolaShot 4
    { 0xACD81B97, 0xD5331EB7 },    // 1xx_Skill_DemonHunter_BolaShot 5 -> Skill_DemonHunter_BolaShot 5
    { 0xACD81B98, 0xD5331EB8 },    // 1xx_Skill_DemonHunter_BolaShot 6 -> Skill_DemonHunter_BolaShot 6
    { 0xACD81B99, 0xD5331EB9 },    // 1xx_Skill_DemonHunter_BolaShot 7 -> Skill_DemonHunter_BolaShot 7
    { 0xACD81B9A, 0xD5331EBA },    // 1xx_Skill_DemonHunter_BolaShot 8 -> Skill_DemonHunter_BolaShot 8
    { 0xACD81B9B, 0xD5331EBA },    // 1xx_Skill_DemonHunter_BolaShot 9 -> Skill_DemonHunter_BolaShot 8
    { 0x3DDC5187, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_Chakram 0.1 Legendary -> (none)
    { 0x9DDDCD8E, 0x9754ECAE },    // 1xx_Skill_DemonHunter_Chakram 1 -> Skill_DemonHunter_Chakram 1
    { 0x59977F7E, 0x9754ECB5 },    // 1xx_Skill_DemonHunter_Chakram 10 -> Skill_DemonHunter_Chakram 8
    { 0x59977F7F, 0x9754ECB5 },    // 1xx_Skill_DemonHunter_Chakram 11 -> Skill_DemonHunter_Chakram 8
    { 0x59977F80, 0x9754ECB5 },    // 1xx_Skill_DemonHunter_Chakram 12 -> Skill_DemonHunter_Chakram 8
    { 0x9DDDCD8F, 0x9754ECAF },    // 1xx_Skill_DemonHunter_Chakram 2 -> Skill_DemonHunter_Chakram 2
    { 0x9DDDCD90, 0x9754ECB0 },    // 1xx_Skill_DemonHunter_Chakram 3 -> Skill_DemonHunter_Chakram 3
    { 0x9DDDCD91, 0x9754ECB1 },    // 1xx_Skill_DemonHunter_Chakram 4 -> Skill_DemonHunter_Chakram 4
    { 0x9DDDCD92, 0x9754ECB2 },    // 1xx_Skill_DemonHunter_Chakram 5 -> Skill_DemonHunter_Chakram 5
    { 0x9DDDCD93, 0x9754ECB3 },    // 1xx_Skill_DemonHunter_Chakram 6 -> Skill_DemonHunter_Chakram 6
    { 0x9DDDCD94, 0x9754ECB4 },    // 1xx_Skill_DemonHunter_Chakram 7 -> Skill_DemonHunter_Chakram 7
    { 0x9DDDCD95, 0x9754ECB5 },    // 1xx_Skill_DemonHunter_Chakram 8 -> Skill_DemonHunter_Chakram 8
    { 0x9DDDCD96, 0x9754ECB5 },    // 1xx_Skill_DemonHunter_Chakram 9 -> Skill_DemonHunter_Chakram 8
    { 0x1570C97D, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_ClusterArrow 0.1 Legendary -> (none)
    { 0x2AEE2484, 0x4155B7A4 },    // 1xx_Skill_DemonHunter_ClusterArrow 1 -> Skill_DemonHunter_ClusterArrow 1
    { 0x88B2B534, 0x4155B7AB },    // 1xx_Skill_DemonHunter_ClusterArrow 10 -> Skill_DemonHunter_ClusterArrow 8
    { 0x88B2B535, 0x4155B7AB },    // 1xx_Skill_DemonHunter_ClusterArrow 11 -> Skill_DemonHunter_ClusterArrow 8
    { 0x88B2B536, 0x4155B7AB },    // 1xx_Skill_DemonHunter_ClusterArrow 12 -> Skill_DemonHunter_ClusterArrow 8
    { 0x2AEE2485, 0x4155B7A5 },    // 1xx_Skill_DemonHunter_ClusterArrow 2 -> Skill_DemonHunter_ClusterArrow 2
    { 0x2AEE2486, 0x4155B7A6 },    // 1xx_Skill_DemonHunter_ClusterArrow 3 -> Skill_DemonHunter_ClusterArrow 3
    { 0x2AEE2487, 0x4155B7A7 },    // 1xx_Skill_DemonHunter_ClusterArrow 4 -> Skill_DemonHunter_ClusterArrow 4
    { 0x2AEE2488, 0x4155B7A8 },    // 1xx_Skill_DemonHunter_ClusterArrow 5 -> Skill_DemonHunter_ClusterArrow 5
    { 0x2AEE2489, 0x4155B7A9 },    // 1xx_Skill_DemonHunter_ClusterArrow 6 -> Skill_DemonHunter_ClusterArrow 6
    { 0x2AEE248A, 0x4155B7AA },    // 1xx_Skill_DemonHunter_ClusterArrow 7 -> Skill_DemonHunter_ClusterArrow 7
    { 0x2AEE248B, 0x4155B7AB },    // 1xx_Skill_DemonHunter_ClusterArrow 8 -> Skill_DemonHunter_ClusterArrow 8
    { 0x2AEE248C, 0x4155B7AB },    // 1xx_Skill_DemonHunter_ClusterArrow 9 -> Skill_DemonHunter_ClusterArrow 8
    { 0xFCA15CD2, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_ElementalArrow 0.1 Legendary -> (none)
    { 0x61F35059, 0xB08C2B79 },    // 1xx_Skill_DemonHunter_ElementalArrow 1 -> Skill_DemonHunter_ElementalArrow 1
    { 0xA05D5BA9, 0xB08C2B80 },    // 1xx_Skill_DemonHunter_ElementalArrow 10 -> Skill_DemonHunter_ElementalArrow 8
    { 0xA05D5BAA, 0xB08C2B80 },    // 1xx_Skill_DemonHunter_ElementalArrow 11 -> Skill_DemonHunter_ElementalArrow 8
    { 0xA05D5BAB, 0xB08C2B80 },    // 1xx_Skill_DemonHunter_ElementalArrow 12 -> Skill_DemonHunter_ElementalArrow 8
    { 0x61F3505A, 0xB08C2B7A },    // 1xx_Skill_DemonHunter_ElementalArrow 2 -> Skill_DemonHunter_ElementalArrow 2
    { 0x61F3505B, 0xB08C2B7B },    // 1xx_Skill_DemonHunter_ElementalArrow 3 -> Skill_DemonHunter_ElementalArrow 3
    { 0x61F3505C, 0xB08C2B7C },    // 1xx_Skill_DemonHunter_ElementalArrow 4 -> Skill_DemonHunter_ElementalArrow 4
    { 0x61F3505D, 0xB08C2B7D },    // 1xx_Skill_DemonHunter_ElementalArrow 5 -> Skill_DemonHunter_ElementalArrow 5
    { 0x61F3505E, 0xB08C2B7E },    // 1xx_Skill_DemonHunter_ElementalArrow 6 -> Skill_DemonHunter_ElementalArrow 6
    { 0x61F3505F, 0xB08C2B7F },    // 1xx_Skill_DemonHunter_ElementalArrow 7 -> Skill_DemonHunter_ElementalArrow 7
    { 0x61F35060, 0xB08C2B80 },    // 1xx_Skill_DemonHunter_ElementalArrow 8 -> Skill_DemonHunter_ElementalArrow 8
    { 0x61F35061, 0xB08C2B80 },    // 1xx_Skill_DemonHunter_ElementalArrow 9 -> Skill_DemonHunter_ElementalArrow 8
    { 0x9A6542F5, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_EntanglingShot 0.1 Legendary -> (none)
    { 0xA766A9FC, 0xF5FF851C },    // 1xx_Skill_DemonHunter_EntanglingShot 1 -> Skill_DemonHunter_EntanglingShot 1
    { 0x943BE9AC, 0xF5FF8523 },    // 1xx_Skill_DemonHunter_EntanglingShot 10 -> Skill_DemonHunter_EntanglingShot 8
    { 0x943BE9AD, 0xF5FF8523 },    // 1xx_Skill_DemonHunter_EntanglingShot 11 -> Skill_DemonHunter_EntanglingShot 8
    { 0x943BE9AE, 0xF5FF8523 },    // 1xx_Skill_DemonHunter_EntanglingShot 12 -> Skill_DemonHunter_EntanglingShot 8
    { 0xA766A9FD, 0xF5FF851D },    // 1xx_Skill_DemonHunter_EntanglingShot 2 -> Skill_DemonHunter_EntanglingShot 2
    { 0xA766A9FE, 0xF5FF851E },    // 1xx_Skill_DemonHunter_EntanglingShot 3 -> Skill_DemonHunter_EntanglingShot 3
    { 0xA766A9FF, 0xF5FF851F },    // 1xx_Skill_DemonHunter_EntanglingShot 4 -> Skill_DemonHunter_EntanglingShot 4
    { 0xA766AA00, 0xF5FF8520 },    // 1xx_Skill_DemonHunter_EntanglingShot 5 -> Skill_DemonHunter_EntanglingShot 5
    { 0xA766AA01, 0xF5FF8521 },    // 1xx_Skill_DemonHunter_EntanglingShot 6 -> Skill_DemonHunter_EntanglingShot 6
    { 0xA766AA02, 0xF5FF8522 },    // 1xx_Skill_DemonHunter_EntanglingShot 7 -> Skill_DemonHunter_EntanglingShot 7
    { 0xA766AA03, 0xF5FF8523 },    // 1xx_Skill_DemonHunter_EntanglingShot 8 -> Skill_DemonHunter_EntanglingShot 8
    { 0xA766AA04, 0xF5FF8523 },    // 1xx_Skill_DemonHunter_EntanglingShot 9 -> Skill_DemonHunter_EntanglingShot 8
    { 0xBCED27A9, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_EvasiveFire 0.1 Legendary -> (none)
    { 0xC11AE0B0, 0xD14C8FD0 },    // 1xx_Skill_DemonHunter_EvasiveFire 1 -> Skill_DemonHunter_EvasiveFire 1
    { 0xE476F6E0, 0xD14C8FD7 },    // 1xx_Skill_DemonHunter_EvasiveFire 10 -> Skill_DemonHunter_EvasiveFire 8
    { 0xE476F6E1, 0xD14C8FD7 },    // 1xx_Skill_DemonHunter_EvasiveFire 11 -> Skill_DemonHunter_EvasiveFire 8
    { 0xE476F6E2, 0xD14C8FD7 },    // 1xx_Skill_DemonHunter_EvasiveFire 12 -> Skill_DemonHunter_EvasiveFire 8
    { 0xC11AE0B1, 0xD14C8FD1 },    // 1xx_Skill_DemonHunter_EvasiveFire 2 -> Skill_DemonHunter_EvasiveFire 2
    { 0xC11AE0B2, 0xD14C8FD2 },    // 1xx_Skill_DemonHunter_EvasiveFire 3 -> Skill_DemonHunter_EvasiveFire 3
    { 0xC11AE0B3, 0xD14C8FD3 },    // 1xx_Skill_DemonHunter_EvasiveFire 4 -> Skill_DemonHunter_EvasiveFire 4
    { 0xC11AE0B4, 0xD14C8FD4 },    // 1xx_Skill_DemonHunter_EvasiveFire 5 -> Skill_DemonHunter_EvasiveFire 5
    { 0xC11AE0B5, 0xD14C8FD5 },    // 1xx_Skill_DemonHunter_EvasiveFire 6 -> Skill_DemonHunter_EvasiveFire 6
    { 0xC11AE0B6, 0xD14C8FD6 },    // 1xx_Skill_DemonHunter_EvasiveFire 7 -> Skill_DemonHunter_EvasiveFire 7
    { 0xC11AE0B7, 0xD14C8FD7 },    // 1xx_Skill_DemonHunter_EvasiveFire 8 -> Skill_DemonHunter_EvasiveFire 8
    { 0xC11AE0B8, 0xD14C8FD7 },    // 1xx_Skill_DemonHunter_EvasiveFire 9 -> Skill_DemonHunter_EvasiveFire 8
    { 0x85CF4979, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_Grenades 0.1 Legendary -> (none)
    { 0x671FCA80, 0x8F7ACDA0 },    // 1xx_Skill_DemonHunter_Grenades 1 -> Skill_DemonHunter_Grenades 1
    { 0x4B191AB0, 0x8F7ACDA7 },    // 1xx_Skill_DemonHunter_Grenades 10 -> Skill_DemonHunter_Grenades 8
    { 0x4B191AB1, 0x8F7ACDA7 },    // 1xx_Skill_DemonHunter_Grenades 11 -> Skill_DemonHunter_Grenades 8
    { 0x4B191AB2, 0x8F7ACDA7 },    // 1xx_Skill_DemonHunter_Grenades 12 -> Skill_DemonHunter_Grenades 8
    { 0x671FCA81, 0x8F7ACDA1 },    // 1xx_Skill_DemonHunter_Grenades 2 -> Skill_DemonHunter_Grenades 2
    { 0x671FCA82, 0x8F7ACDA2 },    // 1xx_Skill_DemonHunter_Grenades 3 -> Skill_DemonHunter_Grenades 3
    { 0x671FCA83, 0x8F7ACDA3 },    // 1xx_Skill_DemonHunter_Grenades 4 -> Skill_DemonHunter_Grenades 4
    { 0x671FCA84, 0x8F7ACDA4 },    // 1xx_Skill_DemonHunter_Grenades 5 -> Skill_DemonHunter_Grenades 5
    { 0x671FCA85, 0x8F7ACDA5 },    // 1xx_Skill_DemonHunter_Grenades 6 -> Skill_DemonHunter_Grenades 6
    { 0x671FCA86, 0x8F7ACDA6 },    // 1xx_Skill_DemonHunter_Grenades 7 -> Skill_DemonHunter_Grenades 7
    { 0x671FCA87, 0x8F7ACDA7 },    // 1xx_Skill_DemonHunter_Grenades 8 -> Skill_DemonHunter_Grenades 8
    { 0x671FCA88, 0x8F7ACDA7 },    // 1xx_Skill_DemonHunter_Grenades 9 -> Skill_DemonHunter_Grenades 8
    { 0x27B19D22, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_HungeringArrow 0.1 Legendary -> (none)
    { 0xB32498A9, 0x01BD73C9 },    // 1xx_Skill_DemonHunter_HungeringArrow 1 -> Skill_DemonHunter_HungeringArrow 1
    { 0x17B7ADF9, 0x01BD73D0 },    // 1xx_Skill_DemonHunter_HungeringArrow 10 -> Skill_DemonHunter_HungeringArrow 8
    { 0x17B7ADFA, 0x01BD73D0 },    // 1xx_Skill_DemonHunter_HungeringArrow 11 -> Skill_DemonHunter_HungeringArrow 8
    { 0x17B7ADFB, 0x01BD73D0 },    // 1xx_Skill_DemonHunter_HungeringArrow 12 -> Skill_DemonHunter_HungeringArrow 8
    { 0xB32498AA, 0x01BD73CA },    // 1xx_Skill_DemonHunter_HungeringArrow 2 -> Skill_DemonHunter_HungeringArrow 2
    { 0xB32498AB, 0x01BD73CB },    // 1xx_Skill_DemonHunter_HungeringArrow 3 -> Skill_DemonHunter_HungeringArrow 3
    { 0xB32498AC, 0x01BD73CC },    // 1xx_Skill_DemonHunter_HungeringArrow 4 -> Skill_DemonHunter_HungeringArrow 4
    { 0xB32498AD, 0x01BD73CD },    // 1xx_Skill_DemonHunter_HungeringArrow 5 -> Skill_DemonHunter_HungeringArrow 5
    { 0xB32498AE, 0x01BD73CE },    // 1xx_Skill_DemonHunter_HungeringArrow 6 -> Skill_DemonHunter_HungeringArrow 6
    { 0xB32498AF, 0x01BD73CF },    // 1xx_Skill_DemonHunter_HungeringArrow 7 -> Skill_DemonHunter_HungeringArrow 7
    { 0xB32498B0, 0x01BD73D0 },    // 1xx_Skill_DemonHunter_HungeringArrow 8 -> Skill_DemonHunter_HungeringArrow 8
    { 0xB32498B1, 0x01BD73D0 },    // 1xx_Skill_DemonHunter_HungeringArrow 9 -> Skill_DemonHunter_HungeringArrow 8
    { 0xB9EDB988, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_Impale 0.1 Legendary -> (none)
    { 0xFB2E6C0F, 0xC4AE272F },    // 1xx_Skill_DemonHunter_Impale 1 -> Skill_DemonHunter_Impale 1
    { 0x60FBEE1F, 0xC4AE2736 },    // 1xx_Skill_DemonHunter_Impale 10 -> Skill_DemonHunter_Impale 8
    { 0x60FBEE20, 0xC4AE2736 },    // 1xx_Skill_DemonHunter_Impale 11 -> Skill_DemonHunter_Impale 8
    { 0x60FBEE21, 0xC4AE2736 },    // 1xx_Skill_DemonHunter_Impale 12 -> Skill_DemonHunter_Impale 8
    { 0xFB2E6C10, 0xC4AE2730 },    // 1xx_Skill_DemonHunter_Impale 2 -> Skill_DemonHunter_Impale 2
    { 0xFB2E6C11, 0xC4AE2731 },    // 1xx_Skill_DemonHunter_Impale 3 -> Skill_DemonHunter_Impale 3
    { 0xFB2E6C12, 0xC4AE2732 },    // 1xx_Skill_DemonHunter_Impale 4 -> Skill_DemonHunter_Impale 4
    { 0xFB2E6C13, 0xC4AE2733 },    // 1xx_Skill_DemonHunter_Impale 5 -> Skill_DemonHunter_Impale 5
    { 0xFB2E6C14, 0xC4AE2734 },    // 1xx_Skill_DemonHunter_Impale 6 -> Skill_DemonHunter_Impale 6
    { 0xFB2E6C15, 0xC4AE2735 },    // 1xx_Skill_DemonHunter_Impale 7 -> Skill_DemonHunter_Impale 7
    { 0xFB2E6C16, 0xC4AE2736 },    // 1xx_Skill_DemonHunter_Impale 8 -> Skill_DemonHunter_Impale 8
    { 0xFB2E6C17, 0xC4AE2736 },    // 1xx_Skill_DemonHunter_Impale 9 -> Skill_DemonHunter_Impale 8
    { 0xBB026379, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_Multishot 0.1 Legendary -> (none)
    { 0xBB5BE480, 0xEF174BA0 },    // 1xx_Skill_DemonHunter_Multishot 1 -> Skill_DemonHunter_Multishot 1
    { 0x26D874B0, 0xEF174BA7 },    // 1xx_Skill_DemonHunter_Multishot 10 -> Skill_DemonHunter_Multishot 8
    { 0x26D874B1, 0xEF174BA7 },    // 1xx_Skill_DemonHunter_Multishot 11 -> Skill_DemonHunter_Multishot 8
    { 0x26D874B2, 0xEF174BA7 },    // 1xx_Skill_DemonHunter_Multishot 12 -> Skill_DemonHunter_Multishot 8
    { 0xBB5BE481, 0xEF174BA1 },    // 1xx_Skill_DemonHunter_Multishot 2 -> Skill_DemonHunter_Multishot 2
    { 0xBB5BE482, 0xEF174BA2 },    // 1xx_Skill_DemonHunter_Multishot 3 -> Skill_DemonHunter_Multishot 3
    { 0xBB5BE483, 0xEF174BA3 },    // 1xx_Skill_DemonHunter_Multishot 4 -> Skill_DemonHunter_Multishot 4
    { 0xBB5BE484, 0xEF174BA4 },    // 1xx_Skill_DemonHunter_Multishot 5 -> Skill_DemonHunter_Multishot 5
    { 0xBB5BE485, 0xEF174BA5 },    // 1xx_Skill_DemonHunter_Multishot 6 -> Skill_DemonHunter_Multishot 6
    { 0xBB5BE486, 0xEF174BA6 },    // 1xx_Skill_DemonHunter_Multishot 7 -> Skill_DemonHunter_Multishot 7
    { 0xBB5BE487, 0xEF174BA7 },    // 1xx_Skill_DemonHunter_Multishot 8 -> Skill_DemonHunter_Multishot 8
    { 0xBB5BE488, 0xEF174BA7 },    // 1xx_Skill_DemonHunter_Multishot 9 -> Skill_DemonHunter_Multishot 8
    { 0xC803BEE6, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_RapidFire 0.1 Legendary -> (none)
    { 0x1152F46D, 0x450E5B8D },    // 1xx_Skill_DemonHunter_RapidFire 1 -> Skill_DemonHunter_RapidFire 1
    { 0x3BB1823D, 0x450E5B94 },    // 1xx_Skill_DemonHunter_RapidFire 10 -> Skill_DemonHunter_RapidFire 8
    { 0x3BB1823E, 0x450E5B94 },    // 1xx_Skill_DemonHunter_RapidFire 11 -> Skill_DemonHunter_RapidFire 8
    { 0x3BB1823F, 0x450E5B94 },    // 1xx_Skill_DemonHunter_RapidFire 12 -> Skill_DemonHunter_RapidFire 8
    { 0x1152F46E, 0x450E5B8E },    // 1xx_Skill_DemonHunter_RapidFire 2 -> Skill_DemonHunter_RapidFire 2
    { 0x1152F46F, 0x450E5B8F },    // 1xx_Skill_DemonHunter_RapidFire 3 -> Skill_DemonHunter_RapidFire 3
    { 0x1152F470, 0x450E5B90 },    // 1xx_Skill_DemonHunter_RapidFire 4 -> Skill_DemonHunter_RapidFire 4
    { 0x1152F471, 0x450E5B91 },    // 1xx_Skill_DemonHunter_RapidFire 5 -> Skill_DemonHunter_RapidFire 5
    { 0x1152F472, 0x450E5B92 },    // 1xx_Skill_DemonHunter_RapidFire 6 -> Skill_DemonHunter_RapidFire 6
    { 0x1152F473, 0x450E5B93 },    // 1xx_Skill_DemonHunter_RapidFire 7 -> Skill_DemonHunter_RapidFire 7
    { 0x1152F474, 0x450E5B94 },    // 1xx_Skill_DemonHunter_RapidFire 8 -> Skill_DemonHunter_RapidFire 8
    { 0x1152F475, 0x450E5B94 },    // 1xx_Skill_DemonHunter_RapidFire 9 -> Skill_DemonHunter_RapidFire 8
    { 0xBD88A9C3, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_SpikeTrap 0.1 Legendary -> (none)
    { 0xEAA6EBCA, 0x1E6252EA },    // 1xx_Skill_DemonHunter_SpikeTrap 1 -> Skill_DemonHunter_SpikeTrap 1
    { 0x3F84653A, 0x1E6252F1 },    // 1xx_Skill_DemonHunter_SpikeTrap 10 -> Skill_DemonHunter_SpikeTrap 8
    { 0x3F84653B, 0x1E6252F1 },    // 1xx_Skill_DemonHunter_SpikeTrap 11 -> Skill_DemonHunter_SpikeTrap 8
    { 0x3F84653C, 0x1E6252F1 },    // 1xx_Skill_DemonHunter_SpikeTrap 12 -> Skill_DemonHunter_SpikeTrap 8
    { 0xEAA6EBCB, 0x1E6252EB },    // 1xx_Skill_DemonHunter_SpikeTrap 2 -> Skill_DemonHunter_SpikeTrap 2
    { 0xEAA6EBCC, 0x1E6252EC },    // 1xx_Skill_DemonHunter_SpikeTrap 3 -> Skill_DemonHunter_SpikeTrap 3
    { 0xEAA6EBCD, 0x1E6252ED },    // 1xx_Skill_DemonHunter_SpikeTrap 4 -> Skill_DemonHunter_SpikeTrap 4
    { 0xEAA6EBCE, 0x1E6252EE },    // 1xx_Skill_DemonHunter_SpikeTrap 5 -> Skill_DemonHunter_SpikeTrap 5
    { 0xEAA6EBCF, 0x1E6252EF },    // 1xx_Skill_DemonHunter_SpikeTrap 6 -> Skill_DemonHunter_SpikeTrap 6
    { 0xEAA6EBD0, 0x1E6252F0 },    // 1xx_Skill_DemonHunter_SpikeTrap 7 -> Skill_DemonHunter_SpikeTrap 7
    { 0xEAA6EBD1, 0x1E6252F1 },    // 1xx_Skill_DemonHunter_SpikeTrap 8 -> Skill_DemonHunter_SpikeTrap 8
    { 0xEAA6EBD2, 0x1E6252F1 },    // 1xx_Skill_DemonHunter_SpikeTrap 9 -> Skill_DemonHunter_SpikeTrap 8
    { 0x1C5BB615, 0xFFFFFFFF },    // 1xx_Skill_DemonHunter_Strafe 0.1 Legendary -> (none)
    { 0x553F6D1C, 0x1EBF283C },    // 1xx_Skill_DemonHunter_Strafe 1 -> Skill_DemonHunter_Strafe 1
    { 0xFD2D10CC, 0x1EBF2843 },    // 1xx_Skill_DemonHunter_Strafe 10 -> Skill_DemonHunter_Strafe 8
    { 0xFD2D10CD, 0x1EBF2843 },    // 1xx_Skill_DemonHunter_Strafe 11 -> Skill_DemonHunter_Strafe 8
    { 0xFD2D10CE, 0x1EBF2843 },    // 1xx_Skill_DemonHunter_Strafe 12 -> Skill_DemonHunter_Strafe 8
    { 0x553F6D1D, 0x1EBF283D },    // 1xx_Skill_DemonHunter_Strafe 2 -> Skill_DemonHunter_Strafe 2
    { 0x553F6D1E, 0x1EBF283E },    // 1xx_Skill_DemonHunter_Strafe 3 -> Skill_DemonHunter_Strafe 3
    { 0x553F6D1F, 0x1EBF283F },    // 1xx_Skill_DemonHunter_Strafe 4 -> Skill_DemonHunter_Strafe 4
    { 0x553F6D20, 0x1EBF2840 },    // 1xx_Skill_DemonHunter_Strafe 5 -> Skill_DemonHunter_Strafe 5
    { 0x553F6D21, 0x1EBF2841 },    // 1xx_Skill_DemonHunter_Strafe 6 -> Skill_DemonHunter_Strafe 6
    { 0x553F6D22, 0x1EBF2842 },    // 1xx_Skill_DemonHunter_Strafe 7 -> Skill_DemonHunter_Strafe 7
    { 0x553F6D23, 0x1EBF2843 },    // 1xx_Skill_DemonHunter_Strafe 8 -> Skill_DemonHunter_Strafe 8
    { 0x553F6D24, 0x1EBF2843 },    // 1xx_Skill_DemonHunter_Strafe 9 -> Skill_DemonHunter_Strafe 8
    { 0x462D5457, 0xFFFFFFFF },    // 1xx_Skill_Monk_CripplingWave 0.1 Legendary -> (none)
    { 0xD938185E, 0xA2B7D37E },    // 1xx_Skill_Monk_CripplingWave 1 -> Skill_Monk_CripplingWave 1
    { 0x003B244E, 0xA2B7D385 },    // 1xx_Skill_Monk_CripplingWave 10 -> Skill_Monk_CripplingWave 8
    { 0x003B244F, 0xA2B7D385 },    // 1xx_Skill_Monk_CripplingWave 11 -> Skill_Monk_CripplingWave 8
    { 0x003B2450, 0xA2B7D385 },    // 1xx_Skill_Monk_CripplingWave 12 -> Skill_Monk_CripplingWave 8
    { 0xD938185F, 0xA2B7D37F },    // 1xx_Skill_Monk_CripplingWave 2 -> Skill_Monk_CripplingWave 2
    { 0xD9381860, 0xA2B7D380 },    // 1xx_Skill_Monk_CripplingWave 3 -> Skill_Monk_CripplingWave 3
    { 0xD9381861, 0xA2B7D381 },    // 1xx_Skill_Monk_CripplingWave 4 -> Skill_Monk_CripplingWave 4
    { 0xD9381862, 0xA2B7D382 },    // 1xx_Skill_Monk_CripplingWave 5 -> Skill_Monk_CripplingWave 5
    { 0xD9381863, 0xA2B7D383 },    // 1xx_Skill_Monk_CripplingWave 6 -> Skill_Monk_CripplingWave 6
    { 0xD9381864, 0xA2B7D384 },    // 1xx_Skill_Monk_CripplingWave 7 -> Skill_Monk_CripplingWave 7
    { 0xD9381865, 0xA2B7D385 },    // 1xx_Skill_Monk_CripplingWave 8 -> Skill_Monk_CripplingWave 8
    { 0xD9381866, 0xA2B7D385 },    // 1xx_Skill_Monk_CripplingWave 9 -> Skill_Monk_CripplingWave 8
    { 0x86CA571B, 0xFFFFFFFF },    // 1xx_Skill_Monk_CycloneStrike 0.1 Legendary -> (none)
    { 0x0397D522, 0xCD179042 },    // 1xx_Skill_Monk_CycloneStrike 1 -> Skill_Monk_CycloneStrike 1
    { 0x76927992, 0xCD179049 },    // 1xx_Skill_Monk_CycloneStrike 10 -> Skill_Monk_CycloneStrike 8
    { 0x76927993, 0xCD179049 },    // 1xx_Skill_Monk_CycloneStrike 11 -> Skill_Monk_CycloneStrike 8
    { 0x76927994, 0xCD179049 },    // 1xx_Skill_Monk_CycloneStrike 12 -> Skill_Monk_CycloneStrike 8
    { 0x0397D523, 0xCD179043 },    // 1xx_Skill_Monk_CycloneStrike 2 -> Skill_Monk_CycloneStrike 2
    { 0x0397D524, 0xCD179044 },    // 1xx_Skill_Monk_CycloneStrike 3 -> Skill_Monk_CycloneStrike 3
    { 0x0397D525, 0xCD179045 },    // 1xx_Skill_Monk_CycloneStrike 4 -> Skill_Monk_CycloneStrike 4
    { 0x0397D526, 0xCD179046 },    // 1xx_Skill_Monk_CycloneStrike 5 -> Skill_Monk_CycloneStrike 5
    { 0x0397D527, 0xCD179047 },    // 1xx_Skill_Monk_CycloneStrike 6 -> Skill_Monk_CycloneStrike 6
    { 0x0397D528, 0xCD179048 },    // 1xx_Skill_Monk_CycloneStrike 7 -> Skill_Monk_CycloneStrike 7
    { 0x0397D529, 0xCD179049 },    // 1xx_Skill_Monk_CycloneStrike 8 -> Skill_Monk_CycloneStrike 8
    { 0x0397D52A, 0xCD179049 },    // 1xx_Skill_Monk_CycloneStrike 9 -> Skill_Monk_CycloneStrike 8
    { 0x143F25B2, 0xFFFFFFFF },    // 1xx_Skill_Monk_DeadlyReach 0.1 Legendary -> (none)
    { 0xB074C939, 0x9A8B3C59 },    // 1xx_Skill_Monk_DeadlyReach 1 -> Skill_Monk_DeadlyReach 1
    { 0xBF0DF089, 0x9A8B3C60 },    // 1xx_Skill_Monk_DeadlyReach 10 -> Skill_Monk_DeadlyReach 8
    { 0xBF0DF08A, 0x9A8B3C60 },    // 1xx_Skill_Monk_DeadlyReach 11 -> Skill_Monk_DeadlyReach 8
    { 0xBF0DF08B, 0x9A8B3C60 },    // 1xx_Skill_Monk_DeadlyReach 12 -> Skill_Monk_DeadlyReach 8
    { 0xB074C93A, 0x9A8B3C5A },    // 1xx_Skill_Monk_DeadlyReach 2 -> Skill_Monk_DeadlyReach 2
    { 0xB074C93B, 0x9A8B3C5B },    // 1xx_Skill_Monk_DeadlyReach 3 -> Skill_Monk_DeadlyReach 3
    { 0xB074C93C, 0x9A8B3C5C },    // 1xx_Skill_Monk_DeadlyReach 4 -> Skill_Monk_DeadlyReach 4
    { 0xB074C93D, 0x9A8B3C5D },    // 1xx_Skill_Monk_DeadlyReach 5 -> Skill_Monk_DeadlyReach 5
    { 0xB074C93E, 0x9A8B3C5E },    // 1xx_Skill_Monk_DeadlyReach 6 -> Skill_Monk_DeadlyReach 6
    { 0xB074C93F, 0x9A8B3C5F },    // 1xx_Skill_Monk_DeadlyReach 7 -> Skill_Monk_DeadlyReach 7
    { 0xB074C940, 0x9A8B3C60 },    // 1xx_Skill_Monk_DeadlyReach 8 -> Skill_Monk_DeadlyReach 8
    { 0xB074C941, 0x9A8B3C60 },    // 1xx_Skill_Monk_DeadlyReach 9 -> Skill_Monk_DeadlyReach 8
    { 0xC0E92FB0, 0xFFFFFFFF },    // 1xx_Skill_Monk_ExplodingPalm 0.1 Legendary -> (none)
    { 0x35096637, 0xFE892157 },    // 1xx_Skill_Monk_ExplodingPalm 1 -> Skill_Monk_ExplodingPalm 1
    { 0xD6362D47, 0xFE89215E },    // 1xx_Skill_Monk_ExplodingPalm 10 -> Skill_Monk_ExplodingPalm 8
    { 0xD6362D48, 0xFE89215E },    // 1xx_Skill_Monk_ExplodingPalm 11 -> Skill_Monk_ExplodingPalm 8
    { 0xD6362D49, 0xFE89215E },    // 1xx_Skill_Monk_ExplodingPalm 12 -> Skill_Monk_ExplodingPalm 8
    { 0x35096638, 0xFE892158 },    // 1xx_Skill_Monk_ExplodingPalm 2 -> Skill_Monk_ExplodingPalm 2
    { 0x35096639, 0xFE892159 },    // 1xx_Skill_Monk_ExplodingPalm 3 -> Skill_Monk_ExplodingPalm 3
    { 0x3509663A, 0xFE89215A },    // 1xx_Skill_Monk_ExplodingPalm 4 -> Skill_Monk_ExplodingPalm 4
    { 0x3509663B, 0xFE89215B },    // 1xx_Skill_Monk_ExplodingPalm 5 -> Skill_Monk_ExplodingPalm 5
    { 0x3509663C, 0xFE89215C },    // 1xx_Skill_Monk_ExplodingPalm 6 -> Skill_Monk_ExplodingPalm 6
    { 0x3509663D, 0xFE89215D },    // 1xx_Skill_Monk_ExplodingPalm 7 -> Skill_Monk_ExplodingPalm 7
    { 0x3509663E, 0xFE89215E },    // 1xx_Skill_Monk_ExplodingPalm 8 -> Skill_Monk_ExplodingPalm 8
    { 0x3509663F, 0xFE89215E },    // 1xx_Skill_Monk_ExplodingPalm 9 -> Skill_Monk_ExplodingPalm 8
    { 0x17631794, 0xFFFFFFFF },    // 1xx_Skill_Monk_FistsofThunder 0.1 Legendary -> (none)
    { 0x366D581B, 0x2FE4773B },    // 1xx_Skill_Monk_FistsofThunder 1 -> Skill_Monk_FistsofThunder 1
    { 0x04185BAB, 0x2FE47742 },    // 1xx_Skill_Monk_FistsofThunder 10 -> Skill_Monk_FistsofThunder 8
    { 0x04185BAC, 0x2FE47742 },    // 1xx_Skill_Monk_FistsofThunder 11 -> Skill_Monk_FistsofThunder 8
    { 0x04185BAD, 0x2FE47742 },    // 1xx_Skill_Monk_FistsofThunder 12 -> Skill_Monk_FistsofThunder 8
    { 0x366D581C, 0x2FE4773C },    // 1xx_Skill_Monk_FistsofThunder 2 -> Skill_Monk_FistsofThunder 2
    { 0x366D581D, 0x2FE4773D },    // 1xx_Skill_Monk_FistsofThunder 3 -> Skill_Monk_FistsofThunder 3
    { 0x366D581E, 0x2FE4773E },    // 1xx_Skill_Monk_FistsofThunder 4 -> Skill_Monk_FistsofThunder 4
    { 0x366D581F, 0x2FE4773F },    // 1xx_Skill_Monk_FistsofThunder 5 -> Skill_Monk_FistsofThunder 5
    { 0x366D5820, 0x2FE47740 },    // 1xx_Skill_Monk_FistsofThunder 6 -> Skill_Monk_FistsofThunder 6
    { 0x366D5821, 0x2FE47741 },    // 1xx_Skill_Monk_FistsofThunder 7 -> Skill_Monk_FistsofThunder 7
    { 0x366D5822, 0x2FE47742 },    // 1xx_Skill_Monk_FistsofThunder 8 -> Skill_Monk_FistsofThunder 8
    { 0x366D5823, 0x2FE47742 },    // 1xx_Skill_Monk_FistsofThunder 9 -> Skill_Monk_FistsofThunder 8
    { 0x9CA7CAEE, 0xFFFFFFFF },    // 1xx_Skill_Monk_LashingTailKick 0.1 Legendary -> (none)
    { 0xBB5EB475, 0xE3B9B795 },    // 1xx_Skill_Monk_LashingTailKick 1 -> Skill_Monk_LashingTailKick 1
    { 0x27354345, 0xE3B9B79C },    // 1xx_Skill_Monk_LashingTailKick 10 -> Skill_Monk_LashingTailKick 8
    { 0x27354346, 0xE3B9B79C },    // 1xx_Skill_Monk_LashingTailKick 11 -> Skill_Monk_LashingTailKick 8
    { 0x27354347, 0xE3B9B79C },    // 1xx_Skill_Monk_LashingTailKick 12 -> Skill_Monk_LashingTailKick 8
    { 0xBB5EB476, 0xE3B9B796 },    // 1xx_Skill_Monk_LashingTailKick 2 -> Skill_Monk_LashingTailKick 2
    { 0xBB5EB477, 0xE3B9B797 },    // 1xx_Skill_Monk_LashingTailKick 3 -> Skill_Monk_LashingTailKick 3
    { 0xBB5EB478, 0xE3B9B798 },    // 1xx_Skill_Monk_LashingTailKick 4 -> Skill_Monk_LashingTailKick 4
    { 0xBB5EB479, 0xE3B9B799 },    // 1xx_Skill_Monk_LashingTailKick 5 -> Skill_Monk_LashingTailKick 5
    { 0xBB5EB47A, 0xE3B9B79A },    // 1xx_Skill_Monk_LashingTailKick 6 -> Skill_Monk_LashingTailKick 6
    { 0xBB5EB47B, 0xE3B9B79B },    // 1xx_Skill_Monk_LashingTailKick 7 -> Skill_Monk_LashingTailKick 7
    { 0xBB5EB47C, 0xE3B9B79C },    // 1xx_Skill_Monk_LashingTailKick 8 -> Skill_Monk_LashingTailKick 8
    { 0xBB5EB47D, 0xE3B9B79C },    // 1xx_Skill_Monk_LashingTailKick 9 -> Skill_Monk_LashingTailKick 8
    { 0xD366A4F0, 0xFFFFFFFF },    // 1xx_Skill_Monk_SweepingWind 0.1 Legendary -> (none)
    { 0xFABCFB77, 0x27A1D297 },    // 1xx_Skill_Monk_SweepingWind 1 -> Skill_Monk_SweepingWind 1
    { 0x525C6A87, 0x27A1D29E },    // 1xx_Skill_Monk_SweepingWind 10 -> Skill_Monk_SweepingWind 8
    { 0x525C6A88, 0x27A1D29E },    // 1xx_Skill_Monk_SweepingWind 11 -> Skill_Monk_SweepingWind 8
    { 0x525C6A89, 0x27A1D29E },    // 1xx_Skill_Monk_SweepingWind 12 -> Skill_Monk_SweepingWind 8
    { 0xFABCFB78, 0x27A1D298 },    // 1xx_Skill_Monk_SweepingWind 2 -> Skill_Monk_SweepingWind 2
    { 0xFABCFB79, 0x27A1D299 },    // 1xx_Skill_Monk_SweepingWind 3 -> Skill_Monk_SweepingWind 3
    { 0xFABCFB7A, 0x27A1D29A },    // 1xx_Skill_Monk_SweepingWind 4 -> Skill_Monk_SweepingWind 4
    { 0xFABCFB7B, 0x27A1D29B },    // 1xx_Skill_Monk_SweepingWind 5 -> Skill_Monk_SweepingWind 5
    { 0xFABCFB7C, 0x27A1D29C },    // 1xx_Skill_Monk_SweepingWind 6 -> Skill_Monk_SweepingWind 6
    { 0xFABCFB7D, 0x27A1D29D },    // 1xx_Skill_Monk_SweepingWind 7 -> Skill_Monk_SweepingWind 7
    { 0xFABCFB7E, 0x27A1D29E },    // 1xx_Skill_Monk_SweepingWind 8 -> Skill_Monk_SweepingWind 8
    { 0xFABCFB7F, 0x27A1D29E },    // 1xx_Skill_Monk_SweepingWind 9 -> Skill_Monk_SweepingWind 8
    { 0x4D41E4E0, 0xFFFFFFFF },    // 1xx_Skill_Monk_TempestRush 0.1 Legendary -> (none)
    { 0x1804D367, 0x021B4687 },    // 1xx_Skill_Monk_TempestRush 1 -> Skill_Monk_TempestRush 1
    { 0x189F4077, 0x021B468E },    // 1xx_Skill_Monk_TempestRush 10 -> Skill_Monk_TempestRush 8
    { 0x189F4078, 0x021B468E },    // 1xx_Skill_Monk_TempestRush 11 -> Skill_Monk_TempestRush 8
    { 0x189F4079, 0x021B468E },    // 1xx_Skill_Monk_TempestRush 12 -> Skill_Monk_TempestRush 8
    { 0x1804D368, 0x021B4688 },    // 1xx_Skill_Monk_TempestRush 2 -> Skill_Monk_TempestRush 2
    { 0x1804D369, 0x021B4689 },    // 1xx_Skill_Monk_TempestRush 3 -> Skill_Monk_TempestRush 3
    { 0x1804D36A, 0x021B468A },    // 1xx_Skill_Monk_TempestRush 4 -> Skill_Monk_TempestRush 4
    { 0x1804D36B, 0x021B468B },    // 1xx_Skill_Monk_TempestRush 5 -> Skill_Monk_TempestRush 5
    { 0x1804D36C, 0x021B468C },    // 1xx_Skill_Monk_TempestRush 6 -> Skill_Monk_TempestRush 6
    { 0x1804D36D, 0x021B468D },    // 1xx_Skill_Monk_TempestRush 7 -> Skill_Monk_TempestRush 7
    { 0x1804D36E, 0x021B468E },    // 1xx_Skill_Monk_TempestRush 8 -> Skill_Monk_TempestRush 8
    { 0x1804D36F, 0x021B468E },    // 1xx_Skill_Monk_TempestRush 9 -> Skill_Monk_TempestRush 8
    { 0x3270937C, 0xFFFFFFFF },    // 1xx_Skill_Monk_WaveofLight 0.1 Legendary -> (none)
    { 0xD5D3B803, 0xBFEA2B23 },    // 1xx_Skill_Monk_WaveofLight 1 -> Skill_Monk_WaveofLight 1
    { 0x904AB893, 0xBFEA2B2A },    // 1xx_Skill_Monk_WaveofLight 10 -> Skill_Monk_WaveofLight 8
    { 0x904AB894, 0xBFEA2B2A },    // 1xx_Skill_Monk_WaveofLight 11 -> Skill_Monk_WaveofLight 8
    { 0x904AB895, 0xBFEA2B2A },    // 1xx_Skill_Monk_WaveofLight 12 -> Skill_Monk_WaveofLight 8
    { 0xD5D3B804, 0xBFEA2B24 },    // 1xx_Skill_Monk_WaveofLight 2 -> Skill_Monk_WaveofLight 2
    { 0xD5D3B805, 0xBFEA2B25 },    // 1xx_Skill_Monk_WaveofLight 3 -> Skill_Monk_WaveofLight 3
    { 0xD5D3B806, 0xBFEA2B26 },    // 1xx_Skill_Monk_WaveofLight 4 -> Skill_Monk_WaveofLight 4
    { 0xD5D3B807, 0xBFEA2B27 },    // 1xx_Skill_Monk_WaveofLight 5 -> Skill_Monk_WaveofLight 5
    { 0xD5D3B808, 0xBFEA2B28 },    // 1xx_Skill_Monk_WaveofLight 6 -> Skill_Monk_WaveofLight 6
    { 0xD5D3B809, 0xBFEA2B29 },    // 1xx_Skill_Monk_WaveofLight 7 -> Skill_Monk_WaveofLight 7
    { 0xD5D3B80A, 0xBFEA2B2A },    // 1xx_Skill_Monk_WaveofLight 8 -> Skill_Monk_WaveofLight 8
    { 0xD5D3B80B, 0xBFEA2B2A },    // 1xx_Skill_Monk_WaveofLight 9 -> Skill_Monk_WaveofLight 8
    { 0x5281E55C, 0xFFFFFFFF },    // 1xx_Skill_Monk_Wayof100Fists 0.1 Legendary -> (none)
    { 0xB87339E3, 0x81F2F503 },    // 1xx_Skill_Monk_Wayof100Fists 1 -> Skill_Monk_Wayof100Fists 1
    { 0xC6DA7673, 0x81F2F50A },    // 1xx_Skill_Monk_Wayof100Fists 10 -> Skill_Monk_Wayof100Fists 8
    { 0xC6DA7674, 0x81F2F50A },    // 1xx_Skill_Monk_Wayof100Fists 11 -> Skill_Monk_Wayof100Fists 8
    { 0xC6DA7675, 0x81F2F50A },    // 1xx_Skill_Monk_Wayof100Fists 12 -> Skill_Monk_Wayof100Fists 8
    { 0xB87339E4, 0x81F2F504 },    // 1xx_Skill_Monk_Wayof100Fists 2 -> Skill_Monk_Wayof100Fists 2
    { 0xB87339E5, 0x81F2F505 },    // 1xx_Skill_Monk_Wayof100Fists 3 -> Skill_Monk_Wayof100Fists 3
    { 0xB87339E6, 0x81F2F506 },    // 1xx_Skill_Monk_Wayof100Fists 4 -> Skill_Monk_Wayof100Fists 4
    { 0xB87339E7, 0x81F2F507 },    // 1xx_Skill_Monk_Wayof100Fists 5 -> Skill_Monk_Wayof100Fists 5
    { 0xB87339E8, 0x81F2F508 },    // 1xx_Skill_Monk_Wayof100Fists 6 -> Skill_Monk_Wayof100Fists 6
    { 0xB87339E9, 0x81F2F509 },    // 1xx_Skill_Monk_Wayof100Fists 7 -> Skill_Monk_Wayof100Fists 7
    { 0xB87339EA, 0x81F2F50A },    // 1xx_Skill_Monk_Wayof100Fists 8 -> Skill_Monk_Wayof100Fists 8
    { 0xB87339EB, 0x81F2F50A },    // 1xx_Skill_Monk_Wayof100Fists 9 -> Skill_Monk_Wayof100Fists 8
    { 0x3DD5DD39, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_AcidCloud 0.1 Legendary -> (none)
    { 0xFADABE40, 0x2E962560 },    // 1xx_Skill_WitchDoctor_AcidCloud 1 -> Skill_WitchDoctor_AcidCloud 1
    { 0x56328670, 0x2E962567 },    // 1xx_Skill_WitchDoctor_AcidCloud 10 -> Skill_WitchDoctor_AcidCloud 8
    { 0x56328671, 0x2E962567 },    // 1xx_Skill_WitchDoctor_AcidCloud 11 -> Skill_WitchDoctor_AcidCloud 8
    { 0x56328672, 0x2E962567 },    // 1xx_Skill_WitchDoctor_AcidCloud 12 -> Skill_WitchDoctor_AcidCloud 8
    { 0xFADABE41, 0x2E962561 },    // 1xx_Skill_WitchDoctor_AcidCloud 2 -> Skill_WitchDoctor_AcidCloud 2
    { 0xFADABE42, 0x2E962562 },    // 1xx_Skill_WitchDoctor_AcidCloud 3 -> Skill_WitchDoctor_AcidCloud 3
    { 0xFADABE43, 0x2E962563 },    // 1xx_Skill_WitchDoctor_AcidCloud 4 -> Skill_WitchDoctor_AcidCloud 4
    { 0xFADABE44, 0x2E962564 },    // 1xx_Skill_WitchDoctor_AcidCloud 5 -> Skill_WitchDoctor_AcidCloud 5
    { 0xFADABE45, 0x2E962565 },    // 1xx_Skill_WitchDoctor_AcidCloud 6 -> Skill_WitchDoctor_AcidCloud 6
    { 0xFADABE46, 0x2E962566 },    // 1xx_Skill_WitchDoctor_AcidCloud 7 -> Skill_WitchDoctor_AcidCloud 7
    { 0xFADABE47, 0x2E962567 },    // 1xx_Skill_WitchDoctor_AcidCloud 8 -> Skill_WitchDoctor_AcidCloud 8
    { 0xFADABE48, 0x2E962567 },    // 1xx_Skill_WitchDoctor_AcidCloud 9 -> Skill_WitchDoctor_AcidCloud 8
    { 0x530E1C97, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_CorpseSpiders 0.1 Legendary -> (none)
    { 0xFF7A809E, 0xE2D477BE },    // 1xx_Skill_WitchDoctor_CorpseSpiders 1 -> Skill_WitchDoctor_CorpseSpiders 1
    { 0xEECA948E, 0xE2D477C5 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 10 -> Skill_WitchDoctor_CorpseSpiders 8
    { 0xEECA948F, 0xE2D477C5 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 11 -> Skill_WitchDoctor_CorpseSpiders 8
    { 0xEECA9490, 0xE2D477C5 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 12 -> Skill_WitchDoctor_CorpseSpiders 8
    { 0xFF7A809F, 0xE2D477BF },    // 1xx_Skill_WitchDoctor_CorpseSpiders 2 -> Skill_WitchDoctor_CorpseSpiders 2
    { 0xFF7A80A0, 0xE2D477C0 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 3 -> Skill_WitchDoctor_CorpseSpiders 3
    { 0xFF7A80A1, 0xE2D477C1 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 4 -> Skill_WitchDoctor_CorpseSpiders 4
    { 0xFF7A80A2, 0xE2D477C2 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 5 -> Skill_WitchDoctor_CorpseSpiders 5
    { 0xFF7A80A3, 0xE2D477C3 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 6 -> Skill_WitchDoctor_CorpseSpiders 6
    { 0xFF7A80A4, 0xE2D477C4 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 7 -> Skill_WitchDoctor_CorpseSpiders 7
    { 0xFF7A80A5, 0xE2D477C5 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 8 -> Skill_WitchDoctor_CorpseSpiders 8
    { 0xFF7A80A6, 0xE2D477C5 },    // 1xx_Skill_WitchDoctor_CorpseSpiders 9 -> Skill_WitchDoctor_CorpseSpiders 8
    { 0x1B22AE41, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_Firebats 0.1 Legendary  -> (none)
    { 0x95B46308, 0xBE0F6628 },    // 1xx_Skill_WitchDoctor_Firebats 1 -> Skill_WitchDoctor_Firebats 1
    { 0x4C40C438, 0xBE0F662F },    // 1xx_Skill_WitchDoctor_Firebats 10 -> Skill_WitchDoctor_Firebats 8
    { 0x4C40C439, 0xBE0F662F },    // 1xx_Skill_WitchDoctor_Firebats 11 -> Skill_WitchDoctor_Firebats 8
    { 0x4C40C43A, 0xBE0F662F },    // 1xx_Skill_WitchDoctor_Firebats 12 -> Skill_WitchDoctor_Firebats 8
    { 0x95B46309, 0xBE0F6629 },    // 1xx_Skill_WitchDoctor_Firebats 2 -> Skill_WitchDoctor_Firebats 2
    { 0x95B4630A, 0xBE0F662A },    // 1xx_Skill_WitchDoctor_Firebats 3 -> Skill_WitchDoctor_Firebats 3
    { 0x95B4630B, 0xBE0F662B },    // 1xx_Skill_WitchDoctor_Firebats 4 -> Skill_WitchDoctor_Firebats 4
    { 0x95B4630C, 0xBE0F662C },    // 1xx_Skill_WitchDoctor_Firebats 5 -> Skill_WitchDoctor_Firebats 5
    { 0x95B4630D, 0xBE0F662D },    // 1xx_Skill_WitchDoctor_Firebats 6 -> Skill_WitchDoctor_Firebats 6
    { 0x95B4630E, 0xBE0F662E },    // 1xx_Skill_WitchDoctor_Firebats 7 -> Skill_WitchDoctor_Firebats 7
    { 0x95B4630F, 0xBE0F662F },    // 1xx_Skill_WitchDoctor_Firebats 8 -> Skill_WitchDoctor_Firebats 8
    { 0x95B46310, 0xBE0F662F },    // 1xx_Skill_WitchDoctor_Firebats 9 -> Skill_WitchDoctor_Firebats 8
    { 0xA53CF717, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_FireBomb 0.1 Legendary -> (none)
    { 0x96AD9B1E, 0xBF089E3E },    // 1xx_Skill_WitchDoctor_FireBomb 1 -> Skill_WitchDoctor_FireBomb 1
    { 0x6C60FF0E, 0xBF089E45 },    // 1xx_Skill_WitchDoctor_FireBomb 10 -> Skill_WitchDoctor_FireBomb 8
    { 0x6C60FF0F, 0xBF089E45 },    // 1xx_Skill_WitchDoctor_FireBomb 11 -> Skill_WitchDoctor_FireBomb 8
    { 0x6C60FF10, 0xBF089E45 },    // 1xx_Skill_WitchDoctor_FireBomb 12 -> Skill_WitchDoctor_FireBomb 8
    { 0x96AD9B1F, 0xBF089E3F },    // 1xx_Skill_WitchDoctor_FireBomb 2 -> Skill_WitchDoctor_FireBomb 2
    { 0x96AD9B20, 0xBF089E40 },    // 1xx_Skill_WitchDoctor_FireBomb 3 -> Skill_WitchDoctor_FireBomb 3
    { 0x96AD9B21, 0xBF089E41 },    // 1xx_Skill_WitchDoctor_FireBomb 4 -> Skill_WitchDoctor_FireBomb 4
    { 0x96AD9B22, 0xBF089E42 },    // 1xx_Skill_WitchDoctor_FireBomb 5 -> Skill_WitchDoctor_FireBomb 5
    { 0x96AD9B23, 0xBF089E43 },    // 1xx_Skill_WitchDoctor_FireBomb 6 -> Skill_WitchDoctor_FireBomb 6
    { 0x96AD9B24, 0xBF089E44 },    // 1xx_Skill_WitchDoctor_FireBomb 7 -> Skill_WitchDoctor_FireBomb 7
    { 0x96AD9B25, 0xBF089E45 },    // 1xx_Skill_WitchDoctor_FireBomb 8 -> Skill_WitchDoctor_FireBomb 8
    { 0x96AD9B26, 0xBF089E45 },    // 1xx_Skill_WitchDoctor_FireBomb 9 -> Skill_WitchDoctor_FireBomb 8
    { 0x942BF851, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_Haunt 0.1 Legendary -> (none)
    { 0xED7D7558, 0x1A624C78 },    // 1xx_Skill_WitchDoctor_Haunt 1 -> Skill_WitchDoctor_Haunt 1
    { 0x9D2C2088, 0x1A624C7F },    // 1xx_Skill_WitchDoctor_Haunt 10 -> Skill_WitchDoctor_Haunt 8
    { 0x9D2C2089, 0x1A624C7F },    // 1xx_Skill_WitchDoctor_Haunt 11 -> Skill_WitchDoctor_Haunt 8
    { 0x9D2C208A, 0x1A624C7F },    // 1xx_Skill_WitchDoctor_Haunt 12 -> Skill_WitchDoctor_Haunt 8
    { 0xED7D7559, 0x1A624C79 },    // 1xx_Skill_WitchDoctor_Haunt 2 -> Skill_WitchDoctor_Haunt 2
    { 0xED7D755A, 0x1A624C7A },    // 1xx_Skill_WitchDoctor_Haunt 3 -> Skill_WitchDoctor_Haunt 3
    { 0xED7D755B, 0x1A624C7B },    // 1xx_Skill_WitchDoctor_Haunt 4 -> Skill_WitchDoctor_Haunt 4
    { 0xED7D755C, 0x1A624C7C },    // 1xx_Skill_WitchDoctor_Haunt 5 -> Skill_WitchDoctor_Haunt 5
    { 0xED7D755D, 0x1A624C7D },    // 1xx_Skill_WitchDoctor_Haunt 6 -> Skill_WitchDoctor_Haunt 6
    { 0xED7D755E, 0x1A624C7E },    // 1xx_Skill_WitchDoctor_Haunt 7 -> Skill_WitchDoctor_Haunt 7
    { 0xED7D755F, 0x1A624C7F },    // 1xx_Skill_WitchDoctor_Haunt 8 -> Skill_WitchDoctor_Haunt 8
    { 0xED7D7560, 0x1A624C7F },    // 1xx_Skill_WitchDoctor_Haunt 9 -> Skill_WitchDoctor_Haunt 8
    { 0xB5100075, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_LocustSwarm 0.1 Legendary -> (none)
    { 0xD7E9277C, 0xE81AD69C },    // 1xx_Skill_WitchDoctor_LocustSwarm 1 -> Skill_WitchDoctor_LocustSwarm 1
    { 0xD50E172C, 0xE81AD6A3 },    // 1xx_Skill_WitchDoctor_LocustSwarm 10 -> Skill_WitchDoctor_LocustSwarm 8
    { 0xD50E172D, 0xE81AD6A3 },    // 1xx_Skill_WitchDoctor_LocustSwarm 11 -> Skill_WitchDoctor_LocustSwarm 8
    { 0xD50E172E, 0xE81AD6A3 },    // 1xx_Skill_WitchDoctor_LocustSwarm 12 -> Skill_WitchDoctor_LocustSwarm 8
    { 0xD7E9277D, 0xE81AD69D },    // 1xx_Skill_WitchDoctor_LocustSwarm 2 -> Skill_WitchDoctor_LocustSwarm 2
    { 0xD7E9277E, 0xE81AD69E },    // 1xx_Skill_WitchDoctor_LocustSwarm 3 -> Skill_WitchDoctor_LocustSwarm 3
    { 0xD7E9277F, 0xE81AD69F },    // 1xx_Skill_WitchDoctor_LocustSwarm 4 -> Skill_WitchDoctor_LocustSwarm 4
    { 0xD7E92780, 0xE81AD6A0 },    // 1xx_Skill_WitchDoctor_LocustSwarm 5 -> Skill_WitchDoctor_LocustSwarm 5
    { 0xD7E92781, 0xE81AD6A1 },    // 1xx_Skill_WitchDoctor_LocustSwarm 6 -> Skill_WitchDoctor_LocustSwarm 6
    { 0xD7E92782, 0xE81AD6A2 },    // 1xx_Skill_WitchDoctor_LocustSwarm 7 -> Skill_WitchDoctor_LocustSwarm 7
    { 0xD7E92783, 0xE81AD6A3 },    // 1xx_Skill_WitchDoctor_LocustSwarm 8 -> Skill_WitchDoctor_LocustSwarm 8
    { 0xD7E92784, 0xE81AD6A3 },    // 1xx_Skill_WitchDoctor_LocustSwarm 9 -> Skill_WitchDoctor_LocustSwarm 8
    { 0x35980A1F, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_PlagueofToads 0.1 Legendary  -> (none)
    { 0x00CB1E26, 0xE4251546 },    // 1xx_Skill_WitchDoctor_PlagueofToads 1 -> Skill_WitchDoctor_PlagueofToads 1
    { 0x1A2EE316, 0xE425154D },    // 1xx_Skill_WitchDoctor_PlagueofToads 10 -> Skill_WitchDoctor_PlagueofToads 8
    { 0x1A2EE317, 0xE425154D },    // 1xx_Skill_WitchDoctor_PlagueofToads 11 -> Skill_WitchDoctor_PlagueofToads 8
    { 0x1A2EE318, 0xE425154D },    // 1xx_Skill_WitchDoctor_PlagueofToads 12 -> Skill_WitchDoctor_PlagueofToads 8
    { 0x00CB1E27, 0xE4251547 },    // 1xx_Skill_WitchDoctor_PlagueofToads 2 -> Skill_WitchDoctor_PlagueofToads 2
    { 0x00CB1E28, 0xE4251548 },    // 1xx_Skill_WitchDoctor_PlagueofToads 3 -> Skill_WitchDoctor_PlagueofToads 3
    { 0x00CB1E29, 0xE4251549 },    // 1xx_Skill_WitchDoctor_PlagueofToads 4 -> Skill_WitchDoctor_PlagueofToads 4
    { 0x00CB1E2A, 0xE425154A },    // 1xx_Skill_WitchDoctor_PlagueofToads 5 -> Skill_WitchDoctor_PlagueofToads 5
    { 0x00CB1E2B, 0xE425154B },    // 1xx_Skill_WitchDoctor_PlagueofToads 6 -> Skill_WitchDoctor_PlagueofToads 6
    { 0x00CB1E2C, 0xE425154C },    // 1xx_Skill_WitchDoctor_PlagueofToads 7 -> Skill_WitchDoctor_PlagueofToads 7
    { 0x00CB1E2D, 0xE425154D },    // 1xx_Skill_WitchDoctor_PlagueofToads 8 -> Skill_WitchDoctor_PlagueofToads 8
    { 0x00CB1E2E, 0xE425154D },    // 1xx_Skill_WitchDoctor_PlagueofToads 9 -> Skill_WitchDoctor_PlagueofToads 8
    { 0x3179AED4, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_PoisonDart 0.1 Legendary  -> (none)
    { 0xDA18F8BB, 0x854143DB },    // 1xx_Skill_WitchDoctor_PoisonDart 1 -> Skill_WitchDoctor_PoisonDart 1
    { 0x1D38104B, 0x854143E2 },    // 1xx_Skill_WitchDoctor_PoisonDart 10 -> Skill_WitchDoctor_PoisonDart 8
    { 0x1D38104C, 0x854143E2 },    // 1xx_Skill_WitchDoctor_PoisonDart 11 -> Skill_WitchDoctor_PoisonDart 8
    { 0x1D38104D, 0x854143E2 },    // 1xx_Skill_WitchDoctor_PoisonDart 12 -> Skill_WitchDoctor_PoisonDart 8
    { 0xDA18F8BC, 0x854143DC },    // 1xx_Skill_WitchDoctor_PoisonDart 2 -> Skill_WitchDoctor_PoisonDart 2
    { 0xDA18F8BD, 0x854143DD },    // 1xx_Skill_WitchDoctor_PoisonDart 3 -> Skill_WitchDoctor_PoisonDart 3
    { 0xDA18F8BE, 0x854143DE },    // 1xx_Skill_WitchDoctor_PoisonDart 4 -> Skill_WitchDoctor_PoisonDart 4
    { 0xDA18F8BF, 0x854143DF },    // 1xx_Skill_WitchDoctor_PoisonDart 5 -> Skill_WitchDoctor_PoisonDart 5
    { 0xDA18F8C0, 0x854143E0 },    // 1xx_Skill_WitchDoctor_PoisonDart 6 -> Skill_WitchDoctor_PoisonDart 6
    { 0xDA18F8C1, 0x854143E1 },    // 1xx_Skill_WitchDoctor_PoisonDart 7 -> Skill_WitchDoctor_PoisonDart 7
    { 0xDA18F8C2, 0x854143E2 },    // 1xx_Skill_WitchDoctor_PoisonDart 8 -> Skill_WitchDoctor_PoisonDart 8
    { 0xDA18F8C3, 0x854143E2 },    // 1xx_Skill_WitchDoctor_PoisonDart 9 -> Skill_WitchDoctor_PoisonDart 8
    { 0x55DD6500, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_SpiritBarrage 0.1 Legendary -> (none)
    { 0x4EC72387, 0x32211AA7 },    // 1xx_Skill_WitchDoctor_SpiritBarrage 1 -> Skill_WitchDoctor_SpiritBarrage 1
    { 0x27AB9497, 0x32211AAE },    // 1xx_Skill_WitchDoctor_SpiritBarrage 10 -> Skill_WitchDoctor_SpiritBarrage 8
    { 0x27AB9498, 0x32211AAE },    // 1xx_Skill_WitchDoctor_SpiritBarrage 11 -> Skill_WitchDoctor_SpiritBarrage 8
    { 0x27AB9499, 0x32211AAE },    // 1xx_Skill_WitchDoctor_SpiritBarrage 12 -> Skill_WitchDoctor_SpiritBarrage 8
    { 0x4EC72388, 0x32211AA8 },    // 1xx_Skill_WitchDoctor_SpiritBarrage 2 -> Skill_WitchDoctor_SpiritBarrage 2
    { 0x4EC72389, 0x32211AA9 },    // 1xx_Skill_WitchDoctor_SpiritBarrage 3 -> Skill_WitchDoctor_SpiritBarrage 3
    { 0x4EC7238A, 0x32211AAA },    // 1xx_Skill_WitchDoctor_SpiritBarrage 4 -> Skill_WitchDoctor_SpiritBarrage 4
    { 0x4EC7238B, 0x32211AAB },    // 1xx_Skill_WitchDoctor_SpiritBarrage 5 -> Skill_WitchDoctor_SpiritBarrage 5
    { 0x4EC7238C, 0x32211AAC },    // 1xx_Skill_WitchDoctor_SpiritBarrage 6 -> Skill_WitchDoctor_SpiritBarrage 6
    { 0x4EC7238D, 0x32211AAD },    // 1xx_Skill_WitchDoctor_SpiritBarrage 7 -> Skill_WitchDoctor_SpiritBarrage 7
    { 0x4EC7238E, 0x32211AAE },    // 1xx_Skill_WitchDoctor_SpiritBarrage 8 -> Skill_WitchDoctor_SpiritBarrage 8
    { 0x4EC7238F, 0x32211AAE },    // 1xx_Skill_WitchDoctor_SpiritBarrage 9 -> Skill_WitchDoctor_SpiritBarrage 8
    { 0x5161BF6F, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_WallofZombies 0.1 Legendary -> (none)
    { 0x44C11F76, 0x281B1696 },    // 1xx_Skill_WitchDoctor_WallofZombies 1 -> Skill_WitchDoctor_WallofZombies 1
    { 0xDCE50E66, 0x281B169D },    // 1xx_Skill_WitchDoctor_WallofZombies 10 -> Skill_WitchDoctor_WallofZombies 8
    { 0xDCE50E67, 0x281B169D },    // 1xx_Skill_WitchDoctor_WallofZombies 11 -> Skill_WitchDoctor_WallofZombies 8
    { 0xDCE50E68, 0x281B169D },    // 1xx_Skill_WitchDoctor_WallofZombies 12 -> Skill_WitchDoctor_WallofZombies 8
    { 0x44C11F77, 0x281B1697 },    // 1xx_Skill_WitchDoctor_WallofZombies 2 -> Skill_WitchDoctor_WallofZombies 2
    { 0x44C11F78, 0x281B1698 },    // 1xx_Skill_WitchDoctor_WallofZombies 3 -> Skill_WitchDoctor_WallofZombies 3
    { 0x44C11F79, 0x281B1699 },    // 1xx_Skill_WitchDoctor_WallofZombies 4 -> Skill_WitchDoctor_WallofZombies 4
    { 0x44C11F7A, 0x281B169A },    // 1xx_Skill_WitchDoctor_WallofZombies 5 -> Skill_WitchDoctor_WallofZombies 5
    { 0x44C11F7B, 0x281B169B },    // 1xx_Skill_WitchDoctor_WallofZombies 6 -> Skill_WitchDoctor_WallofZombies 6
    { 0x44C11F7C, 0x281B169C },    // 1xx_Skill_WitchDoctor_WallofZombies 7 -> Skill_WitchDoctor_WallofZombies 7
    { 0x44C11F7D, 0x281B169D },    // 1xx_Skill_WitchDoctor_WallofZombies 8 -> Skill_WitchDoctor_WallofZombies 8
    { 0x44C11F7E, 0x281B169D },    // 1xx_Skill_WitchDoctor_WallofZombies 9 -> Skill_WitchDoctor_WallofZombies 8
    { 0x83ABDB13, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_ZombieCharger 0.1 Legendary -> (none)
    { 0x4A39A51A, 0x2D939C3A },    // 1xx_Skill_WitchDoctor_ZombieCharger 1 -> Skill_WitchDoctor_ZombieCharger 1
    { 0x916E488A, 0x2D939C41 },    // 1xx_Skill_WitchDoctor_ZombieCharger 10 -> Skill_WitchDoctor_ZombieCharger 8
    { 0x916E488B, 0x2D939C41 },    // 1xx_Skill_WitchDoctor_ZombieCharger 11 -> Skill_WitchDoctor_ZombieCharger 8
    { 0x916E488C, 0x2D939C41 },    // 1xx_Skill_WitchDoctor_ZombieCharger 12 -> Skill_WitchDoctor_ZombieCharger 8
    { 0x4A39A51B, 0x2D939C3B },    // 1xx_Skill_WitchDoctor_ZombieCharger 2 -> Skill_WitchDoctor_ZombieCharger 2
    { 0x4A39A51C, 0x2D939C3C },    // 1xx_Skill_WitchDoctor_ZombieCharger 3 -> Skill_WitchDoctor_ZombieCharger 3
    { 0x4A39A51D, 0x2D939C3D },    // 1xx_Skill_WitchDoctor_ZombieCharger 4 -> Skill_WitchDoctor_ZombieCharger 4
    { 0x4A39A51E, 0x2D939C3E },    // 1xx_Skill_WitchDoctor_ZombieCharger 5 -> Skill_WitchDoctor_ZombieCharger 5
    { 0x4A39A51F, 0x2D939C3F },    // 1xx_Skill_WitchDoctor_ZombieCharger 6 -> Skill_WitchDoctor_ZombieCharger 6
    { 0x4A39A520, 0x2D939C40 },    // 1xx_Skill_WitchDoctor_ZombieCharger 7 -> Skill_WitchDoctor_ZombieCharger 7
    { 0x4A39A521, 0x2D939C41 },    // 1xx_Skill_WitchDoctor_ZombieCharger 8 -> Skill_WitchDoctor_ZombieCharger 8
    { 0x4A39A522, 0x2D939C41 },    // 1xx_Skill_WitchDoctor_ZombieCharger 9 -> Skill_WitchDoctor_ZombieCharger 8
    { 0xF0997404, 0xFFFFFFFF },    // 1xx_Skill_WitchDoctor_ZombieDogs 0.1 Legendary -> (none)
    { 0xDA218C8B, 0x8549D7AB },    // 1xx_Skill_WitchDoctor_ZombieDogs 1 -> Skill_WitchDoctor_ZombieDogs 1
    { 0x1E531E1B, 0x8549D7B2 },    // 1xx_Skill_WitchDoctor_ZombieDogs 10 -> Skill_WitchDoctor_ZombieDogs 8
    { 0x1E531E1C, 0x8549D7B2 },    // 1xx_Skill_WitchDoctor_ZombieDogs 11 -> Skill_WitchDoctor_ZombieDogs 8
    { 0x1E531E1D, 0x8549D7B2 },    // 1xx_Skill_WitchDoctor_ZombieDogs 12 -> Skill_WitchDoctor_ZombieDogs 8
    { 0xDA218C8C, 0x8549D7AC },    // 1xx_Skill_WitchDoctor_ZombieDogs 2 -> Skill_WitchDoctor_ZombieDogs 2
    { 0xDA218C8D, 0x8549D7AD },    // 1xx_Skill_WitchDoctor_ZombieDogs 3 -> Skill_WitchDoctor_ZombieDogs 3
    { 0xDA218C8E, 0x8549D7AE },    // 1xx_Skill_WitchDoctor_ZombieDogs 4 -> Skill_WitchDoctor_ZombieDogs 4
    { 0xDA218C8F, 0x8549D7AF },    // 1xx_Skill_WitchDoctor_ZombieDogs 5 -> Skill_WitchDoctor_ZombieDogs 5
    { 0xDA218C90, 0x8549D7B0 },    // 1xx_Skill_WitchDoctor_ZombieDogs 6 -> Skill_WitchDoctor_ZombieDogs 6
    { 0xDA218C91, 0x8549D7B1 },    // 1xx_Skill_WitchDoctor_ZombieDogs 7 -> Skill_WitchDoctor_ZombieDogs 7
    { 0xDA218C92, 0x8549D7B2 },    // 1xx_Skill_WitchDoctor_ZombieDogs 8 -> Skill_WitchDoctor_ZombieDogs 8
    { 0xDA218C93, 0x8549D7B2 },    // 1xx_Skill_WitchDoctor_ZombieDogs 9 -> Skill_WitchDoctor_ZombieDogs 8
    { 0x82811D05, 0xFFFFFFFF },    // 1xx_Skill_Wizard_ArcaneOrb 0.1 Legendary -> (none)
    { 0xC51EEC0C, 0xAF355F2C },    // 1xx_Skill_Wizard_ArcaneOrb 1 -> Skill_Wizard_ArcaneOrb 1
    { 0x68FC6DBC, 0xAF355F33 },    // 1xx_Skill_Wizard_ArcaneOrb 10 -> Skill_Wizard_ArcaneOrb 8
    { 0x68FC6DBD, 0xAF355F33 },    // 1xx_Skill_Wizard_ArcaneOrb 11 -> Skill_Wizard_ArcaneOrb 8
    { 0x68FC6DBE, 0xAF355F33 },    // 1xx_Skill_Wizard_ArcaneOrb 12 -> Skill_Wizard_ArcaneOrb 8
    { 0xC51EEC0D, 0xAF355F2D },    // 1xx_Skill_Wizard_ArcaneOrb 2 -> Skill_Wizard_ArcaneOrb 2
    { 0xC51EEC0E, 0xAF355F2E },    // 1xx_Skill_Wizard_ArcaneOrb 3 -> Skill_Wizard_ArcaneOrb 3
    { 0xC51EEC0F, 0xAF355F2F },    // 1xx_Skill_Wizard_ArcaneOrb 4 -> Skill_Wizard_ArcaneOrb 4
    { 0xC51EEC10, 0xAF355F30 },    // 1xx_Skill_Wizard_ArcaneOrb 5 -> Skill_Wizard_ArcaneOrb 5
    { 0xC51EEC11, 0xAF355F31 },    // 1xx_Skill_Wizard_ArcaneOrb 6 -> Skill_Wizard_ArcaneOrb 6
    { 0xC51EEC12, 0xAF355F32 },    // 1xx_Skill_Wizard_ArcaneOrb 7 -> Skill_Wizard_ArcaneOrb 7
    { 0xC51EEC13, 0xAF355F33 },    // 1xx_Skill_Wizard_ArcaneOrb 8 -> Skill_Wizard_ArcaneOrb 8
    { 0xC51EEC14, 0xAF355F33 },    // 1xx_Skill_Wizard_ArcaneOrb 9 -> Skill_Wizard_ArcaneOrb 8
    { 0xF50FDF30, 0xFFFFFFFF },    // 1xx_Skill_Wizard_ArcaneTorrent 0.1 Legendary -> (none)
    { 0xE80CD5B7, 0x1067D8D7 },    // 1xx_Skill_Wizard_ArcaneTorrent 1 -> Skill_Wizard_ArcaneTorrent 1
    { 0xE9A78CC7, 0x1067D8DE },    // 1xx_Skill_Wizard_ArcaneTorrent 10 -> Skill_Wizard_ArcaneTorrent 8
    { 0xE9A78CC8, 0x1067D8DE },    // 1xx_Skill_Wizard_ArcaneTorrent 11 -> Skill_Wizard_ArcaneTorrent 8
    { 0xE9A78CC9, 0x1067D8DE },    // 1xx_Skill_Wizard_ArcaneTorrent 12 -> Skill_Wizard_ArcaneTorrent 8
    { 0xE80CD5B8, 0x1067D8D8 },    // 1xx_Skill_Wizard_ArcaneTorrent 2 -> Skill_Wizard_ArcaneTorrent 2
    { 0xE80CD5B9, 0x1067D8D9 },    // 1xx_Skill_Wizard_ArcaneTorrent 3 -> Skill_Wizard_ArcaneTorrent 3
    { 0xE80CD5BA, 0x1067D8DA },    // 1xx_Skill_Wizard_ArcaneTorrent 4 -> Skill_Wizard_ArcaneTorrent 4
    { 0xE80CD5BB, 0x1067D8DB },    // 1xx_Skill_Wizard_ArcaneTorrent 5 -> Skill_Wizard_ArcaneTorrent 5
    { 0xE80CD5BC, 0x1067D8DC },    // 1xx_Skill_Wizard_ArcaneTorrent 6 -> Skill_Wizard_ArcaneTorrent 6
    { 0xE80CD5BD, 0x1067D8DD },    // 1xx_Skill_Wizard_ArcaneTorrent 7 -> Skill_Wizard_ArcaneTorrent 7
    { 0xE80CD5BE, 0x1067D8DE },    // 1xx_Skill_Wizard_ArcaneTorrent 8 -> Skill_Wizard_ArcaneTorrent 8
    { 0xE80CD5BF, 0x1067D8DE },    // 1xx_Skill_Wizard_ArcaneTorrent 9 -> Skill_Wizard_ArcaneTorrent 8
    { 0x562A72DA, 0xFFFFFFFF },    // 1xx_Skill_Wizard_Blizzard 0.1 Legendary -> (none)
    { 0x61851A61, 0x1B09A981 },    // 1xx_Skill_Wizard_Blizzard 1 -> Skill_Wizard_Blizzard 1
    { 0x922866B1, 0x1B09A988 },    // 1xx_Skill_Wizard_Blizzard 10 -> Skill_Wizard_Blizzard 8
    { 0x922866B2, 0x1B09A988 },    // 1xx_Skill_Wizard_Blizzard 11 -> Skill_Wizard_Blizzard 8
    { 0x922866B3, 0x1B09A988 },    // 1xx_Skill_Wizard_Blizzard 12 -> Skill_Wizard_Blizzard 8
    { 0x61851A62, 0x1B09A982 },    // 1xx_Skill_Wizard_Blizzard 2 -> Skill_Wizard_Blizzard 2
    { 0x61851A63, 0x1B09A983 },    // 1xx_Skill_Wizard_Blizzard 3 -> Skill_Wizard_Blizzard 3
    { 0x61851A64, 0x1B09A984 },    // 1xx_Skill_Wizard_Blizzard 4 -> Skill_Wizard_Blizzard 4
    { 0x61851A65, 0x1B09A985 },    // 1xx_Skill_Wizard_Blizzard 5 -> Skill_Wizard_Blizzard 5
    { 0x61851A66, 0x1B09A986 },    // 1xx_Skill_Wizard_Blizzard 6 -> Skill_Wizard_Blizzard 6
    { 0x61851A67, 0x1B09A987 },    // 1xx_Skill_Wizard_Blizzard 7 -> Skill_Wizard_Blizzard 7
    { 0x61851A68, 0x1B09A988 },    // 1xx_Skill_Wizard_Blizzard 8 -> Skill_Wizard_Blizzard 8
    { 0x61851A69, 0x1B09A988 },    // 1xx_Skill_Wizard_Blizzard 9 -> Skill_Wizard_Blizzard 8
    { 0x30A0BE1B, 0xFFFFFFFF },    // 1xx_Skill_Wizard_Disintegrate 0.1 Legendary -> (none)
    { 0x2F5BBC22, 0x28D2DB42 },    // 1xx_Skill_Wizard_Disintegrate 1 -> Skill_Wizard_Disintegrate 1
    { 0x1AD34092, 0x28D2DB49 },    // 1xx_Skill_Wizard_Disintegrate 10 -> Skill_Wizard_Disintegrate 8
    { 0x1AD34093, 0x28D2DB49 },    // 1xx_Skill_Wizard_Disintegrate 11 -> Skill_Wizard_Disintegrate 8
    { 0x1AD34094, 0x28D2DB49 },    // 1xx_Skill_Wizard_Disintegrate 12 -> Skill_Wizard_Disintegrate 8
    { 0x2F5BBC23, 0x28D2DB43 },    // 1xx_Skill_Wizard_Disintegrate 2 -> Skill_Wizard_Disintegrate 2
    { 0x2F5BBC24, 0x28D2DB44 },    // 1xx_Skill_Wizard_Disintegrate 3 -> Skill_Wizard_Disintegrate 3
    { 0x2F5BBC25, 0x28D2DB45 },    // 1xx_Skill_Wizard_Disintegrate 4 -> Skill_Wizard_Disintegrate 4
    { 0x2F5BBC26, 0x28D2DB46 },    // 1xx_Skill_Wizard_Disintegrate 5 -> Skill_Wizard_Disintegrate 5
    { 0x2F5BBC27, 0x28D2DB47 },    // 1xx_Skill_Wizard_Disintegrate 6 -> Skill_Wizard_Disintegrate 6
    { 0x2F5BBC28, 0x28D2DB48 },    // 1xx_Skill_Wizard_Disintegrate 7 -> Skill_Wizard_Disintegrate 7
    { 0x2F5BBC29, 0x28D2DB49 },    // 1xx_Skill_Wizard_Disintegrate 8 -> Skill_Wizard_Disintegrate 8
    { 0x2F5BBC2A, 0x28D2DB49 },    // 1xx_Skill_Wizard_Disintegrate 9 -> Skill_Wizard_Disintegrate 8
    { 0xF652E477, 0xFFFFFFFF },    // 1xx_Skill_Wizard_Electrocute 0.1 Legendary -> (none)
    { 0x4BEC787E, 0x156C339E },    // 1xx_Skill_Wizard_Electrocute 1 -> Skill_Wizard_Electrocute 1
    { 0xC97B886E, 0x156C33A5 },    // 1xx_Skill_Wizard_Electrocute 10 -> Skill_Wizard_Electrocute 8
    { 0xC97B886F, 0x156C33A5 },    // 1xx_Skill_Wizard_Electrocute 11 -> Skill_Wizard_Electrocute 8
    { 0xC97B8870, 0x156C33A5 },    // 1xx_Skill_Wizard_Electrocute 12 -> Skill_Wizard_Electrocute 8
    { 0x4BEC787F, 0x156C339F },    // 1xx_Skill_Wizard_Electrocute 2 -> Skill_Wizard_Electrocute 2
    { 0x4BEC7880, 0x156C33A0 },    // 1xx_Skill_Wizard_Electrocute 3 -> Skill_Wizard_Electrocute 3
    { 0x4BEC7881, 0x156C33A1 },    // 1xx_Skill_Wizard_Electrocute 4 -> Skill_Wizard_Electrocute 4
    { 0x4BEC7882, 0x156C33A2 },    // 1xx_Skill_Wizard_Electrocute 5 -> Skill_Wizard_Electrocute 5
    { 0x4BEC7883, 0x156C33A3 },    // 1xx_Skill_Wizard_Electrocute 6 -> Skill_Wizard_Electrocute 6
    { 0x4BEC7884, 0x156C33A4 },    // 1xx_Skill_Wizard_Electrocute 7 -> Skill_Wizard_Electrocute 7
    { 0x4BEC7885, 0x156C33A5 },    // 1xx_Skill_Wizard_Electrocute 8 -> Skill_Wizard_Electrocute 8
    { 0x4BEC7886, 0x156C33A5 },    // 1xx_Skill_Wizard_Electrocute 9 -> Skill_Wizard_Electrocute 8
    { 0x16128274, 0xFFFFFFFF },    // 1xx_Skill_Wizard_EnergyTwister 0.1 Legendary -> (none)
    { 0xC2FD72FB, 0xEB58761B },    // 1xx_Skill_Wizard_EnergyTwister 1 -> Skill_Wizard_EnergyTwister 1
    { 0x22ABD28B, 0xEB587622 },    // 1xx_Skill_Wizard_EnergyTwister 10 -> Skill_Wizard_EnergyTwister 8
    { 0x22ABD28C, 0xEB587622 },    // 1xx_Skill_Wizard_EnergyTwister 11 -> Skill_Wizard_EnergyTwister 8
    { 0x22ABD28D, 0xEB587622 },    // 1xx_Skill_Wizard_EnergyTwister 12 -> Skill_Wizard_EnergyTwister 8
    { 0xC2FD72FC, 0xEB58761C },    // 1xx_Skill_Wizard_EnergyTwister 2 -> Skill_Wizard_EnergyTwister 2
    { 0xC2FD72FD, 0xEB58761D },    // 1xx_Skill_Wizard_EnergyTwister 3 -> Skill_Wizard_EnergyTwister 3
    { 0xC2FD72FE, 0xEB58761E },    // 1xx_Skill_Wizard_EnergyTwister 4 -> Skill_Wizard_EnergyTwister 4
    { 0xC2FD72FF, 0xEB58761F },    // 1xx_Skill_Wizard_EnergyTwister 5 -> Skill_Wizard_EnergyTwister 5
    { 0xC2FD7300, 0xEB587620 },    // 1xx_Skill_Wizard_EnergyTwister 6 -> Skill_Wizard_EnergyTwister 6
    { 0xC2FD7301, 0xEB587621 },    // 1xx_Skill_Wizard_EnergyTwister 7 -> Skill_Wizard_EnergyTwister 7
    { 0xC2FD7302, 0xEB587622 },    // 1xx_Skill_Wizard_EnergyTwister 8 -> Skill_Wizard_EnergyTwister 8
    { 0xC2FD7303, 0xEB587622 },    // 1xx_Skill_Wizard_EnergyTwister 9 -> Skill_Wizard_EnergyTwister 8
    { 0xF183742D, 0xFFFFFFFF },    // 1xx_Skill_Wizard_ExplosiveBlast 0.1 Legendary -> (none)
    { 0x18E74734, 0x4CA2AE54 },    // 1xx_Skill_Wizard_ExplosiveBlast 1 -> Skill_Wizard_ExplosiveBlast 1
    { 0x35D02DE4, 0x4CA2AE5B },    // 1xx_Skill_Wizard_ExplosiveBlast 10 -> Skill_Wizard_ExplosiveBlast 8
    { 0x35D02DE5, 0x4CA2AE5B },    // 1xx_Skill_Wizard_ExplosiveBlast 11 -> Skill_Wizard_ExplosiveBlast 8
    { 0x35D02DE6, 0x4CA2AE5B },    // 1xx_Skill_Wizard_ExplosiveBlast 12 -> Skill_Wizard_ExplosiveBlast 8
    { 0x18E74735, 0x4CA2AE55 },    // 1xx_Skill_Wizard_ExplosiveBlast 2 -> Skill_Wizard_ExplosiveBlast 2
    { 0x18E74736, 0x4CA2AE56 },    // 1xx_Skill_Wizard_ExplosiveBlast 3 -> Skill_Wizard_ExplosiveBlast 3
    { 0x18E74737, 0x4CA2AE57 },    // 1xx_Skill_Wizard_ExplosiveBlast 4 -> Skill_Wizard_ExplosiveBlast 4
    { 0x18E74738, 0x4CA2AE58 },    // 1xx_Skill_Wizard_ExplosiveBlast 5 -> Skill_Wizard_ExplosiveBlast 5
    { 0x18E74739, 0x4CA2AE59 },    // 1xx_Skill_Wizard_ExplosiveBlast 6 -> Skill_Wizard_ExplosiveBlast 6
    { 0x18E7473A, 0x4CA2AE5A },    // 1xx_Skill_Wizard_ExplosiveBlast 7 -> Skill_Wizard_ExplosiveBlast 7
    { 0x18E7473B, 0x4CA2AE5B },    // 1xx_Skill_Wizard_ExplosiveBlast 8 -> Skill_Wizard_ExplosiveBlast 8
    { 0x18E7473C, 0x4CA2AE5B },    // 1xx_Skill_Wizard_ExplosiveBlast 9 -> Skill_Wizard_ExplosiveBlast 8
    { 0x944BF1D0, 0xFFFFFFFF },    // 1xx_Skill_Wizard_Hydra 0.1 Legendary -> (none)
    { 0x981FF857, 0x4FB9DB77 },    // 1xx_Skill_Wizard_Hydra 1 -> Skill_Wizard_Hydra 1
    { 0x9C1F0367, 0x4FB9DB7E },    // 1xx_Skill_Wizard_Hydra 10 -> Skill_Wizard_Hydra 8
    { 0x9C1F0368, 0x4FB9DB7E },    // 1xx_Skill_Wizard_Hydra 11 -> Skill_Wizard_Hydra 8
    { 0x9C1F0369, 0x4FB9DB7E },    // 1xx_Skill_Wizard_Hydra 12 -> Skill_Wizard_Hydra 8
    { 0x981FF858, 0x4FB9DB78 },    // 1xx_Skill_Wizard_Hydra 2 -> Skill_Wizard_Hydra 2
    { 0x981FF859, 0x4FB9DB79 },    // 1xx_Skill_Wizard_Hydra 3 -> Skill_Wizard_Hydra 3
    { 0x981FF85A, 0x4FB9DB7A },    // 1xx_Skill_Wizard_Hydra 4 -> Skill_Wizard_Hydra 4
    { 0x981FF85B, 0x4FB9DB7B },    // 1xx_Skill_Wizard_Hydra 5 -> Skill_Wizard_Hydra 5
    { 0x981FF85C, 0x4FB9DB7C },    // 1xx_Skill_Wizard_Hydra 6 -> Skill_Wizard_Hydra 6
    { 0x981FF85D, 0x4FB9DB7D },    // 1xx_Skill_Wizard_Hydra 7 -> Skill_Wizard_Hydra 7
    { 0x981FF85E, 0x4FB9DB7E },    // 1xx_Skill_Wizard_Hydra 8 -> Skill_Wizard_Hydra 8
    { 0x981FF85F, 0x4FB9DB7E },    // 1xx_Skill_Wizard_Hydra 9 -> Skill_Wizard_Hydra 8
    { 0x3E7858EF, 0xFFFFFFFF },    // 1xx_Skill_Wizard_MagicMissile 0.1 Legendary -> (none)
    { 0x720578F6, 0x6B7C9816 },    // 1xx_Skill_Wizard_MagicMissile 1 -> Skill_Wizard_MagicMissile 1
    { 0xB2B497E6, 0x6B7C981D },    // 1xx_Skill_Wizard_MagicMissile 10 -> Skill_Wizard_MagicMissile 8
    { 0xB2B497E7, 0x6B7C981D },    // 1xx_Skill_Wizard_MagicMissile 11 -> Skill_Wizard_MagicMissile 8
    { 0xB2B497E8, 0x6B7C981D },    // 1xx_Skill_Wizard_MagicMissile 12 -> Skill_Wizard_MagicMissile 8
    { 0x720578F7, 0x6B7C9817 },    // 1xx_Skill_Wizard_MagicMissile 2 -> Skill_Wizard_MagicMissile 2
    { 0x720578F8, 0x6B7C9818 },    // 1xx_Skill_Wizard_MagicMissile 3 -> Skill_Wizard_MagicMissile 3
    { 0x720578F9, 0x6B7C9819 },    // 1xx_Skill_Wizard_MagicMissile 4 -> Skill_Wizard_MagicMissile 4
    { 0x720578FA, 0x6B7C981A },    // 1xx_Skill_Wizard_MagicMissile 5 -> Skill_Wizard_MagicMissile 5
    { 0x720578FB, 0x6B7C981B },    // 1xx_Skill_Wizard_MagicMissile 6 -> Skill_Wizard_MagicMissile 6
    { 0x720578FC, 0x6B7C981C },    // 1xx_Skill_Wizard_MagicMissile 7 -> Skill_Wizard_MagicMissile 7
    { 0x720578FD, 0x6B7C981D },    // 1xx_Skill_Wizard_MagicMissile 8 -> Skill_Wizard_MagicMissile 8
    { 0x720578FE, 0x6B7C981D },    // 1xx_Skill_Wizard_MagicMissile 9 -> Skill_Wizard_MagicMissile 8
    { 0x8A0E17A4, 0xFFFFFFFF },    // 1xx_Skill_Wizard_Meteor 0.1 Legendary -> (none)
    { 0x5A4BC02B, 0x0522074B },    // 1xx_Skill_Wizard_Meteor 1 -> Skill_Wizard_Meteor 1
    { 0xA3C3C5BB, 0x05220752 },    // 1xx_Skill_Wizard_Meteor 10 -> Skill_Wizard_Meteor 8
    { 0xA3C3C5BC, 0x05220752 },    // 1xx_Skill_Wizard_Meteor 11 -> Skill_Wizard_Meteor 8
    { 0xA3C3C5BD, 0x05220752 },    // 1xx_Skill_Wizard_Meteor 12 -> Skill_Wizard_Meteor 8
    { 0x5A4BC02C, 0x0522074C },    // 1xx_Skill_Wizard_Meteor 2 -> Skill_Wizard_Meteor 2
    { 0x5A4BC02D, 0x0522074D },    // 1xx_Skill_Wizard_Meteor 3 -> Skill_Wizard_Meteor 3
    { 0x5A4BC02E, 0x0522074E },    // 1xx_Skill_Wizard_Meteor 4 -> Skill_Wizard_Meteor 4
    { 0x5A4BC02F, 0x0522074F },    // 1xx_Skill_Wizard_Meteor 5 -> Skill_Wizard_Meteor 5
    { 0x5A4BC030, 0x05220750 },    // 1xx_Skill_Wizard_Meteor 6 -> Skill_Wizard_Meteor 6
    { 0x5A4BC031, 0x05220751 },    // 1xx_Skill_Wizard_Meteor 7 -> Skill_Wizard_Meteor 7
    { 0x5A4BC032, 0x05220752 },    // 1xx_Skill_Wizard_Meteor 8 -> Skill_Wizard_Meteor 8
    { 0x5A4BC033, 0x05220752 },    // 1xx_Skill_Wizard_Meteor 9 -> Skill_Wizard_Meteor 8
    { 0x2EDC8E67, 0xFFFFFFFF },    // 1xx_Skill_Wizard_RayofFrost 0.1 Legendary -> (none)
    { 0x7773BA6E, 0xA458918E },    // 1xx_Skill_Wizard_RayofFrost 1 -> Skill_Wizard_RayofFrost 1
    { 0x65EB085E, 0xA4589195 },    // 1xx_Skill_Wizard_RayofFrost 10 -> Skill_Wizard_RayofFrost 8
    { 0x65EB085F, 0xA4589195 },    // 1xx_Skill_Wizard_RayofFrost 11 -> Skill_Wizard_RayofFrost 8
    { 0x65EB0860, 0xA4589195 },    // 1xx_Skill_Wizard_RayofFrost 12 -> Skill_Wizard_RayofFrost 8
    { 0x7773BA6F, 0xA458918F },    // 1xx_Skill_Wizard_RayofFrost 2 -> Skill_Wizard_RayofFrost 2
    { 0x7773BA70, 0xA4589190 },    // 1xx_Skill_Wizard_RayofFrost 3 -> Skill_Wizard_RayofFrost 3
    { 0x7773BA71, 0xA4589191 },    // 1xx_Skill_Wizard_RayofFrost 4 -> Skill_Wizard_RayofFrost 4
    { 0x7773BA72, 0xA4589192 },    // 1xx_Skill_Wizard_RayofFrost 5 -> Skill_Wizard_RayofFrost 5
    { 0x7773BA73, 0xA4589193 },    // 1xx_Skill_Wizard_RayofFrost 6 -> Skill_Wizard_RayofFrost 6
    { 0x7773BA74, 0xA4589194 },    // 1xx_Skill_Wizard_RayofFrost 7 -> Skill_Wizard_RayofFrost 7
    { 0x7773BA75, 0xA4589195 },    // 1xx_Skill_Wizard_RayofFrost 8 -> Skill_Wizard_RayofFrost 8
    { 0x7773BA76, 0xA4589195 },    // 1xx_Skill_Wizard_RayofFrost 9 -> Skill_Wizard_RayofFrost 8
    { 0x95B7ECB9, 0xFFFFFFFF },    // 1xx_Skill_Wizard_ShockPulse 0.1 Legendary -> (none)
    { 0x55898DC0, 0x826E64E0 },    // 1xx_Skill_Wizard_ShockPulse 1 -> Skill_Wizard_ShockPulse 1
    { 0x06BB45F0, 0x826E64E7 },    // 1xx_Skill_Wizard_ShockPulse 10 -> Skill_Wizard_ShockPulse 8
    { 0x06BB45F1, 0x826E64E7 },    // 1xx_Skill_Wizard_ShockPulse 11 -> Skill_Wizard_ShockPulse 8
    { 0x06BB45F2, 0x826E64E7 },    // 1xx_Skill_Wizard_ShockPulse 12 -> Skill_Wizard_ShockPulse 8
    { 0x55898DC1, 0x826E64E1 },    // 1xx_Skill_Wizard_ShockPulse 2 -> Skill_Wizard_ShockPulse 2
    { 0x55898DC2, 0x826E64E2 },    // 1xx_Skill_Wizard_ShockPulse 3 -> Skill_Wizard_ShockPulse 3
    { 0x55898DC3, 0x826E64E3 },    // 1xx_Skill_Wizard_ShockPulse 4 -> Skill_Wizard_ShockPulse 4
    { 0x55898DC4, 0x826E64E4 },    // 1xx_Skill_Wizard_ShockPulse 5 -> Skill_Wizard_ShockPulse 5
    { 0x55898DC5, 0x826E64E5 },    // 1xx_Skill_Wizard_ShockPulse 6 -> Skill_Wizard_ShockPulse 6
    { 0x55898DC6, 0x826E64E6 },    // 1xx_Skill_Wizard_ShockPulse 7 -> Skill_Wizard_ShockPulse 7
    { 0x55898DC7, 0x826E64E7 },    // 1xx_Skill_Wizard_ShockPulse 8 -> Skill_Wizard_ShockPulse 8
    { 0x55898DC8, 0x826E64E7 },    // 1xx_Skill_Wizard_ShockPulse 9 -> Skill_Wizard_ShockPulse 8
    { 0x0E116D4E, 0xFFFFFFFF },    // 1xx_Skill_Wizard_SpectralBlade 0.1 Legendary -> (none)
    { 0xF9F9C6D5, 0x2254C9F5 },    // 1xx_Skill_Wizard_SpectralBlade 1 -> Skill_Wizard_SpectralBlade 1
    { 0x3932A1A5, 0x2254C9FC },    // 1xx_Skill_Wizard_SpectralBlade 10 -> Skill_Wizard_SpectralBlade 8
    { 0x3932A1A6, 0x2254C9FC },    // 1xx_Skill_Wizard_SpectralBlade 11 -> Skill_Wizard_SpectralBlade 8
    { 0x3932A1A7, 0x2254C9FC },    // 1xx_Skill_Wizard_SpectralBlade 12 -> Skill_Wizard_SpectralBlade 8
    { 0xF9F9C6D6, 0x2254C9F6 },    // 1xx_Skill_Wizard_SpectralBlade 2 -> Skill_Wizard_SpectralBlade 2
    { 0xF9F9C6D7, 0x2254C9F7 },    // 1xx_Skill_Wizard_SpectralBlade 3 -> Skill_Wizard_SpectralBlade 3
    { 0xF9F9C6D8, 0x2254C9F8 },    // 1xx_Skill_Wizard_SpectralBlade 4 -> Skill_Wizard_SpectralBlade 4
    { 0xF9F9C6D9, 0x2254C9F9 },    // 1xx_Skill_Wizard_SpectralBlade 5 -> Skill_Wizard_SpectralBlade 5
    { 0xF9F9C6DA, 0x2254C9FA },    // 1xx_Skill_Wizard_SpectralBlade 6 -> Skill_Wizard_SpectralBlade 6
    { 0xF9F9C6DB, 0x2254C9FB },    // 1xx_Skill_Wizard_SpectralBlade 7 -> Skill_Wizard_SpectralBlade 7
    { 0xF9F9C6DC, 0x2254C9FC },    // 1xx_Skill_Wizard_SpectralBlade 8 -> Skill_Wizard_SpectralBlade 8
    { 0xF9F9C6DD, 0x2254C9FC },    // 1xx_Skill_Wizard_SpectralBlade 9 -> Skill_Wizard_SpectralBlade 8
    { 0xF41A982D, 0xE0FFEB4D },    // 1xx_Sockets Amulet I -> Sockets Amulet I
    { 0x776D9E36, 0x00FD5556 },    // 1xx_Sockets Amulet II -> Sockets Amulet II
    { 0x6521655F, 0x20A8007F },    // 1xx_Sockets Amulet III -> Sockets Amulet III
    { 0x776D9E43, 0x00FD5563 },    // 1xx_Sockets Amulet IV -> Sockets Amulet IV
    { 0xF41A983A, 0xE0FFEB5A },    // 1xx_Sockets Amulet V -> Sockets Amulet V
    { 0x7A18E8EC, 0xC14EF40C },    // 1xx_Sockets Belt I -> Sockets Belt I
    { 0xBD3606D5, 0xEB2D75F5 },    // 1xx_Sockets Belt II -> Sockets Belt II
    { 0x63F6E1DE, 0x50DC34FE },    // 1xx_Sockets Belt III -> Sockets Belt III
    { 0xBD3606E2, 0xEB2D7602 },    // 1xx_Sockets Belt IV -> Sockets Belt IV
    { 0x7A18E8F9, 0xC14EF419 },    // 1xx_Sockets Belt V -> Sockets Belt V
    { 0x31F58B34, 0x1EDADE54 },    // 1xx_Sockets Bracer I -> Sockets Bracer I
    { 0x70A6F21D, 0xFA36A93D },    // 1xx_Sockets Bracer II -> Sockets Bracer II
    { 0x85853626, 0x410BD146 },    // 1xx_Sockets Bracer III -> Sockets Bracer III
    { 0x70A6F22A, 0xFA36A94A },    // 1xx_Sockets Bracer IV -> Sockets Bracer IV
    { 0x31F58B41, 0x1EDADE61 },    // 1xx_Sockets Bracer V -> Sockets Bracer V
    { 0x10B1E17C, 0x3EA9509C },    // 1xx_Sockets Chest I -> Sockets Chest I
    { 0x26EE1165, 0x13D36485 },    // 1xx_Sockets Chest II -> Sockets Chest II
    { 0x04B03E6E, 0x8E3FF58E },    // 1xx_Sockets Chest III -> Sockets Chest III
    { 0x26EE1172, 0x13D36492 },    // 1xx_Sockets Chest IV -> Sockets Chest IV
    { 0x10B1E189, 0x3EA950A9 },    // 1xx_Sockets Chest V -> Sockets Chest V
    { 0x8817BEEB, 0xCF4DCA0B },    // 1xx_Sockets Helm I -> Sockets Helm I
    { 0x8B0F9CB4, 0xB9070BD4 },    // 1xx_Sockets Helm II -> Sockets Helm II
    { 0xED03339D, 0xD9E886BD },    // 1xx_Sockets Helm III -> Sockets Helm III
    { 0x8B0F9CC1, 0xB9070BE1 },    // 1xx_Sockets Helm IV -> Sockets Helm IV
    { 0x8817BEF8, 0xCF4DCA18 },    // 1xx_Sockets Helm V -> Sockets Helm V
    { 0xB0DA2865, 0x8A34BF85 },    // 1xx_Sockets I -> Sockets I
    { 0xCC1F356E, 0xD0CCB08E },    // 1xx_Sockets II -> Sockets II
    { 0x5005E397, 0xEA62C2B7 },    // 1xx_Sockets III -> Sockets III
    { 0xCC1F357B, 0xD0CCB09B },    // 1xx_Sockets IV -> Sockets IV
    { 0xCC1F357D, 0xD0CCB09D },    // 1xx_Sockets IX -> Sockets IX
    { 0xF35F5FBE, 0xE044B2DE },    // 1xx_Sockets Shield I -> Sockets Shield I
    { 0x5F4B57E7, 0xE8DB0F07 },    // 1xx_Sockets Shield II -> Sockets Shield II
    { 0x48B65530, 0x043CF050 },    // 1xx_Sockets Shield III -> Sockets Shield III
    { 0x5F4B57F4, 0xE8DB0F14 },    // 1xx_Sockets Shield IV -> Sockets Shield IV
    { 0xF35F5FCB, 0xE044B2EB },    // 1xx_Sockets Shield V -> Sockets Shield V
    { 0xB0DA2872, 0x8A34BF92 },    // 1xx_Sockets V -> Sockets V
    { 0xCC1F371B, 0xD0CCB23B },    // 1xx_Sockets VI -> Sockets VI
    { 0x50061AE4, 0xEA62FA04 },    // 1xx_Sockets VII -> Sockets VII
    { 0x50C977CD, 0x36C23AED },    // 1xx_Sockets VIII -> Sockets VIII
    { 0xB0DA2874, 0x8A34BF94 },    // 1xx_Sockets X -> Sockets X
    { 0xCC1F375D, 0xD0CCB27D },    // 1xx_Sockets XI -> Sockets XI
    { 0x50062366, 0xEA630286 },    // 1xx_Sockets XII -> Sockets XII
    { 0x50CA908F, 0x36C353AF },    // 1xx_Sockets XIII -> Sockets XIII
    { 0x50062373, 0xEA630293 },    // 1xx_Sockets XIV -> Sockets XIV
    { 0xCC1F376A, 0xD0CCB28A },    // 1xx_Sockets XV -> Sockets XV
    { 0x50062513, 0xEA630433 },    // 1xx_Sockets XVI -> Sockets XVI
    { 0x50CAC7DC, 0x36C38AFC },    // 1xx_Sockets XVII -> Sockets XVII
    { 0xFA0CE539, 0x9F1E0C59 },    // 1xx_SpiritHeals 1 -> SpiritHeals 1
    { 0x3BA98C89, 0x82DF97A9 },    // 1xx_SpiritHeals 10 -> SpiritHeals 10
    { 0x3BA98C8A, 0x82DF97A9 },    // 1xx_SpiritHeals 11 -> SpiritHeals 10
    { 0x3BA98C8B, 0x82DF97A9 },    // 1xx_SpiritHeals 12 -> SpiritHeals 10
    { 0x3BA98C8C, 0x82DF97A9 },    // 1xx_SpiritHeals 13 -> SpiritHeals 10
    { 0x3BA98C8D, 0x82DF97A9 },    // 1xx_SpiritHeals 14 -> SpiritHeals 10
    { 0xFA0CE53A, 0x9F1E0C5A },    // 1xx_SpiritHeals 2 -> SpiritHeals 2
    { 0xFA0CE53B, 0x9F1E0C5B },    // 1xx_SpiritHeals 3 -> SpiritHeals 3
    { 0xFA0CE53C, 0x9F1E0C5C },    // 1xx_SpiritHeals 4 -> SpiritHeals 4
    { 0xFA0CE53D, 0x9F1E0C5D },    // 1xx_SpiritHeals 5 -> SpiritHeals 5
    { 0xFA0CE53E, 0x9F1E0C5E },    // 1xx_SpiritHeals 6 -> SpiritHeals 6
    { 0xFA0CE53F, 0x9F1E0C5F },    // 1xx_SpiritHeals 7 -> SpiritHeals 7
    { 0xFA0CE540, 0x9F1E0C60 },    // 1xx_SpiritHeals 8 -> SpiritHeals 8
    { 0xFA0CE541, 0x9F1E0C61 },    // 1xx_SpiritHeals 9 -> SpiritHeals 9
    { 0xFC3BEBDD, 0xA14D12FD },    // 1xx_SpiritRegen 1 -> SpiritRegen 1
    { 0x83B967AD, 0xCAEF72CD },    // 1xx_SpiritRegen 10 -> SpiritRegen 10
    { 0x83B967AE, 0xCAEF72CD },    // 1xx_SpiritRegen 11 -> SpiritRegen 10
    { 0x83B967AF, 0xCAEF72CD },    // 1xx_SpiritRegen 12 -> SpiritRegen 10
    { 0x83B967B0, 0xCAEF72CD },    // 1xx_SpiritRegen 13 -> SpiritRegen 10
    { 0x83B967B1, 0xCAEF72CD },    // 1xx_SpiritRegen 14 -> SpiritRegen 10
    { 0xFC3BEBDE, 0xA14D12FE },    // 1xx_SpiritRegen 2 -> SpiritRegen 2
    { 0xFC3BEBDF, 0xA14D12FF },    // 1xx_SpiritRegen 3 -> SpiritRegen 3
    { 0xFC3BEBE0, 0xA14D1300 },    // 1xx_SpiritRegen 4 -> SpiritRegen 4
    { 0xFC3BEBE1, 0xA14D1301 },    // 1xx_SpiritRegen 5 -> SpiritRegen 5
    { 0xFC3BEBE2, 0xA14D1302 },    // 1xx_SpiritRegen 6 -> SpiritRegen 6
    { 0xFC3BEBE3, 0xA14D1303 },    // 1xx_SpiritRegen 7 -> SpiritRegen 7
    { 0xFC3BEBE4, 0xA14D1304 },    // 1xx_SpiritRegen 8 -> SpiritRegen 8
    { 0xFC3BEBE5, 0xA14D1305 },    // 1xx_SpiritRegen 9 -> SpiritRegen 9
    { 0x05F6800A, 0x0862872A },    // 1xx_Str 1 -> Str 1
    { 0xDC989E72, 0x0A900D92 },    // 1xx_Str 1 Secondary -> Str 1 Secondary
    { 0xD0DAE695, 0xBDC039B5 },    // 1xx_Str 1 Two-Handed -> Str 1 Two-Handed
    { 0xC4C6817A, 0x14B36C9A },    // 1xx_Str 10 -> Str 10
    { 0x14AD2BE2, 0x01927F02 },    // 1xx_Str 10 Secondary -> Str 10 Secondary
    { 0x0B812205, 0x9510D925 },    // 1xx_Str 10 Two-Handed -> Str 10 Two-Handed
    { 0xC4C6817B, 0x14B36C9B },    // 1xx_Str 11 -> Str 11
    { 0x9A09E123, 0x86EF3443 },    // 1xx_Str 11 Secondary -> Str 11 Secondary
    { 0x3C747F66, 0xC6043686 },    // 1xx_Str 11 Two-Handed -> Str 11 Two-Handed
    { 0xC4C6817C, 0x14B36C9C },    // 1xx_Str 12 -> Str 12
    { 0x1F669664, 0x0C4BE984 },    // 1xx_Str 12 Secondary -> Str 12 Secondary
    { 0x6D67DCC7, 0xF6F793E7 },    // 1xx_Str 12 Two-Handed -> Str 12 Two-Handed
    { 0xC4C6817D, 0x14B36C9D },    // 1xx_Str 13 -> Str 13
    { 0xA4C34BA5, 0x91A89EC5 },    // 1xx_Str 13 Secondary -> Str 13 Secondary
    { 0x9E5B3A28, 0x27EAF148 },    // 1xx_Str 13 Two-Handed -> Str 13 Two-Handed
    { 0xC4C6817E, 0x14B36C9E },    // 1xx_Str 14 -> Str 14
    { 0x2A2000E6, 0x17055406 },    // 1xx_Str 14 Secondary -> Str 14 Secondary
    { 0xCF4E9789, 0x58DE4EA9 },    // 1xx_Str 14 Two-Handed -> Str 14 Two-Handed
    { 0xDA1A1478, 0xFFFFFFFF },    // 1xx_Str 14_Archon -> (none)
    { 0xC4C6817F, 0x14B36C9F },    // 1xx_Str 15 -> Str 15
    { 0xAF7CB627, 0x9C620947 },    // 1xx_Str 15 Secondary -> Str 15 Secondary
    { 0x0041F4EA, 0x89D1AC0A },    // 1xx_Str 15 Two-Handed -> Str 15 Two-Handed
    { 0xC4C68180, 0x14B36CA0 },    // 1xx_Str 16 -> Str 16
    { 0x34D96B68, 0x21BEBE88 },    // 1xx_Str 16 Secondary -> Str 16 Secondary
    { 0x3135524B, 0xBAC5096B },    // 1xx_Str 16 Two-Handed -> Str 16 Two-Handed
    { 0xC4C68181, 0x14B36CA1 },    // 1xx_Str 17 -> Str 17
    { 0xBA3620A9, 0xA71B73C9 },    // 1xx_Str 17 Secondary -> Str 17 Secondary
    { 0x6228AFAC, 0xBAC5096B },    // 1xx_Str 17 Two-Handed -> Str 16 Two-Handed
    { 0x05F6800B, 0x0862872B },    // 1xx_Str 2 -> Str 2
    { 0x61F553B3, 0x8FECC2D3 },    // 1xx_Str 2 Secondary -> Str 2 Secondary
    { 0x01CE43F6, 0xEEB39716 },    // 1xx_Str 2 Two-Handed -> Str 2 Two-Handed
    { 0x05F6800C, 0x0862872C },    // 1xx_Str 3 -> Str 3
    { 0xE75208F4, 0x15497814 },    // 1xx_Str 3 Secondary -> Str 3 Secondary
    { 0x32C1A157, 0x1FA6F477 },    // 1xx_Str 3 Two-Handed -> Str 3 Two-Handed
    { 0x05F6800D, 0x0862872D },    // 1xx_Str 4 -> Str 4
    { 0x6CAEBE35, 0x9AA62D55 },    // 1xx_Str 4 Secondary -> Str 4 Secondary
    { 0x63B4FEB8, 0x509A51D8 },    // 1xx_Str 4 Two-Handed -> Str 4 Two-Handed
    { 0x05F6800E, 0x0862872E },    // 1xx_Str 5 -> Str 5
    { 0xF20B7376, 0x2002E296 },    // 1xx_Str 5 Secondary -> Str 5 Secondary
    { 0x94A85C19, 0x818DAF39 },    // 1xx_Str 5 Two-Handed -> Str 5 Two-Handed
    { 0x05F6800F, 0x0862872F },    // 1xx_Str 6 -> Str 6
    { 0x776828B7, 0xA55F97D7 },    // 1xx_Str 6 Secondary -> Str 6 Secondary
    { 0xC59BB97A, 0xB2810C9A },    // 1xx_Str 6 Two-Handed -> Str 6 Two-Handed
    { 0x05F68010, 0x08628730 },    // 1xx_Str 7 -> Str 7
    { 0xFCC4DDF8, 0x2ABC4D18 },    // 1xx_Str 7 Secondary -> Str 7 Secondary
    { 0xF68F16DB, 0xE37469FB },    // 1xx_Str 7 Two-Handed -> Str 7 Two-Handed
    { 0x05F68011, 0x08628731 },    // 1xx_Str 8 -> Str 8
    { 0x82219339, 0xB0190259 },    // 1xx_Str 8 Secondary -> Str 8 Secondary
    { 0x2782743C, 0x1467C75C },    // 1xx_Str 8 Two-Handed -> Str 8 Two-Handed
    { 0x05F68012, 0x08628732 },    // 1xx_Str 9 -> Str 9
    { 0x077E487A, 0x3575B79A },    // 1xx_Str 9 Secondary -> Str 9 Secondary
    { 0x5875D19D, 0x455B24BD },    // 1xx_Str 9 Two-Handed -> Str 9 Two-Handed
    { 0x42C4EC04, 0xFFFFFFFF },    // 1xx_StrDex 0.1 Legendary -> (none)
    { 0x5596A651, 0xFFFFFFFF },    // 1xx_StrDex 0.1 Secondary -> (none)
    { 0x450332EF, 0xFFFFFFFF },    // 1xx_StrDex 0.1 Two-Handed Legendary -> (none)
    { 0x155904C3, 0x142D37E3 },    // 1xx_StrDex I -> StrDex I
    { 0x3BEF1E6B, 0xF775B98B },    // 1xx_StrDex I Secondary -> StrDex I Secondary
    { 0x1B0165AE, 0x475B64CE },    // 1xx_StrDex I Two-Handed -> StrDex I Two-Handed
    { 0xC0799D8C, 0x99D434AC },    // 1xx_StrDex II -> StrDex II
    { 0x10780674, 0x3CD20594 },    // 1xx_StrDex II Secondary -> StrDex II Secondary
    { 0x80A74ED7, 0x384131F7 },    // 1xx_StrDex II Two-Handed -> StrDex II Two-Handed
    { 0xCFAD4F75, 0xD45ACA95 },    // 1xx_StrDex III -> StrDex III
    { 0x761DEF9D, 0x2DB7D2BD },    // 1xx_StrDex III Secondary -> StrDex III Secondary
    { 0x9B0A5D20, 0x45E0A440 },    // 1xx_StrDex III Two-Handed -> StrDex III Two-Handed
    { 0xC0799D99, 0x99D434B9 },    // 1xx_StrDex IV -> StrDex IV
    { 0xD62D3AC1, 0x028739E1 },    // 1xx_StrDex IV Secondary -> StrDex IV Secondary
    { 0xFD030CC4, 0xB49CEFE4 },    // 1xx_StrDex IV Two-Handed -> StrDex IV Two-Handed
    { 0xC0799D9B, 0x99D434BB },    // 1xx_StrDex IX -> StrDex IX
    { 0xE0E6A543, 0x0D40A463 },    // 1xx_StrDex IX Secondary -> StrDex IX Secondary
    { 0x5EE9C786, 0x1683AAA6 },    // 1xx_StrDex IX Two-Handed -> StrDex IX Two-Handed
    { 0x155904D0, 0x142D37F0 },    // 1xx_StrDex V -> StrDex V
    { 0x01A452B8, 0xBD2AEDD8 },    // 1xx_StrDex V Secondary -> StrDex V Secondary
    { 0x975D239B, 0xC3B722BB },    // 1xx_StrDex V Two-Handed -> StrDex V Two-Handed
    { 0xC0799F39, 0x99D43659 },    // 1xx_StrDex VI -> StrDex VI
    { 0x8CD3C461, 0xB92DC381 },    // 1xx_StrDex VI Secondary -> StrDex VI Secondary
    { 0x887ACA64, 0x4014AD84 },    // 1xx_StrDex VI Two-Handed -> StrDex VI Two-Handed
    { 0xCFAD86C2, 0xD45B01E2 },    // 1xx_StrDex VII -> StrDex VII
    { 0x7DF16B2A, 0x358B4E4A },    // 1xx_StrDex VII Secondary -> StrDex VII Secondary
    { 0x9D4D4A4D, 0x4823916D },    // 1xx_StrDex VII Two-Handed -> StrDex VII Two-Handed
    { 0xC55E5F6B, 0x5FBB3E8B },    // 1xx_StrDex VIII -> StrDex VIII
    { 0x92C3EB13, 0x3D9A3233 },    // 1xx_StrDex VIII Secondary -> StrDex VIII Secondary
    { 0x4C6FC756, 0x520EF276 },    // 1xx_StrDex VIII Two-Handed -> StrDex VIII Two-Handed
    { 0x155904D2, 0x142D37F2 },    // 1xx_StrDex X -> StrDex X
    { 0x0C5DBD3A, 0xC7E4585A },    // 1xx_StrDex X Secondary -> StrDex X Secondary
    { 0xF943DE5D, 0x259DDD7D },    // 1xx_StrDex X Two-Handed -> StrDex X Two-Handed
    { 0xC0799F7B, 0x99D4369B },    // 1xx_StrDex XI -> StrDex XI
    { 0xEEBA7F23, 0x1B147E43 },    // 1xx_StrDex XI Secondary -> StrDex XI Secondary
    { 0x2738DD66, 0xDED2C086 },    // 1xx_StrDex XI Two-Handed -> StrDex XI Two-Handed
    { 0xCFAD8F44, 0xD45B0A64 },    // 1xx_StrDex XII -> StrDex XII
    { 0x1CAF7E2C, 0xD449614C },    // 1xx_StrDex XII Secondary -> StrDex XII Secondary
    { 0x13CDBD8F, 0xBEA404AF },    // 1xx_StrDex XII Two-Handed -> StrDex XII Two-Handed
    { 0x01C6F3EE, 0xFFFFFFFF },    // 1xx_StrInt 0.1 Legendary -> (none)
    { 0x3A394396, 0xFFFFFFFF },    // 1xx_StrInt 0.1 Secondary Legendary -> (none)
    { 0xC4C63499, 0xFFFFFFFF },    // 1xx_StrInt 0.1 Two-Handed Legendary -> (none)
    { 0x15B85DAD, 0x148C90CD },    // 1xx_StrInt I -> StrInt I
    { 0x441A23D5, 0xFFA0BEF5 },    // 1xx_StrInt I Secondary -> StrInt I Secondary
    { 0x288D1858, 0x54E71778 },    // 1xx_StrInt I Two-Handed -> StrInt I Two-Handed
    { 0xCCC413B6, 0xA61EAAD6 },    // 1xx_StrInt II -> StrInt II
    { 0x1E03B91E, 0x4A5DB83E },    // 1xx_StrInt II Secondary -> StrInt II Secondary
    { 0x3FA956C1, 0xF74339E1 },    // 1xx_StrInt II Two-Handed -> StrInt II Two-Handed
    { 0x65468ADF, 0x69F405FF },    // 1xx_StrInt III -> StrInt III
    { 0x351FF787, 0xECB9DAA7 },    // 1xx_StrInt III Secondary -> StrInt III Secondary
    { 0x3A4D624A, 0xE523A96A },    // 1xx_StrInt III Two-Handed -> StrInt III Two-Handed
    { 0xCCC413C3, 0xA61EAAE3 },    // 1xx_StrInt IV -> StrInt IV
    { 0xE3B8ED6B, 0x1012EC8B },    // 1xx_StrInt IV Secondary -> StrInt IV Secondary
    { 0xBC0514AE, 0x739EF7CE },    // 1xx_StrInt IV Two-Handed -> StrInt IV Two-Handed
    { 0xCCC413C5, 0xA61EAAE5 },    // 1xx_StrInt IX -> StrInt IX
    { 0xEE7257ED, 0x1ACC570D },    // 1xx_StrInt IX Secondary -> StrInt IX Secondary
    { 0x1DEBCF70, 0xD585B290 },    // 1xx_StrInt IX Two-Handed -> StrInt IX Two-Handed
    { 0x15B85DBA, 0x148C90DA },    // 1xx_StrInt V -> StrInt V
    { 0x09CF5822, 0xC555F342 },    // 1xx_StrInt V Secondary -> StrInt V Secondary
    { 0xA4E8D645, 0xD142D565 },    // 1xx_StrInt V Two-Handed -> StrInt V Two-Handed
    { 0xCCC41563, 0xA61EAC83 },    // 1xx_StrInt VI -> StrInt VI
    { 0x9A5F770B, 0xC6B9762B },    // 1xx_StrInt VI Secondary -> StrInt VI Secondary
    { 0x477CD24E, 0xFF16B56E },    // 1xx_StrInt VI Two-Handed -> StrInt VI Two-Handed
    { 0x6546C22C, 0x69F43D4C },    // 1xx_StrInt VII -> StrInt VII
    { 0x3CF37314, 0xF48D5634 },    // 1xx_StrInt VII Secondary -> StrInt VII Secondary
    { 0x3C904F77, 0xE7669697 },    // 1xx_StrInt VII Two-Handed -> StrInt VII Two-Handed
    { 0x0E1F0815, 0xA87BE735 },    // 1xx_StrInt VIII -> StrInt VIII
    { 0x3206F03D, 0xDCDD375D },    // 1xx_StrInt VIII Secondary -> StrInt VIII Secondary
    { 0xD41371C0, 0xD9B29CE0 },    // 1xx_StrInt VIII Two-Handed -> StrInt VIII Two-Handed
    { 0x15B85DBC, 0x148C90DC },    // 1xx_StrInt X -> StrInt X
    { 0x1488C2A4, 0xD00F5DC4 },    // 1xx_StrInt X Secondary -> StrInt X Secondary
    { 0x06CF9107, 0x33299027 },    // 1xx_StrInt X Two-Handed -> StrInt X Two-Handed
    { 0xCCC415A5, 0xA61EACC5 },    // 1xx_StrInt XI -> StrInt XI
    { 0xFC4631CD, 0x28A030ED },    // 1xx_StrInt XI Secondary -> StrInt XI Secondary
    { 0xE63AE550, 0x9DD4C870 },    // 1xx_StrInt XI Two-Handed -> StrInt XI Two-Handed
    { 0x6546CAAE, 0x69F445CE },    // 1xx_StrInt XII -> StrInt XII
    { 0xDBB18616, 0x934B6936 },    // 1xx_StrInt XII Secondary -> StrInt XII Secondary
    { 0xB310C2B9, 0x5DE709D9 },    // 1xx_StrInt XII Two-Handed -> StrInt XII Two-Handed
    { 0x39CDB096, 0xFFFFFFFF },    // 1xx_StrVit 0.1 Legendary -> (none)
    { 0x0554B841, 0xFFFFFFFF },    // 1xx_StrVit 0.1 Two-Handed Legendary -> (none)
    { 0x0688BE76, 0xFFFFFFFF },    // 1xx_StrVit 0.I Secondary Legendary -> (none)
    { 0x16A0DE55, 0x15751175 },    // 1xx_StrVit I -> StrVit I
    { 0x6679967D, 0x2200319D },    // 1xx_StrVit I Secondary -> StrVit I Secondary
    { 0x96DAE000, 0xC334DF20 },    // 1xx_StrVit I Two-Handed -> StrVit I Two-Handed
    { 0xEABCA95E, 0xC417407E },    // 1xx_StrVit II -> StrVit II
    { 0x8C5180C6, 0xB8AB7FE6 },    // 1xx_StrVit II Secondary -> StrVit II Secondary
    { 0x77B01369, 0x2F49F689 },    // 1xx_StrVit II Two-Handed -> StrVit II Two-Handed
    { 0x4251D587, 0x46FF50A7 },    // 1xx_StrVit III -> StrVit III
    { 0x6D26B42F, 0x24C0974F },    // 1xx_StrVit III Secondary -> StrVit III Secondary
    { 0x732BB3F2, 0x1E01FB12 },    // 1xx_StrVit III Two-Handed -> StrVit III Two-Handed
    { 0xEABCA96B, 0xC417408B },    // 1xx_StrVit IV -> StrVit IV
    { 0x5206B513, 0x7E60B433 },    // 1xx_StrVit IV Secondary -> StrVit IV Secondary
    { 0xF40BD156, 0xABA5B476 },    // 1xx_StrVit IV Two-Handed -> StrVit IV Two-Handed
    { 0xEABCA96D, 0xC417408D },    // 1xx_StrVit IX -> StrVit IX
    { 0x5CC01F95, 0x891A1EB5 },    // 1xx_StrVit IX Secondary -> StrVit IX Secondary
    { 0x55F28C18, 0x0D8C6F38 },    // 1xx_StrVit IX Two-Handed -> StrVit IX Two-Handed
    { 0x16A0DE62, 0x15751182 },    // 1xx_StrVit V -> StrVit V
    { 0x2C2ECACA, 0xE7B565EA },    // 1xx_StrVit V Secondary -> StrVit V Secondary
    { 0x13369DED, 0x3F909D0D },    // 1xx_StrVit V Two-Handed -> StrVit V Two-Handed
    { 0xEABCAB0B, 0xC417422B },    // 1xx_StrVit VI -> StrVit VI
    { 0x08AD3EB3, 0x35073DD3 },    // 1xx_StrVit VI Secondary -> StrVit VI Secondary
    { 0x7F838EF6, 0x371D7216 },    // 1xx_StrVit VI Two-Handed -> StrVit VI Two-Handed
    { 0x42520CD4, 0x46FF87F4 },    // 1xx_StrVit VII -> StrVit VII
    { 0x74FA2FBC, 0x2C9412DC },    // 1xx_StrVit VII Secondary -> StrVit VII Secondary
    { 0x756EA11F, 0x2044E83F },    // 1xx_StrVit VII Two-Handed -> StrVit VII Two-Handed
    { 0x8C93A7BD, 0x26F086DD },    // 1xx_StrVit VIII -> StrVit VIII
    { 0x6AE541E5, 0x15BB8905 },    // 1xx_StrVit VIII Secondary -> StrVit VIII Secondary
    { 0x28BBF868, 0x2E5B2388 },    // 1xx_StrVit VIII Two-Handed -> StrVit VIII Two-Handed
    { 0x16A0DE64, 0x15751184 },    // 1xx_StrVit X -> StrVit X
    { 0x36E8354C, 0xF26ED06C },    // 1xx_StrVit X Secondary -> StrVit X Secondary
    { 0x751D58AF, 0xA17757CF },    // 1xx_StrVit X Two-Handed -> StrVit X Two-Handed
    { 0xEABCAB4D, 0xC417426D },    // 1xx_StrVit XI -> StrVit XI
    { 0x6A93F975, 0x96EDF895 },    // 1xx_StrVit XI Secondary -> StrVit XI Secondary
    { 0x1E41A1F8, 0xD5DB8518 },    // 1xx_StrVit XI Two-Handed -> StrVit XI Two-Handed
    { 0x42521556, 0x46FF9076 },    // 1xx_StrVit XII -> StrVit XII
    { 0x13B842BE, 0xCB5225DE },    // 1xx_StrVit XII Secondary -> StrVit XII Secondary
    { 0xEBEF1461, 0x96C55B81 },    // 1xx_StrVit XII Two-Handed -> StrVit XII Two-Handed
    { 0x4299A17A, 0x89CFAC9A },    // 1xx_Superior Armor -> Superior Armor
    { 0x72BF13FA, 0x2A58F71A },    // 1xx_Superior Armor Def 1 -> Superior Armor Def 1
    { 0x72BF13FB, 0x2A58F71B },    // 1xx_Superior Armor Def 2 -> Superior Armor Def 2
    { 0x72BF13FC, 0x2A58F71C },    // 1xx_Superior Armor Def 3 -> Superior Armor Def 3
    { 0x72BF13FD, 0x2A58F71D },    // 1xx_Superior Armor Def 4 -> Superior Armor Def 4
    { 0x72BF13FE, 0x2A58F71E },    // 1xx_Superior Armor Def 5 -> Superior Armor Def 5
    { 0x72BF13FF, 0x2A58F71F },    // 1xx_Superior Armor Def 6 -> Superior Armor Def 6
    { 0x898C80D4, 0x131C37F4 },    // 1xx_Superior Weapon 1 -> Superior Weapon 1
    { 0x898C80D5, 0x131C37F5 },    // 1xx_Superior Weapon 2 -> Superior Weapon 2
    { 0x898C80D6, 0x131C37F6 },    // 1xx_Superior Weapon 3 -> Superior Weapon 3
    { 0x898C80D7, 0x131C37F7 },    // 1xx_Superior Weapon 4 -> Superior Weapon 4
    { 0x898C80D8, 0x131C37F8 },    // 1xx_Superior Weapon 5 -> Superior Weapon 5
    { 0x898C80D9, 0x131C37F9 },    // 1xx_Superior Weapon 6 -> Superior Weapon 6
    { 0x898C80DA, 0x131C37FA },    // 1xx_Superior Weapon 7 -> Superior Weapon 7
    { 0x6C2F583E, 0x35AF135E },    // 1xx_Superior Weapon Crit Dmg 1 -> Superior Weapon Crit Dmg 1
    { 0x6C2F583F, 0x35AF135F },    // 1xx_Superior Weapon Crit Dmg 2 -> Superior Weapon Crit Dmg 2
    { 0x6C2F5840, 0x35AF1360 },    // 1xx_Superior Weapon Crit Dmg 3 -> Superior Weapon Crit Dmg 3
    { 0x6C2F5841, 0x35AF1361 },    // 1xx_Superior Weapon Crit Dmg 4 -> Superior Weapon Crit Dmg 4
    { 0x6C2F5842, 0x35AF1362 },    // 1xx_Superior Weapon Crit Dmg 5 -> Superior Weapon Crit Dmg 5
    { 0x6C2F5843, 0x35AF1363 },    // 1xx_Superior Weapon Crit Dmg 6 -> Superior Weapon Crit Dmg 6
    { 0x0E79D1D2, 0xF89044F2 },    // 1xx_Superior Weapon MaxDmg 1 -> Superior Weapon MaxDmg 1
    { 0x0E79D1D3, 0xF89044F3 },    // 1xx_Superior Weapon MaxDmg 2 -> Superior Weapon MaxDmg 2
    { 0x0E79D1D4, 0xF89044F4 },    // 1xx_Superior Weapon MaxDmg 3 -> Superior Weapon MaxDmg 3
    { 0x0E79D1D5, 0xF89044F5 },    // 1xx_Superior Weapon MaxDmg 4 -> Superior Weapon MaxDmg 4
    { 0x0E79D1D6, 0xF89044F6 },    // 1xx_Superior Weapon MaxDmg 5 -> Superior Weapon MaxDmg 5
    { 0x0E79D1D7, 0xF89044F7 },    // 1xx_Superior Weapon MaxDmg 6 -> Superior Weapon MaxDmg 6
    { 0x5EF82190, 0x490E94B0 },    // 1xx_Superior Weapon MinDmg 1 -> Superior Weapon MinDmg 1
    { 0x5EF82191, 0x490E94B1 },    // 1xx_Superior Weapon MinDmg 2 -> Superior Weapon MinDmg 2
    { 0x5EF82192, 0x490E94B2 },    // 1xx_Superior Weapon MinDmg 3 -> Superior Weapon MinDmg 3
    { 0x5EF82193, 0x490E94B3 },    // 1xx_Superior Weapon MinDmg 4 -> Superior Weapon MinDmg 4
    { 0x5EF82194, 0x490E94B4 },    // 1xx_Superior Weapon MinDmg 5 -> Superior Weapon MinDmg 5
    { 0x5EF82195, 0x490E94B5 },    // 1xx_Superior Weapon MinDmg 6 -> Superior Weapon MinDmg 6
    { 0x4548FAE5, 0xFECD8A05 },    // 1xx_Superior Weapon Speed 1 -> Superior Weapon Speed 1
    { 0x4548FAE6, 0xFECD8A06 },    // 1xx_Superior Weapon Speed 2 -> Superior Weapon Speed 2
    { 0x4548FAE7, 0xFECD8A07 },    // 1xx_Superior Weapon Speed 3 -> Superior Weapon Speed 3
    { 0x4548FAE8, 0xFECD8A08 },    // 1xx_Superior Weapon Speed 4 -> Superior Weapon Speed 4
    { 0x4548FAE9, 0xFECD8A09 },    // 1xx_Superior Weapon Speed 5 -> Superior Weapon Speed 5
    { 0x4548FAEA, 0xFECD8A0A },    // 1xx_Superior Weapon Speed 6 -> Superior Weapon Speed 6
    { 0x5FE2B7AF, 0x5EB6EACF },    // 1xx_Thorns 1 -> Thorns 1
    { 0x6D366857, 0x28BD0377 },    // 1xx_Thorns 1 Secondary -> Thorns 1 Secondary
    { 0x5C39ADBF, 0x359444DF },    // 1xx_Thorns 10 -> Thorns 10
    { 0xB9043267, 0xE55E3187 },    // 1xx_Thorns 10 Secondary -> Thorns 10 Secondary
    { 0x5C39ADC0, 0x359444E0 },    // 1xx_Thorns 11 -> Thorns 11
    { 0x3E60E7A8, 0x6ABAE6C8 },    // 1xx_Thorns 11 Secondary -> Thorns 11 Secondary
    { 0x5C39ADC1, 0x359444E1 },    // 1xx_Thorns 12 -> Thorns 12
    { 0xC3BD9CE9, 0xF0179C09 },    // 1xx_Thorns 12 Secondary -> Thorns 12 Secondary
    { 0x5C39ADC2, 0x359444E2 },    // 1xx_Thorns 13 -> Thorns 13
    { 0x491A522A, 0x7574514A },    // 1xx_Thorns 13 Secondary -> Thorns 13 Secondary
    { 0x5C39ADC3, 0x359444E3 },    // 1xx_Thorns 14 -> Thorns 14
    { 0xCE77076B, 0xFAD1068B },    // 1xx_Thorns 14 Secondary -> Thorns 14 Secondary
    { 0x5C39ADC4, 0x359444E4 },    // 1xx_Thorns 15 -> Thorns 15
    { 0x53D3BCAC, 0x802DBBCC },    // 1xx_Thorns 15 Secondary -> Thorns 15 Secondary
    { 0x5C39ADC5, 0x359444E4 },    // 1xx_Thorns 16 -> Thorns 15
    { 0xD93071ED, 0x802DBBCC },    // 1xx_Thorns 16 Secondary -> Thorns 15 Secondary
    { 0x5FE2B7B0, 0x5EB6EAD0 },    // 1xx_Thorns 2 -> Thorns 2
    { 0xF2931D98, 0xAE19B8B8 },    // 1xx_Thorns 2 Secondary -> Thorns 2 Secondary
    { 0x5FE2B7B1, 0x5EB6EAD1 },    // 1xx_Thorns 3 -> Thorns 3
    { 0x77EFD2D9, 0x33766DF9 },    // 1xx_Thorns 3 Secondary -> Thorns 3 Secondary
    { 0x5FE2B7B2, 0x5EB6EAD2 },    // 1xx_Thorns 4 -> Thorns 4
    { 0xFD4C881A, 0xB8D3233A },    // 1xx_Thorns 4 Secondary -> Thorns 4 Secondary
    { 0x5FE2B7B3, 0x5EB6EAD3 },    // 1xx_Thorns 5 -> Thorns 5
    { 0x82A93D5B, 0x3E2FD87B },    // 1xx_Thorns 5 Secondary -> Thorns 5 Secondary
    { 0x5FE2B7B4, 0x5EB6EAD4 },    // 1xx_Thorns 6 -> Thorns 6
    { 0x0805F29C, 0xC38C8DBC },    // 1xx_Thorns 6 Secondary -> Thorns 6 Secondary
    { 0x5FE2B7B5, 0x5EB6EAD5 },    // 1xx_Thorns 7 -> Thorns 7
    { 0x8D62A7DD, 0x48E942FD },    // 1xx_Thorns 7 Secondary -> Thorns 7 Secondary
    { 0x5FE2B7B6, 0x5EB6EAD6 },    // 1xx_Thorns 8 -> Thorns 8
    { 0x12BF5D1E, 0xCE45F83E },    // 1xx_Thorns 8 Secondary -> Thorns 8 Secondary
    { 0x5FE2B7B7, 0x5EB6EAD7 },    // 1xx_Thorns 9 -> Thorns 9
    { 0x981C125F, 0x53A2AD7F },    // 1xx_Thorns 9 Secondary -> Thorns 9 Secondary
    { 0x99D94FDE, 0xFFFFFFFF },    // 1xx_(none) -> (none)
    { 0xA10F9FA5, 0xFFFFFFFF },    // 1xx_(none) -> (none)
    { 0x0626C9E4, 0x0892D104 },    // 1xx_Vit 1 -> Vit 1
    { 0xD96A80CC, 0x0761EFEC },    // 1xx_Vit 1 Secondary -> Vit 1 Secondary
    { 0x67E9142F, 0x54CE674F },    // 1xx_Vit 1 Two-Handed -> Vit 1 Two-Handed
    { 0xCB000694, 0x1AECF1B4 },    // 1xx_Vit 10 -> Vit 10
    { 0xABBB597C, 0x98A0AC9C },    // 1xx_Vit 10 Secondary -> Vit 10 Secondary
    { 0x845502DF, 0x0DE4B9FF },    // 1xx_Vit 10 Two-Handed -> Vit 10 Two-Handed
    { 0xCB000695, 0x1AECF1B5 },    // 1xx_Vit 11 -> Vit 11
    { 0x31180EBD, 0x1DFD61DD },    // 1xx_Vit 11 Secondary -> Vit 11 Secondary
    { 0xB5486040, 0x3ED81760 },    // 1xx_Vit 11 Two-Handed -> Vit 11 Two-Handed
    { 0xCB000696, 0x1AECF1B6 },    // 1xx_Vit 12 -> Vit 12
    { 0xB674C3FE, 0xA35A171E },    // 1xx_Vit 12 Secondary -> Vit 12 Secondary
    { 0xE63BBDA1, 0x6FCB74C1 },    // 1xx_Vit 12 Two-Handed -> Vit 12 Two-Handed
    { 0xCB000697, 0x1AECF1B7 },    // 1xx_Vit 13 -> Vit 13
    { 0x3BD1793F, 0x28B6CC5F },    // 1xx_Vit 13 Secondary -> Vit 13 Secondary
    { 0x172F1B02, 0xA0BED222 },    // 1xx_Vit 13 Two-Handed -> Vit 13 Two-Handed
    { 0xCB000698, 0x1AECF1B8 },    // 1xx_Vit 14 -> Vit 14
    { 0xC12E2E80, 0xAE1381A0 },    // 1xx_Vit 14 Secondary -> Vit 14 Secondary
    { 0x48227863, 0xD1B22F83 },    // 1xx_Vit 14 Two-Handed -> Vit 14 Two-Handed
    { 0xB87B9852, 0xFFFFFFFF },    // 1xx_Vit 14_Archon -> (none)
    { 0xCB000699, 0x1AECF1B9 },    // 1xx_Vit 15 -> Vit 15
    { 0x468AE3C1, 0x337036E1 },    // 1xx_Vit 15 Secondary -> Vit 15 Secondary
    { 0x7915D5C4, 0x02A58CE4 },    // 1xx_Vit 15 Two-Handed -> Vit 15 Two-Handed
    { 0xCB00069A, 0x1AECF1BA },    // 1xx_Vit 16 -> Vit 16
    { 0xCBE79902, 0xB8CCEC22 },    // 1xx_Vit 16 Secondary -> Vit 16 Secondary
    { 0xAA093325, 0x3398EA45 },    // 1xx_Vit 16 Two-Handed -> Vit 16 Two-Handed
    { 0xCB00069B, 0x1AECF1BB },    // 1xx_Vit 17 -> Vit 17
    { 0x51444E43, 0x3E29A163 },    // 1xx_Vit 17 Secondary -> Vit 17 Secondary
    { 0xDAFC9086, 0x3398EA45 },    // 1xx_Vit 17 Two-Handed -> Vit 16 Two-Handed
    { 0x0626C9E5, 0x0892D105 },    // 1xx_Vit 2 -> Vit 2
    { 0x5EC7360D, 0x8CBEA52D },    // 1xx_Vit 2 Secondary -> Vit 2 Secondary
    { 0x98DC7190, 0x85C1C4B0 },    // 1xx_Vit 2 Two-Handed -> Vit 2 Two-Handed
    { 0x0626C9E6, 0x0892D106 },    // 1xx_Vit 3 -> Vit 3
    { 0xE423EB4E, 0x121B5A6E },    // 1xx_Vit 3 Secondary -> Vit 3 Secondary
    { 0xC9CFCEF1, 0xB6B52211 },    // 1xx_Vit 3 Two-Handed -> Vit 3 Two-Handed
    { 0x0626C9E7, 0x0892D107 },    // 1xx_Vit 4 -> Vit 4
    { 0x6980A08F, 0x97780FAF },    // 1xx_Vit 4 Secondary -> Vit 4 Secondary
    { 0xFAC32C52, 0xE7A87F72 },    // 1xx_Vit 4 Two-Handed -> Vit 4 Two-Handed
    { 0x0626C9E8, 0x0892D108 },    // 1xx_Vit 5 -> Vit 5
    { 0xEEDD55D0, 0x1CD4C4F0 },    // 1xx_Vit 5 Secondary -> Vit 5 Secondary
    { 0x2BB689B3, 0x189BDCD3 },    // 1xx_Vit 5 Two-Handed -> Vit 5 Two-Handed
    { 0x0626C9E9, 0x0892D109 },    // 1xx_Vit 6 -> Vit 6
    { 0x743A0B11, 0xA2317A31 },    // 1xx_Vit 6 Secondary -> Vit 6 Secondary
    { 0x5CA9E714, 0x498F3A34 },    // 1xx_Vit 6 Two-Handed -> Vit 6 Two-Handed
    { 0x0626C9EA, 0x0892D10A },    // 1xx_Vit 7 -> Vit 7
    { 0xF996C052, 0x278E2F72 },    // 1xx_Vit 7 Secondary -> Vit 7 Secondary
    { 0x8D9D4475, 0x7A829795 },    // 1xx_Vit 7 Two-Handed -> Vit 7 Two-Handed
    { 0x0626C9EB, 0x0892D10B },    // 1xx_Vit 8 -> Vit 8
    { 0x7EF37593, 0xACEAE4B3 },    // 1xx_Vit 8 Secondary -> Vit 8 Secondary
    { 0xBE90A1D6, 0xAB75F4F6 },    // 1xx_Vit 8 Two-Handed -> Vit 8 Two-Handed
    { 0x0626C9EC, 0x0892D10C },    // 1xx_Vit 9 -> Vit 9
    { 0x04502AD4, 0x324799F4 },    // 1xx_Vit 9 Secondary -> Vit 9 Secondary
    { 0xEF83FF37, 0xDC695257 },    // 1xx_Vit 9 Two-Handed -> Vit 9 Two-Handed
    { 0x26E9AADB, 0xFFFFFFFF },    // 1xx_WeaponHitBlind1h 0.1 Legendary -> (none)
    { 0x044B88E2, 0xBFD22402 },    // 1xx_WeaponHitBlind1h 1 -> WeaponHitBlind1h 1
    { 0x8DBCA552, 0xBA16A472 },    // 1xx_WeaponHitBlind1h 10 -> WeaponHitBlind1h 10
    { 0x8DBCA553, 0xBA16A473 },    // 1xx_WeaponHitBlind1h 11 -> WeaponHitBlind1h 11
    { 0x8DBCA554, 0xBA16A474 },    // 1xx_WeaponHitBlind1h 12 -> WeaponHitBlind1h 12
    { 0x8DBCA555, 0xBA16A474 },    // 1xx_WeaponHitBlind1h 13 -> WeaponHitBlind1h 12
    { 0x8DBCA556, 0xBA16A474 },    // 1xx_WeaponHitBlind1h 14 -> WeaponHitBlind1h 12
    { 0x8DBCA557, 0xBA16A474 },    // 1xx_WeaponHitBlind1h 15 -> WeaponHitBlind1h 12
    { 0x8DBCA558, 0xBA16A474 },    // 1xx_WeaponHitBlind1h 16 -> WeaponHitBlind1h 12
    { 0x044B88E3, 0xBFD22403 },    // 1xx_WeaponHitBlind1h 2 -> WeaponHitBlind1h 2
    { 0x044B88E4, 0xBFD22404 },    // 1xx_WeaponHitBlind1h 3 -> WeaponHitBlind1h 3
    { 0x044B88E5, 0xBFD22405 },    // 1xx_WeaponHitBlind1h 4 -> WeaponHitBlind1h 4
    { 0x044B88E6, 0xBFD22406 },    // 1xx_WeaponHitBlind1h 5 -> WeaponHitBlind1h 5
    { 0x044B88E7, 0xBFD22407 },    // 1xx_WeaponHitBlind1h 6 -> WeaponHitBlind1h 6
    { 0x044B88E8, 0xBFD22408 },    // 1xx_WeaponHitBlind1h 7 -> WeaponHitBlind1h 7
    { 0x044B88E9, 0xBFD22409 },    // 1xx_WeaponHitBlind1h 8 -> WeaponHitBlind1h 8
    { 0x044B88EA, 0xBFD2240A },    // 1xx_WeaponHitBlind1h 9 -> WeaponHitBlind1h 9
    { 0x331ED0BC, 0xFFFFFFFF },    // 1xx_WeaponHitBlind2h 0.1 Legendary -> (none)
    { 0x044C1543, 0xBFD2B063 },    // 1xx_WeaponHitBlind2h 1 -> WeaponHitBlind2h 1
    { 0x8DCEBDD3, 0xBA28BCF3 },    // 1xx_WeaponHitBlind2h 10 -> WeaponHitBlind2h 10
    { 0x8DCEBDD4, 0xBA28BCF4 },    // 1xx_WeaponHitBlind2h 11 -> WeaponHitBlind2h 11
    { 0x8DCEBDD5, 0xBA28BCF5 },    // 1xx_WeaponHitBlind2h 12 -> WeaponHitBlind2h 12
    { 0x8DCEBDD6, 0xBA28BCF5 },    // 1xx_WeaponHitBlind2h 13 -> WeaponHitBlind2h 12
    { 0x8DCEBDD7, 0xBA28BCF5 },    // 1xx_WeaponHitBlind2h 14 -> WeaponHitBlind2h 12
    { 0x8DCEBDD8, 0xBA28BCF5 },    // 1xx_WeaponHitBlind2h 15 -> WeaponHitBlind2h 12
    { 0x8DCEBDD9, 0xBA28BCF5 },    // 1xx_WeaponHitBlind2h 16 -> WeaponHitBlind2h 12
    { 0x044C1544, 0xBFD2B064 },    // 1xx_WeaponHitBlind2h 2 -> WeaponHitBlind2h 2
    { 0x044C1545, 0xBFD2B065 },    // 1xx_WeaponHitBlind2h 3 -> WeaponHitBlind2h 3
    { 0x044C1546, 0xBFD2B066 },    // 1xx_WeaponHitBlind2h 4 -> WeaponHitBlind2h 4
    { 0x044C1547, 0xBFD2B067 },    // 1xx_WeaponHitBlind2h 5 -> WeaponHitBlind2h 5
    { 0x044C1548, 0xBFD2B068 },    // 1xx_WeaponHitBlind2h 6 -> WeaponHitBlind2h 6
    { 0x044C1549, 0xBFD2B069 },    // 1xx_WeaponHitBlind2h 7 -> WeaponHitBlind2h 7
    { 0x044C154A, 0xBFD2B06A },    // 1xx_WeaponHitBlind2h 8 -> WeaponHitBlind2h 8
    { 0x044C154B, 0xBFD2B06B },    // 1xx_WeaponHitBlind2h 9 -> WeaponHitBlind2h 9
    { 0x01FCB79E, 0xFFFFFFFF },    // 1xx_WeaponHitChill1h 0.1 Legendary -> (none)
    { 0xC3A71925, 0x7F2DB445 },    // 1xx_WeaponHitChill1h 1 -> WeaponHitChill1h 1
    { 0x388A3DF5, 0x64E43D15 },    // 1xx_WeaponHitChill1h 10 -> WeaponHitChill1h 10
    { 0x388A3DF6, 0x64E43D16 },    // 1xx_WeaponHitChill1h 11 -> WeaponHitChill1h 11
    { 0x388A3DF7, 0x64E43D17 },    // 1xx_WeaponHitChill1h 12 -> WeaponHitChill1h 12
    { 0x388A3DF8, 0x64E43D17 },    // 1xx_WeaponHitChill1h 13 -> WeaponHitChill1h 12
    { 0x388A3DF9, 0x64E43D17 },    // 1xx_WeaponHitChill1h 14 -> WeaponHitChill1h 12
    { 0x388A3DFA, 0x64E43D17 },    // 1xx_WeaponHitChill1h 15 -> WeaponHitChill1h 12
    { 0x388A3DFB, 0x64E43D17 },    // 1xx_WeaponHitChill1h 16 -> WeaponHitChill1h 12
    { 0xC3A71926, 0x7F2DB446 },    // 1xx_WeaponHitChill1h 2 -> WeaponHitChill1h 2
    { 0xC3A71927, 0x7F2DB447 },    // 1xx_WeaponHitChill1h 3 -> WeaponHitChill1h 3
    { 0xC3A71928, 0x7F2DB448 },    // 1xx_WeaponHitChill1h 4 -> WeaponHitChill1h 4
    { 0xC3A71929, 0x7F2DB449 },    // 1xx_WeaponHitChill1h 5 -> WeaponHitChill1h 5
    { 0xC3A7192A, 0x7F2DB44A },    // 1xx_WeaponHitChill1h 6 -> WeaponHitChill1h 6
    { 0xC3A7192B, 0x7F2DB44B },    // 1xx_WeaponHitChill1h 7 -> WeaponHitChill1h 7
    { 0xC3A7192C, 0x7F2DB44C },    // 1xx_WeaponHitChill1h 8 -> WeaponHitChill1h 8
    { 0xC3A7192D, 0x7F2DB44D },    // 1xx_WeaponHitChill1h 9 -> WeaponHitChill1h 9
    { 0x0E31DD7F, 0xFFFFFFFF },    // 1xx_WeaponHitChill2h 0.1 Legendary -> (none)
    { 0xC3A7A586, 0x7F2E40A6 },    // 1xx_WeaponHitChill2h 1 -> WeaponHitChill2h 1
    { 0x389C5676, 0x64F65596 },    // 1xx_WeaponHitChill2h 10 -> WeaponHitChill2h 10
    { 0x389C5677, 0x64F65597 },    // 1xx_WeaponHitChill2h 11 -> WeaponHitChill2h 11
    { 0x389C5678, 0x64F65598 },    // 1xx_WeaponHitChill2h 12 -> WeaponHitChill2h 12
    { 0x389C5679, 0x64F65598 },    // 1xx_WeaponHitChill2h 13 -> WeaponHitChill2h 12
    { 0x389C567A, 0x64F65598 },    // 1xx_WeaponHitChill2h 14 -> WeaponHitChill2h 12
    { 0x389C567B, 0x64F65598 },    // 1xx_WeaponHitChill2h 15 -> WeaponHitChill2h 12
    { 0x389C567C, 0x64F65598 },    // 1xx_WeaponHitChill2h 16 -> WeaponHitChill2h 12
    { 0xC3A7A587, 0x7F2E40A7 },    // 1xx_WeaponHitChill2h 2 -> WeaponHitChill2h 2
    { 0xC3A7A588, 0x7F2E40A8 },    // 1xx_WeaponHitChill2h 3 -> WeaponHitChill2h 3
    { 0xC3A7A589, 0x7F2E40A9 },    // 1xx_WeaponHitChill2h 4 -> WeaponHitChill2h 4
    { 0xC3A7A58A, 0x7F2E40AA },    // 1xx_WeaponHitChill2h 5 -> WeaponHitChill2h 5
    { 0xC3A7A58B, 0x7F2E40AB },    // 1xx_WeaponHitChill2h 6 -> WeaponHitChill2h 6
    { 0xC3A7A58C, 0x7F2E40AC },    // 1xx_WeaponHitChill2h 7 -> WeaponHitChill2h 7
    { 0xC3A7A58D, 0x7F2E40AD },    // 1xx_WeaponHitChill2h 8 -> WeaponHitChill2h 8
    { 0xC3A7A58E, 0x7F2E40AE },    // 1xx_WeaponHitChill2h 9 -> WeaponHitChill2h 9
    { 0x42D1B0B0, 0xFFFFFFFF },    // 1xx_WeaponHitFear1h 0.1 Legendary -> (none)
    { 0xD1686737, 0x5AF81E57 },    // 1xx_WeaponHitFear1h 1 -> WeaponHitFear1h 1
    { 0xFE754E47, 0xB9FBE967 },    // 1xx_WeaponHitFear1h 10 -> WeaponHitFear1h 10
    { 0xFE754E48, 0xB9FBE968 },    // 1xx_WeaponHitFear1h 11 -> WeaponHitFear1h 11
    { 0xFE754E49, 0xB9FBE969 },    // 1xx_WeaponHitFear1h 12 -> WeaponHitFear1h 12
    { 0xFE754E4A, 0xB9FBE969 },    // 1xx_WeaponHitFear1h 13 -> WeaponHitFear1h 12
    { 0xFE754E4B, 0xB9FBE969 },    // 1xx_WeaponHitFear1h 14 -> WeaponHitFear1h 12
    { 0xFE754E4C, 0xB9FBE969 },    // 1xx_WeaponHitFear1h 15 -> WeaponHitFear1h 12
    { 0xFE754E4D, 0xB9FBE969 },    // 1xx_WeaponHitFear1h 16 -> WeaponHitFear1h 12
    { 0xD1686738, 0x5AF81E58 },    // 1xx_WeaponHitFear1h 2 -> WeaponHitFear1h 2
    { 0xD1686739, 0x5AF81E59 },    // 1xx_WeaponHitFear1h 3 -> WeaponHitFear1h 3
    { 0xD168673A, 0x5AF81E5A },    // 1xx_WeaponHitFear1h 4 -> WeaponHitFear1h 4
    { 0xD168673B, 0x5AF81E5B },    // 1xx_WeaponHitFear1h 5 -> WeaponHitFear1h 5
    { 0xD168673C, 0x5AF81E5C },    // 1xx_WeaponHitFear1h 6 -> WeaponHitFear1h 6
    { 0xD168673D, 0x5AF81E5D },    // 1xx_WeaponHitFear1h 7 -> WeaponHitFear1h 7
    { 0xD168673E, 0x5AF81E5E },    // 1xx_WeaponHitFear1h 8 -> WeaponHitFear1h 8
    { 0xD168673F, 0x5AF81E5F },    // 1xx_WeaponHitFear1h 9 -> WeaponHitFear1h 9
    { 0x4F06D691, 0xFFFFFFFF },    // 1xx_WeaponHitFear2h 0.1 Legendary -> (none)
    { 0xD168F398, 0x5AF8AAB8 },    // 1xx_WeaponHitFear2h 1 -> WeaponHitFear2h 1
    { 0xFE8766C8, 0xBA0E01E8 },    // 1xx_WeaponHitFear2h 10 -> WeaponHitFear2h 10
    { 0xFE8766C9, 0xBA0E01E9 },    // 1xx_WeaponHitFear2h 11 -> WeaponHitFear2h 11
    { 0xFE8766CA, 0xBA0E01EA },    // 1xx_WeaponHitFear2h 12 -> WeaponHitFear2h 12
    { 0xFE8766CB, 0xBA0E01EA },    // 1xx_WeaponHitFear2h 13 -> WeaponHitFear2h 12
    { 0xFE8766CC, 0xBA0E01EA },    // 1xx_WeaponHitFear2h 14 -> WeaponHitFear2h 12
    { 0xFE8766CD, 0xBA0E01EA },    // 1xx_WeaponHitFear2h 15 -> WeaponHitFear2h 12
    { 0xFE8766CE, 0xBA0E01EA },    // 1xx_WeaponHitFear2h 16 -> WeaponHitFear2h 12
    { 0xD168F399, 0x5AF8AAB9 },    // 1xx_WeaponHitFear2h 2 -> WeaponHitFear2h 2
    { 0xD168F39A, 0x5AF8AABA },    // 1xx_WeaponHitFear2h 3 -> WeaponHitFear2h 3
    { 0xD168F39B, 0x5AF8AABB },    // 1xx_WeaponHitFear2h 4 -> WeaponHitFear2h 4
    { 0xD168F39C, 0x5AF8AABC },    // 1xx_WeaponHitFear2h 5 -> WeaponHitFear2h 5
    { 0xD168F39D, 0x5AF8AABD },    // 1xx_WeaponHitFear2h 6 -> WeaponHitFear2h 6
    { 0xD168F39E, 0x5AF8AABE },    // 1xx_WeaponHitFear2h 7 -> WeaponHitFear2h 7
    { 0xD168F39F, 0x5AF8AABF },    // 1xx_WeaponHitFear2h 8 -> WeaponHitFear2h 8
    { 0xD168F3A0, 0x5AF8AAC0 },    // 1xx_WeaponHitFear2h 9 -> WeaponHitFear2h 9
    { 0xC01D6ED3, 0xFFFFFFFF },    // 1xx_WeaponHitFreeze1h 0.1 Legendary -> (none)
    { 0x29DF98DA, 0x563997FA },    // 1xx_WeaponHitFreeze1h 1 -> WeaponHitFreeze1h 1
    { 0x65D2B44A, 0x1D6C976A },    // 1xx_WeaponHitFreeze1h 10 -> WeaponHitFreeze1h 10
    { 0x65D2B44B, 0x1D6C976B },    // 1xx_WeaponHitFreeze1h 11 -> WeaponHitFreeze1h 11
    { 0x65D2B44C, 0x1D6C976C },    // 1xx_WeaponHitFreeze1h 12 -> WeaponHitFreeze1h 12
    { 0x65D2B44D, 0x1D6C976C },    // 1xx_WeaponHitFreeze1h 13 -> WeaponHitFreeze1h 12
    { 0x65D2B44E, 0x1D6C976C },    // 1xx_WeaponHitFreeze1h 14 -> WeaponHitFreeze1h 12
    { 0x65D2B44F, 0x1D6C976C },    // 1xx_WeaponHitFreeze1h 15 -> WeaponHitFreeze1h 12
    { 0x65D2B450, 0x1D6C976C },    // 1xx_WeaponHitFreeze1h 16 -> WeaponHitFreeze1h 12
    { 0x29DF98DB, 0x563997FB },    // 1xx_WeaponHitFreeze1h 2 -> WeaponHitFreeze1h 2
    { 0x29DF98DC, 0x563997FC },    // 1xx_WeaponHitFreeze1h 3 -> WeaponHitFreeze1h 3
    { 0x29DF98DD, 0x563997FD },    // 1xx_WeaponHitFreeze1h 4 -> WeaponHitFreeze1h 4
    { 0x29DF98DE, 0x563997FE },    // 1xx_WeaponHitFreeze1h 5 -> WeaponHitFreeze1h 5
    { 0x29DF98DF, 0x563997FF },    // 1xx_WeaponHitFreeze1h 6 -> WeaponHitFreeze1h 6
    { 0x29DF98E0, 0x56399800 },    // 1xx_WeaponHitFreeze1h 7 -> WeaponHitFreeze1h 7
    { 0x29DF98E1, 0x56399801 },    // 1xx_WeaponHitFreeze1h 8 -> WeaponHitFreeze1h 8
    { 0x29DF98E2, 0x56399802 },    // 1xx_WeaponHitFreeze1h 9 -> WeaponHitFreeze1h 9
    { 0xCC5294B4, 0xFFFFFFFF },    // 1xx_WeaponHitFreeze2h 0.1 Legendary -> (none)
    { 0x29E0253B, 0x563A245B },    // 1xx_WeaponHitFreeze2h 1 -> WeaponHitFreeze2h 1
    { 0x65E4CCCB, 0x1D7EAFEB },    // 1xx_WeaponHitFreeze2h 10 -> WeaponHitFreeze2h 10
    { 0x65E4CCCC, 0x1D7EAFEC },    // 1xx_WeaponHitFreeze2h 11 -> WeaponHitFreeze2h 11
    { 0x65E4CCCD, 0x1D7EAFED },    // 1xx_WeaponHitFreeze2h 12 -> WeaponHitFreeze2h 12
    { 0x65E4CCCE, 0x1D7EAFED },    // 1xx_WeaponHitFreeze2h 13 -> WeaponHitFreeze2h 12
    { 0x65E4CCCF, 0x1D7EAFED },    // 1xx_WeaponHitFreeze2h 14 -> WeaponHitFreeze2h 12
    { 0x65E4CCD0, 0x1D7EAFED },    // 1xx_WeaponHitFreeze2h 15 -> WeaponHitFreeze2h 12
    { 0x65E4CCD1, 0x1D7EAFED },    // 1xx_WeaponHitFreeze2h 16 -> WeaponHitFreeze2h 12
    { 0x29E0253C, 0x563A245C },    // 1xx_WeaponHitFreeze2h 2 -> WeaponHitFreeze2h 2
    { 0x29E0253D, 0x563A245D },    // 1xx_WeaponHitFreeze2h 3 -> WeaponHitFreeze2h 3
    { 0x29E0253E, 0x563A245E },    // 1xx_WeaponHitFreeze2h 4 -> WeaponHitFreeze2h 4
    { 0x29E0253F, 0x563A245F },    // 1xx_WeaponHitFreeze2h 5 -> WeaponHitFreeze2h 5
    { 0x29E02540, 0x563A2460 },    // 1xx_WeaponHitFreeze2h 6 -> WeaponHitFreeze2h 6
    { 0x29E02541, 0x563A2461 },    // 1xx_WeaponHitFreeze2h 7 -> WeaponHitFreeze2h 7
    { 0x29E02542, 0x563A2462 },    // 1xx_WeaponHitFreeze2h 8 -> WeaponHitFreeze2h 8
    { 0x29E02543, 0x563A2463 },    // 1xx_WeaponHitFreeze2h 9 -> WeaponHitFreeze2h 9
    { 0xC779F663, 0xFFFFFFFF },    // 1xx_WeaponHitImmobilize1h 0.1 Legendary -> (none)
    { 0xB848486A, 0x71CCD78A },    // 1xx_WeaponHitImmobilize1h 1 -> WeaponHitImmobilize1h 1
    { 0xC15155DA, 0xAB67C8FA },    // 1xx_WeaponHitImmobilize1h 10 -> WeaponHitImmobilize1h 10
    { 0xC15155DB, 0xAB67C8FB },    // 1xx_WeaponHitImmobilize1h 11 -> WeaponHitImmobilize1h 11
    { 0xC15155DC, 0xAB67C8FC },    // 1xx_WeaponHitImmobilize1h 12 -> WeaponHitImmobilize1h 12
    { 0xC15155DD, 0xAB67C8FC },    // 1xx_WeaponHitImmobilize1h 13 -> WeaponHitImmobilize1h 12
    { 0xC15155DE, 0xAB67C8FC },    // 1xx_WeaponHitImmobilize1h 14 -> WeaponHitImmobilize1h 12
    { 0xC15155DF, 0xAB67C8FC },    // 1xx_WeaponHitImmobilize1h 15 -> WeaponHitImmobilize1h 12
    { 0xC15155E0, 0xAB67C8FC },    // 1xx_WeaponHitImmobilize1h 16 -> WeaponHitImmobilize1h 12
    { 0xB848486B, 0x71CCD78B },    // 1xx_WeaponHitImmobilize1h 2 -> WeaponHitImmobilize1h 2
    { 0xB848486C, 0x71CCD78C },    // 1xx_WeaponHitImmobilize1h 3 -> WeaponHitImmobilize1h 3
    { 0xB848486D, 0x71CCD78D },    // 1xx_WeaponHitImmobilize1h 4 -> WeaponHitImmobilize1h 4
    { 0xB848486E, 0x71CCD78E },    // 1xx_WeaponHitImmobilize1h 5 -> WeaponHitImmobilize1h 5
    { 0xB848486F, 0x71CCD78F },    // 1xx_WeaponHitImmobilize1h 6 -> WeaponHitImmobilize1h 6
    { 0xB8484870, 0x71CCD790 },    // 1xx_WeaponHitImmobilize1h 7 -> WeaponHitImmobilize1h 7
    { 0xB8484871, 0x71CCD791 },    // 1xx_WeaponHitImmobilize1h 8 -> WeaponHitImmobilize1h 8
    { 0xB8484872, 0x71CCD792 },    // 1xx_WeaponHitImmobilize1h 9 -> WeaponHitImmobilize1h 9
    { 0xD3AF1C44, 0xFFFFFFFF },    // 1xx_WeaponHitImmobilize2h 0.1 Legendary -> (none)
    { 0xB848D4CB, 0x71CD63EB },    // 1xx_WeaponHitImmobilize2h 1 -> WeaponHitImmobilize2h 1
    { 0xC1636E5B, 0xAB79E17B },    // 1xx_WeaponHitImmobilize2h 10 -> WeaponHitImmobilize2h 10
    { 0xC1636E5C, 0xAB79E17C },    // 1xx_WeaponHitImmobilize2h 11 -> WeaponHitImmobilize2h 11
    { 0xC1636E5D, 0xAB79E17D },    // 1xx_WeaponHitImmobilize2h 12 -> WeaponHitImmobilize2h 12
    { 0xC1636E5E, 0xAB79E17D },    // 1xx_WeaponHitImmobilize2h 13 -> WeaponHitImmobilize2h 12
    { 0xC1636E5F, 0xAB79E17D },    // 1xx_WeaponHitImmobilize2h 14 -> WeaponHitImmobilize2h 12
    { 0xC1636E60, 0xAB79E17D },    // 1xx_WeaponHitImmobilize2h 15 -> WeaponHitImmobilize2h 12
    { 0xC1636E61, 0xAB79E17D },    // 1xx_WeaponHitImmobilize2h 16 -> WeaponHitImmobilize2h 12
    { 0xB848D4CC, 0x71CD63EC },    // 1xx_WeaponHitImmobilize2h 2 -> WeaponHitImmobilize2h 2
    { 0xB848D4CD, 0x71CD63ED },    // 1xx_WeaponHitImmobilize2h 3 -> WeaponHitImmobilize2h 3
    { 0xB848D4CE, 0x71CD63EE },    // 1xx_WeaponHitImmobilize2h 4 -> WeaponHitImmobilize2h 4
    { 0xB848D4CF, 0x71CD63EF },    // 1xx_WeaponHitImmobilize2h 5 -> WeaponHitImmobilize2h 5
    { 0xB848D4D0, 0x71CD63F0 },    // 1xx_WeaponHitImmobilize2h 6 -> WeaponHitImmobilize2h 6
    { 0xB848D4D1, 0x71CD63F1 },    // 1xx_WeaponHitImmobilize2h 7 -> WeaponHitImmobilize2h 7
    { 0xB848D4D2, 0x71CD63F2 },    // 1xx_WeaponHitImmobilize2h 8 -> WeaponHitImmobilize2h 8
    { 0xB848D4D3, 0x71CD63F3 },    // 1xx_WeaponHitImmobilize2h 9 -> WeaponHitImmobilize2h 9
    { 0x26DC15B9, 0xFFFFFFFF },    // 1xx_WeaponHitKnockback1h 0.1 Legendary -> (none)
    { 0xEC6836C0, 0xF20761E0 },    // 1xx_WeaponHitKnockback1h 1 -> WeaponHitKnockback1h 1
    { 0x796F0EF0, 0x32F39E10 },    // 1xx_WeaponHitKnockback1h 10 -> WeaponHitKnockback1h 10
    { 0x796F0EF1, 0x32F39E11 },    // 1xx_WeaponHitKnockback1h 11 -> WeaponHitKnockback1h 11
    { 0x796F0EF2, 0x32F39E12 },    // 1xx_WeaponHitKnockback1h 12 -> WeaponHitKnockback1h 12
    { 0x796F0EF3, 0x32F39E12 },    // 1xx_WeaponHitKnockback1h 13 -> WeaponHitKnockback1h 12
    { 0x796F0EF4, 0x32F39E12 },    // 1xx_WeaponHitKnockback1h 14 -> WeaponHitKnockback1h 12
    { 0x796F0EF5, 0x32F39E12 },    // 1xx_WeaponHitKnockback1h 15 -> WeaponHitKnockback1h 12
    { 0x796F0EF6, 0x32F39E12 },    // 1xx_WeaponHitKnockback1h 16 -> WeaponHitKnockback1h 12
    { 0xEC6836C1, 0xF20761E1 },    // 1xx_WeaponHitKnockback1h 2 -> WeaponHitKnockback1h 2
    { 0xEC6836C2, 0xF20761E2 },    // 1xx_WeaponHitKnockback1h 3 -> WeaponHitKnockback1h 3
    { 0xEC6836C3, 0xF20761E3 },    // 1xx_WeaponHitKnockback1h 4 -> WeaponHitKnockback1h 4
    { 0xEC6836C4, 0xF20761E4 },    // 1xx_WeaponHitKnockback1h 5 -> WeaponHitKnockback1h 5
    { 0xEC6836C5, 0xF20761E5 },    // 1xx_WeaponHitKnockback1h 6 -> WeaponHitKnockback1h 6
    { 0xEC6836C6, 0xF20761E6 },    // 1xx_WeaponHitKnockback1h 7 -> WeaponHitKnockback1h 7
    { 0xEC6836C7, 0xF20761E7 },    // 1xx_WeaponHitKnockback1h 8 -> WeaponHitKnockback1h 8
    { 0xEC6836C8, 0xF20761E8 },    // 1xx_WeaponHitKnockback1h 9 -> WeaponHitKnockback1h 9
    { 0x33113B9A, 0xFFFFFFFF },    // 1xx_WeaponHitKnockback2h 0.1 Legendary -> (none)
    { 0xEC68C321, 0xF207EE41 },    // 1xx_WeaponHitKnockback2h 1 -> WeaponHitKnockback2h 1
    { 0x79812771, 0x3305B691 },    // 1xx_WeaponHitKnockback2h 10 -> WeaponHitKnockback2h 10
    { 0x79812772, 0x3305B692 },    // 1xx_WeaponHitKnockback2h 11 -> WeaponHitKnockback2h 11
    { 0x79812773, 0x3305B693 },    // 1xx_WeaponHitKnockback2h 12 -> WeaponHitKnockback2h 12
    { 0x79812774, 0x3305B693 },    // 1xx_WeaponHitKnockback2h 13 -> WeaponHitKnockback2h 12
    { 0x79812775, 0x3305B693 },    // 1xx_WeaponHitKnockback2h 14 -> WeaponHitKnockback2h 12
    { 0x79812776, 0x3305B693 },    // 1xx_WeaponHitKnockback2h 15 -> WeaponHitKnockback2h 12
    { 0x79812777, 0x3305B693 },    // 1xx_WeaponHitKnockback2h 16 -> WeaponHitKnockback2h 12
    { 0xEC68C322, 0xF207EE42 },    // 1xx_WeaponHitKnockback2h 2 -> WeaponHitKnockback2h 2
    { 0xEC68C323, 0xF207EE43 },    // 1xx_WeaponHitKnockback2h 3 -> WeaponHitKnockback2h 3
    { 0xEC68C324, 0xF207EE44 },    // 1xx_WeaponHitKnockback2h 4 -> WeaponHitKnockback2h 4
    { 0xEC68C325, 0xF207EE45 },    // 1xx_WeaponHitKnockback2h 5 -> WeaponHitKnockback2h 5
    { 0xEC68C326, 0xF207EE46 },    // 1xx_WeaponHitKnockback2h 6 -> WeaponHitKnockback2h 6
    { 0xEC68C327, 0xF207EE47 },    // 1xx_WeaponHitKnockback2h 7 -> WeaponHitKnockback2h 7
    { 0xEC68C328, 0xF207EE48 },    // 1xx_WeaponHitKnockback2h 8 -> WeaponHitKnockback2h 8
    { 0xEC68C329, 0xF207EE49 },    // 1xx_WeaponHitKnockback2h 9 -> WeaponHitKnockback2h 9
    { 0x5A3F1F37, 0xFFFFFFFF },    // 1xx_WeaponHitSlow1h 0.1 Legendary -> (none)
    { 0x0C9A933E, 0x962A4A5E },    // 1xx_WeaponHitSlow1h 1 -> WeaponHitSlow1h 1
    { 0x9FECFB2E, 0x5B73964E },    // 1xx_WeaponHitSlow1h 10 -> WeaponHitSlow1h 10
    { 0x9FECFB2F, 0x5B73964F },    // 1xx_WeaponHitSlow1h 11 -> WeaponHitSlow1h 11
    { 0x9FECFB30, 0x5B739650 },    // 1xx_WeaponHitSlow1h 12 -> WeaponHitSlow1h 12
    { 0x9FECFB31, 0x5B739650 },    // 1xx_WeaponHitSlow1h 13 -> WeaponHitSlow1h 12
    { 0x9FECFB32, 0x5B739650 },    // 1xx_WeaponHitSlow1h 14 -> WeaponHitSlow1h 12
    { 0x9FECFB33, 0x5B739650 },    // 1xx_WeaponHitSlow1h 15 -> WeaponHitSlow1h 12
    { 0x9FECFB34, 0x5B739650 },    // 1xx_WeaponHitSlow1h 16 -> WeaponHitSlow1h 12
    { 0x0C9A933F, 0x962A4A5F },    // 1xx_WeaponHitSlow1h 2 -> WeaponHitSlow1h 2
    { 0x0C9A9340, 0x962A4A60 },    // 1xx_WeaponHitSlow1h 3 -> WeaponHitSlow1h 3
    { 0x0C9A9341, 0x962A4A61 },    // 1xx_WeaponHitSlow1h 4 -> WeaponHitSlow1h 4
    { 0x0C9A9342, 0x962A4A62 },    // 1xx_WeaponHitSlow1h 5 -> WeaponHitSlow1h 5
    { 0x0C9A9343, 0x962A4A63 },    // 1xx_WeaponHitSlow1h 6 -> WeaponHitSlow1h 6
    { 0x0C9A9344, 0x962A4A64 },    // 1xx_WeaponHitSlow1h 7 -> WeaponHitSlow1h 7
    { 0x0C9A9345, 0x962A4A65 },    // 1xx_WeaponHitSlow1h 8 -> WeaponHitSlow1h 8
    { 0x0C9A9346, 0x962A4A66 },    // 1xx_WeaponHitSlow1h 9 -> WeaponHitSlow1h 9
    { 0x66744518, 0xFFFFFFFF },    // 1xx_WeaponHitSlow2h 0.1 Legendary -> (none)
    { 0x0C9B1F9F, 0x962AD6BF },    // 1xx_WeaponHitSlow2h 1 -> WeaponHitSlow2h 1
    { 0x9FFF13AF, 0x5B85AECF },    // 1xx_WeaponHitSlow2h 10 -> WeaponHitSlow2h 10
    { 0x9FFF13B0, 0x5B85AED0 },    // 1xx_WeaponHitSlow2h 11 -> WeaponHitSlow2h 11
    { 0x9FFF13B1, 0x5B85AED1 },    // 1xx_WeaponHitSlow2h 12 -> WeaponHitSlow2h 12
    { 0x9FFF13B2, 0x5B85AED1 },    // 1xx_WeaponHitSlow2h 13 -> WeaponHitSlow2h 12
    { 0x9FFF13B3, 0x5B85AED1 },    // 1xx_WeaponHitSlow2h 14 -> WeaponHitSlow2h 12
    { 0x9FFF13B4, 0x5B85AED1 },    // 1xx_WeaponHitSlow2h 15 -> WeaponHitSlow2h 12
    { 0x9FFF13B5, 0x5B85AED1 },    // 1xx_WeaponHitSlow2h 16 -> WeaponHitSlow2h 12
    { 0x0C9B1FA0, 0x962AD6C0 },    // 1xx_WeaponHitSlow2h 2 -> WeaponHitSlow2h 2
    { 0x0C9B1FA1, 0x962AD6C1 },    // 1xx_WeaponHitSlow2h 3 -> WeaponHitSlow2h 3
    { 0x0C9B1FA2, 0x962AD6C2 },    // 1xx_WeaponHitSlow2h 4 -> WeaponHitSlow2h 4
    { 0x0C9B1FA3, 0x962AD6C3 },    // 1xx_WeaponHitSlow2h 5 -> WeaponHitSlow2h 5
    { 0x0C9B1FA4, 0x962AD6C4 },    // 1xx_WeaponHitSlow2h 6 -> WeaponHitSlow2h 6
    { 0x0C9B1FA5, 0x962AD6C5 },    // 1xx_WeaponHitSlow2h 7 -> WeaponHitSlow2h 7
    { 0x0C9B1FA6, 0x962AD6C6 },    // 1xx_WeaponHitSlow2h 8 -> WeaponHitSlow2h 8
    { 0x0C9B1FA7, 0x962AD6C7 },    // 1xx_WeaponHitSlow2h 9 -> WeaponHitSlow2h 9
    { 0x4BEE2BFC, 0xFFFFFFFF },    // 1xx_WeaponHitStun1h 0.1 Legendary -> (none)
    { 0x81C89083, 0x0B5847A3 },    // 1xx_WeaponHitStun1h 1 -> WeaponHitStun1h 1
    { 0xBADAA113, 0x76613C33 },    // 1xx_WeaponHitStun1h 10 -> WeaponHitStun1h 10
    { 0xBADAA114, 0x76613C34 },    // 1xx_WeaponHitStun1h 11 -> WeaponHitStun1h 11
    { 0xBADAA115, 0x76613C35 },    // 1xx_WeaponHitStun1h 12 -> WeaponHitStun1h 12
    { 0xBADAA116, 0x76613C35 },    // 1xx_WeaponHitStun1h 13 -> WeaponHitStun1h 12
    { 0xBADAA117, 0x76613C35 },    // 1xx_WeaponHitStun1h 14 -> WeaponHitStun1h 12
    { 0xBADAA118, 0x76613C35 },    // 1xx_WeaponHitStun1h 15 -> WeaponHitStun1h 12
    { 0xBADAA119, 0x76613C35 },    // 1xx_WeaponHitStun1h 16 -> WeaponHitStun1h 12
    { 0x81C89084, 0x0B5847A4 },    // 1xx_WeaponHitStun1h 2 -> WeaponHitStun1h 2
    { 0x81C89085, 0x0B5847A5 },    // 1xx_WeaponHitStun1h 3 -> WeaponHitStun1h 3
    { 0x81C89086, 0x0B5847A6 },    // 1xx_WeaponHitStun1h 4 -> WeaponHitStun1h 4
    { 0x81C89087, 0x0B5847A7 },    // 1xx_WeaponHitStun1h 5 -> WeaponHitStun1h 5
    { 0x81C89088, 0x0B5847A8 },    // 1xx_WeaponHitStun1h 6 -> WeaponHitStun1h 6
    { 0x81C89089, 0x0B5847A9 },    // 1xx_WeaponHitStun1h 7 -> WeaponHitStun1h 7
    { 0x81C8908A, 0x0B5847AA },    // 1xx_WeaponHitStun1h 8 -> WeaponHitStun1h 8
    { 0x81C8908B, 0x0B5847AB },    // 1xx_WeaponHitStun1h 9 -> WeaponHitStun1h 9
    { 0x582351DD, 0xFFFFFFFF },    // 1xx_WeaponHitStun2h 0.1 Legendary -> (none)
    { 0x81C91CE4, 0x0B58D404 },    // 1xx_WeaponHitStun2h 1 -> WeaponHitStun2h 1
    { 0xBAECB994, 0x767354B4 },    // 1xx_WeaponHitStun2h 10 -> WeaponHitStun2h 10
    { 0xBAECB995, 0x767354B5 },    // 1xx_WeaponHitStun2h 11 -> WeaponHitStun2h 11
    { 0xBAECB996, 0x767354B6 },    // 1xx_WeaponHitStun2h 12 -> WeaponHitStun2h 12
    { 0xBAECB997, 0x767354B6 },    // 1xx_WeaponHitStun2h 13 -> WeaponHitStun2h 12
    { 0xBAECB998, 0x767354B6 },    // 1xx_WeaponHitStun2h 14 -> WeaponHitStun2h 12
    { 0xBAECB999, 0x767354B6 },    // 1xx_WeaponHitStun2h 15 -> WeaponHitStun2h 12
    { 0xBAECB99A, 0x767354B6 },    // 1xx_WeaponHitStun2h 16 -> WeaponHitStun2h 12
    { 0x81C91CE5, 0x0B58D405 },    // 1xx_WeaponHitStun2h 2 -> WeaponHitStun2h 2
    { 0x81C91CE6, 0x0B58D406 },    // 1xx_WeaponHitStun2h 3 -> WeaponHitStun2h 3
    { 0x81C91CE7, 0x0B58D407 },    // 1xx_WeaponHitStun2h 4 -> WeaponHitStun2h 4
    { 0x81C91CE8, 0x0B58D408 },    // 1xx_WeaponHitStun2h 5 -> WeaponHitStun2h 5
    { 0x81C91CE9, 0x0B58D409 },    // 1xx_WeaponHitStun2h 6 -> WeaponHitStun2h 6
    { 0x81C91CEA, 0x0B58D40A },    // 1xx_WeaponHitStun2h 7 -> WeaponHitStun2h 7
    { 0x81C91CEB, 0x0B58D40B },    // 1xx_WeaponHitStun2h 8 -> WeaponHitStun2h 8
    { 0x81C91CEC, 0x0B58D40C },    // 1xx_WeaponHitStun2h 9 -> WeaponHitStun2h 9
    */
};

constexpr size_t kNumAffixGbidMappings = sizeof(s_AffixGbidMappings) / sizeof(s_AffixGbidMappings[0]);
