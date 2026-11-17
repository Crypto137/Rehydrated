#pragma once

#include <rex/system/kernel_state.h>

namespace Memory {

template <typename T>
inline T* GetHostPtr(u32 va)
{
    auto* memory = REX_KERNEL_MEMORY();
    if (!memory || !va)
        return nullptr;

    return memory->template TranslateVirtual<T*>(va);
}

inline u32 GetGuestPtr(const void* ptr)
{
    auto* memory = REX_KERNEL_MEMORY();
    if (!memory || !ptr)
        return 0;

    return memory->HostToGuestVirtual(ptr);
}

}  // namespace Memory

template <typename T>
using be = rex::be<T>;

template <typename T>
struct be_ptr
{
    be<u32> value;

    operator u32() const { return value; }

    explicit operator bool() const { return value != 0; }

    be_ptr& operator=(u32 v) {
        value = v;
        return *this;
    }

    T* GetHost() const
    {
        return Memory::GetHostPtr(value);
    }
};
