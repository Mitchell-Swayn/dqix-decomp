#include <globaldefs.h>
ARM
extern "C" void Window_ClearResourceBuffers(void*);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);
extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void*,int,int,int);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void Graphics_UpdateSelectedRecordMarker(void*);
extern "C" void Graphics_ConfigureConditionalDisplayEntry(void*);
extern "C" unsigned Window_IsVisible(void*);
extern "C" void Window_UpdateEnabledEntryAndRoot(void*,void*);
// Original: arm9/ov003 @ 0x02159078; symbol: Graphics_UpdateActiveTransfersAndEnabledWindow; size: 0x88.
// Updates active display transfers and enabled window after marker/configuration updates.
extern "C" void Graphics_UpdateActiveTransfersAndEnabledWindow(char* self) {
 if(!self[0x588])return;
 if(*(unsigned char*)(self+0x587))return;
 Window_ClearResourceBuffers(self+0xf4);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(self+0xf4);
 Window_FillCanvasRectanglesOnAlternateLayer(self+0xf4,1,2,1);Graphics_ResetCountedThirtyTwoByteTransfers(self+0xf4);
 Graphics_UpdateSelectedRecordMarker(self);Graphics_ConfigureConditionalDisplayEntry(self);
 if(*(void**)(self+0x570) && Window_IsVisible(*(void**)(self+0x570)))Window_UpdateEnabledEntryAndRoot(*(void**)(self+0x570),self+0x98);
}
