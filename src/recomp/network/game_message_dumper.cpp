#include "recomp/network/game_message_dumper.h"

#include <format>

#include <rex/cvar.h>
#include <rex/logging.h>

#include "core/memory_utils.h"
#include "game/attributes/attrib_defs.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"

REXCVAR_DEFINE_BOOL(server_log_outgoing_messages, false, "Hydra/Server", "Logs server -> client messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

REXCVAR_DEFINE_BOOL(server_log_incoming_messages, false, "Hydra/Server", "Logs client -> server messages")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

namespace
{

std::string AttributeToString(const NetAttributeKeyValue& tKeyVal)
{
    AttribDef* cgarAttribDefs = MemoryUtils::GetHostPtr<AttribDef>(0x82F9DA88);
    const char* pszName = MemoryUtils::GetHostPtr<const char>(cgarAttribDefs[tKeyVal.eKeyAttrib].pszName);

    if (tKeyVal.nKeyParam.m_bExists && tKeyVal.nKeyParam.m_tValue)
    {
        return std::format("{}[{}] = {}",
            pszName,
            tKeyVal.nKeyParam.m_tValue.get(),
            tKeyVal.nValue.get());
    }
    else
    {
        return std::format("{} = {}",
            pszName,
            tKeyVal.nValue.get());
    }
}

std::string GetDataString(const void* pMessage, unsigned int pTypeDescriptor)
{
    switch (pTypeDescriptor)
    {
        case DT_SIMPLE_MESSAGE:
            return "";

        case DT_DWORD_DATA_MESSAGE:
        {
            const DWordDataMessage* dwordDataMessage = static_cast<const DWordDataMessage*>(pMessage);
            return std::format("dwData={}", dwordDataMessage->dwData.get());
        }

        case DT_INT_DATA_MESSAGE:
        {
            const IntDataMessage* intDataMessage = static_cast<const IntDataMessage*>(pMessage);
            return std::format("nData={}", intDataMessage->nData.get());
        }

        case DT_BOOL_DATA_MESSAGE:
        {
            const BoolDataMessage* boolDataMessage = static_cast<const BoolDataMessage*>(pMessage);
            return std::format("bVal={}", boolDataMessage->bVal ? "true" : "false");
        }

        case DT_DATA_ID_DATA_MESSAGE:
        {
            const DataIDDataMessage* dataIDDataMessage = static_cast<const DataIDDataMessage*>(pMessage);
            return std::format("id={}", dataIDDataMessage->id.get());
        }

        case DT_ANN_DATA_MESSAGE:
        {
            const ANNDataMessage* annDataMessage = static_cast<const ANNDataMessage*>(pMessage);
            return std::format("ann={}", static_cast<int>(annDataMessage->ann.get()));
        }

        case DT_SNO_DATA_MESSAGE:
        {
            // TODO: get readable sno name
            const SNODataMessage* snoDataMessage = static_cast<const SNODataMessage*>(pMessage);
            return std::format("sno={}", static_cast<int>(snoDataMessage->snoData.get()));
        }

        case DT_SNONAME_DATA_MESSAGE:
        {
            // TODO: get readable group/handle names
            const SNONameDataMessage* snonameDataMessage = static_cast<const SNONameDataMessage*>(pMessage);
            return std::format("snoGroup={}, snoHandle={}",
                static_cast<int>(snonameDataMessage->snoname.snoGroup.get()),
                static_cast<int>(snonameDataMessage->snoname.snoHandle.get()));
        }

        case DT_GBID_DATA_MESSAGE:
        {
            const GBIDDataMessage* gbidDataMessage = static_cast<const GBIDDataMessage*>(pMessage);
            return std::format("gbidData={}", static_cast<int>(gbidDataMessage->gbidData.get()));
        }

        case DT_PLAYER_INDEX_MESSAGE:
        {
            const PlayerIndexMessage* playerIndexMessage = static_cast<const PlayerIndexMessage*>(pMessage);
            return std::format("nPlayerIndex={}", playerIndexMessage->nPlayerIndex.get());
        }

        case DT_PLAYER_DWORD_DATA_MESSAGE:
        {
            const PlayerDWordDataMessage* playerDwordDataMessage = static_cast<const PlayerDWordDataMessage*>(pMessage);
            return std::format("dwData={}, nPlayerIndex={}",
                playerDwordDataMessage->dwData.get(),
                playerDwordDataMessage->nPlayerIndex.get());
        }

        case DT_GENERIC_BLOB_MESSAGE:
        {
            // TODO: output blob as a hex string? parse protobuf based on message type?
            const GenericBlobMessage* genericBlobMessage = static_cast<const GenericBlobMessage*>(pMessage);
            return std::format("uBlobSize={}", genericBlobMessage->uBlobSize.get());

        }

        case DT_JOIN_CONSOLE_GAME_MESSAGE:
        {
            const JoinConsoleGameMessage* joinConsoleGameMessage = static_cast<const JoinConsoleGameMessage*>(pMessage);
            return std::format("eXLocale={}, uControllerIndex={}, uLicenses={}",
                static_cast<int>(joinConsoleGameMessage->eXLocale.get()),
                static_cast<int>(joinConsoleGameMessage->uControllerIndex),
                joinConsoleGameMessage->uLicenses.get());
        }

        case DT_VERSIONS_MESSAGE:
        {
            const VersionsMessage* versionsMessage = static_cast<const VersionsMessage*>(pMessage);
            return std::format("uSNOPackHash={}, uProtocolHash={}, szBuildVer={}",
                versionsMessage->uSNOPackHash.get(),
                versionsMessage->uProtocolHash.get(),
                versionsMessage->szBuildVer);
        }

        case DT_CONNECTION_ESTABLISHED_MESSAGE:
        {
            const ConnectionEstablishedMessage* connectionEstablishedMessage = static_cast<const ConnectionEstablishedMessage*>(pMessage);
            return std::format("nPlayerIndex={}, dwAnimSyncedSeed={}, dwSnoCoreDataHash={}",
                connectionEstablishedMessage->nPlayerIndex.get(),
                connectionEstablishedMessage->dwAnimSyncedSeed.get(),
                connectionEstablishedMessage->dwSnoCoreDataHash.get());
        }

        case DT_REVEAL_TEAM_MESSAGE:
        {
            const RevealTeamMessage* revealTeamMessage = static_cast<const RevealTeamMessage*>(pMessage);
            return std::format("eTeam={}, dwTeamFlags=0x{:08X}, eTeamColoring={}",
                static_cast<int>(revealTeamMessage->eTeam.get()),
                revealTeamMessage->dwTeamFlags.get(),
                static_cast<int>(revealTeamMessage->eTeamColoring.get()));
        }

        case DT_TRICKLE_MESSAGE:
        {
            const TrickleMessage* trickleMessage = static_cast<const TrickleMessage*>(pMessage);
            std::string str = std::format("ann=0x{:08X}, snoActor={}, tPlace={}, snoLevelArea={}, eTrickleInfoType={}, dwTrickleFlags=0x{:08X}",
                static_cast<u32>(trickleMessage->ann.get()),
                static_cast<i32>(trickleMessage->snoActor.get()),
                "<UNDEFINED>",
                static_cast<i32>(trickleMessage->snoLevelArea.get()),
                static_cast<i32>(trickleMessage->eTrickleInfoType.get()),
                static_cast<u32>(trickleMessage->dwTrickleFlags.get())
            );

            if (trickleMessage->nPlayerIndexOwner.m_bExists)
                str += std::format(", nPlayerIndexOwner={}", trickleMessage->nPlayerIndexOwner.m_tValue.get());

            if (trickleMessage->flHealthPercent.m_bExists)
                str += std::format(", flHealthPercent={}", trickleMessage->flHealthPercent.m_tValue.get());

            if (trickleMessage->dwHeadstoneCorpseReviveTime.m_bExists)
                str += std::format(", dwHeadstoneCorpseReviveTime={}", trickleMessage->dwHeadstoneCorpseReviveTime.m_tValue.get());

            if (trickleMessage->snoMinimapIcon.m_bExists)
                str += std::format(", snoMinimapIcon={}", trickleMessage->snoMinimapIcon.m_tValue.get());

            if (trickleMessage->hMinimapStringLabel.m_bExists)
                str += std::format(", hMinimapStringLabel={}", trickleMessage->hMinimapStringLabel.m_tValue.get());

            if (trickleMessage->hMinimapIconLabel.m_bExists)
                str += std::format(", hMinimapIconLabel={}", trickleMessage->hMinimapIconLabel.m_tValue.get());

            if (trickleMessage->snoStringList.m_bExists)
                str += std::format(", snoStringList={}", trickleMessage->snoStringList.m_tValue.get());

            if (trickleMessage->fMinDisplayRangeSq.m_bExists)
                str += std::format(", fMinDisplayRangeSq={}", trickleMessage->fMinDisplayRangeSq.m_tValue.get());

            if (trickleMessage->fMaxDisplayRangeSq.m_bExists)
                str += std::format(", fMaxDisplayRangeSq={}", trickleMessage->fMaxDisplayRangeSq.m_tValue.get());

            if (trickleMessage->field116.m_bExists)
                str += std::format(", field116={}", trickleMessage->field116.m_tValue.get());

            if (trickleMessage->field124.m_bExists)
                str += std::format(", field124={}", trickleMessage->field124.m_tValue.get());

            if (trickleMessage->field132.m_bExists)
                str += std::format(", field132={}", trickleMessage->field132.m_tValue.get());

            return str;
        }

        case DT_ATTRIBUTE_SET_VALUE_MESSAGE:
        {
            const AttributeSetValueMessage* attributeSetValueMessage = static_cast<const AttributeSetValueMessage*>(pMessage);
            return AttributeToString(attributeSetValueMessage->tKeyVal);
        }

        case DT_ATTRIBUTES_SET_VALUES_MESSAGE:
        {
            const AttributesSetValuesMessage* attributesSetValuesMessage = static_cast<const AttributesSetValuesMessage*>(pMessage);
            std::string str = AttributeToString(attributesSetValuesMessage->atKeyVals[0]);
            for (int i = 1; i < attributesSetValuesMessage->nAttributeCount; ++i)
                str += std::format(", {}", AttributeToString(attributesSetValuesMessage->atKeyVals[i]));
            return str;
        }

        default:
            return "<UNDEFINED>";
    }
}

}

std::string GameMessageDumper::PrintGameMessage(const void* pMessage)
{
    unsigned int pTypeDescriptor = 0;
    unsigned int dwSize = 0;
    const char* pszMessageLabel = nullptr;
    GetGameMessageTypeAndSize(static_cast<const RequiredMessageHeader*>(pMessage)->eType, pTypeDescriptor, dwSize, pszMessageLabel);

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
