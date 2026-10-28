#pragma once

class TcpSession;

class ITcpSessionConsumer
{
public:
    virtual size_t OnDataReceived(TcpSession* session, const char* buf, size_t len) = 0;
    virtual ~ITcpSessionConsumer() = default;
};
