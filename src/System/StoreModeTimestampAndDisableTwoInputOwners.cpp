#include <globaldefs.h>
#include <System/Timing.h>
extern unsigned data_02153628[]; extern unsigned char data_02114e30[],data_02114e54[];
extern "C" void SetByteFieldAtOffset1C(void*,unsigned char); extern "C" void ClearCurrentAndPreviousInputWords(void*); extern "C" void SetByteFieldAtOffset61(void*,unsigned char); extern "C" void TouchInput_ResetTrackingStateWrapper(void*);
// Original: arm9/main @ 0x020E1154; symbol: func_020e1154; size: 0x50.
extern "C" void StoreModeTimestampAndDisableTwoInputOwners(unsigned mode) { unsigned long long time=GetCurrentTimestamp(); *(unsigned long long*)(data_02153628+1)=time; data_02153628[0]=mode; SetByteFieldAtOffset1C(data_02114e30,0); ClearCurrentAndPreviousInputWords(data_02114e30); SetByteFieldAtOffset61(data_02114e54,0); TouchInput_ResetTrackingStateWrapper(data_02114e54); }
