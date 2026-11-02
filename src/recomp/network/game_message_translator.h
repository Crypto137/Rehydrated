#pragma once

#include <rex/types.h>

#include "game/types.h"
#include "game/attributes/attrib.h"
#include "game/network/game_message.h"

struct TypeDescriptorField;

namespace GameMessageTranslator
{

GameMessageType ConvertMessageTypeConsoleToPC(GameMessageType eConsoleType);

GameMessageType ConvertMessageTypePCToConsole(GameMessageType ePCType);

Attrib ConvertAttribConsoleToPC(Attrib eConsoleAttrib);

Attrib ConvertAttribPCToConsole(Attrib ePCAttrib);

SNO ConvertSnoConsoleToPC(SNOGroup snoGroup, SNO snoConsole);

SNO ConvertSnoPCToConsole(SNOGroup snoGroup, SNO snoPC);

GBID ConvertGbidConsoleToPC(GameBalanceType eType, GBID gbidConsole);

GBID ConvertGbidPCToConsole(GameBalanceType eType, GBID gbidPC);

void TranslateMessageConsoleToPC(void* pMessage);

void TranslateMessagePCToConsole(void* pMessage);

bool IsMessageAllowedForConsolePassthrough(void* pMessage);

bool IsMessagePCCompatible(void* pMessage);

bool IsFieldPCCompatible(u32 ptTypeDescriptor, const TypeDescriptorField& field);

u32 GetTypeDescriptorOverride(GameMessageType eConsoleType);

int GetFieldBitCountOverride(u32 ptTypeDescriptor, const TypeDescriptorField& field);

}
