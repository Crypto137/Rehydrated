#pragma once

#include "core/memory.h"
#include "game/types.h"
#include "game/sigma/math/vector3d.h"

struct WorldPlace
{
    Vector3D wp;
    be<SWorldID> idSWorld;
};
