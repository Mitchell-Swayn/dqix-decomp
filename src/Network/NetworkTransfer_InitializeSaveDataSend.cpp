// Original field widths, callee calling behavior and exact symbols reviewed.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {void NetworkOwnership_ClearEntry(void*);void LinkedQueue_InitializeNodeStatus(void*);void CombatStatus_ClearAttackStage(void*);void CharacterState_ResetAuxiliaryTracking(void*);void GameState_SelectPlacementVariantAndInvalidateSource(void*,int);void* memcpy(void*,const void*,unsigned);void* Graphics_GetGlobalOamTransferState();int Graphics_ReadSelectedScreenPowerState(void*);void Graphics_SetOamScreenEnabled(void*,unsigned,int);void TextCache_ResetEntry(void*);void* Network_GetConnectionManager();int Network_IsSessionActive(void*);char* DisplayLayout_FindPartById(void*,int);unsigned short* Zone3D_GetMainInstance();void MessageTextTable_Reset(void*);int PartySelection_GetMemberMask(void*,unsigned);void ActorPathGraph_ResetNodeLinksAndFlags(void*);}struct SignedThree{signed int low:3;unsigned int rest:29;};
// Original: arm9/main @ 0x020DBC9C; symbol: func_020dbc9c; size: 0x28.
extern "C" void NetworkTransfer_InitializeSaveDataSend(char* p){LinkedQueue_InitializeNodeStatus(p);p[0]=0x4c;p[8]=0;*(int*)(p+12)=0;*(int*)(p+16)=0;}
