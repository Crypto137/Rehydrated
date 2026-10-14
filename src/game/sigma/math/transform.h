#pragma once

#include <rex/types.h>

#include "game/sigma/math/quaternion.h"
#include "game/sigma/math/vector3d.h"

struct PRTransform
{
    Quaternion q;
    Vector3D wp;
};

struct PRSTransform
{
    Quaternion q;
    Vector3D wp;
    rex::be<f32> flScale;
};
