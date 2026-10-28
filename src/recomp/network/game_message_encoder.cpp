#include "recomp/network/game_message_encoder.h"

#include <bit>
#include <cstring>

#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/attributes/attrib_defs.h"
#include "game/attributes/attribute_compressor.h"
#include "game/sigma/type_descriptor/type_descriptor.h"
#include "recomp/network/game_message_translator.h"
#include "recomp/network/xfloat16.h"

namespace
{

constexpr u32 cgarAttribDefs = 0x82F9DA88;

bool AttributeCompressor_EncodeUncompressed(AttributeCompressorUncompressed* ptCompressor, XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    u32 dwBits = ptCompressor->m_dwBits;
    if (tEncoder.GetUsed() + dwBits > tEncoder.GetSize())
        return false;

    i32 nValue = tKeyValue.nValue;

    tEncoder.Put(nValue, dwBits);
    return true;
}

bool AttributeCompressor_EncodeBoundedInt(AttributeCompressorBoundedInt* ptCompressor, XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    u32 dwBits = ptCompressor->m_dwBits;

    // HACK: adjust bit count for PC compat (4 players / 3 bits on console -> 8 players / 4 bits on PC)
    if (tKeyValue.eKeyAttrib == ATTRIBUTE_PET_OWNER || tKeyValue.eKeyAttrib == ATTRIBUTE_PET_CREATOR)
        dwBits = 4;
    // HACK end

    if (tEncoder.GetUsed() + dwBits > tEncoder.GetSize())
        return false;

    i32 nValue = tKeyValue.nValue;
    if (nValue < ptCompressor->m_nMin || nValue > ptCompressor->m_nMax)
        return false;   // the original code just crashes in this case

    nValue -= ptCompressor->m_nMin;

    tEncoder.Put(nValue, dwBits);
    return true;
}

bool AttributeCompressor_EncodeLinearFloat(AttributeCompressorLinearFloat* ptCompressor, XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    // This compressor type doesn't appear to be used by any attributes
    // in any publicly available version of the game.
    REXLOG_WARN("AttributeCompressor_EncodeLinearFloat() called");
    return false;
}

bool AttributeCompressor_EncodeFloat16(AttributeCompressorFloat16* ptCompressor, XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    u32 dwBits = ptCompressor->m_dwBits;
    if (tEncoder.GetUsed() + dwBits > tEncoder.GetSize())
        return false;

    i32 nValue = tKeyValue.nValue;
    XFloat16 xfloat16 = std::bit_cast<float, i32>(nValue);

    tEncoder.Put(xfloat16.m_uData, dwBits);
    return true;
}

bool AttributeCompressor_EncodeFloatVariable(AttributeCompressorFloatVariable* ptCompressor, XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    i32 nValue = tKeyValue.nValue;
    f32 flValue = std::bit_cast<f32, i32>(nValue);

    float maxValue16 = XFloat16::GetAbsoluteMaximumValue();
    u32 dwBits = flValue >= maxValue16 || flValue <= -maxValue16 ? 32 : 16;

    if (tEncoder.GetUsed() + 1 + dwBits > tEncoder.GetSize())
        return false;

    tEncoder.PutBool(dwBits == 16);

    uint32_t data;
    if (dwBits == 16)
    {
        XFloat16 xfloat16 = flValue;
        data = xfloat16.m_uData;
    }
    else
    {
        data = nValue;
    }

    tEncoder.Put(data, dwBits);
    return true;
}

bool AttributeCompressor_Encode(XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    Attrib eAttrib = tKeyValue.eKeyAttrib;

    // HACK: encode Special_Inventory_Has_Sold as BoundedInt in the 0-1 range
    // (reuse compressor from another bool attribute to achieve this)
    if (eAttrib == ATTRIBUTE_SPECIAL_INVENTORY_HAS_SOLD)
        eAttrib = ATTRIBUTE_INVULNERABLE;
    // HACK end

    AttribDef& tAttribDef = MemoryUtils::GetHostPtr<AttribDef>(cgarAttribDefs)[eAttrib];
    AttributeCompressor* ptCompressor = MemoryUtils::GetHostPtr<AttributeCompressor>(tAttribDef.ptCompressor);

    switch (ptCompressor->m_eType)
    {
        case ACT_UNCOMPRESSED:
            return AttributeCompressor_EncodeUncompressed(static_cast<AttributeCompressorUncompressed*>(ptCompressor), tEncoder, tKeyValue);

        case ACT_BOUNDED_INT:
            return AttributeCompressor_EncodeBoundedInt(static_cast<AttributeCompressorBoundedInt*>(ptCompressor), tEncoder, tKeyValue);

        case ACT_LINEAR_FLOAT:
            return AttributeCompressor_EncodeLinearFloat(static_cast<AttributeCompressorLinearFloat*>(ptCompressor), tEncoder, tKeyValue);

        case ACT_FLOAT16:
            return AttributeCompressor_EncodeFloat16(static_cast<AttributeCompressorFloat16*>(ptCompressor), tEncoder, tKeyValue);

        case ACT_FLOAT_VARIABLE:
            return AttributeCompressor_EncodeFloatVariable(static_cast<AttributeCompressorFloatVariable*>(ptCompressor), tEncoder, tKeyValue);

        default:
            REXLOG_WARN("AttributeCompressor_Encode(): Unknown compressor type {}", static_cast<int>(ptCompressor->m_eType.get()));
            return false;
    }
}

XDecoder::Result AttributeCompressor_Decode(XDecoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    // The client doesn't send any attributes, so we can implement this later if needed
    return XDecoder::RESULT_CORRUPTED;
}

// forward declare Encode and Decode to be able to call them recursively in subfunctions

bool Encode(const XTypeDescriptor* ptTypeDesc, void* pMessage, const TypeDescriptorField& field, XEncoder& tEncoder);

XDecoder::Result Decode(const XTypeDescriptor* ptTypeDesc, void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder);

size_t XTypeDescriptor_SizeOf(u32 ptTypeDescGuest)
{
    // complex types
    XTypeDescriptor* ptTypeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(ptTypeDescGuest);
    i32 nFieldCount = ptTypeDesc->nFieldCount;
    if (nFieldCount > 0)
    {
        TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(ptTypeDesc->arFields);
        return arFields[nFieldCount - 1].nDataOffset;
    }

    // primitive types
    switch (ptTypeDescGuest)
    {
        case DT_BYTE:
        case DT_PERCENT:
            return 1;

        case DT_WORD:
            return 2;

        case DT_SNO:
        case DT_SNONAME_HANDLE:
        case DT_SNO_GROUP:
        case DT_TIME:
        case DT_TIME_2:
        case DT_GBID:
        case DT_ATTRIBUTEPARAM:
        case DT_VELOCITY:
        case DT_ACCEL:
        case DT_ANGULARVELOCITY:
        case DT_MASS:
        case DT_IMPULSE:
        case DT_ANIM_TAG:
        case DT_ACTOR_GROUP:
        case DT_INT:
        case DT_INT_2:
        case DT_DATAID:
        case DT_FLOAT:
        case DT_ANGLE:
        case DT_HIGHPRECISIONPERCENT:
        case DT_TRANSLATEABLE:
        case DT_OPTIONAL:
        case DT_ENUM:
            return 4;

        case DT_INT64:
            return 8;

        default:
            return 0;
    }
}

bool GenericFloatEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    f32 value = *static_cast<f32*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        f32 flMinValue = field.vMinFieldValue.value;
        f32 flMaxValue = field.vMaxFieldValue.value;
        if (value < flMinValue || value > flMaxValue)
            return false; // the original code just crashes in this case
    }

    u32 uData;
    if (field.dwFlags & (1 << TDF_XFLOAT16))
    {
        XFloat16 xfloat16 = value;
        uData = xfloat16.m_uData;
    }
    else
    {
        uData = std::bit_cast<u32, f32>(value);
    }

    // !!original code bug!!: uses 32 bits even for XFloat16 encoded values
    tEncoder.Put(uData, 32);
    return true;
}

XDecoder::Result GenericFloatDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;

    f32 value;
    if (field.dwFlags & (1 << TDF_XFLOAT16))
    {
        XFloat16 xfloat16 = static_cast<u16>(uData);
        value = xfloat16;
    }
    else
    {
        value = std::bit_cast<f32, u32>(uData);
    }

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        f32 flMinValue = field.vMinFieldValue.value;
        f32 flMaxValue = field.vMaxFieldValue.value;
        if (value < flMinValue || value > flMaxValue)
        {
            REXLOG_WARN("Decoded field is outside of MinMax bounds!");
            return XDecoder::RESULT_CORRUPTED;
        }
    }

    value = rex::byte_swap(value);  // LE -> BE
    *static_cast<f32*>(lpDefinition) = value;

    return XDecoder::RESULT_VALID;
}

bool GenericIntEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    i32 value = *static_cast<i32*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;
        if (value < nMinValue || value > nMaxValue)
            return false; // the original code just crashes in this case

        value -= nMinValue;
    }

    tEncoder.Put(value, nBitCount);
    return true;
}

XDecoder::Result GenericIntDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;
    
    i32 value = static_cast<i32>(uData);

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;

        value += nMinValue;

        if (value < nMinValue || value > nMaxValue)
        {
            REXLOG_WARN("Decoded field is outside of MinMax bounds!");
            return XDecoder::RESULT_CORRUPTED;
        }
    }

    value = rex::byte_swap(value);  // LE -> BE
    *static_cast<i32*>(lpDefinition) = value;

    return XDecoder::RESULT_VALID;
}

bool Int64Encode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    i64 value = *static_cast<i64*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;
        if (value < nMinValue || value > nMaxValue)
            return false; // the original code just crashes in this case

        value -= nMinValue;
    }

    tEncoder.PutU64(value, nBitCount);
    return true;
}

XDecoder::Result Int64Decode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u64 uData = 0;
    XDecoder::Result result = tDecoder.GetU64(uData, field.nBitCount);
    if (result)
        return result;

    i64 value = static_cast<i64>(uData);

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;

        value += nMinValue;

        if (value < nMinValue || value > nMaxValue)
        {
            REXLOG_WARN("Decoded field is outside of MinMax bounds!");
            return XDecoder::RESULT_CORRUPTED;
        }
    }

    value = rex::byte_swap(value);  // LE -> BE
    *static_cast<i64*>(lpDefinition) = value;

    return XDecoder::RESULT_VALID;
}

bool WordEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    u16 value = *static_cast<u16*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;
        if (value < nMinValue || value > nMaxValue)
            return false; // the original code just crashes in this case

        value -= nMinValue;
    }

    tEncoder.Put(value, nBitCount);
    return true;
}

XDecoder::Result WordDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;

    u16 value = static_cast<u16>(uData);

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;

        value += nMinValue;

        if (value < nMinValue || value > nMaxValue)
        {
            REXLOG_WARN("Decoded field is outside of MinMax bounds!");
            return XDecoder::RESULT_CORRUPTED;
        }
    }

    value = rex::byte_swap(value);  // LE -> BE
    *static_cast<u16*>(lpDefinition) = value;

    return XDecoder::RESULT_VALID;
}

bool ByteEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    u8 value = *static_cast<u8*>(lpDefinition);
    // no endianness swap here

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;
        if (value < nMinValue || value > nMaxValue)
            return false; // the original code just crashes in this case

        value -= nMinValue;
    }

    tEncoder.Put(value, nBitCount);
    return true;
}

XDecoder::Result ByteDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;

    u8 value = static_cast<u8>(uData);

    if (field.dwFlags & (1 << TDF_MINMAX_BOUNDED))
    {
        i32 nMinValue = field.vMinFieldValue.value;
        i32 nMaxValue = field.vMaxFieldValue.value;

        value += nMinValue;

        if (value < nMinValue || value > nMaxValue)
        {
            REXLOG_WARN("Decoded field is outside of MinMax bounds!");
            return XDecoder::RESULT_CORRUPTED;
        }
    }

    // no endianness swap here
    *static_cast<u8*>(lpDefinition) = value;

    return XDecoder::RESULT_VALID;
}

bool PercentEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    u8 value = *static_cast<u8*>(lpDefinition);

    tEncoder.Put(value, nBitCount);
    return true;
}

XDecoder::Result PercentDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;

    *static_cast<u8*>(lpDefinition) = uData;

    return XDecoder::RESULT_VALID;
}

bool FlagEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    if (tEncoder.GetUsed() == tEncoder.GetSize())
        return false;

    u32 value = *static_cast<u32*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE
    value = (value >> field.nBit) & 1;

    tEncoder.PutBool(value);
    return true;
}

XDecoder::Result FlagDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    i32 value = 0;
    XDecoder::Result result = tDecoder.GetBool(value);
    if (result)
        return result;

    u32 bits = *static_cast<u32*>(lpDefinition);
    bits = rex::byte_swap(value);  // BE -> LE

    if (value)
        bits |= (1 << field.nBit);
    else
        bits &= ~(1 << field.nBit);

    bits = rex::byte_swap(value);  // LE -> BE
    *static_cast<u32*>(lpDefinition) = bits;

    return XDecoder::RESULT_VALID;
}

bool SnoEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    u32 value = *static_cast<u32*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE

    tEncoder.Put(value, nBitCount);
    return true;
}

XDecoder::Result SnoDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;

    uData = rex::byte_swap(uData);  // LE -> BE
    *static_cast<u32*>(lpDefinition) = uData;

    return XDecoder::RESULT_VALID;
}

bool GbidEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    u32 value = *static_cast<u32*>(lpDefinition);
    value = rex::byte_swap(value);  // BE -> LE

    // !!original code bug!!: checks nBitCount, but always uses 32 bits for encoding
    tEncoder.Put(value, 32);
    return true;
}

XDecoder::Result GbidDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 uData = 0;
    XDecoder::Result result = tDecoder.Get(uData, field.nBitCount);
    if (result)
        return result;

    uData = rex::byte_swap(uData);  // LE -> BE
    *static_cast<u32*>(lpDefinition) = uData;

    return XDecoder::RESULT_VALID;
}

bool OptionalEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    size_t usedBefore = tEncoder.GetUsed();
    if (usedBefore == tEncoder.GetSize())
        return false;

    u32 hasValue = *static_cast<u32*>(lpDefinition);
    hasValue = rex::byte_swap(hasValue);  // BE -> LE, probably not really necessary in this case? let's keep it for consistency

    tEncoder.PutBool(hasValue);

    if (hasValue)
    {
        XTypeDescriptor* ptTypeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(field.ptAuxDataType);

        // The original doesn't use dynamic fields for this particular case,
        // but we use fields for dynamic dispatch, so we need a dynamic field here.
        // Copy the original field to preserve metadata like bit counts.
        TypeDescriptorField dynamicField = field;
        dynamicField.ptDataType = field.ptAuxDataType;
        dynamicField.ptAuxDataType = DT_NULL;

        if (!Encode(ptTypeDesc, static_cast<char*>(lpDefinition) + 4, dynamicField, tEncoder))
        {
            tEncoder.SetUsed(usedBefore);
            return false;
        }
    }

    return true;
}

XDecoder::Result OptionalDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    i32 hasValue = 0;
    XDecoder::Result result = tDecoder.GetBool(hasValue);
    if (result)
        return result;

    hasValue = rex::byte_swap(hasValue);  // BE -> LE, probably not really necessary in this case? let's keep it for consistency
    *static_cast<i32*>(lpDefinition) = hasValue;

    if (hasValue)
    {
        XTypeDescriptor* ptTypeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(field.ptAuxDataType);

        // The original doesn't use dynamic fields for this particular case,
        // but we use fields for dynamic dispatch, so we need a dynamic field here.
        // Copy the original field to preserve metadata like bit counts.
        TypeDescriptorField dynamicField = field;
        dynamicField.ptDataType = field.ptAuxDataType;
        dynamicField.ptAuxDataType = DT_NULL;

        result = Decode(ptTypeDesc, static_cast<char*>(lpDefinition) + 4, dynamicField, tDecoder);
        if (result)
            return result;
    }

    return XDecoder::RESULT_VALID;
}

bool FixedArrayEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nCount = field.nCount;
    size_t elementSize = XTypeDescriptor_SizeOf(field.ptAuxDataType);
    size_t usedBefore = tEncoder.GetUsed();

    if (field.dwFlags & (1 << TDF_VARIABLE_COUNT))
    {
        i32 nArraySizeBitCount = field.nArraySizeBitCount;
        if (tEncoder.GetUsed() + nArraySizeBitCount > tEncoder.GetSize())
            return false;

        nCount = *reinterpret_cast<i32*>(static_cast<u8*>(lpDefinition) + field.nUsedElementsOffset);
        nCount = rex::byte_swap(nCount);  // BE -> LE

        tEncoder.Put(nCount, nArraySizeBitCount);
    }

    XTypeDescriptor* ptAuxTypeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(field.ptAuxDataType);
    size_t offset = 0;

    // the original code allocates a dynamic field here, but doesn't use it and pass the original field instead
    TypeDescriptorField dynamicField = field;
    dynamicField.ptDataType = field.ptAuxDataType;
    dynamicField.ptAuxDataType = DT_NULL;

    for (i32 i = 0; i < nCount; ++i)
    {
        if (!Encode(ptAuxTypeDesc, static_cast<u8*>(lpDefinition) + offset, dynamicField, tEncoder))
        {
            tEncoder.SetUsed(usedBefore);
            return false;
        }

        offset += elementSize;
    }

    return true;
}

XDecoder::Result FixedArrayDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    i32 nCount = field.nCount;
    size_t elementSize = XTypeDescriptor_SizeOf(field.ptAuxDataType);

    XDecoder::Result result = XDecoder::RESULT_VALID;

    if (field.dwFlags & (1 << TDF_VARIABLE_COUNT))
    {
        i32 nArraySizeBitCount = field.nArraySizeBitCount;

        u32 dwCount = 0;
        XDecoder::Result result = tDecoder.Get(dwCount, field.nArraySizeBitCount);
        if (result)
            return result;

        if (dwCount > nCount)
            return XDecoder::RESULT_CORRUPTED;

        nCount = static_cast<i32>(dwCount);

        void* ptUsedElements = static_cast<u8*>(lpDefinition) + field.nUsedElementsOffset;
        *static_cast<u32*>(ptUsedElements) = rex::byte_swap(dwCount);    // LE -> BE
    }

    XTypeDescriptor* ptAuxTypeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(field.ptAuxDataType);
    size_t offset = 0;

    // the original code allocates a dynamic field here, but doesn't use it and pass the original field instead
    TypeDescriptorField dynamicField = field;
    dynamicField.ptDataType = field.ptAuxDataType;
    dynamicField.ptAuxDataType = DT_NULL;

    for (i32 i = 0; i < nCount; ++i)
    {
        result = Decode(ptAuxTypeDesc, static_cast<u8*>(lpDefinition) + offset, dynamicField, tDecoder);
        if (result)
            return result;

        offset += elementSize;
    }

    return XDecoder::RESULT_VALID;
}

bool CharArrayEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    size_t length = std::strlen(static_cast<char*>(lpDefinition));

    size_t prefixBits = field.nBitCount;

    size_t alignedPrefixBits = (prefixBits + 7) & ~size_t(7);
    size_t payloadBits = length * 8;

    if (tEncoder.GetUsed() + alignedPrefixBits + payloadBits > tEncoder.GetSize())
        return false;

    tEncoder.Put(length, prefixBits);
    tEncoder.PutAsciiStringBytesAligned8(static_cast<const uint8_t*>(lpDefinition), length);

    return true;
}

XDecoder::Result CharArrayDecode(void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 dwLength = 0;
    XDecoder::Result result = tDecoder.Get(dwLength, field.nBitCount);
    if (result)
        return result;

    if (dwLength > field.nCount)
        return XDecoder::RESULT_CORRUPTED;

    return tDecoder.GetAsciiStringBytesAligned8(static_cast<u8*>(lpDefinition), dwLength);
}

bool EncodePrimitive(const XTypeDescriptor* ptTypeDesc, void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    switch (field.ptDataType)
    {
        case DT_INT:
        case DT_INT_2:
        case DT_DATAID:
            return GenericIntEncode(lpDefinition, field, tEncoder);

        case DT_VELOCITY:
        case DT_ACCEL:
        case DT_MASS:
        case DT_IMPULSE:
        case DT_FLOAT:
        case DT_ANGLE:
        case DT_HIGHPRECISIONPERCENT:
            return GenericFloatEncode(lpDefinition, field, tEncoder);

        case DT_INT64:
            return Int64Encode(lpDefinition, field, tEncoder);

        case DT_WORD:
            return WordEncode(lpDefinition, field, tEncoder);

        case DT_BYTE:
            return ByteEncode(lpDefinition, field, tEncoder);

        case DT_PERCENT:
            return PercentEncode(lpDefinition, field, tEncoder);

        case DT_FLAG:
            return FlagEncode(lpDefinition, field, tEncoder);

        case DT_SNO:
        case DT_SNO_GROUP:
        case DT_SNONAME_HANDLE:
            return SnoEncode(lpDefinition, field, tEncoder);

        case DT_GBID:
            return GbidEncode(lpDefinition, field, tEncoder);

        case DT_OPTIONAL:
            return OptionalEncode(lpDefinition, field, tEncoder);

        case DT_FIXEDARRAY:
            return FixedArrayEncode(lpDefinition, field, tEncoder);

        case DT_CHARARRAY:
            return CharArrayEncode(lpDefinition, field, tEncoder);

        default:
            const char* szClassName = MemoryUtils::GetHostPtr<const char>(ptTypeDesc->szClassName);
            REXLOG_WARN("EncodePrimitive(): Unhandled primitive type {} (0x{:08X})", szClassName, field.ptDataType.value.get());
            return false;
    }

    return true;
}

XDecoder::Result DecodePrimitive(const XTypeDescriptor* ptTypeDesc, void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    switch (field.ptDataType)
    {
        case DT_INT:
        case DT_INT_2:
        case DT_DATAID:
            return GenericIntDecode(lpDefinition, field, tDecoder);

        case DT_VELOCITY:
        case DT_ACCEL:
        case DT_MASS:
        case DT_IMPULSE:
        case DT_FLOAT:
        case DT_ANGLE:
        case DT_HIGHPRECISIONPERCENT:
            return GenericFloatDecode(lpDefinition, field, tDecoder);

        case DT_INT64:
            return Int64Decode(lpDefinition, field, tDecoder);

        case DT_WORD:
            return WordDecode(lpDefinition, field, tDecoder);

        case DT_BYTE:
            return ByteDecode(lpDefinition, field, tDecoder);

        case DT_PERCENT:
            return PercentDecode(lpDefinition, field, tDecoder);

        case DT_FLAG:
            return FlagDecode(lpDefinition, field, tDecoder);

        case DT_SNO:
        case DT_SNO_GROUP:
        case DT_SNONAME_HANDLE:
            return SnoDecode(lpDefinition, field, tDecoder);

        case DT_GBID:
            return GbidDecode(lpDefinition, field, tDecoder);

        case DT_OPTIONAL:
            return OptionalDecode(lpDefinition, field, tDecoder);

        case DT_FIXEDARRAY:
            return FixedArrayDecode(lpDefinition, field, tDecoder);

        case DT_CHARARRAY:
            return CharArrayDecode(lpDefinition, field, tDecoder);

        default:
            const char* szClassName = MemoryUtils::GetHostPtr<const char>(ptTypeDesc->szClassName);
            REXLOG_WARN("DecodePrimitive(): Unhandled primitive type {} (0x{:08X})", szClassName, field.ptDataType.value.get());
            return XDecoder::RESULT_CORRUPTED;
    }
}

bool Encode(const XTypeDescriptor* ptTypeDesc, void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    u32 nFieldCount = ptTypeDesc->nFieldCount;

    if (!nFieldCount)
        return EncodePrimitive(ptTypeDesc, lpDefinition, field, tEncoder);

    size_t usedBefore = tEncoder.GetUsed();

    TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(ptTypeDesc->arFields);

    for (int i = 0; i < nFieldCount; ++i)
    {
        TypeDescriptorField& subfield = arFields[i];
        if (subfield.ptDataType == DT_NULL)
            break;

        if (!GameMessageTranslator::IsFieldPCCompatible(field.ptDataType, subfield))
            continue;

        // Bit count overrides for some fields (mostly player index)
        i32 nBitCountOriginal = subfield.nBitCount;
        i32 nBitCountOverride = GameMessageTranslator::GetFieldBitCountOverride(field.ptDataType, subfield);

        if (nBitCountOverride != -1)
            subfield.nBitCount = nBitCountOverride;

        XTypeDescriptor* ptSubfieldType = MemoryUtils::GetHostPtr<XTypeDescriptor>(subfield.ptDataType);
        bool encoded = Encode(ptSubfieldType, static_cast<u8*>(lpDefinition) + subfield.nDataOffset.get(), subfield, tEncoder);

        if (nBitCountOverride != -1)
            subfield.nBitCount = nBitCountOriginal;

        if (!encoded)
        {
            tEncoder.SetUsed(usedBefore);
            return false;
        }

        // HACK: encode snoMusic twice to fill SceneSpecification.snoCombatMusic
        if (field.ptDataType == 0x82FA7574 && subfield.nDataOffset == 52)
        {
            int snoCombatMusic = -1;    // SNO_NONE
            if (!Encode(ptSubfieldType, &snoCombatMusic, subfield, tEncoder))
            {
                tEncoder.SetUsed(usedBefore);
                return false;
            }
        }
        // HACK end

        // HACK: Write nNumQuestRewardEntries in HeroStateData
        if (field.ptDataType == 0x82FA7AFC && subfield.nDataOffset == 20)
        {
            TypeDescriptorField dynamicField = {};
            dynamicField.ptDataType = DT_INT;
            dynamicField.ptAuxDataType = DT_NULL;
            dynamicField.nDataOffset = 2436;
            dynamicField.nBitCount = 32;
            ptSubfieldType = MemoryUtils::GetHostPtr<XTypeDescriptor>(dynamicField.ptDataType);
            if (!Encode(ptSubfieldType, static_cast<u8*>(lpDefinition) + dynamicField.nDataOffset.get(), dynamicField, tEncoder))
            {
                tEncoder.SetUsed(usedBefore);
                return false;
            }
        }
        // HACK end
    }

    return true;
}

XDecoder::Result Decode(const XTypeDescriptor* ptTypeDesc, void* lpDefinition, const TypeDescriptorField& field, XDecoder& tDecoder)
{
    u32 nFieldCount = ptTypeDesc->nFieldCount;

    if (!nFieldCount)
        return DecodePrimitive(ptTypeDesc, lpDefinition, field, tDecoder);

    TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(ptTypeDesc->arFields);

    for (int i = 0; i < nFieldCount; ++i)
    {
        TypeDescriptorField& subfield = arFields[i];
        if (subfield.ptDataType == DT_NULL)
            break;

        XTypeDescriptor* ptSubfieldType = MemoryUtils::GetHostPtr<XTypeDescriptor>(subfield.ptDataType);
        XDecoder::Result result = Decode(ptSubfieldType, static_cast<u8*>(lpDefinition) + subfield.nDataOffset.get(), subfield, tDecoder);
        if (result)
            return result;
    }

    return XDecoder::RESULT_VALID;
}

}  // namespace

bool GameMessageEncoder::EncodeMessage(void* pMessage, XEncoder& tEncoder)
{
    RequiredMessageHeader* header = static_cast<RequiredMessageHeader*>(pMessage);

    u32 pTypeDescriptor = 0;
    u32 dwSize = 0;
    const char* pszMessageLabel = nullptr;
    GetGameMessageTypeAndSize(header->eType, pTypeDescriptor, dwSize, pszMessageLabel);

    size_t usedBefore = tEncoder.GetUsed();

    XTypeDescriptor* ptTypeDescHost = MemoryUtils::GetHostPtr<XTypeDescriptor>(pTypeDescriptor);

    TypeDescriptorField dynamicField = {};  // TODO?: full constructor for dynamic fields
    dynamicField.ptDataType = pTypeDescriptor;
    dynamicField.ptAuxDataType = DT_NULL;

    // Translate Console -> PC right before encode to keep other code consistent with the console version
    GameMessageTranslator::TranslateMessageConsoleToPC(pMessage);

    bool encoded = Encode(ptTypeDescHost, pMessage, dynamicField, tEncoder);

    // Revert translation so that special message encoding code below works correctly
    GameMessageTranslator::TranslateMessagePCToConsole(pMessage);

    if (!encoded)
        goto cleanup;

    if (pTypeDescriptor == DT_GENERIC_BLOB_MESSAGE)
    {
        u32 blobSize = static_cast<GenericBlobMessage*>(pMessage)->uBlobSize;

        if ((tEncoder.GetSizeBytes() - tEncoder.GetUsedBytes()) < blobSize)
            goto cleanup;

        tEncoder.PutBytesAligned8(static_cast<uint8_t*>(pMessage) + 12, blobSize);
    }
    else if (header->eType == SMSG_ATTRIBUTE_SET_VALUE)
    {
        AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pMessage);
        if (!AttributeCompressor_Encode(tEncoder, attributeSetValueMessage->tKeyVal))
            goto cleanup;
    }
    else if (header->eType == SMSG_ATTRIBUTES_SET_VALUES)
    {
        AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pMessage);
        int attributeCount = attributesSetValuesMessage->nAttributeCount;
        for (int i = 0; i < attributeCount; ++i)
        {
            if (!AttributeCompressor_Encode(tEncoder, attributesSetValuesMessage->atKeyVals[i]))
                goto cleanup;
        }
    }

    return true;

cleanup:
    // valid path when encode buffer gets filled (e.g. on initial load)
    tEncoder.SetUsed(usedBefore);
    return false;
}

XDecoder::Result GameMessageEncoder::DecodeMessage(GameMessageType eMessageType, void* pDecodeToBuffer, u32 dwBufferSize, XDecoder& tDecoder)
{
    u32 pTypeDescriptor = 0;
    u32 dwSize = 0;
    const char* pszMessageLabel = nullptr;
    if (!GetGameMessageTypeAndSize(eMessageType, pTypeDescriptor, dwSize, pszMessageLabel))
        return XDecoder::RESULT_CORRUPTED;

    const XTypeDescriptor* ptTypeDescHost = MemoryUtils::GetHostPtr<const XTypeDescriptor>(pTypeDescriptor);

    TypeDescriptorField dynamicField = {};
    dynamicField.ptDataType = pTypeDescriptor;
    dynamicField.ptAuxDataType = DT_NULL;

    XDecoder::Result result = Decode(ptTypeDescHost, pDecodeToBuffer, dynamicField, tDecoder);
    if (result)
        return result;

    if (pTypeDescriptor == DT_GENERIC_BLOB_MESSAGE)
    {
        // Used by the client in CMSG_SAVE_BANNER
        u32 blobSize = static_cast<GenericBlobMessage*>(pDecodeToBuffer)->uBlobSize;

        if (blobSize > 0x8000 || (tDecoder.GetSizeBytes() - tDecoder.GetUsedBytes()) < blobSize)
            return XDecoder::RESULT_CORRUPTED;

        tDecoder.GetBytesAligned8(static_cast<uint8_t*>(pDecodeToBuffer) + 12, blobSize);
    }
    else if (eMessageType == SMSG_ATTRIBUTE_SET_VALUE)
    {
        AttributeSetValueMessage* attributeSetValueMessage = static_cast<AttributeSetValueMessage*>(pDecodeToBuffer);
        result = AttributeCompressor_Decode(tDecoder, attributeSetValueMessage->tKeyVal);
        if (result)
            return result;
    }
    else if (eMessageType == SMSG_ATTRIBUTES_SET_VALUES)
    {
        AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<AttributesSetValuesMessage*>(pDecodeToBuffer);
        int attributeCount = attributesSetValuesMessage->nAttributeCount;
        for (int i = 0; i < attributeCount; ++i)
        {
            result = AttributeCompressor_Decode(tDecoder, attributesSetValuesMessage->atKeyVals[i]);
            if (result)
                return result;
        }
    }

    return XDecoder::RESULT_VALID;
}
