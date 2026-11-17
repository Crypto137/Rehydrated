#include "recomp/gameplay_options.h"

#include <rex/ppc/hook.h>

//REXCVAR_DEFINE_BOOL(item_enable_large_slot_items, true, "Hydra/Gameplay", "Restore large slot item functionality from the PC version").lifecycle(rex::cvar::Lifecycle::kHotReload);

//REXCVAR_DEFINE_BOOL(item_drop_magic_items_unidentified, false, "Hydra/Gameplay", "Make magic (blue) items drop as unidentified").lifecycle(rex::cvar::Lifecycle::kHotReload);

//REXCVAR_DEFINE_BOOL(item_drop_rare_items_unidentified, true, "Hydra/Gameplay", "Make rare (yellow) items drop as unidentified").lifecycle(rex::cvar::Lifecycle::kHotReload);

//REXCVAR_DEFINE_BOOL(item_drop_legendary_items_unidentified, true, "Hydra/Gameplay", "Make legendary (orange) items drop as unidentified").lifecycle(rex::cvar::Lifecycle::kHotReload);

REX_IMPORT(__imp__ItemHasLabel, Guest_ItemHasLabel, u32(u32, u32));

bool GameplayOptions::ItemIsLargeSlotItem(GBID gbidItem)
{
    //if (!REXCVAR_GET(item_enable_large_slot_items))
        return false;

    // This code mimics the PC-side implementation (as of 1.0.8) that is removed from console builds.
    if (Guest_ItemHasLabel(gbidItem, ITL_ARMOR) && !Guest_ItemHasLabel(gbidItem, ITL_BELT))
        return true;

    if (Guest_ItemHasLabel(gbidItem, ITL_WEAPON))
        return true;

    if (Guest_ItemHasLabel(gbidItem, ITL_OFFHAND))
        return true;

    return false;
}

bool GameplayOptions::ItemIsQualityLevelDropUnidentified(ItemQualityLevel eItemQualityLevel)
{
    /*
    if (eItemQualityLevel >= IQL_MAGIC_1_AFFIX && eItemQualityLevel <= IQL_MAGIC_3_AFFIX)
        return REXCVAR_GET(item_drop_magic_items_unidentified);
    else if (eItemQualityLevel >= IQL_RARE_4_AFFIX && eItemQualityLevel <= IQL_RARE_6_AFFIX)
        return REXCVAR_GET(item_drop_rare_items_unidentified);
    else if (eItemQualityLevel == IQL_LEGENDARY)
        return REXCVAR_GET(item_drop_legendary_items_unidentified);
    */

    return eItemQualityLevel == IQL_LEGENDARY;
}
