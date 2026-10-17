#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
ARM
struct Flag5 { unsigned char a:5,flag:1,b:2; };
extern "C"{char* ReadGlobalOperationContextPointerAt4();int TestCurrentStatusAgainstVariadicAllowedValues(int,...);void SetGlobalIndexedWordAtOffset18(int,void*);int func_020d40bc(int,int,...);int ReadCachedStatusHalfwordAndClassify();void* Object_GetGlobalThirtyTwoEntryContainer();char* GetBoundedSlotUnlessFlag8000(void*,int);void WriteFirstAvailableVerticalCoordinate(void*,int);int Object_ReadDataFromFirstAvailableRenderTarget(void*);int ReadFirstAvailableVerticalCoordinate(void*);void* Object_GetGlobalSixteenEntryDisplayState(void*);void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);void InvalidateWords0And8AndClearByte4(void*);void* func_0200fd70(GameState*,int);int func_020373e4(void*);void Object3D_DrawOrProcessWhenCountdownExpired(void*);void AppendKeyToGlobalTwentyFourHalfwordHistory(int);}
#pragma force_active on
// Original: arm9/main @ 0x020D4894; symbol: func_020d4894; size: 0x6C.
extern "C" unsigned ReadAlignedSharedBufferSizeWhenReady(){char* root=ReadGlobalOperationContextPointerAt4();if(TestCurrentStatusAgainstVariadicAllowedValues(2,7,8))return 0;char* p=*(char**)(root+4);InvalidateDataCacheRange(p+12,4);p=*(char**)(root+4);if(*(int*)(p+12)==1)return 0;InvalidateDataCacheRange(p+60,4);p=*(char**)(root+4);return (*(unsigned short*)(p+60)+31)&~31;}
