#pragma once

#include <rex/ppc.h>

// Game

void HydraHook_SGameInitializeGame(PPCRegister& r3);

// Network

void HydraHook_ClientMessageReceiveAllMessage(PPCRegister& r3);

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3);

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4);