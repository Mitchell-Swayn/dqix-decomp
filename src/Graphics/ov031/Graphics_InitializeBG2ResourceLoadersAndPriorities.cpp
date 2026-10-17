#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
extern "C" char data_ov031_0224bd48[];
extern "C" char data_ov031_0224bd60[];
extern "C" char data_ov031_0224bd78[];
extern "C" void System_LoadResourceAndInvokeCallback(void*,void (*)(const void*,unsigned,unsigned));
// Original: arm9/ov031 @ 0x02233A8C; symbol: func_ov031_02233a8c; size: 0xA8.
extern "C" void Graphics_InitializeBG2ResourceLoadersAndPriorities(void) {
    System_LoadResourceAndInvokeCallback(data_ov031_0224bd48,LoadToMainBG2CharacterData);
    System_LoadResourceAndInvokeCallback(data_ov031_0224bd60,LoadToMainBGStandardPalette);
    System_LoadResourceAndInvokeCallback(data_ov031_0224bd78,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short *)0x04001008;
    volatile unsigned short *first = (volatile unsigned short *)0x04000008;
    volatile unsigned short *main = (volatile unsigned short *)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    *first = (*first & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
