#pragma once

#include <rex/system/xtypes.h>

struct XTypeDescriptor;

struct SymbolicEntry
{
    rex::be<i32> nValue;
    rex::TypedGuestPointer<char> sName;
};

struct TypeDescriptorField
{
    rex::TypedGuestPointer<const char> szFieldName;
    rex::TypedGuestPointer<XTypeDescriptor> ptDataType;
    rex::be<i32> nDataOffset;
    rex::TypedGuestPointer<void> vDefaultFieldValue;
    rex::TypedGuestPointer<void> vMinFieldValue;
    rex::TypedGuestPointer<void> vMaxFieldValue;
    rex::be<u32> dwFlags;
    rex::TypedGuestPointer<XTypeDescriptor> ptAuxDataType;
    rex::be<i32> nSerOffset;
    rex::be<i32> nCount;
    rex::be<i32> nUsedElementsOffset;
    rex::be<i16> nBitCount;
    rex::be<i16> nArraySizeBitCount;
    rex::be<u32> dwFilter;
    rex::be<i32> eTagBase;
    rex::TypedGuestPointer<SymbolicEntry> pSymbolTable;
    rex::be<i32> nBit;
    rex::TypedGuestPointer<void> pfnStringToInt;
    rex::TypedGuestPointer<void> pfnIntToString;
    rex::be<i32> nVariantTypeValue;
    char szDynamicFieldName[64];
};
