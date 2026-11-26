#pragma once

#include <atomic>
#include <list>
#include <memory>
#include <mutex>

#include "core/types.h"
#include "core/network/tcp_server.h"

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

    bool OnStartScreenUpdate();

    void OnMainMenuUpdate();

    void OnPerformStartupFlow();

    bool PartyCanStartGame();

    void OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection);

    void OnPostXServerReadUpdate();

    bool OnServerEventReceive(u32 idServerSocket, u32 pMessage);

    bool OnServerPutMessageOnOutgoingQueue(u32 idGameConnection, u32 pMessage);

    void OnServerSocketDisconnect(u32 idServerSocket, i32 eReason);

    void OnConnectionAccepted(u32 idServerSocket);

    // ITcpSessionConsumer
    void OnTcpSessionStateChanged(TcpSessionId sessionId, TcpSession::State newState) override;
    size_t OnTcpSessionDataReceived(TcpSessionId sessionId, const char* buf, size_t len) override;

    inline bool IsEnabled() const { return m_isEnabled; }

private:
    PCProxy();
    ~PCProxy() = default;

    void ReceiveMessages(const char* buf, size_t len);
    void SendSystemBroadcast(const char* gameText);
    void BootConsoleClient();

    bool m_isEnabled;
    bool m_isReadingUpdate;
    std::atomic<bool> m_joinRequested;
    std::atomic<bool> m_bootConsoleClient;
    TcpServer m_tcpServer;
    std::atomic<TcpSessionId> m_tcpSessionId;
    u32 m_guestSocketId;
    std::list<std::unique_ptr<char[]>> m_outgoingMessages;
    std::list<std::unique_ptr<char[]>> m_incomingMessages;
    // We don't have a mutex for outgoing messages because that queue
    // should be interacted with only from the guest server thread.
    std::mutex m_incomingMessageMutex;
};
