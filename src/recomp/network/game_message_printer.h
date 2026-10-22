#pragma once

#include <string>

struct RequiredMessageHeader;

namespace GameMessagePrinter
{

std::string PrintGameMessage(const RequiredMessageHeader* pMessage);

}