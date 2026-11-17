#include "recomp/network/game_message_dumper.h"

#include <format>

#include <rex/logging/logger.h>

#include "core/memory.h"
#include "game/attributes/attrib_defs.h"
#include "game/network/game_connection.h"
#include "game/network/game_message.h"

//REXCVAR_DEFINE_BOOL(server_log_outgoing_messages, false, "Hydra/Server", "Logs server -> client messages").lifecycle(rex::cvar::Lifecycle::kHotReload);

//REXCVAR_DEFINE_BOOL(server_log_incoming_messages, false, "Hydra/Server", "Logs client -> server messages").lifecycle(rex::cvar::Lifecycle::kHotReload);

namespace
{

std::string AttributeToString(const NetAttributeKeyValue& tKeyVal)
{
    AttribDef* cgarAttribDefs = Memory::GetHostPtr<AttribDef>(0x82F9DA88);
    const char* pszName = cgarAttribDefs[tKeyVal.eKeyAttrib].pszName.GetHost();

    if (tKeyVal.nKeyParam.m_bExists && tKeyVal.nKeyParam.m_tValue)
    {
        return std::format("{}[{}] = {}",
            pszName,
            tKeyVal.nKeyParam.m_tValue.Get(),
            tKeyVal.nValue.Get());
    }
    else
    {
        return std::format("{} = {}",
            pszName,
            tKeyVal.nValue.Get());
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
            return std::format("dwData={}", dwordDataMessage->dwData.Get());
        }

        case DT_INT_DATA_MESSAGE:
        {
            const IntDataMessage* intDataMessage = static_cast<const IntDataMessage*>(pMessage);
            return std::format("nData={}", intDataMessage->nData.Get());
        }

        case DT_BOOL_DATA_MESSAGE:
        {
            const BoolDataMessage* boolDataMessage = static_cast<const BoolDataMessage*>(pMessage);
            return std::format("bVal={}", boolDataMessage->bVal ? "true" : "false");
        }

        case DT_DATA_ID_DATA_MESSAGE:
        {
            const DataIDDataMessage* dataIDDataMessage = static_cast<const DataIDDataMessage*>(pMessage);
            return std::format("id={}", dataIDDataMessage->id.Get());
        }

        case DT_ANN_DATA_MESSAGE:
        {
            const ANNDataMessage* annDataMessage = static_cast<const ANNDataMessage*>(pMessage);
            return std::format("ann={}", static_cast<int>(annDataMessage->ann.Get()));
        }

        case DT_SNO_DATA_MESSAGE:
        {
            // TODO: get readable sno name
            const SNODataMessage* snoDataMessage = static_cast<const SNODataMessage*>(pMessage);
            return std::format("sno={}", static_cast<int>(snoDataMessage->snoData.Get()));
        }

        case DT_SNONAME_DATA_MESSAGE:
        {
            // TODO: get readable group/handle names
            const SNONameDataMessage* snonameDataMessage = static_cast<const SNONameDataMessage*>(pMessage);
            return std::format("snoGroup={}, snoHandle={}",
                static_cast<int>(snonameDataMessage->snoname.snoGroup.Get()),
                static_cast<int>(snonameDataMessage->snoname.snoHandle.Get()));
        }

        case DT_GBID_DATA_MESSAGE:
        {
            const GBIDDataMessage* gbidDataMessage = static_cast<const GBIDDataMessage*>(pMessage);
            return std::format("gbidData={}", static_cast<int>(gbidDataMessage->gbidData.Get()));
        }

        case DT_PLAYER_INDEX_MESSAGE:
        {
            const PlayerIndexMessage* playerIndexMessage = static_cast<const PlayerIndexMessage*>(pMessage);
            return std::format("nPlayerIndex={}", playerIndexMessage->nPlayerIndex.Get());
        }

        case DT_PLAYER_DWORD_DATA_MESSAGE:
        {
            const PlayerDWordDataMessage* playerDwordDataMessage = static_cast<const PlayerDWordDataMessage*>(pMessage);
            return std::format("dwData={}, nPlayerIndex={}",
                playerDwordDataMessage->dwData.Get(),
                playerDwordDataMessage->nPlayerIndex.Get());
        }

        case DT_GENERIC_BLOB_MESSAGE:
        {
            // TODO: output blob as a hex string? parse protobuf based on message type?
            const GenericBlobMessage* genericBlobMessage = static_cast<const GenericBlobMessage*>(pMessage);
            return std::format("uBlobSize={}", genericBlobMessage->uBlobSize.Get());

        }

        case DT_JOIN_CONSOLE_GAME_MESSAGE:
        {
            const JoinConsoleGameMessage* joinConsoleGameMessage = static_cast<const JoinConsoleGameMessage*>(pMessage);
            return std::format("eXLocale={}, uControllerIndex={}, uLicenses={}",
                static_cast<int>(joinConsoleGameMessage->eXLocale.Get()),
                static_cast<int>(joinConsoleGameMessage->uControllerIndex),
                joinConsoleGameMessage->uLicenses.Get());
        }

        case DT_VERSIONS_MESSAGE:
        {
            const VersionsMessage* versionsMessage = static_cast<const VersionsMessage*>(pMessage);
            return std::format("uSNOPackHash={}, uProtocolHash={}, szBuildVer={}",
                versionsMessage->uSNOPackHash.Get(),
                versionsMessage->uProtocolHash.Get(),
                versionsMessage->szBuildVer);
        }

        case DT_CONNECTION_ESTABLISHED_MESSAGE:
        {
            const ConnectionEstablishedMessage* connectionEstablishedMessage = static_cast<const ConnectionEstablishedMessage*>(pMessage);
            return std::format("nPlayerIndex={}, dwAnimSyncedSeed={}, dwSnoCoreDataHash={}",
                connectionEstablishedMessage->nPlayerIndex.Get(),
                connectionEstablishedMessage->dwAnimSyncedSeed.Get(),
                connectionEstablishedMessage->dwSnoCoreDataHash.Get());
        }

        case DT_REVEAL_TEAM_MESSAGE:
        {
            const RevealTeamMessage* revealTeamMessage = static_cast<const RevealTeamMessage*>(pMessage);
            return std::format("eTeam={}, dwTeamFlags=0x{:08X}, eTeamColoring={}",
                static_cast<int>(revealTeamMessage->eTeam.Get()),
                revealTeamMessage->dwTeamFlags.Get(),
                static_cast<int>(revealTeamMessage->eTeamColoring.Get()));
        }

        case DT_TRICKLE_MESSAGE:
        {
            const TrickleMessage* trickleMessage = static_cast<const TrickleMessage*>(pMessage);
            std::string str = std::format("ann=0x{:08X}, snoActor={}, tPlace={}, snoLevelArea={}, eTrickleInfoType={}, dwTrickleFlags=0x{:08X}",
                static_cast<u32>(trickleMessage->ann.Get()),
                static_cast<i32>(trickleMessage->snoActor.Get()),
                "<UNDEFINED>",
                static_cast<i32>(trickleMessage->snoLevelArea.Get()),
                static_cast<i32>(trickleMessage->eTrickleInfoType.Get()),
                static_cast<u32>(trickleMessage->dwTrickleFlags.Get())
            );

            if (trickleMessage->nPlayerIndexOwner.m_bExists)
                str += std::format(", nPlayerIndexOwner={}", trickleMessage->nPlayerIndexOwner.m_tValue.Get());

            if (trickleMessage->flHealthPercent.m_bExists)
                str += std::format(", flHealthPercent={}", trickleMessage->flHealthPercent.m_tValue.Get());

            if (trickleMessage->dwHeadstoneCorpseReviveTime.m_bExists)
                str += std::format(", dwHeadstoneCorpseReviveTime={}", trickleMessage->dwHeadstoneCorpseReviveTime.m_tValue.Get());

            if (trickleMessage->snoMinimapIcon.m_bExists)
                str += std::format(", snoMinimapIcon={}", trickleMessage->snoMinimapIcon.m_tValue.Get());

            if (trickleMessage->hMinimapStringLabel.m_bExists)
                str += std::format(", hMinimapStringLabel={}", trickleMessage->hMinimapStringLabel.m_tValue.Get());

            if (trickleMessage->hMinimapIconLabel.m_bExists)
                str += std::format(", hMinimapIconLabel={}", trickleMessage->hMinimapIconLabel.m_tValue.Get());

            if (trickleMessage->snoStringList.m_bExists)
                str += std::format(", snoStringList={}", trickleMessage->snoStringList.m_tValue.Get());

            if (trickleMessage->fMinDisplayRangeSq.m_bExists)
                str += std::format(", fMinDisplayRangeSq={}", trickleMessage->fMinDisplayRangeSq.m_tValue.Get());

            if (trickleMessage->fMaxDisplayRangeSq.m_bExists)
                str += std::format(", fMaxDisplayRangeSq={}", trickleMessage->fMaxDisplayRangeSq.m_tValue.Get());

            if (trickleMessage->field116.m_bExists)
                str += std::format(", field116={}", trickleMessage->field116.m_tValue.Get());

            if (trickleMessage->field124.m_bExists)
                str += std::format(", field124={}", trickleMessage->field124.m_tValue.Get());

            if (trickleMessage->field132.m_bExists)
                str += std::format(", field132={}", trickleMessage->field132.m_tValue.Get());

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

        case DT_AFFIX_MESSAGE:
        {
            const AffixMessage* affixMessage = static_cast<const AffixMessage*>(pMessage);
            std::string str = std::format("ann=0x{:08X}, eAffixArray={}, aAffixGBIDs=[",
                static_cast<int>(affixMessage->ann.Get()),
                static_cast<int>(affixMessage->eAffixArray.Get()));
            if (affixMessage->dwAffixArrayCount)
            {
                str += std::format("0x{:08X}", affixMessage->aAffixGBIDs[0].Get());
                for (int i = 1; i < affixMessage->dwAffixArrayCount; ++i)
                    str += std::format(", 0x{:08X}", affixMessage->aAffixGBIDs[i].Get());
            }
            str += "]";
            return str;
        }

        case DT_NPC_INTERACT_OPTIONS_MESSAGE:
        {
            const NPCInteractOptionsMessage* npcInteractOptionsMessage = static_cast<const NPCInteractOptionsMessage*>(pMessage);

            std::string str = std::format("annTalkingTo=0x{:08X}", static_cast<int>(npcInteractOptionsMessage->annTalkingTo.Get()));

            str += ", tNPCInteraction = [";
            int nNumInteractions = npcInteractOptionsMessage->nNumInteractions;
            for (int i = 0; i < nNumInteractions; ++i)
            {
                const NPCInteraction& tNPCInteraction = npcInteractOptionsMessage->tNPCInteraction[i];
                str += std::format("({}) eType={}, dwData=0x{:08X}, dwData2=0x{:08X}, dwFlags=0x{:08X}; ",
                    i,
                    static_cast<int>(tNPCInteraction.eType.Get()),
                    tNPCInteraction.dwData.Get(),
                    tNPCInteraction.dwData2.Get(),
                    tNPCInteraction.dwFlags.Get());
            }
            str += "]";

            str += std::format(", ePreferredMenu={}", static_cast<int>(npcInteractOptionsMessage->ePreferredMenu.Get()));

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
    //if (!REXCVAR_GET(server_log_outgoing_messages))
        return;

    i32 nBufferCount = ptGameConnection->tOutgoingPacketBufferList.m_nCount;
    if (!nBufferCount)
        return;

    REXLOG_INFO("OUTGOING PACKET (nMessageCount={})", nBufferCount);

    TPacketBufferListNode* listNode = ptGameConnection->tOutgoingPacketBufferList.m_pHead.GetHost();
    int i = 0;
    while (listNode)
    {
        PacketBuffer* tPacketBuffer = listNode->m_tData.GetHost();
        RequiredMessageHeader* pMessage = reinterpret_cast<RequiredMessageHeader*>(&tPacketBuffer->byteData[0]);

        REXLOG_INFO("  [{}] {}", i++, PrintGameMessage(pMessage));

        listNode = listNode->m_pNext.GetHost();
    }
}

void GameMessageDumper::OnServerMessageReceiveOutsideGame(int idServerSocket, const RequiredMessageHeader* pMessage)
{
    // TODO: handle this at packet level rather than message level

    //if (!REXCVAR_GET(server_log_incoming_messages))
        return;

    REXLOG_INFO("INCOMING MESSAGE: [0x{:08X}] {}", idServerSocket, PrintGameMessage(pMessage));
}
