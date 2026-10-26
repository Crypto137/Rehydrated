#include "recomp/network/game_message_dumper.h"

#include <format>

#include <rex/cvar.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"

REXCVAR_DEFINE_BOOL(server_log_outgoing_messages, false, "Hydra/Server", "Logs server -> client messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

REXCVAR_DEFINE_BOOL(server_log_incoming_messages, false, "Hydra/Server", "Logs client -> server messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

namespace
{

std::string GetDataString(const RequiredMessageHeader* pMessage, unsigned int pTypeDescriptor)
{
    switch (pTypeDescriptor)
    {
        case DT_SIMPLE_MESSAGE:
            return "";

        case DT_DWORD_DATA_MESSAGE:
        {
            const DWordDataMessage* dwordDataMessage = reinterpret_cast<const DWordDataMessage*>(pMessage);
            return std::format("dwData={}", dwordDataMessage->dwData.get());
        }

        case DT_INT_DATA_MESSAGE:
        {
            const IntDataMessage* intDataMessage = reinterpret_cast<const IntDataMessage*>(pMessage);
            return std::format("nData={}", intDataMessage->nData.get());
        }

        case DT_BOOL_DATA_MESSAGE:
        {
            const BoolDataMessage* boolDataMessage = reinterpret_cast<const BoolDataMessage*>(pMessage);
            return std::format("bVal={}", boolDataMessage->bVal ? "true" : "false");
        }

        case DT_DATA_ID_DATA_MESSAGE:
        {
            const DataIDDataMessage* dataIDDataMessage = reinterpret_cast<const DataIDDataMessage*>(pMessage);
            return std::format("id={}", dataIDDataMessage->id.get());
        }

        case DT_ANN_DATA_MESSAGE:
        {
            const ANNDataMessage* annDataMessage = reinterpret_cast<const ANNDataMessage*>(pMessage);
            return std::format("ann={}", static_cast<int>(annDataMessage->ann.get()));
        }

        case DT_SNO_DATA_MESSAGE:
        {
            // TODO: get readable sno name
            const SNODataMessage* snoDataMessage = reinterpret_cast<const SNODataMessage*>(pMessage);
            return std::format("sno={}", static_cast<int>(snoDataMessage->snoData.get()));
        }

        case DT_SNONAME_DATA_MESSAGE:
        {
            // TODO: get readable group/handle names
            const SNONameDataMessage* snonameDataMessage = reinterpret_cast<const SNONameDataMessage*>(pMessage);
            return std::format("snoGroup={}, snoHandle={}",
                static_cast<int>(snonameDataMessage->snoname.snoGroup.get()),
                static_cast<int>(snonameDataMessage->snoname.snoHandle.get()));
        }

        case DT_GBID_DATA_MESSAGE:
        {
            const GBIDDataMessage* gbidDataMessage = reinterpret_cast<const GBIDDataMessage*>(pMessage);
            return std::format("gbidData={}", static_cast<int>(gbidDataMessage->gbidData.get()));
        }

        case DT_PLAYER_INDEX_MESSAGE:
        {
            const PlayerIndexMessage* playerIndexMessage = reinterpret_cast<const PlayerIndexMessage*>(pMessage);
            return std::format("nPlayerIndex={}", playerIndexMessage->nPlayerIndex.get());
        }

        case DT_PLAYER_DWORD_DATA_MESSAGE:
        {
            const PlayerDWordDataMessage* playerDwordDataMessage = reinterpret_cast<const PlayerDWordDataMessage*>(pMessage);
            return std::format("dwData={}, nPlayerIndex={}",
                playerDwordDataMessage->dwData.get(),
                playerDwordDataMessage->nPlayerIndex.get());
        }

        case DT_GENERIC_BLOB_MESSAGE:
        {
            // TODO: output blob as a hex string? parse protobuf based on message type?
            const GenericBlobMessage* genericBlobMessage = reinterpret_cast<const GenericBlobMessage*>(pMessage);
            return std::format("uBlobSize={}", genericBlobMessage->uBlobSize.get());

        }

        case DT_JOIN_CONSOLE_GAME_MESSAGE:
        {
            const JoinConsoleGameMessage* joinConsoleGameMessage = reinterpret_cast<const JoinConsoleGameMessage*>(pMessage);
            return std::format("eXLocale={}, uControllerIndex={}, uLicenses={}",
                static_cast<int>(joinConsoleGameMessage->eXLocale.get()),
                static_cast<int>(joinConsoleGameMessage->uControllerIndex),
                joinConsoleGameMessage->uLicenses.get());
        }

        case DT_VERSIONS_MESSAGE:
        {
            const VersionsMessage* versionsMessage = reinterpret_cast<const VersionsMessage*>(pMessage);
            return std::format("uSNOPackHash={}, uProtocolHash={}, szBuildVer={}",
                versionsMessage->uSNOPackHash.get(),
                versionsMessage->uProtocolHash.get(),
                versionsMessage->szBuildVer);
        }

        case DT_CONNECTION_ESTABLISHED_MESSAGE:
        {
            const ConnectionEstablishedMessage* connectionEstablishedMessage = reinterpret_cast<const ConnectionEstablishedMessage*>(pMessage);
            return std::format("nPlayerIndex={}, dwAnimSyncedSeed={}, dwSnoCoreDataHash={}",
                connectionEstablishedMessage->nPlayerIndex.get(),
                connectionEstablishedMessage->dwAnimSyncedSeed.get(),
                connectionEstablishedMessage->dwSnoCoreDataHash.get());
        }

        default:
            return "<UNDEFINED>";
    }
}

}

std::string GameMessageDumper::PrintGameMessage(const RequiredMessageHeader* pMessage)
{
    unsigned int pTypeDescriptor = 0;
    unsigned int dwSize = 0;
    const char* pszMessageLabel = nullptr;
    GetGameMessageTypeAndSize(pMessage->eType, pTypeDescriptor, dwSize, pszMessageLabel);

    return std::format("{} ({})", pszMessageLabel, GetDataString(pMessage, pTypeDescriptor));
}

void GameMessageDumper::OnServerSendOutgoingMessages(const GameConnection* ptGameConnection)
{
    if (!REXCVAR_GET(server_log_outgoing_messages))
        return;

    i32 nBufferCount = ptGameConnection->tOutgoingPacketBufferList.m_nCount;
    if (!nBufferCount)
        return;

    REXLOG_INFO("OUTGOING PACKET (nMessageCount={})", nBufferCount);

    TPacketBufferListNode* listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(ptGameConnection->tOutgoingPacketBufferList.m_pHead);
    int i = 0;
    while (listNode)
    {
        PacketBuffer* tPacketBuffer = MemoryUtils::GetHostPtr<PacketBuffer>(listNode->m_tData);
        RequiredMessageHeader* pMessage = reinterpret_cast<RequiredMessageHeader*>(&tPacketBuffer->byteData[0]);

        REXLOG_INFO("  [{}] {}", i++, PrintGameMessage(pMessage));

        listNode = MemoryUtils::GetHostPtr<TPacketBufferListNode>(listNode->m_pNext);
    }
}

void GameMessageDumper::OnServerMessageReceiveOutsideGame(int idServerSocket, const RequiredMessageHeader* pMessage)
{
    // TODO: handle this at packet level rather than message level

    if (!REXCVAR_GET(server_log_incoming_messages))
        return;

    REXLOG_INFO("INCOMING MESSAGE: [0x{:08X}] {}", idServerSocket, PrintGameMessage(pMessage));
}
