#pragma once

#include "game/network/game_message.h"
#include "recomp/network/xdecoder.h"
#include "recomp/network/xencoder.h"

namespace GameMessageEncoder
{

bool EncodeMessage(void* pMessage, XEncoder& tEncoder);

XDecoder::Result DecodeMessage(GameMessageType eMessageType, void* pDecodeToBuffer, u32 dwBufferSize, XDecoder& tDecoder);

}
