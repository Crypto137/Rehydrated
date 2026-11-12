#pragma once

#include <rex/types.h>

#include "game/types.h"
#include "game/world_place.h"

enum TargetType : int
{
    TT_INVALID = -1,
    TT_NONE,
    TT_ACTOR,
    TT_POINT,
    TT_ACTOR_WITH_FALLBACK_POINT,
    TT_NUM_TYPES,
};

struct Target
{
    rex::be<TargetType> eType;
    rex::be<ACDID> idACDTarget;
    WorldPlace tPlace;
    rex::be<i32> bForcedActorTarget;
};
