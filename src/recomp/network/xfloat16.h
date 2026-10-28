#pragma once

#include <cstdint>

struct XFloat16
{
    XFloat16() = default;
    XFloat16(float value) { *this = value; }
    XFloat16(uint16_t uData) { m_uData = uData; }

    inline static float const GetAbsoluteMaximumValue() { return 65536.0f; }

    XFloat16& operator=(float value);

    operator float() const;

    uint16_t m_uData;
};
