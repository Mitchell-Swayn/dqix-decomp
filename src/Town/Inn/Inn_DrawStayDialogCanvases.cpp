#include <globaldefs.h>
ARM
extern "C" void Window_ClearResourceBuffers(unsigned char*);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void*, int, int, int);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Graphics_UpdateBufferedRecordMarkerPosition(char*);
// Original: arm9/ov003 @ 0x0215CA1C; symbol: Unclassified_UpdateCountedResourcesWhenByte3BCSet; size: 0x4C.
// When self+0x3BC is nonzero, clears indexed resources, processes the 0xE0-byte records, runs the mode helper, resets transfer tracking, and updates the buffered marker position.
extern "C" void Inn_DrawStayDialogCanvases(void* self) {
    if (*(unsigned char*)((char*)self + 0x3BC) == 0) return;
    char* records = (char*)self + 0x98;
    Window_ClearResourceBuffers((unsigned char*)records);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(records);
    Window_FillCanvasRectanglesOnAlternateLayer(records, 1, 2, 1);
    Graphics_ResetCountedThirtyTwoByteTransfers(records);
    Graphics_UpdateBufferedRecordMarkerPosition((char*)self);
}
