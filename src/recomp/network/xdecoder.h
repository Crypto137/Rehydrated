#pragma once

#include <cstdint>

class XDecoder
{
public:
    enum Result
    {
        RESULT_VALID,
        RESULT_TRUNCATED,
        RESULT_CORRUPTED,
    };

    virtual ~XDecoder() = default;

    void SetData(const void* d, size_t sizeBytes);
    void SetUsed(size_t u);
    Result GetAligned8(uint32_t& x, size_t bits);
    Result Get(uint32_t& x, size_t bits);
    Result GetU64(uint64_t& v, size_t bits);
    Result GetBool(int32_t& b);
    Result GetBytesAligned8(uint8_t* data, size_t size);
    Result GetAsciiStringBytesAligned8(uint8_t* data, size_t length);

    inline size_t GetSize() const { return m_size; }
    inline size_t GetSizeBytes() const { return m_size / 8; }
    inline size_t GetUsed() const { return m_used; }
    inline size_t GetUsedBytes() const { return (m_used + 7) / 8; }

protected:
    inline virtual Result DataOverflow() { return RESULT_TRUNCATED; };

private:
    const uint8_t* m_data;
    size_t m_size;
    size_t m_used;
};
