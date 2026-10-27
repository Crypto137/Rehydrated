#pragma once

#include "game/attributes/attrib.h"
#include "game/network/game_message.h"

namespace GameMessageTranslator
{

GameMessageType ConvertMessageTypeConsoleToPC(GameMessageType eConsoleType);

GameMessageType ConvertMessageTypePCToConsole(GameMessageType ePCType);

Attrib ConvertAttribConsoleToPC(Attrib eConsoleAttrib);

Attrib ConvertAttribPCToConsole(Attrib ePCAttrib);

void TranslateMessageConsoleToPC(void* pMessage);

void TranslateMessagePCToConsole(void* pMessage);

bool IsMessagePCCompatible(void* pMessage);

}
