#pragma once

#include "core/memory.h"
#include "game/types.h"

struct PacketBufferHeader
{
    be<u32> dwPoolHandle;
    be<DataID> idSocket;
};

struct PacketBuffer
{
    PacketBufferHeader tHeader;
    char byteData[1];
};

// TODO: use templates to recreate the original XPooledList implementation
struct TPacketBufferListNode
{
    be_ptr<PacketBuffer> m_tData;
    be_ptr<TPacketBufferListNode> m_pPrev;
    be_ptr<TPacketBufferListNode> m_pNext;
};

struct TPacketBufferList
{
    be_ptr<TPacketBufferListNode> m_pHead;
    be_ptr<TPacketBufferListNode> m_pTail;
    be<i32> m_nCount;
    be_ptr<void> m_ptNodeAllocator;
};

typedef i32 GameConnectionID;
typedef i32 ServerSocketID;

struct GameConnection
{
    be<GameConnectionID> id;
    be<ServerSocketID> idServerSocket;
    be<i32> nPlayerIndex[4];
    char uPlayerCount;
    TPacketBufferList tOutgoingPacketBufferList;
    be<u32> dword2C;   // m_ConstructorCalled for TPacketBufferList?
    be<u32> bInGame;
    be<i32> bDisposing;
    be<i32> bTerminateConnectionWhenOutgoingQueueEmpty;
    be<i32> bNeedHeartBeat;
    be<u32> dword40;   // dwLastHeartBeatTime?
};
