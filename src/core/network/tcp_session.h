#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

#include <WinSock2.h>

#include "core/network/tcp_session_consumer.h"

class TcpSession
{
public:
    enum State
    {
        eStateCreated,
        eStateConnected,
        eStateDisconnecting,
        eStateDisconnected,
    };

    TcpSession(SOCKET socket, ITcpSessionConsumer* consumer);
    ~TcpSession();

    void Run();
    void Disconnect();

    inline State GetState() const { return m_state; }

    bool Send(const char* data, int len);

private:
    static constexpr int BUFFER_SIZE = 1024 * 128;

    void BeginDisconnect();
    void ReceiveLoop();
    void SendLoop();

    std::atomic<SOCKET> m_socket;
    std::atomic<State> m_state;

    char m_recvBuffer[BUFFER_SIZE];
    int m_recvPosition;
    std::thread m_recvThread;
    ITcpSessionConsumer* m_consumer;

    char m_sendBuffer[BUFFER_SIZE];
    int m_sendPendingBytes;
    std::thread m_sendThread;
    std::mutex m_sendMutex;
    std::condition_variable m_sendCv;
};
