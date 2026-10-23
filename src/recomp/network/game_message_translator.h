#pragma once

struct GameConnection;
struct RequiredMessageHeader;

namespace GameMessageTranslator
{

void ConsoleToPC(RequiredMessageHeader* pMessage);

void PCToConsole(RequiredMessageHeader* pMessage);

void EncodePC(const GameConnection* ptGameConnection, char*& buffer, int& len);

}