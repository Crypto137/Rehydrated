#include "core/network/tcp_session.h"

#include <cstring>
#include <iostream>

TcpSession::TcpSession(SOCKET socket, ITcpSessionConsumer* consumer) :
    m_socket(socket),
    m_state(eStateCreated),
    m_recvBuffer(),
    m_recvPosition(0),
    m_consumer(consumer),
    m_sendBuffer(),
    m_sendPendingBytes()
{
}

TcpSession::~TcpSession()
{
    Disconnect();
}

void TcpSession::Run()
{
    if (m_state != eStateCreated)
        return;

    m_state = eStateConnected;

    m_recvThread = std::thread(&TcpSession::ReceiveLoop, this);
    m_sendThread = std::thread(&TcpSession::SendLoop, this);
}

void TcpSession::Disconnect()
{
    if (m_state == eStateConnected)
        BeginDisconnect();

    m_sendCv.notify_all();  // wake blocked send thread

    std::thread::id thisId = std::this_thread::get_id();

    if (m_recvThread.joinable() && thisId != m_recvThread.get_id())
        m_recvThread.join();

    if (m_sendThread.joinable() && thisId != m_sendThread.get_id())
        m_sendThread.join();

    m_state = eStateDisconnected;
}

void TcpSession::BeginDisconnect()
{
    if (m_state != eStateConnected)
        return;

    m_state = eStateDisconnecting;

    SOCKET socket = m_socket.exchange(INVALID_SOCKET);
    if (socket != INVALID_SOCKET)
    {
        shutdown(socket, SD_BOTH);
        closesocket(socket);
    }
}

bool TcpSession::Send(const char* data, int len)
{
    if (m_state != eStateConnected)
        return false;

    if (len <= 0)
        return true;

    {
        std::unique_lock<std::mutex> lock(m_sendMutex);

        if (m_sendPendingBytes + len > BUFFER_SIZE)
            return false;

        std::memcpy(&m_sendBuffer[m_sendPendingBytes], data, len);
        m_sendPendingBytes += len;
    }

    m_sendCv.notify_one();
    return true;
}

void TcpSession::ReceiveLoop()
{
    while (m_state == eStateConnected)
    {
        if (m_socket == INVALID_SOCKET)
            return;

        int remaining = sizeof(m_recvBuffer) - m_recvPosition;
        if (remaining == 0)
        {
            std::cout << "Receive buffer overflow" << std::endl;
            BeginDisconnect();
            return;
        }

        int result = recv(m_socket, &m_recvBuffer[m_recvPosition], remaining, 0);
        if (result > 0)
        {
            m_recvPosition += result;

            int consumed = m_consumer->OnDataReceived(this, &m_recvBuffer[0], m_recvPosition);

            int newPosition = m_recvPosition - consumed;
            if (newPosition > 0)
                std::memmove(&m_recvBuffer[0], &m_recvBuffer[consumed], newPosition);
            m_recvPosition = newPosition;
        }
        else if (result == 0)
        {
            std::cout << "Connection lost" << std::endl;
            BeginDisconnect();
            return;
        }
        else
        {
            int wsaLastError = WSAGetLastError();
            if (wsaLastError != WSAEINTR)
                std::cout << "Socket error when receiving (" << wsaLastError << ")" << std::endl;

            BeginDisconnect();
            return;
        }
    }
}

void TcpSession::SendLoop()
{
    while (m_state == eStateConnected)
    {
        std::unique_lock<std::mutex> lock(m_sendMutex);

        m_sendCv.wait(lock, [&] { return m_sendPendingBytes > 0 || m_state != eStateConnected; });
        if (m_state != eStateConnected || m_socket == INVALID_SOCKET)
            return;

        int totalSent = 0;
        while (totalSent < m_sendPendingBytes)
        {
            int sent = send(m_socket, &m_sendBuffer[totalSent], m_sendPendingBytes - totalSent, 0);
            if (sent > 0)
            {
                totalSent += sent;
            }
            else if (sent == 0)
            {
                BeginDisconnect();
                return;
            }
            else
            {
                int wsaLastError = WSAGetLastError();
                if (wsaLastError != WSAEINTR)
                    std::cout << "Socket error when sending (" << wsaLastError << ")" << std::endl;

                BeginDisconnect();
                return;
            }

        }

        m_sendPendingBytes = 0;
        std::cout << "sent " << totalSent << " bytes" << std::endl;
    }
}
