#pragma once

#include <rex/system/kernel_state.h>

namespace MemoryUtils {

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

}  // namespace MemoryUtils