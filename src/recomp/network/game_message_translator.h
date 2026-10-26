#pragma once

#include "game/network/game_message.h"

namespace GameMessageTranslator
{

GameMessageType ConvertMessageTypeConsoleToPC(GameMessageType eConsoleType);

GameMessageType ConvertMessageTypePCToConsole(GameMessageType ePCType);

}
