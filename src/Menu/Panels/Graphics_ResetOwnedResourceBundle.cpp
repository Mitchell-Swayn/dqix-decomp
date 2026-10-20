#include <globaldefs.h>
ARM
extern "C" unsigned int Window_GetCanvasStackDepth(char *);
extern "C" void Window_PopCanvasesAndResetSelection(void *, int);
extern "C" void Window_ClearResourceBuffers(unsigned char *);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *);
extern "C" void Window_ResetResourceTransfers(void *);
// Original: arm9/ov023 @ 0x021D8B6C; symbol: func_ov023_021d8b6c; size: 0x48.
extern "C" void Graphics_ResetOwnedResourceBundle(void *p) {
    void *state = (char *)p + 0x20;
    if (Window_GetCanvasStackDepth((char *)state))
        Window_PopCanvasesAndResetSelection(state, 1);
    Window_ClearResourceBuffers((unsigned char *)state);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(state);
    Graphics_ResetCountedThirtyTwoByteTransfers(state);
    Window_ResetResourceTransfers(state);
}
