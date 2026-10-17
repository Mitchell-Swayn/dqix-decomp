#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* ReadGlobalOperationContextPointerAt4();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void SetGlobalIndexedWordAtOffset18(int,void*);int func_020d40bc(int,int,...);int ReadCachedStatusHalfwordAndClassify();void* Object_GetGlobalThirtyTwoEntryContainer();char* GetBoundedSlotUnlessFlag8000(void*,int);void WriteFirstAvailableVerticalCoordinate(void*,int);int Object_ReadDataFromFirstAvailableRenderTarget(void*);int ReadFirstAvailableVerticalCoordinate(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void InvalidateWords0And8AndClearByte4(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void AppendKeyToGlobalTwentyFourHalfwordHistory(int);}
#pragma force_active on
// Original: arm9/main @ 0x020D5AEC; symbol: func_020d5aec; size: 0x70.
extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void* arg){char* root=ReadGlobalOperationContextPointerAt4();int status=TestCurrentStatusAgainstVariadicAllowedValues(2,9,10);if(status)return status;InvalidateDataCacheRange(*(char**)(root+4)+12,4);if(!*(int*)(*(char**)(root+4)+12))return 3;SetGlobalIndexedWordAtOffset18(16,arg);status=func_020d40bc(16,0);return status?status:2;}
