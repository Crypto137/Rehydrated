#pragma once

#include <cstdint>

class XEncoder
{
public:
    virtual ~XEncoder() = default;

    void SetData(void* d, size_t sizeBytes);
    void SetUsed(size_t u);
    void PutAligned8(uint32_t x, size_t bits);
    void Put(uint32_t x, size_t bits);
    void PutU64(uint64_t v, size_t size);
    void PutBool(int32_t b);
    void PutBytesAligned8(const uint8_t* data, size_t size);
    void PutAsciiStringBytesAligned8(const uint8_t* data, size_t length);

    inline size_t GetSize() const { return m_size; }
    inline size_t GetSizeBytes() const { return m_size / 8; }
    inline size_t GetUsed() const { return m_used; }
    inline size_t GetUsedBytes() const { return (m_used + 7) / 8; }

protected:
    inline virtual void DataOverflow() {}

private:
    uint8_t* m_data;
    size_t m_size;
    size_t m_used;
};
