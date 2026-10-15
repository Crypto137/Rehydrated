#pragma once

#include <rex/types.h>

#include "game/sigma/math/quaternion.h"
#include "game/sigma/math/vector3d.h"

// Position-Rotation Transform
struct PRTransform
{
    Quaternion q;
    Vector3D wp;
};

// Position-Rotation-Scale Transform
struct PRSTransform
{
    Quaternion q;
    Vector3D wp;
    rex::be<f32> flScale;
};
