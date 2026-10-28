#pragma once

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

    void OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection);

    void OnPostXServerReadUpdate();

    bool OnServerEventReceive(u32 idServerSocket, u32 pMessage);

    size_t OnDataReceived(TcpSession* session, const char* buf, size_t len) override;

    inline bool IsEnabled() const { return m_isEnabled; }

private:
    PCProxy();
    ~PCProxy() = default;

    bool m_isEnabled;
    bool m_isReadingUpdate;
    TcpServer m_tcpServer;
    u32 m_lastGuestSocketId;
};
