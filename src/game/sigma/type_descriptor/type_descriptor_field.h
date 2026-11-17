#pragma once

#include "core/memory.h"

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
    be<i32> nValue;
    be_ptr<char> sName;
};

struct TypeDescriptorField
{
    be_ptr<const char> szFieldName;
    be_ptr<XTypeDescriptor> ptDataType;
    be<i32> nDataOffset;
    be_ptr<void> vDefaultFieldValue;
    be_ptr<void> vMinFieldValue;
    be_ptr<void> vMaxFieldValue;
    be<u32> dwFlags;
    be_ptr<XTypeDescriptor> ptAuxDataType;
    be<i32> nSerOffset;
    be<i32> nCount;
    be<i32> nUsedElementsOffset;
    be<i16> nBitCount;
    be<i16> nArraySizeBitCount;
    be<u32> dwFilter;
    be<i32> eTagBase;
    be_ptr<SymbolicEntry> pSymbolTable;
    be<i32> nBit;
    be_ptr<void> pfnStringToInt;
    be_ptr<void> pfnIntToString;
    be<i32> nVariantTypeValue;
    char szDynamicFieldName[64];
};
