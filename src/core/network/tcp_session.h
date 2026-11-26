#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

#include <WinSock2.h>

using TcpSessionId = unsigned int;

class ITcpSessionConsumer
{
public:
    virtual void OnClientConnected(TcpSessionId sessionId) = 0;
    virtual void OnClientDisconnected(TcpSessionId sessionId) = 0;
    virtual size_t OnDataReceived(TcpSessionId sessionId, const char* buf, size_t len) = 0;
    virtual ~ITcpSessionConsumer() = default;
};

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

    TcpSession(TcpSessionId id, SOCKET socket, ITcpSessionConsumer* consumer);
    ~TcpSession();

    void Run();
    void Disconnect();

    inline TcpSessionId GetId() const { return m_id; }
    inline State GetState() const { return m_state; }

    bool Send(const char* data, int len);

private:
    static constexpr int kBufferSize = 1024 * 128;

    void BeginDisconnect();
    void ReceiveLoop();
    void SendLoop();

    TcpSessionId m_id;
    std::atomic<SOCKET> m_socket;
    std::atomic<State> m_state;

    char m_recvBuffer[kBufferSize];
    int m_recvPosition;
    std::thread m_recvThread;
    ITcpSessionConsumer* m_consumer;

    char m_sendBuffer[kBufferSize];
    int m_sendPendingBytes;
    std::thread m_sendThread;
    std::mutex m_sendMutex;
    std::condition_variable m_sendCv;
};
