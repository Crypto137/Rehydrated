#pragma once

struct RequiredMessageHeader;

namespace GameMessageTranslator
{

bool ConsoleToPC(RequiredMessageHeader* pMessage);

bool PCToConsole(RequiredMessageHeader* pMessage);

}
