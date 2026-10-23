#pragma once

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

    void OnServerSendOutgoingMessagesForGameConnection(const GameConnection* ptGameConnection);

    inline bool IsEnabled() const { return m_isEnabled; }

private:
    PCProxy();
    ~PCProxy() = default;

    bool m_isEnabled;
};
