#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void System_LoadResourceAndInvokeCallback(const char*,void(*)(const void*,unsigned,unsigned));
extern "C" char data_ov031_0224bbd0[];
// Original: arm9/ov031 @ 0x0223117C; symbol: func_ov031_0223117c; size: 0x80.
extern "C" void Graphics_LoadXb4MultiScreenAndSetPriorities() {
    System_LoadResourceAndInvokeCallback(data_ov031_0224bbd0,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short*)0x04001008;
    volatile unsigned short *main = (volatile unsigned short*)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    *(volatile unsigned short*)0x04000008 = (*(volatile unsigned short*)0x04000008 & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
