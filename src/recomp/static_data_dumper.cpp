#include "recomp/static_data_dumper.h"

#include <cstring>
#include <fstream>
#include <set>

#include <rex/logging.h>

#include "core/memory_utils.h"
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
        complexDescriptors.insert(complexTypeDescPtr);

        ComplexTypeDescriptor* complexTypeDesc = static_cast<ComplexTypeDescriptor*>(typeDesc);        
        TypeDescriptorField* arFields = MemoryUtils::GetHostPtr<TypeDescriptorField>(complexTypeDesc->arFields);
        for (int i = 0; i < fieldCount; ++i)
        {
            TypeDescriptorField* field = &arFields[i];

            if (field->szFieldName)
                strings.insert(field->szFieldName);

            // TODO: dump SymbolicEntry            

            DiscoverTypeDescriptors(field->ptDataType, primitiveDescriptors, complexDescriptors, strings);
            //DiscoverTypeDescriptors(field->ptAuxDataType, primitiveDescriptors, complexDescriptors, strings); // TODO: add ConversationTreeNode handling
        }
    }

    template <typename T>
    void WriteToStream(std::ofstream& stream, const T* data, std::size_t count = 1)
    {
        stream.write(reinterpret_cast<const char*>(data), count * sizeof(T));
    }
}

void StaticDataDumper::DumpTypeDescriptors(rex::TypedGuestPointer<ComplexTypeDescriptor> typeDescPtr, char* fileName)
{
    REXLOG_INFO("Dumping type descriptors...");

    GuestPtrSet<XTypeDescriptor> primitiveDescriptors{};
    GuestPtrSet<ComplexTypeDescriptor> complexDescriptors{};
    GuestPtrSet<char> strings{};

    REXLOG_INFO("Discovering type descriptors...");

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

