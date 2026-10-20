#include <globaldefs.h>
ARM
extern "C" void CharacterCreation_RefreshChoiceBackgrounds(void*),CharacterCreation_DrawSelectionSprites(void*),Graphics_UpdateSelectedResourcePositions(void*);
extern "C" void Window_ClearResourceBuffers(void*),ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*),Graphics_ResetCountedThirtyTwoByteTransfers(void*);
struct UpdateState { char unknown[0xc58]; signed char phase; };
// Original: arm9/ov009 @ 0x02184BBC; symbol: func_ov009_02184bbc; size: 0x74.
extern "C" void Graphics_UpdateStageResourceRecords(UpdateState* state) {
 if(state->phase==0 || state->phase==12) return;
 CharacterCreation_RefreshChoiceBackgrounds(state);CharacterCreation_DrawSelectionSprites(state);Graphics_UpdateSelectedResourcePositions(state);
 if(state->phase!=10) { void* item=(char*)state+0x1f8;Window_ClearResourceBuffers(item);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(item);Graphics_ResetCountedThirtyTwoByteTransfers(item); }
 void* item=(char*)state+0x2b4;Window_ClearResourceBuffers(item);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(item);Graphics_ResetCountedThirtyTwoByteTransfers(item);
}
