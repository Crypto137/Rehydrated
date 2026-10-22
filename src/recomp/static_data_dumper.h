#pragma once

namespace StaticDataDumper {

void OnNetworkInitializeForAppFinished();

void OnFastAttribInitializeForAppFinished();

void DumpTypeDescriptors(const char* fileName);

void DumpGameMessages(const char* fileName);

void DumpAttribDefs(const char* fileName);

}  // namespace TypeDescriptorDumper