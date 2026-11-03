#pragma once

#include <list>
#include <memory>
#include <mutex>

#include <rex/types.h>

#include "core/network/tcp_server.h"
#include "core/network/tcp_session_consumer.h"

struct GameConnection;

class PCProxy : public ITcpSessionConsumer
{
public:
    PCProxy(const PCProxy&) = delete;
    PCProxy& operator=(const PCProxy&) = delete;
    PCProxy(PCProxy&&) = delete;
    PCProxy& operator=(PCProxy&&) = delete;

    static PCProxy& Instance()
    {
        static PCProxy instance;
        return instance;
    }

    void Initialize();

    bool PartyCanStartGame();

    bool ItemIsLargeSlotItem(u32 gbidItem) const;

    void OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection);

    void OnPostXServerReadUpdate();

    bool OnServerEventReceive(u32 idServerSocket, u32 pMessage);

    bool OnServerPutMessageOnOutgoingQueue(u32 idGameConnection, u32 pMessage);

    void OnServerSocketDisconnect(u32 idServerSocket, i32 eReason);

    void OnConnectionAccepted(u32 idServerSocket);

    size_t OnDataReceived(TcpSession* session, const char* buf, size_t len) override;

private:
    PCProxy();
    ~PCProxy() = default;

    void ReceiveMessages(const char* buf, size_t len);
    void SendSystemBroadcast(const char* gameText);

    bool m_isEnabled;
    bool m_isReadingUpdate;
    TcpServer m_tcpServer;
    u32 m_guestSocketId;
    std::list<std::unique_ptr<char[]>> m_outgoingMessages;
    std::list<std::unique_ptr<char[]>> m_incomingMessages;
    std::mutex m_pcMessageMutex;
};
