#include "recomp/network/xfloat16.h"

#include <bit>

XFloat16& XFloat16::operator=(float value)
{
    uint32_t bits32 = std::bit_cast<uint32_t, float>(value);
    uint32_t bits16 = 0;

    int32_t exponent = static_cast<int32_t>((bits32 >> 23) & 0xFF) - 127 + 15;
    if (exponent < 0)
        exponent = 0;

    bits16 = (bits32 >> 16) & 0x8000;                               // sign
    bits16 |= ((static_cast<uint32_t>(exponent) << 10) & 0xFFFF);   // exponent
    bits16 |= (bits32 >> 13) & 0x3FF;                               // mantissa

    m_uData = static_cast<uint16_t>(bits16);
    return *this;
}

XFloat16::operator float() const
{
    if (m_uData == 0)
        return 0.0f;

    uint32_t bits16 = m_uData;
    uint32_t bits32 = 0;

    bits32 = (bits16 & 0x8000) << 16;                       // sign
    bits32 |= (((bits16 >> 10) & 0x1F) - 15 + 127) << 23;   // exponent
    bits32 |= (bits16 & 0x3FF) << 13;                       // mantissa

    return std::bit_cast<float, uint32_t>(bits32);
}
