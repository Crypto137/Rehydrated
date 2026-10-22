#pragma once

#include <fstream>

namespace IO
{

template <typename T>
void WriteToStream(std::ofstream& stream, const T* data, std::size_t count = 1)
{
    stream.write(reinterpret_cast<const char*>(data), count * sizeof(T));
}

}
