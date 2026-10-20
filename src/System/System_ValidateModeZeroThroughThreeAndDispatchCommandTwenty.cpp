#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* WMi_GetSystemWork();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void WMi_SetCallbackTable(int,void*);int WMi_SendCommand(int,int,...);int WMi_CheckIdle();void* ActorPool_GetGlobalInstance();char* ActorPool_GetActiveSlot(void*,int);void Actor_SetRepresentationTargetYaw(void*,int);int Actor_GetRepresentationTargetYawOrZero(void*);int Actor_GetRepresentationCurrentYawOrZero(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void ActorEffectLoader_InvalidateQueuedRequest(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void ScriptFlagHistory_AppendGlobalKey(int);}
#pragma force_active on
// Original: arm9/main @ 0x020D68DC; symbol: func_020d68dc; size: 0x74.
extern "C" int System_ValidateModeZeroThroughThreeAndDispatchCommandTwenty(void* p,unsigned n,void* q){int status=WMi_CheckIdle();if(status)return status;if(n>3)return 6;if(n){if(!q)return 6;CleanCacheRange(q,80);}WMi_SetCallbackTable(20,p);status=WMi_SendCommand(20,2,n,q);return status?status:2;}
