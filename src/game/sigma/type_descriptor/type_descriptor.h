#pragma once

#include "game/sigma/type_descriptor/type_descriptor_field.h"

#include <rex/system/xtypes.h>

struct XTypeDescriptor
{
    rex::TypedGuestPointer<void> __vftable;
    rex::TypedGuestPointer<char> szName;
    rex::be<i32> nVersion;
    rex::TypedGuestPointer<TypeDescriptorField> arFields;
    rex::be<u32> nFieldCount;
    rex::TypedGuestPointer<void> pfuncDOMVersion;
    rex::be<u32> dwFlags;
};

struct ComplexTypeDescriptor : XTypeDescriptor
{
    static constexpr u32 pRegistrationHead = 0x830D6B24;

    rex::TypedGuestPointer<void> pfuncToVariant;
    rex::TypedGuestPointer<void> pfuncFromVariant;
    rex::TypedGuestPointer<void> pfuncVariantsEqual;
    rex::TypedGuestPointer<void> pfuncLoadFromDefaultData;
    rex::TypedGuestPointer<ComplexTypeDescriptor> pNextRegisteredDescriptor;
};
