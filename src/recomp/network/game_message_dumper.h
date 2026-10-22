#pragma once

struct GameConnection;
struct RequiredMessageHeader;

namespace GameMessageDumper
{

void OnServerSendOutgoingMessages(const GameConnection* ptGameConnection);

void OnServerMessageReceiveOutsideGame(int idServerSocket, const RequiredMessageHeader* pMessage);

}
