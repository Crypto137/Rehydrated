#pragma once

#include "core/memory.h"

struct FastAttribKey
{
    be<i32> nValue;
};

union FastAttribValue
{
    be<f32> flValue;
    be<i32> nValue;
};
