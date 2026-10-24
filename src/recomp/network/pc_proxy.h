#pragma once

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

    void OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection);

    int OnDataReceived(TcpSession* session, const char* buf, int len) override;

    inline bool IsEnabled() const { return m_isEnabled; }

private:
    PCProxy();
    ~PCProxy() = default;

    bool m_isEnabled;
    TcpServer m_tcpServer;
    TcpSession* m_tcpSession;
};
