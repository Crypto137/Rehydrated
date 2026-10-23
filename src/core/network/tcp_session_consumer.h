#pragma once

class TcpSession;

class ITcpSessionConsumer
{
public:
    virtual int OnDataReceived(TcpSession* session, const char* buf, int len) = 0;
    virtual ~ITcpSessionConsumer() = default;
};
