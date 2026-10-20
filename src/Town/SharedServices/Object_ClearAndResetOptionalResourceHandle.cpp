#include <globaldefs.h>
ARM
extern "C" void Window_ClearResourceBuffers(unsigned char *);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void *, int, int, int);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *);
extern "C" void Town_DrawDestinationSelectionCursor(void *);
// Original: arm9/ov003 @ 0x0217DA48; symbol: func_ov003_0217da48; size: 0x5C.
extern "C" void Object_ClearAndResetOptionalResourceHandle(unsigned char *owner) {
    if (*(void **)(owner + 0x90) != 0 && (*(signed char *)(owner + 4) == 2 || *(signed char *)(owner + 5) == 0)) {
        Window_ClearResourceBuffers(*(unsigned char **)(owner + 0x90));
        ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(*(void **)(owner + 0x90));
        Window_FillCanvasRectanglesOnAlternateLayer(*(void **)(owner + 0x90), 2, 1, 1);
        Graphics_ResetCountedThirtyTwoByteTransfers(*(void **)(owner + 0x90));
    }
    Town_DrawDestinationSelectionCursor(owner);
}
