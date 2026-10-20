#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* WMi_GetSystemWork();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void WMi_SetCallbackTable(int,void*);int WMi_SendCommand(int,int,...);int WMi_CheckIdle();void* ActorPool_GetGlobalInstance();char* ActorPool_GetActiveSlot(void*,int);void Actor_SetRepresentationTargetYaw(void*,int);int Actor_GetRepresentationTargetYawOrZero(void*);int Actor_GetRepresentationCurrentYawOrZero(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void ActorEffectLoader_InvalidateQueuedRequest(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void ScriptFlagHistory_AppendGlobalKey(int);}
#pragma force_active on
// Original: arm9/main @ 0x020D4894; symbol: func_020d4894; size: 0x6C.
extern "C" unsigned System_ReadAlignedSharedBufferSizeWhenReady(){char* root=WMi_GetSystemWork();if(TestCurrentStatusAgainstVariadicAllowedValues(2,7,8))return 0;char* p=*(char**)(root+4);InvalidateDataCacheRange(p+12,4);p=*(char**)(root+4);if(*(int*)(p+12)==1)return 0;InvalidateDataCacheRange(p+60,4);p=*(char**)(root+4);return (*(unsigned short*)(p+60)+31)&~31;}
