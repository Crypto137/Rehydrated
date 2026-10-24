#pragma once

#include <rex/system/xtypes.h>

#include "game/sigma/type_descriptor/type_descriptor_field.h"

struct XTypeDescriptor
{
    rex::TypedGuestPointer<void> __vftable;
    rex::TypedGuestPointer<const char> szClassName;
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

enum PrimitiveTypeDescriptor : u32
{
    DT_SNO = 0x82FAB918,
    DT_SNONAME_HANDLE = 0x82FAB934,
    DT_SNO_GROUP = 0x82FAB950,
    DT_TIME = 0x82FAB96C,
    DT_TIME_2 = 0x82FAB988,
    DT_FORMULA = 0x82FAB9A4,
    DT_GBID = 0x82FAB9C0,
    DT_ATTRIBUTEPARAM = 0x82FAB9DC,
    DT_VELOCITY = 0x82FAB9F8,
    DT_ACCEL = 0x82FABA14,
    DT_ANGULARVELOCITY = 0x82FABA30,
    DT_MASS = 0x82FABA68,
    DT_IMPULSE = 0x82FABA84,
    DT_TAGMAP = 0x82FABAA0,
    DT_ANIM_TAG = 0x82FABABC,
    DT_ACTOR_GROUP = 0x82FABAF4,
    DT_INT = 0x82FABB48,
    DT_NULL = 0x82FC50A4,
    DT_INT_2 = 0x82FC50C0,
    DT_DATAID = 0x82FC50DC,
    DT_INT64 = 0x82FC50F8,
    DT_BYTE = 0x82FC5114,
    DT_FLOAT = 0x82FC5130,
    DT_WORD = 0x82FC5168,
    DT_CHARARRAY = 0x82FC5184,
    DT_ANGLE = 0x82FC51BC,
    DT_PERCENT = 0x82FC51D8,
    DT_HIGHPRECISIONPERCENT = 0x82FC51F4,
    DT_ENUM = 0x82FC5210,
    DT_FLAG = 0x82FC522C,
    DT_TRANSLATEABLE = 0x82FC5248,
    DT_FIXEDARRAY = 0x82FC5264,
    DT_VARIABLEARRAY = 0x82FC5280,
    DT_CSTRING = 0x82FC529C,
    DT_OPTIONAL = 0x82FC52B8,
};
