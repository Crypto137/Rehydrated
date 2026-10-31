#pragma once

#include <rex/types.h>

#include "game/attributes/attrib.h"
#include "game/network/game_message.h"

struct TypeDescriptorField;

namespace GameMessageTranslator
{

GameMessageType ConvertMessageTypeConsoleToPC(GameMessageType eConsoleType);

GameMessageType ConvertMessageTypePCToConsole(GameMessageType ePCType);

Attrib ConvertAttribConsoleToPC(Attrib eConsoleAttrib);

Attrib ConvertAttribPCToConsole(Attrib ePCAttrib);

GBID ConvertGbidConsoleToPC(GBID gbidConsole);

GBID ConvertGbidPCToConsole(GBID gbidPC);

void TranslateMessageConsoleToPC(void* pMessage);

void TranslateMessagePCToConsole(void* pMessage);

bool IsMessagePCCompatible(void* pMessage);

bool IsFieldPCCompatible(u32 ptTypeDescriptor, const TypeDescriptorField& field);

u32 GetTypeDescriptorOverride(GameMessageType eConsoleType);

int GetFieldBitCountOverride(u32 ptTypeDescriptor, const TypeDescriptorField& field);

}
