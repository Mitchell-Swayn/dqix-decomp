#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void System_LoadResourceAndInvokeCallback(const char*,void(*)(const void*,unsigned,unsigned));
extern "C" char data_ov031_0224b884[];
// Original: arm9/ov031 @ 0x022289A4; symbol: func_ov031_022289a4; size: 0x80.
extern "C" void Graphics_LoadMultiBackgroundScreenAndSetPriorities() {
    System_LoadResourceAndInvokeCallback(data_ov031_0224b884,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short*)0x04001008;
    volatile unsigned short *main = (volatile unsigned short*)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    *(volatile unsigned short*)0x04000008 = (*(volatile unsigned short*)0x04000008 & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
