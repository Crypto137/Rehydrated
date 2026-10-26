#pragma once

#include <string>

struct GameConnection;
struct RequiredMessageHeader;

namespace GameMessageDumper
{

std::string PrintGameMessage(const RequiredMessageHeader* pMessage);

void OnServerSendOutgoingMessages(const GameConnection* ptGameConnection);

void OnServerMessageReceiveOutsideGame(int idServerSocket, const RequiredMessageHeader* pMessage);

}
