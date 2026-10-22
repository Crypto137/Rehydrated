#pragma once

#include <rex/system/xtypes.h>

#include "game/types.h"

struct PacketBufferHeader
{
    rex::be<u32> dwPoolHandle;
    rex::be<DataID> idSocket;
};

struct PacketBuffer
{
    PacketBufferHeader tHeader;
    char byteData[1];
};

// TODO: use templates to recreate the original XPooledList implementation
struct TPacketBufferListNode
{
    rex::TypedGuestPointer<PacketBuffer> m_tData;
    rex::TypedGuestPointer<TPacketBufferListNode> m_pPrev;
    rex::TypedGuestPointer<TPacketBufferListNode> m_pNext;
};

struct TPacketBufferList
{
    rex::TypedGuestPointer<TPacketBufferListNode> m_pHead;
    rex::TypedGuestPointer<TPacketBufferListNode> m_pTail;
    rex::be<i32> m_nCount;
    rex::TypedGuestPointer<void> m_ptNodeAllocator;
};

typedef i32 GameConnectionID;
typedef i32 ServerSocketID;

struct GameConnection
{
    rex::be<GameConnectionID> id;
    rex::be<ServerSocketID> idServerSocket;
    rex::be<i32> nPlayerIndex[4];
    char uPlayerCount;
    TPacketBufferList tOutgoingPacketBufferList;
    rex::be<u32> dword2C;   // m_ConstructorCalled for TPacketBufferList?
    rex::be<u32> dword30;   // bInGame?
    rex::be<i32> bDisposing;
    rex::be<i32> bTerminateConnectionWhenOutgoingQueueEmpty;
    rex::be<i32> bNeedHeartBeat;
    rex::be<u32> dword40;   // dwLastHeartBeatTime?
};
