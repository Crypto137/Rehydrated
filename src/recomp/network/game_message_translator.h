#pragma once

struct RequiredMessageHeader;

namespace GameMessageTranslator
{

void ConsoleToPC(RequiredMessageHeader* pMessage);

void PCToConsole(RequiredMessageHeader* pMessage);

}