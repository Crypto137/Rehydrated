struct TypeDescriptorField
{
    be u32 szFieldName;
    be u32 ptDataType;
    be u32 nDataOffset;
    be u32 vDefaultFieldValue;
    be u32 vMinFieldValue;
    be u32 vMaxFieldValue;
    be u32 dwFlags;
    be u32 ptAuxDataType;
    be u32 nSerOffset;
    be u32 nCount;
    be u32 nUsedElementsOffset;
    be u16 nBitCount;
    be u16 nArraySizeBitCount;
    be u32 dwFilter;
    be u32 eTagBase;
    be u32 pSymbolTable;
    be u32 nBit;
    be u32 pfnStringToInt;
    be u32 pfnIntToString;
    be u32 nVariantTypeValue;
    char szDynamicFieldName[64];
};

struct XTypeDescriptor
{
    be u32 address;
    be u32 vftable;
    be u32 szName;
    be u32 nVersion;
    be u32 arFields;
    be u32 nFieldCount;
    be u32 pfuncDOMVersion;
    be u32 dwFlags;
};

struct ComplexTypeDescriptor : XTypeDescriptor
{
    be u32 pfuncToVariant;
    be u32 pfuncFromVariant;
    be u32 pfuncVariantsEqual;
    be u32 pfuncLoadFromDefaultData;
    be u32 pNextRegisteredDescriptor;

    TypeDescriptorField fields[nFieldCount];
};

struct DumpedString 
{
    be u32 address;
    char text[];
};

struct TypeDescriptorDump
{
    le u32 numPrimitiveDescriptors;
    XTypeDescriptor primitiveDescriptors[numPrimitiveDescriptors];

    le u32 numComplexDescriptors;
    ComplexTypeDescriptor complexDescriptors[numComplexDescriptors];

    le u32 numStrings;
    DumpedString strings[numStrings];
};

TypeDescriptorDump dump @ 0x00;