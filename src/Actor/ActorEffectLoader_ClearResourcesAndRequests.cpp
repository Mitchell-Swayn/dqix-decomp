#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* WMi_GetSystemWork();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void WMi_SetCallbackTable(int,void*);int WMi_SendCommand(int,int,...);int WMi_CheckIdle();void* ActorPool_GetGlobalInstance();char* ActorPool_GetActiveSlot(void*,int);void Actor_SetRepresentationTargetYaw(void*,int);int Actor_GetRepresentationTargetYawOrZero(void*);int Actor_GetRepresentationCurrentYawOrZero(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void ActorEffectLoader_InvalidateQueuedRequest(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void ScriptFlagHistory_AppendGlobalKey(int);}
#pragma force_active on
// Original: arm9/main @ 0x020DA1AC; symbol: func_020da1ac; size: 0x80.
extern "C" void ActorEffectLoader_ClearResourcesAndRequests(char* p){void* obj=Object_GetGlobalSixteenEntryDisplayState(p);if(obj){RemoveMatchingNodeAndResetMatchingObjectSlots(obj,20);RemoveMatchingNodeAndResetMatchingObjectSlots(obj,21);RemoveMatchingNodeAndResetMatchingObjectSlots(obj,22);}char* field=p+20;for(unsigned char i=0;i<4;++i,field+=12)ActorEffectLoader_InvalidateQueuedRequest(field);*(int*)p=0;*(int*)(p+4)=0;p[12]=0;p[13]=0;p[14]=0;p[15]=0;p[17]=0;}
