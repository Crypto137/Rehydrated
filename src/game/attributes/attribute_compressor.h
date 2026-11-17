#pragma once

#include "core/memory.h"

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
    be_ptr<u32> __vftable;
    be<AttributeCompressorType> m_eType;
    be_ptr<AttributeCompressor> m_ptNextCompressor;
};

struct AttributeCompressorUncompressed : AttributeCompressor
{
    be<u32> m_dwBits;
};

struct AttributeCompressorBoundedInt : AttributeCompressor
{
    be<i32> m_nMin;
    be<i32> m_nMax;
    be<u32> m_dwBits;
};

struct AttributeCompressorLinearFloat : AttributeCompressor
{
    be<f32> m_fMin;
    be<f32> m_fMax;
    be<u32> m_dwBits;
    be<f32> m_fMultiplier;
    be<f32> m_fOOMultiplier;
};

struct AttributeCompressorFloat16 : AttributeCompressor
{
    be<u32> m_dwBits;
};

struct AttributeCompressorFloatVariable : AttributeCompressor
{
};
