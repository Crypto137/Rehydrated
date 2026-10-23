#pragma once

#include <atomic>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>

#include <WinSock2.h>

class TcpSession;
class ITcpSessionConsumer;

typedef int TcpSessionId;

class TcpServer
{
public:
	TcpServer(ITcpSessionConsumer* sessionConsumer);
	~TcpServer();

	bool Start(const std::string& host, const std::string& port);

	bool Stop();

private:
	void AcceptConnections();
	void CleanUpSessions();

	TcpSession* AddSession(SOCKET socket);
	bool RemoveSession(TcpSessionId sessionId);

	std::atomic<bool> m_isRunning;
	std::thread m_cleanupThread;
	std::thread m_acceptThread;
	std::atomic<SOCKET> m_listenSocket;
	int m_currentSessionId;
	std::unordered_map<TcpSessionId, std::unique_ptr<TcpSession>> m_sessions;
	std::mutex m_sessionMutex;

	ITcpSessionConsumer* m_sessionConsumer;
};