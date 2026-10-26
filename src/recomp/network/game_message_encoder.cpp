#include "recomp/network/game_message_encoder.h"

#include <bit>
#include <cstring>

#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/sigma/type_descriptor/type_descriptor.h"

namespace
{

bool AttributeCompressor_Encode(XEncoder& tEncoder, NetAttributeKeyValue& tKeyValue)
{
    // TODO
    return true;
}

// forward declare Encode to be able to call it recursively in subfunctions
bool Encode(const XTypeDescriptor* ptTypeDesc, void* pMessage, const TypeDescriptorField& field, XEncoder& tEncoder);

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
        // TODO?: XFloat16
        uData = 0;
    }
    else
    {
        uData = std::bit_cast<u32, f32>(value);
    }

    tEncoder.Put(uData, 32);
    return true;
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

bool PercentEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    i32 nBitCount = field.nBitCount;
    if (tEncoder.GetUsed() + nBitCount > tEncoder.GetSize())
        return false;

    u8 value = *static_cast<u8*>(lpDefinition);

    tEncoder.Put(value, nBitCount);
    return true;
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

bool OptionalEncode(void* lpDefinition, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    size_t usedBefore = tEncoder.GetUsed();
    if (usedBefore == tEncoder.GetSize())
        return false;

    i32 hasValue = *static_cast<int*>(lpDefinition);
    hasValue = rex::byte_swap(hasValue);  // BE -> LE, probably not really necessary in this case? let's keep it for consistency

    tEncoder.PutBool(hasValue);

    if (hasValue)
    {
        XTypeDescriptor* ptTypeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(field.ptAuxDataType);
        if (!Encode(ptTypeDesc, static_cast<char*>(lpDefinition) + 4, field, tEncoder))
        {
            tEncoder.SetUsed(usedBefore);
            return false;
        }
    }

    return true;
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

    TypeDescriptorField dynamicField = {};
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

bool EncodePrimitive(const XTypeDescriptor* ptTypeDesc, void* pMessage, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    switch (field.ptDataType)
    {
        case DT_INT:
        case DT_INT_2:
        case DT_DATAID:
            return GenericIntEncode(pMessage, field, tEncoder);

        case DT_VELOCITY:
        case DT_ACCEL:
        case DT_MASS:
        case DT_IMPULSE:
        case DT_FLOAT:
        case DT_ANGLE:
        case DT_HIGHPRECISIONPERCENT:
            return GenericFloatEncode(pMessage, field, tEncoder);

        case DT_INT64:
            return Int64Encode(pMessage, field, tEncoder);

        case DT_WORD:
            return WordEncode(pMessage, field, tEncoder);

        case DT_BYTE:
            return ByteEncode(pMessage, field, tEncoder);

        case DT_PERCENT:
            return PercentEncode(pMessage, field, tEncoder);

        case DT_FLAG:
            return FlagEncode(pMessage, field, tEncoder);

        case DT_SNO:
        case DT_SNO_GROUP:
        case DT_SNONAME_HANDLE:
            return SnoEncode(pMessage, field, tEncoder);

        case DT_GBID:
            return GbidEncode(pMessage, field, tEncoder);

        case DT_OPTIONAL:
            return OptionalEncode(pMessage, field, tEncoder);

        case DT_FIXEDARRAY:
            return FixedArrayEncode(pMessage, field, tEncoder);

        case DT_CHARARRAY:
            return CharArrayEncode(pMessage, field, tEncoder);

        default:
            const char* szClassName = MemoryUtils::GetHostPtr<const char>(ptTypeDesc->szClassName);
            REXLOG_WARN("EncodePrimitive(): Unhandled primitive type {} (0x{:08X})", szClassName, field.ptDataType.value.get());
            return false;
    }

    return true;
}

bool Encode(const XTypeDescriptor* ptTypeDesc, void* pMessage, const TypeDescriptorField& field, XEncoder& tEncoder)
{
    u32 nFieldCount = ptTypeDesc->nFieldCount;

    if (!nFieldCount)
        return EncodePrimitive(ptTypeDesc, pMessage, field, tEncoder);

    size_t usedBefore = tEncoder.GetUsed();

    TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(ptTypeDesc->arFields);

    for (int i = 0; i < nFieldCount; ++i)
    {
        TypeDescriptorField& field = arFields[i];
        if (field.ptDataType == DT_NULL)
            break;

        XTypeDescriptor* ptChildType = MemoryUtils::GetHostPtr<XTypeDescriptor>(field.ptDataType);
        if (!Encode(ptChildType, static_cast<u8*>(pMessage) + field.nDataOffset.get(), field, tEncoder))
        {
            tEncoder.SetUsed(usedBefore);
            return false;
        }
    }

    return true;
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

    TypeDescriptorField dynamicField = {};  // TODO?: full constructor for dynamic fields
    dynamicField.ptDataType = pTypeDescriptor;
    dynamicField.ptAuxDataType = DT_NULL;

    XTypeDescriptor* ptTypeDescHost = MemoryUtils::GetHostPtr<XTypeDescriptor>(pTypeDescriptor);
    if (!Encode(ptTypeDescHost, pMessage, dynamicField, tEncoder))
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
    // TODO
    return XDecoder::RESULT_VALID;
}
