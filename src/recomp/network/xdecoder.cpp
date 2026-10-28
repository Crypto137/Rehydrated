#include "recomp/network/xdecoder.h"

void XDecoder::SetData(const void* d, size_t sizeBytes)
{
    m_data = static_cast<const uint8_t*>(d);
    m_size = 8 * sizeBytes;
    m_used = 0;
}

void XDecoder::SetUsed(size_t u)
{
    m_used = u;
}

XDecoder::Result XDecoder::GetAligned8(uint32_t& x, size_t bits)
{
    x = 0;

    if (!bits)
        return RESULT_VALID;

    size_t bitsRemaining = bits;

    while (bitsRemaining > 0)
    {
        if (m_used >= m_size)
        {
            XDecoder::Result overflowResult = DataOverflow();
            if (overflowResult)
                return overflowResult;
        }

        x = (x << 8) | m_data[m_used / 8];

        m_used += 8;
        bitsRemaining -= 8;
    }

    return RESULT_VALID;
}

XDecoder::Result XDecoder::Get(uint32_t& x, size_t bits)
{
    x = 0;

    if (!bits)
        return RESULT_VALID;

    size_t bitsRemaining = bits;

    while (bitsRemaining > 0)
    {
        if (m_used >= m_size)
        {
            XDecoder::Result overflowResult = DataOverflow();
            if (overflowResult)
                return overflowResult;
        }

        size_t bitOffset = m_used % 8;
        size_t currentBits = 8 - bitOffset;
        if (bitsRemaining < currentBits)
            currentBits = bitsRemaining;

        uint8_t mask = static_cast<uint8_t>((1u << currentBits) - 1);
        uint8_t currentData = static_cast<uint8_t>(m_data[m_used / 8] >> bitOffset) & mask;

        x |= static_cast<uint32_t>(currentData) << (bitsRemaining - currentBits);

        m_used += currentBits;
        bitsRemaining -= currentBits;
    }

    return RESULT_VALID;
}

XDecoder::Result XDecoder::GetU64(uint64_t& v, size_t bits)
{
    v = 0;

    size_t bitsRemaining = bits;

    while (bitsRemaining > 0)
    {
        size_t currentBits = 32;
        if (bitsRemaining < currentBits)
            currentBits = bitsRemaining;

        uint32_t currentData = 0;
        XDecoder::Result result = Get(currentData, currentBits);
        if (result)
            return result;

        v = (v << currentBits) | currentData;

        bitsRemaining -= currentBits;
    }

    return RESULT_VALID;
}

XDecoder::Result XDecoder::GetBool(int32_t& b)
{
    return Get(reinterpret_cast<uint32_t&>(b), 1);
}

XDecoder::Result XDecoder::GetBytesAligned8(uint8_t* data, size_t size)
{
    m_used = (m_used + 7) & ~size_t(7);

    size_t bitsRemaining = 8 * size;

    if (bitsRemaining >= 32)
    {
        size_t numDwords = bitsRemaining / 32;
        for (size_t i = 0; i < numDwords; i++)
        {
            uint32_t dword = 0;
            size_t currentBits = 32;
            while (currentBits > 0)
            {
                if (m_used >= m_size)
                {
                    XDecoder::Result overflowResult = DataOverflow();
                    if (overflowResult)
                        return overflowResult;
                }

                dword = (dword << 8) | m_data[m_used / 8];

                currentBits -= 8;
                m_used += 8;
            }

            data[0] = (dword >> 24) & 0xFF;
            data[1] = (dword >> 16) & 0xFF;
            data[2] = (dword >> 8) & 0xFF;
            data[3] = dword & 0xFF;

            data += 4;
            bitsRemaining -= 32;
        }
    }

    if (bitsRemaining > 0)
    {
        uint32_t dword = 0;
        XDecoder::Result result = GetAligned8(dword, bitsRemaining);
        if (result)
            return result;

        do
        {
            bitsRemaining -= 8;
            *data++ = static_cast<uint8_t>(dword >> bitsRemaining);
        }
        while (bitsRemaining > 0);
    }

    return RESULT_VALID;
}

XDecoder::Result XDecoder::GetAsciiStringBytesAligned8(uint8_t* data, size_t length)
{
    return GetBytesAligned8(data, length);
}
