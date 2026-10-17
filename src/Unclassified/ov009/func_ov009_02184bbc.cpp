#include <globaldefs.h>
ARM
extern "C" void func_ov023_021da274(void*),func_ov023_021da770(void*),Graphics_UpdateSelectedResourcePositions(void*);
extern "C" void ClearEachIndexedEntryResource(void*),ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*),Graphics_ResetCountedThirtyTwoByteTransfers(void*);
struct UpdateState { char unknown[0xc58]; signed char phase; };
// Original: arm9/ov009 @ 0x02184BBC; symbol: func_ov009_02184bbc; size: 0x74.
extern "C" void func_ov009_02184bbc(UpdateState* state) {
 if(state->phase==0 || state->phase==12) return;
 func_ov023_021da274(state);func_ov023_021da770(state);Graphics_UpdateSelectedResourcePositions(state);
 if(state->phase!=10) { void* item=(char*)state+0x1f8;ClearEachIndexedEntryResource(item);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(item);Graphics_ResetCountedThirtyTwoByteTransfers(item); }
 void* item=(char*)state+0x2b4;ClearEachIndexedEntryResource(item);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(item);Graphics_ResetCountedThirtyTwoByteTransfers(item);
}
