#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* ReadGlobalOperationContextPointerAt4();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void SetGlobalIndexedWordAtOffset18(int,void*);int func_020d40bc(int,int,...);int ReadCachedStatusHalfwordAndClassify();void* Object_GetGlobalThirtyTwoEntryContainer();char* GetBoundedSlotUnlessFlag8000(void*,int);void WriteFirstAvailableVerticalCoordinate(void*,int);int Object_ReadDataFromFirstAvailableRenderTarget(void*);int ReadFirstAvailableVerticalCoordinate(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void InvalidateWords0And8AndClearByte4(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void AppendKeyToGlobalTwentyFourHalfwordHistory(int);}
#pragma force_active on
// Original: arm9/main @ 0x020D68DC; symbol: func_020d68dc; size: 0x74.
extern "C" int ValidateModeZeroThroughThreeAndDispatchCommandTwenty(void* p,unsigned n,void* q){int status=ReadCachedStatusHalfwordAndClassify();if(status)return status;if(n>3)return 6;if(n){if(!q)return 6;CleanCacheRange(q,80);}SetGlobalIndexedWordAtOffset18(20,p);status=func_020d40bc(20,2,n,q);return status?status:2;}
