#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
extern "C" char Graphics_InitializeBG2ScreenLoaderAndPriorities_PathCharYb5MultiNscL[];
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void (*)(const void*,unsigned,unsigned));
// Original: arm9/ov031 @ 0x02229E70; symbol: func_ov031_02229e70; size: 0x80.
extern "C" void Graphics_InitializeBG2ScreenLoaderAndPriorities(void) {
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_InitializeBG2ScreenLoaderAndPriorities_PathCharYb5MultiNscL,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short *)0x04001008;
    volatile unsigned short *first = (volatile unsigned short *)0x04000008;
    volatile unsigned short *main = (volatile unsigned short *)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    *first = (*first & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
