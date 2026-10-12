#pragma once

#include <rex/system/xtypes.h>

struct ComplexTypeDescriptor;

namespace StaticDataDumper {

void DumpTypeDescriptors(rex::TypedGuestPointer<ComplexTypeDescriptor> typeDescPtr, char* fileName);

}  // namespace TypeDescriptorDumper