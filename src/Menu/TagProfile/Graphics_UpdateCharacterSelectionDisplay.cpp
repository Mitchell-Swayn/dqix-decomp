#include <globaldefs.h>
extern "C" void Graphics_RefreshTransfersAndSubmitSelectedFortyByteRecord(void*), Window_ClearResourceBuffers(void*), ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*), Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void*, int, int, int);
extern "C" void Menu_DrawSelectedCanvasAnimatedMarker(void*), Menu_DrawDateControlArrowPairs(void*), Menu_DrawDateControlAuxiliarySprite(void*), Menu_DrawCanvasAccessorySprite(void*), SubmitMode14IndexedFixedPosition(void*);
// Initialize shared profile-screen components and configure UI transitions.
// Original: arm9/ov012 @ 0x02185A24; symbol: func_ov012_02185a24; size: 0x94.
extern "C" void Graphics_UpdateCharacterSelectionDisplay(unsigned char* screen) {
    Graphics_RefreshTransfersAndSubmitSelectedFortyByteRecord(screen + 0xd28);
    Window_ClearResourceBuffers(screen + 0xac);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(screen + 0xac);
    Window_FillCanvasRectanglesOnAlternateLayer(screen + 0xac, 1, 2, 1);
    Window_FillCanvasRectanglesOnAlternateLayer(screen + 0xac, 1, 3, 1);
    Window_FillCanvasRectanglesOnAlternateLayer(screen + 0xac, 2, 3, 0);
    Graphics_ResetCountedThirtyTwoByteTransfers(screen + 0xac);
    Menu_DrawSelectedCanvasAnimatedMarker(screen);
    Menu_DrawDateControlArrowPairs(screen);
    Menu_DrawDateControlAuxiliarySprite(screen);
    Menu_DrawCanvasAccessorySprite(screen);
    SubmitMode14IndexedFixedPosition(screen);
}
