struct AttribDef
{
    be u32 eAttrib;
    be u32 tDefaultValue;
    be u32 eParameterType;
    be u32 eAttributeOperator;
    be u32 eAttributeDataType;
    be u32 pszFormulaItem;
    be u32 pszFormulaCharacter;
    be u32 pszName;
    be u32 ptCompressor;
    u8 uSyncFlags;
    padding[3];
};

enum AttributeCompressorType : u32
{
    ACT_UNCOMPRESSED,
    ACT_BOUNDED_INT,
    ACT_LINEAR_FLOAT,
    ACT_FLOAT16,
    ACT_FLOAT_VARIABLE,
};

struct AttributeCompressor
{
    be u32 address;
    be u32 vftable;
    be AttributeCompressorType m_eType;
    be u32 m_ptNextCompressor;
    
    if (m_eType == AttributeCompressorType::ACT_UNCOMPRESSED)
    {
        be u32 m_dwBits;
    }
    else if (m_eType == AttributeCompressorType::ACT_BOUNDED_INT)
    {
        be s32 m_nMin;
        be s32 m_nMax;
        be u32 m_dwBits;
    }
    else if (m_eType == AttributeCompressorType::ACT_LINEAR_FLOAT)
    {
        be float m_fMin;
        be float m_fMax;
        be u32 m_dwBits;
        be float m_fMultiplier;
        be float m_fOOMultiplier;
    }
    else if (m_eType == AttributeCompressorType::ACT_FLOAT16)
    {
        be u32 m_dwBits;
    }
    else if (m_eType == AttributeCompressorType::ACT_FLOAT_VARIABLE)
    {
    }
};

struct DumpedString 
{
    be u32 address;
    char text[];
};

struct AttribDefsDump
{
    le u32 numAttribs;
    AttribDef attribDefs[numAttribs];
    
    le u32 numCompressors;
    AttributeCompressor compressors[numCompressors];
    
    le u32 numStrings;
    DumpedString strings[numStrings];
};

AttribDefsDump dump @ 0x00;