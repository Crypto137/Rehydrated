#pragma once

#include "core/memory.h"
#include "game/sigma/math/vector3d.h"

struct Quaternion
{
    Vector3D wvImag;
    be<f32> wdReal;
};

struct Quaternion16
{
    be<i16> x;
    be<i16> y;
    be<i16> z;
    be<i16> w;
};
