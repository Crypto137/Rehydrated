#pragma once

#include <cstdint>

class XEncoder
{
public:
    void SetData(void* d, size_t sizeBytes);
    void SetUsed(size_t u);
    void PutAligned8(uint32_t x, size_t bits);
    void Put(uint32_t x, size_t bits);
    void PutU64(uint64_t v, size_t size);
    void PutBool(int32_t b);
    void PutBytesAligned8(const uint8_t* data, size_t size);
    void PutAsciiStringBytesAligned8(const uint8_t* data, size_t length);

protected:
    virtual void DataOverflow() = 0;

private:
    uint8_t* m_data;
    size_t m_size;
    size_t m_used;
};