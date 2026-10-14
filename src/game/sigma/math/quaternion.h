#pragma once

#include <rex/types.h>

#include "game/sigma/math/vector3d.h"

struct Quaternion
{
    Vector3D wvImag;
    rex::be<f32> wdReal;
};

struct Quaternion16
{
    rex::be<i16> x;
    rex::be<i16> y;
    rex::be<i16> z;
    rex::be<i16> w;
};
