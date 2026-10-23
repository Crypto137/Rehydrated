#pragma once

#include "core/network/tcp_server.h"
#include "core/network/tcp_session_consumer.h"

struct GameConnection;

class PCProxy
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

    void OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection);

    int OnClientDataReceived(TcpSession* session, const char* buf, int len);

    inline bool IsEnabled() const { return m_isEnabled; }

private:
    PCProxy();
    ~PCProxy() = default;

    class TcpConsumer : public ITcpSessionConsumer
    {
        inline virtual int OnDataReceived(TcpSession* session, const char* buf, int len) override
        {
            return PCProxy::Instance().OnClientDataReceived(session, buf, len);
        }
    };

    bool m_isEnabled;
    TcpConsumer m_tcpConsumer;
    TcpServer m_tcpServer;
    TcpSession* m_tcpSession;
};
