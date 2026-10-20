struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" bool TextCanvas_IsReady(int self);
extern "C" void Grid_SetLastTouchIndex(int object, unsigned int value);
extern "C" unsigned int Window_UpdateCanvasesAndSelection(unsigned char *self, unsigned int value);
// Original: arm9/ov003 @ 0x021694B8; symbol: func_ov003_021694b8; size: 0x54.
extern "C" void Bank_UpdateDialogSelection(unsigned char *base, unsigned int value) {
    unsigned int record = (unsigned int)Window_GetSelectedTextCanvas((WindowCanvasOwner*)((char *)(base + 0xE4)));
    if (record != 0 && TextCanvas_IsReady((int)record) && (*(unsigned char *)(record + 0xC5) & 2) == 0) {
        Grid_SetLastTouchIndex((int)(base + 0xE8), 0xFFFFFFFF);
    }
    base[0x4EA] = (unsigned char)Window_UpdateCanvasesAndSelection(base + 0xE4, value);
}
