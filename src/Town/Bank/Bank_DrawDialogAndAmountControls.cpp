#include <globaldefs.h>
ARM
extern "C" void Window_ClearResourceBuffers(unsigned char *object);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *object);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void *object, int first, int second, int third);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *object);
extern "C" void Graphics_PositionSelectedRecordResourceEntries(void *object);
extern "C" void Bank_DrawLocalizedAmountActionSprites(void *object);
// Original: arm9/ov003 @ 0x02168560; symbol: func_ov003_02168560; size: 0x48.
extern "C" void Bank_DrawDialogAndAmountControls(void *state) {
    unsigned char *object = (unsigned char *)state + 0xe4;
    Window_ClearResourceBuffers(object);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(object);
    Window_FillCanvasRectanglesOnAlternateLayer(object, 1, 2, 1);
    Graphics_ResetCountedThirtyTwoByteTransfers(object);
    Graphics_PositionSelectedRecordResourceEntries(state);
    Bank_DrawLocalizedAmountActionSprites(state);
}
