#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* WMi_GetSystemWork();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void WMi_SetCallbackTable(int,void*);int WMi_SendCommand(int,int,...);int WMi_CheckIdle();void* ActorPool_GetGlobalInstance();char* ActorPool_GetActiveSlot(void*,int);void Actor_SetRepresentationTargetYaw(void*,int);int Actor_GetRepresentationTargetYawOrZero(void*);int Actor_GetRepresentationCurrentYawOrZero(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void ActorEffectLoader_InvalidateQueuedRequest(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void ScriptFlagHistory_AppendGlobalKey(int);}
#pragma force_active on
// Original: arm9/main @ 0x020D5AEC; symbol: func_020d5aec; size: 0x70.
extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void* arg){char* root=WMi_GetSystemWork();int status=TestCurrentStatusAgainstVariadicAllowedValues(2,9,10);if(status)return status;InvalidateDataCacheRange(*(char**)(root+4)+12,4);if(!*(int*)(*(char**)(root+4)+12))return 3;WMi_SetCallbackTable(16,arg);status=WMi_SendCommand(16,0);return status?status:2;}
