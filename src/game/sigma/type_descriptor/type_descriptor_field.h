#pragma once

#include <rex/system/xtypes.h>

struct XTypeDescriptor;

enum TypeDescriptorFieldFlags : int
{
    TDF_XML_SERIALIZATION,
    TDF_XGROWABLE_ARRAY,
    TDF_GBID_COLUMN,
    TDF_VARIABLE_COUNT,
    TDF_MINMAX_BOUNDED,
    TDF_XPTR64,
    TDF_IGNORE_ON_SERVER,
    TDF_XFLOAT16,
    TDF_REQUIRED_SNO,
    TDF_SOFT_LINK,
    TDF_SERVER_ONLY,
    TDF_PC_ONLY,
    TDF_XBOX360_ONLY,
    TDF_PS3_ONLY,
    TDF_AXE_ONLY,
    TDF_XPTR128,
    TDF_COMPUTE_ARRAY_COUNT,
    TDF_DISABLE_TAGMAP_OPTIMIZATION,
    TDF_DISABLE_DATA_MERGE,
    TDF_BIT_FLAGS,
    //TDF_XBOXONE_ONLY,
    //TDF_PS4_ONLY,
    //TDF_NX64_ONLY,
};

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
