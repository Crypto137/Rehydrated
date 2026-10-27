#pragma once

#include <rex/system/xtypes.h>

enum AttributeCompressorType
{
    ACT_UNCOMPRESSED,
    ACT_BOUNDED_INT,
    ACT_LINEAR_FLOAT,
    ACT_FLOAT16,
    ACT_FLOAT_VARIABLE,
    ACT_COUNT,
};

struct AttributeCompressor
{
    rex::TypedGuestPointer<u32> __vftable;
    rex::be<AttributeCompressorType> m_eType;
    rex::TypedGuestPointer<AttributeCompressor> m_ptNextCompressor;
};

struct AttributeCompressorUncompressed : AttributeCompressor
{
    rex::be<u32> m_dwBits;
};

struct AttributeCompressorBoundedInt : AttributeCompressor
{
    rex::be<i32> m_nMin;
    rex::be<i32> m_nMax;
    rex::be<u32> m_dwBits;
};

struct AttributeCompressorLinearFloat : AttributeCompressor
{
    rex::be<f32> m_fMin;
    rex::be<f32> m_fMax;
    rex::be<u32> m_dwBits;
    rex::be<f32> m_fMultiplier;
    rex::be<f32> m_fOOMultiplier;
};

struct AttributeCompressorFloat16 : AttributeCompressor
{
    rex::be<u32> m_dwBits;
};

struct AttributeCompressorFloatVariable : AttributeCompressor
{
};
