#include "recomp/static_data_dumper.h"

#include <cstring>
#include <fstream>
#include <set>
#include <vector>

#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/memory_utils.h"
#include "game/network/game_message_type.h"
#include "game/sigma/type_descriptor/type_descriptor.h"

template <typename T>
using GuestPtr = rex::TypedGuestPointer<T>;

template <typename T>
using GuestPtrSet = std::set<GuestPtr<T>>;

namespace {
    void DiscoverTypeDescriptors(GuestPtr<XTypeDescriptor> typeDescPtr, GuestPtrSet<XTypeDescriptor>& primitiveDescriptors,
        GuestPtrSet<ComplexTypeDescriptor>& complexDescriptors, GuestPtrSet<char>& strings)
    {
        XTypeDescriptor* typeDesc = MemoryUtils::GetHostPtr<XTypeDescriptor>(typeDescPtr);
        if (!typeDesc)
            return;

        if (typeDesc->szName)
            strings.insert(typeDesc->szName);

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

    template <typename T>
    void WriteToStream(std::ofstream& stream, const T* data, std::size_t count = 1)
    {
        stream.write(reinterpret_cast<const char*>(data), count * sizeof(T));
    }
}

void StaticDataDumper::DumpTypeDescriptors(const char* fileName)
{
    REXLOG_INFO("Dumping type descriptors...");

    GuestPtrSet<XTypeDescriptor> primitiveDescriptors{};
    GuestPtrSet<ComplexTypeDescriptor> complexDescriptors{};
    GuestPtrSet<char> strings{};

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

    REXLOG_INFO("Writing type descriptors...");

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

REX_IMPORT(__imp__GetGameMessageTypeAndSize, GetGameMessageTypeAndSize, u32(u32, u32, u32, u32));

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

    for (int i = MSG_INVALID + 1; i <= MSG_NUM_MESSAGES; i++)
    {
        rex::ppc::stack_guard guard(frame.ctx);

        u32 pTypeDescriptorPtr = rex::ppc::stack_push(frame.ctx, base, 0);
        u32 dwSizePtr = rex::ppc::stack_push(frame.ctx, base, 0);
        u32 pszMessageLabelPtr = rex::ppc::stack_push(frame.ctx, base, 0);

        u32 result = GetGameMessageTypeAndSize(i, pTypeDescriptorPtr, dwSizePtr, pszMessageLabelPtr);
        if (!result)
            continue;

        GameMessageInfo gameMessageInfo;
        gameMessageInfo.eMessageType = i;
        gameMessageInfo.pTypeDescriptor = *MemoryUtils::GetHostPtr<rex::be<u32>>(pTypeDescriptorPtr);
        gameMessageInfo.dwSize = *MemoryUtils::GetHostPtr<rex::be<u32>>(dwSizePtr);
        gameMessageInfo.pszMessageLabel = *MemoryUtils::GetHostPtr<rex::be<u32>>(pszMessageLabelPtr);
        gameMessages.push_back(gameMessageInfo);
    }

    REXLOG_INFO("Writing game messages...");

    std::ofstream file(fileName, std::ios::binary);

    int count = gameMessages.size();
    WriteToStream(file, &count);
    WriteToStream(file, &gameMessages.front(), count);

    REXLOG_INFO("Finished dumping game messages");
}

