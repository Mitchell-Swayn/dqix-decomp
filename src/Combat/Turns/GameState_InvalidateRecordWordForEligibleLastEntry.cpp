struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_GetTopTextCanvas(WindowCanvasOwner*);
extern "C" bool TextCanvas_IsReady(int);
extern "C" void Grid_SetLastTouchIndex(void *, unsigned int);
// Original: arm9/ov000 @ 0x02175440; symbol: func_ov000_02175440; size: 0x40.
// Finds the final 224-byte record; if its state equals three and flag 2 is clear, writes minus one through the embedded record owner.
extern "C" void GameState_InvalidateRecordWordForEligibleLastEntry(unsigned char *obj) {
    unsigned char *record = (unsigned char *)Window_GetTopTextCanvas((WindowCanvasOwner*)(obj + 0x188));
    if (record == 0) return;
    if (!TextCanvas_IsReady((int)record)) return;
    if ((record[0xc5] & 2) != 0) return;
    Grid_SetLastTouchIndex(obj + 0x18c, 0xffffffff);
}
