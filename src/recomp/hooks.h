#pragma once

#include <rex/ppc.h>

// Game

void HydraHook_SGameInitializeGame(PPCRegister& r3);

// Input

void HydraHook_PostInputUpdate(PPCRegister& r3);

// Network

bool HydraHook_Console_Online_PartyCanStartGame(PPCRegister& r3);

void HydraHook_ClientMessageReceiveAllMessage(PPCRegister& r3);

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3);

void HydraHook_PostXServerReadUpdate();

void HydraHook_ServerSendOutgoingMessagesForGameConnection(PPCRegister& r3);

bool HydraHook_ServerEventReceive(PPCRegister& r3, PPCRegister& r4);

bool HydraHook_XServerSendBuffer(PPCRegister& r3, PPCRegister& r4, PPCRegister& r5);

void HydraHook_sServerSocketMsgHandler(PPCRegister& r3, PPCRegister& r4, PPCRegister& r5);

void HydraHook_ServerMessageReceiveOutsideGame(PPCRegister& r3, PPCRegister& r4);

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4);

// Subsystem

void HydraHook_PostNetworkInitializeForApp();

void HydraHook_PostFastAttribInitializeForApp();
