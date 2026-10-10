#pragma once

#include <rex/ppc.h>

// Game

void HydraHook_SGameInitializeGame(PPCRegister& r3);

// Network

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3);
