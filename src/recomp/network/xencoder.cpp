#include "recomp/network/xencoder.h"

void XEncoder::SetData(void* d, size_t sizeBytes)
{
    m_data = reinterpret_cast<uint8_t*>(d);
    m_size = 8 * sizeBytes;
    m_used = 0;
}

void XEncoder::SetUsed(size_t u)
{
    m_used = u;
}

void XEncoder::PutAligned8(uint32_t x, size_t bits)
{
    size_t bitsRemaining = bits;

    while (bitsRemaining > 0)
    {
        if (m_used >= m_size)
            DataOverflow();

        bitsRemaining -= 8;
        m_data[m_used / 8] = static_cast<uint8_t>(x >> bitsRemaining);
        m_used += 8;
    }
}

void XEncoder::Put(uint32_t x, size_t bits)
{
    size_t bitsRemaining = bits;

    while (bitsRemaining > 0)
    {
        if (m_used >= m_size)
            DataOverflow();

        size_t bitOffset = m_used % 8;
        size_t currentBits = 8 - bitOffset;
        if (bitsRemaining < currentBits)
            currentBits = bitsRemaining;

        bitsRemaining -= currentBits;

        uint8_t mask = static_cast<uint8_t>((1u << currentBits) - 1);
        uint8_t currentData = static_cast<uint8_t>(x >> bitsRemaining) & mask;

        uint8_t& target = m_data[m_used / 8];
        target = (target & ~(mask << bitOffset)) | (currentData << bitOffset);

        m_used += currentBits;
    }
}

void XEncoder::PutU64(uint64_t v, size_t size)
{
    size_t bitsRemaining = size;

    while (bitsRemaining > 0)
    {
        size_t currentBits = 32;
        if (bitsRemaining < currentBits)
            currentBits = bitsRemaining;

        Put(static_cast<uint32_t>(v >> (bitsRemaining - currentBits)), currentBits);

        bitsRemaining -= currentBits;
    }
}

void XEncoder::PutBool(int32_t b)
{
    Put(b != 0, 1);
}

void XEncoder::PutBytesAligned8(const uint8_t* data, size_t size)
{
    Put(0, ((m_used + 7) & ~size_t(7)) - m_used);

    size_t bitsRemaining = 8 * size;

    if (bitsRemaining >= 32)
    {
        size_t numDwords = bitsRemaining / 32;
        for (size_t i = 0; i < numDwords; i++)
        {
            uint32_t dword = (static_cast<uint32_t>(data[0]) << 24) |
                             (static_cast<uint32_t>(data[1]) << 16) |
                             (static_cast<uint32_t>(data[2]) << 8) |
                             (static_cast<uint32_t>(data[3]));

            size_t currentBits = 32;
            while (currentBits > 0)
            {
                if (m_used >= m_size)
                    DataOverflow();

                currentBits -= 8;
                m_data[m_used / 8] = static_cast<uint8_t>(dword >> currentBits);
                m_used += 8;
            }

            data += 4;
            bitsRemaining -= 32;
        }
    }

    if (bitsRemaining > 0)
    {
        size_t numBytes = ((bitsRemaining - 1) / 8) + 1;
        uint32_t dword = 0;

        for (size_t i = 0; i < numBytes; ++i)
            dword = data[i] | (dword << 8);

        PutAligned8(dword, bitsRemaining);
    }
}

void XEncoder::PutAsciiStringBytesAligned8(const uint8_t* data, size_t length)
{
    PutBytesAligned8(data, length);
}
