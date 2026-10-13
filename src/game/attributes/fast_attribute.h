#pragma once

#include <rex/types.h>

struct FastAttribKey
{
    rex::be<i32> nValue;
};

union FastAttribValue
{
    rex::be<f32> flValue;
    rex::be<i32> nValue;
};
