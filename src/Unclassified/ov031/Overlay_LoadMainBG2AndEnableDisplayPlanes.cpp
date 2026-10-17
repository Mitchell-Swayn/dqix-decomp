#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_0224bda0;
extern "C" void LoadToMainBG2ScreenData(void);
extern "C" void System_LoadResourceAndInvokeCallback(void*, void*);
// Original: arm9/ov031 @ 0x02234118; symbol: func_ov031_02234118; size: 0x6C.
extern "C" void Overlay_LoadMainBG2AndEnableDisplayPlanes(void) {
    System_LoadResourceAndInvokeCallback(&data_ov031_0224bda0, (void*)LoadToMainBG2ScreenData);
    volatile unsigned short* display = (volatile unsigned short*)0x04001008;
    volatile unsigned short* control = (volatile unsigned short*)0x0400000a;
    display[0] = (display[0] & ~3) | 3;
    display[1] = (display[1] & ~3) | 3;
    control[0] = (control[0] & ~3) | 3;
    control[1] = (control[1] & ~3) | 3;
}
