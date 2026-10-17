#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* ReadGlobalOperationContextPointerAt4();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void SetGlobalIndexedWordAtOffset18(int,void*);int func_020d40bc(int,int,...);int ReadCachedStatusHalfwordAndClassify();void* Object_GetGlobalThirtyTwoEntryContainer();char* GetBoundedSlotUnlessFlag8000(void*,int);void WriteFirstAvailableVerticalCoordinate(void*,int);int Object_ReadDataFromFirstAvailableRenderTarget(void*);int ReadFirstAvailableVerticalCoordinate(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void InvalidateWords0And8AndClearByte4(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void AppendKeyToGlobalTwentyFourHalfwordHistory(int);}
#pragma force_active on
// Original: arm9/main @ 0x020DA1AC; symbol: func_020da1ac; size: 0x80.
extern "C" void RemoveThreeResourcesAndResetFourTasks(char* p){void* obj=Object_GetGlobalSixteenEntryDisplayState(p);if(obj){RemoveMatchingNodeAndResetMatchingObjectSlots(obj,20);RemoveMatchingNodeAndResetMatchingObjectSlots(obj,21);RemoveMatchingNodeAndResetMatchingObjectSlots(obj,22);}char* field=p+20;for(unsigned char i=0;i<4;++i,field+=12)InvalidateWords0And8AndClearByte4(field);*(int*)p=0;*(int*)(p+4)=0;p[12]=0;p[13]=0;p[14]=0;p[15]=0;p[17]=0;}
