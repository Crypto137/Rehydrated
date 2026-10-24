#include "core/network/tcp_server.h"

#include <cstring>
#include <iostream>
#include <vector>

#include <WS2tcpip.h>

#include "core/network/tcp_session.h"

TcpServer::TcpServer(ITcpSessionConsumer* sessionConsumer) :
    m_isRunning(false),
    m_listenSocket(INVALID_SOCKET),
    m_currentSessionId(0),
    m_sessions(),
    m_sessionConsumer(sessionConsumer)
{
}

TcpServer::~TcpServer()
{
    Stop();
}

bool TcpServer::Start(const std::string& host, const std::string& port)
{
    if (m_isRunning)
        return false;

    int result = 0;
    addrinfo* resolvedAddrInfo = nullptr;

    WSADATA wsaData;
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result)
    {
        std::cout << "WSAStartup failed (" << result << ")" << std::endl;
        return false;
    }

    addrinfo hints;
    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = 0;

    result = getaddrinfo(host.c_str(), port.c_str(), &hints, &resolvedAddrInfo);
    if (result)
    {
        std::cout << "getaddrinfo failed (" << result << ")" << std::endl;
        goto cleanup;
    }

    m_listenSocket = socket(resolvedAddrInfo->ai_family, resolvedAddrInfo->ai_socktype, resolvedAddrInfo->ai_protocol);
    if (m_listenSocket == INVALID_SOCKET)
    {
        std::cout << "Socket creation failed (" << WSAGetLastError() << ")" << std::endl;
        goto cleanup;
    }

    result = bind(m_listenSocket, resolvedAddrInfo->ai_addr, resolvedAddrInfo->ai_addrlen);
    if (result == SOCKET_ERROR)
    {
        std::cout << "Socket failed to bind on " << host << ":" << port << "(" << WSAGetLastError() << ")" << std::endl;
        goto cleanup;
    }

    freeaddrinfo(resolvedAddrInfo);
    resolvedAddrInfo = nullptr;

    result = listen(m_listenSocket, SOMAXCONN);
    if (result == SOCKET_ERROR)
    {
        std::cout << "listen failed (" << WSAGetLastError() << ")" << std::endl;
        goto cleanup;
    }

    m_isRunning = true;
    m_cleanupThread = std::thread(&TcpServer::CleanUpSessions, this);
    m_acceptThread = std::thread(&TcpServer::AcceptConnections, this);

    std::cout << "TcpServer listening on " << host << ":" << port << "..." << std::endl;
    return true;

cleanup:
    if (resolvedAddrInfo)
        freeaddrinfo(resolvedAddrInfo);

    if (m_listenSocket != INVALID_SOCKET)
    {
        closesocket(m_listenSocket);
        m_listenSocket = INVALID_SOCKET;
    }

    WSACleanup();
    return false;
}

bool TcpServer::Stop()
{
    if (!m_isRunning)
        return false;

    m_isRunning = false;

    SOCKET socket = m_listenSocket.exchange(INVALID_SOCKET);
    if (socket != INVALID_SOCKET)
    {
        shutdown(socket, SD_BOTH);
        closesocket(socket);
    }

    if (m_cleanupThread.joinable())
        m_cleanupThread.join();

    if (m_acceptThread.joinable())
        m_acceptThread.join();

    while (!m_sessions.empty())
    {
        auto it = m_sessions.begin();
        RemoveSession(it->first);
    }

    WSACleanup();

    std::cout << "TcpServer stopped" << std::endl;
    return true;
}

bool TcpServer::HasActiveSessions()
{
    std::unique_lock<std::mutex> lock(m_sessionMutex);
    return !m_sessions.empty();
}

std::shared_ptr<TcpSession> TcpServer::GetFirstSession()
{
    // just a temp thing to get things going
    std::unique_lock<std::mutex> lock(m_sessionMutex);

    auto it = m_sessions.begin();
    if (it == m_sessions.end())
        return nullptr;

    return it->second;
}

void TcpServer::AcceptConnections()
{
    std::cout << "Accepting connections..." << std::endl;

    while (m_isRunning)
    {
        if (m_listenSocket == INVALID_SOCKET)
        {
            std::cout << "m_listenSocket is invalid while m_isRunning is true, which should not be happening" << std::endl;
            break;
        }

        SOCKET socket = accept(m_listenSocket, NULL, NULL);
        if (socket == INVALID_SOCKET)
        {
            int wsaLastError = WSAGetLastError();
            if (wsaLastError == WSAEINTR)
                break;

            std::cout << "Failed to accept client (" << wsaLastError << ")" << std::endl;
            continue;
        }

        BOOL bNoDelay = TRUE;
        int result = setsockopt(socket, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char*>(&bNoDelay), sizeof(bNoDelay));
        if (result == SOCKET_ERROR)
        {
            std::cout << "Failed to set TCP_NODELAY on socket (" << WSAGetLastError() << ")" << std::endl;
            closesocket(socket);
            continue;
        }

        TcpSession* session = AddSession(socket);
        if (!session)
        {
            closesocket(socket);
            std::cout << "Failed to create session" << std::endl;
            continue;
        }

        std::cout << "Client connected" << std::endl;
        session->Run();
    }

    std::cout << "No longer accepting connections" << std::endl;
}

TcpSession* TcpServer::AddSession(SOCKET socket)
{
    std::unique_lock<std::mutex> lock(m_sessionMutex);

    if (!m_sessionConsumer)
    {
        std::cout << "No session consumer to create session" << std::endl;
        return nullptr;
    }

    TcpSessionId sessionId = ++m_currentSessionId;
    auto it = m_sessions.emplace(sessionId, std::make_shared<TcpSession>(socket, m_sessionConsumer));
    if (!it.second)
        return nullptr;

    return it.first->second.get();
}

bool TcpServer::RemoveSession(TcpSessionId sessionId)
{
    std::unique_lock<std::mutex> lock(m_sessionMutex);

    auto it = m_sessions.find(sessionId);
    if (it == m_sessions.end())
        return false;

    m_sessions.erase(it);
    return true;
}

void TcpServer::CleanUpSessions()
{
    // ugly temp junk just to avoid leaking
    while (true)
    {
        if (!m_isRunning)
            break;

        std::vector<TcpSessionId> disconnectedIds{};

        {
            std::unique_lock<std::mutex> lock(m_sessionMutex);
            for (auto it = m_sessions.begin(); it != m_sessions.end(); ++it)
            {
                TcpSession::State state = it->second->GetState();
                if (state == TcpSession::eStateDisconnecting || state == TcpSession::eStateDisconnected)
                    disconnectedIds.push_back(it->first);
            }
        }

        for (auto& it : disconnectedIds)
        {
            RemoveSession(it);
            std::cout << "Cleaned up disconnected session " << it << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
