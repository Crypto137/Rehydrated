#pragma once

#include <rex/kernel/thread_state.h>
#include <rex/ppc/stack.h>

#include "core/types.h"

namespace Memory {

template <typename T>
inline T* GetHostPtr(u32 va)
{
    if (!va)
        return nullptr;

    auto* thread_state = rex::kernel::ThreadState::Get();
    return rex::memory::GuestPtr<T*>(thread_state->GetAddressSpace()->GetVirtualMembase(), va);
}

}  // namespace Memory

template <typename T>
using be = rex::BE<T>;

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
        return Memory::GetHostPtr<T>(value);
    }
};

using StackFrame = rex::ppc::StackFrame;
