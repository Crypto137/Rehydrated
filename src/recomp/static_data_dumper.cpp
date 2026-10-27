#include "recomp/static_data_dumper.h"

#include <cstring>
#include <fstream>
#include <set>
#include <vector>

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/io.h"
#include "core/memory_utils.h"
#include "game/attributes/attribute_compressor.h"
#include "game/attributes/attrib_defs.h"
#include "game/network/game_message_type.h"
#include "game/sigma/type_descriptor/type_descriptor.h"

using namespace IO;

REXCVAR_DEFINE_BOOL(dump_type_descriptors, false, "Hydra/Static Data", "Dumps type descriptors on startup")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_BOOL(dump_game_messages, false, "Hydra/Static Data", "Dumps game message metadata on startup")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

REXCVAR_DEFINE_BOOL(dump_attrib_defs, false, "Hydra/Static Data", "Dumps attribute definitions on startup")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

template <typename T>
using GuestPtr = rex::TypedGuestPointer<T>;

template <typename T>
using GuestPtrSet = std::set<GuestPtr<T>>;

namespace
{

void DiscoverTypeDescriptors(GuestPtr<XTypeDescriptor> typeDescPtr, GuestPtrSet<XTypeDescriptor>& primitiveDescriptors,
    GuestPtrSet<ComplexTypeDescriptor>& complexDescriptors, GuestPtrSet<const char>& strings)
{
    XTypeDescriptor* typeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(typeDescPtr);
    if (!typeDesc)
        return;

    if (typeDesc->szClassName)
        strings.insert(typeDesc->szClassName);

    int fieldCount = typeDesc->nFieldCount;
    if (fieldCount == 0)
    {
        primitiveDescriptors.insert(typeDescPtr);
        return;
    }

    GuestPtr<ComplexTypeDescriptor> complexTypeDescPtr{};
    complexTypeDescPtr.value = typeDescPtr.value;
    auto inserted = complexDescriptors.insert(complexTypeDescPtr);
    if (!inserted.second)   // already inserted, this protects against infinite loops in recursive types (e.g. ConversationTreeNode)
        return;

    ComplexTypeDescriptor* complexTypeDesc = static_cast<ComplexTypeDescriptor*>(typeDesc);
    TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(complexTypeDesc->arFields);
    for (int i = 0; i < fieldCount; ++i)
    {
        TypeDescriptorField* field = &arFields[i];

        if (field->szFieldName)
            strings.insert(field->szFieldName);

        // TODO: dump SymbolicEntry            

        DiscoverTypeDescriptors(field->ptDataType, primitiveDescriptors, complexDescriptors, strings);
        DiscoverTypeDescriptors(field->ptAuxDataType, primitiveDescriptors, complexDescriptors, strings);
    }
}

}  // namespace

void StaticDataDumper::OnNetworkInitializeForAppFinished()
{
    if (REXCVAR_GET(dump_type_descriptors))
        StaticDataDumper::DumpTypeDescriptors("_TypeDescriptors.bin");

    if (REXCVAR_GET(dump_game_messages))
        StaticDataDumper::DumpGameMessages("_GameMessages.bin");
}

void StaticDataDumper::OnFastAttribInitializeForAppFinished()
{
    if (REXCVAR_GET(dump_attrib_defs))
        StaticDataDumper::DumpAttribDefs("_AttribDefs.bin");
}

void StaticDataDumper::DumpTypeDescriptors(const char* fileName)
{
    REXLOG_INFO("Dumping type descriptors...");

    GuestPtrSet<XTypeDescriptor> primitiveDescriptors{};
    GuestPtrSet<ComplexTypeDescriptor> complexDescriptors{};
    GuestPtrSet<const char> strings{};

    REXLOG_INFO("Discovering type descriptors...");

    GuestPtr<ComplexTypeDescriptor> typeDescPtr = *MemoryUtils::GetHostPtr<rex::TypedGuestPointer<ComplexTypeDescriptor>>(ComplexTypeDescriptor::pRegistrationHead);
    while (typeDescPtr)
    {
        GuestPtr<XTypeDescriptor> castTypeDescPtr{};
        castTypeDescPtr.value = typeDescPtr.value;

        DiscoverTypeDescriptors(castTypeDescPtr, primitiveDescriptors, complexDescriptors, strings);

        ComplexTypeDescriptor* typeDesc = MemoryUtils::GetHostPtr<ComplexTypeDescriptor>(typeDescPtr);
        if (!typeDesc)
            break;

        typeDescPtr = typeDesc->pNextRegisteredDescriptor;
    }

    REXLOG_INFO("Writing type descriptors to {}...", fileName);

    std::ofstream file(fileName, std::ios::binary);

    int numPrimitiveDescriptors = primitiveDescriptors.size();
    WriteToStream(file, &numPrimitiveDescriptors);
    for (auto& primitiveDescPtr : primitiveDescriptors)
    {
        WriteToStream(file, &primitiveDescPtr.value);

        XTypeDescriptor* primitiveDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(primitiveDescPtr);
        if (!primitiveDesc)
            continue;

        WriteToStream(file, primitiveDesc);
    }

    int numComplexDescriptors = complexDescriptors.size();
    WriteToStream(file, &numComplexDescriptors);
    for (auto& complexDescPtr : complexDescriptors)
    {
        WriteToStream(file, &complexDescPtr.value);

        ComplexTypeDescriptor* complexDesc = MemoryUtils::GetHostPtr<ComplexTypeDescriptor>(complexDescPtr);
        if (!complexDesc)
            continue;

        WriteToStream(file, complexDesc);

        TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(complexDesc->arFields);
        if (arFields)
        {
            u32 nFieldCount = complexDesc->nFieldCount;
            WriteToStream(file, arFields, nFieldCount);
        }
    }

    int numStrings = strings.size();
    WriteToStream(file, &numStrings);
    for (auto& strPtr : strings)
    {
        WriteToStream(file, &strPtr.value);

        char* str = MemoryUtils::GetHostPtr<char>(strPtr);
        if (!str)
            continue;

        WriteToStream(file, str, std::strlen(str) + 1);
    }

    REXLOG_INFO("Finished dumping type descriptors");
}

REX_IMPORT(__imp__GetGameMessageTypeAndSize, Guest_GetGameMessageTypeAndSize, u32(u32, u32, u32, u32));

namespace {

struct GameMessageInfo
{
    rex::be<u32> eMessageType;
    rex::be<u32> pTypeDescriptor;
    rex::be<u32> dwSize;
    rex::be<u32> pszMessageLabel;
};

}

void StaticDataDumper::DumpGameMessages(const char* fileName)
{
    REXLOG_INFO("Dumping game messages...");

    auto* memory = REX_KERNEL_MEMORY();
    if (!memory)
        return;
    auto* base = memory->virtual_membase();

    rex::CallFrame frame(*rex::runtime::ThreadState::Get()->context());

    std::vector<GameMessageInfo> gameMessages{};
    gameMessages.reserve(MSG_NUM_MESSAGES);

    for (int i = MSG_INVALID + 1; i <= MSG_NUM_MESSAGES; ++i)
    {
        rex::ppc::stack_guard guard(frame.ctx);

        u32 pTypeDescriptorPtr = rex::ppc::stack_push(frame.ctx, base, 0);
        u32 dwSizePtr = rex::ppc::stack_push(frame.ctx, base, 0);
        u32 pszMessageLabelPtr = rex::ppc::stack_push(frame.ctx, base, 0);

        u32 result = Guest_GetGameMessageTypeAndSize(i, pTypeDescriptorPtr, dwSizePtr, pszMessageLabelPtr);
        if (!result)
            continue;

        GameMessageInfo gameMessageInfo;
        gameMessageInfo.eMessageType = i;
        gameMessageInfo.pTypeDescriptor = *MemoryUtils::GetHostPtr<rex::be<u32>>(pTypeDescriptorPtr);
        gameMessageInfo.dwSize = *MemoryUtils::GetHostPtr<rex::be<u32>>(dwSizePtr);
        gameMessageInfo.pszMessageLabel = *MemoryUtils::GetHostPtr<rex::be<u32>>(pszMessageLabelPtr);
        gameMessages.push_back(gameMessageInfo);
    }

    REXLOG_INFO("Writing game messages to {}...", fileName);

    std::ofstream file(fileName, std::ios::binary);

    int count = gameMessages.size();
    WriteToStream(file, &count);
    WriteToStream(file, &gameMessages.front(), count);

    REXLOG_INFO("Finished dumping game messages");
}

void StaticDataDumper::DumpAttribDefs(const char* fileName)
{
    REXLOG_INFO("Dumping attribute definitions...");

    constexpr u32 cgarAttribDefs = 0x82F9DA88;

    GuestPtrSet<const char> strings{};
    GuestPtrSet<AttributeCompressor> compressors{};

    AttribDef* attribDefs = MemoryUtils::GetHostPtr<AttribDef>(cgarAttribDefs);
    for (int i = ATTRIBUTE_AXEBADDATA; i < NUM_ATTRIBUTES; ++i)
    {
        if (attribDefs[i].pszFormulaItem)
            strings.insert(attribDefs[i].pszFormulaItem);

        if (attribDefs[i].pszFormulaCharacter)
            strings.insert(attribDefs[i].pszFormulaCharacter);

        if (attribDefs[i].pszName)
            strings.insert(attribDefs[i].pszName);

        if (attribDefs[i].ptCompressor)
            compressors.insert(attribDefs[i].ptCompressor);
    }

    REXLOG_INFO("Writing attribute definitions to {}...", fileName);

    std::ofstream file(fileName, std::ios::binary);

    int count = NUM_ATTRIBUTES;
    WriteToStream(file, &count);
    WriteToStream(file, attribDefs, count);

    int numCompressors = compressors.size();
    WriteToStream(file, &numCompressors);
    for (auto& compressorPtr : compressors)
    {
        WriteToStream(file, &compressorPtr.value);

        AttributeCompressor* compressor = MemoryUtils::GetHostPtr<AttributeCompressor>(compressorPtr);
        if (!compressor)
            continue;

        switch (compressor->m_eType)
        {
            case ACT_UNCOMPRESSED:
                WriteToStream(file, static_cast<AttributeCompressorUncompressed*>(compressor));
                break;

            case ACT_BOUNDED_INT:
                WriteToStream(file, static_cast<AttributeCompressorBoundedInt*>(compressor));
                break;

            case ACT_LINEAR_FLOAT:
                WriteToStream(file, static_cast<AttributeCompressorLinearFloat*>(compressor));
                break;

            case ACT_FLOAT16:
                WriteToStream(file, static_cast<AttributeCompressorFloat16*>(compressor));
                break;

            case ACT_FLOAT_VARIABLE:
                WriteToStream(file, static_cast<AttributeCompressorFloatVariable*>(compressor));
                break;

            default:
                REXLOG_WARN("Unknown attribute compressor type 0x{:08X}", static_cast<u32>(compressor->m_eType));
                return;
        }
    }

    int numStrings = strings.size();
    WriteToStream(file, &numStrings);
    for (auto& strPtr : strings)
    {
        WriteToStream(file, &strPtr.value);

        const char* str = MemoryUtils::GetHostPtr<const char>(strPtr);
        if (!str)
            continue;

        WriteToStream(file, str, std::strlen(str) + 1);
    }

    REXLOG_INFO("Finished dumping attribute definitions");
}
