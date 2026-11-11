#pragma once

#include <rex/ppc.h>

// Game

void HydraHook_ItemIsLargeSlotItem(PPCRegister& r3);

void HydraHook_SGameInitializeGame(PPCRegister& r3);

void HydraHook_LootCreateItem_IsItemQualityLevelDropUnidentified(PPCRegister& r25, PPCRegister& r26);

// Input

void HydraHook_InputPlatformKeyConvert();

void HydraHook_InputUpdate();

// Network

bool HydraHook_Console_Online_PartyCanStartGame(PPCRegister& r3);

void HydraHook_ClientMessageReceiveAllMessage(PPCRegister& r3);

void HydraHook_ClientMessageReceiveGameMessage(PPCRegister& r3);

void HydraHook_PostXServerReadUpdate();

void HydraHook_ServerSendOutgoingMessagesForGameConnection(PPCRegister& r3);

bool HydraHook_ServerEventReceive(PPCRegister& r3, PPCRegister& r4);

bool HydraHook_ServerPutMessageOnOutgoingQueue(PPCRegister& r3, PPCRegister& r4);

void HydraHook_XServerSocketDisconnect(PPCRegister& r3, PPCRegister& r4);

void HydraHook_XServerReadUpdate_OnJoined(PPCRegister& r3);

void HydraHook_ServerMessageReceiveOutsideGame(PPCRegister& r3, PPCRegister& r4);

void HydraHook_ServerMessageReceive(PPCRegister& r3, PPCRegister& r4);

// Subsystem

void HydraHook_PostNetworkInitializeForApp();

void HydraHook_PostFastAttribInitializeForApp();
