#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned,unsigned);
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void System_LoadResourceAndInvokeCallback(const char*,void(*)(const void*,unsigned,unsigned));
extern "C" char data_ov031_0224bb8c[],data_ov031_0224bba4[],data_ov031_0224bbbc[];
// Original: arm9/ov031 @ 0x02230F20; symbol: func_ov031_02230f20; size: 0x94.
extern "C" void Graphics_LoadStepThreeBackgroundAssets() {
    System_LoadResourceAndInvokeCallback(data_ov031_0224bb8c,LoadToMainBG2CharacterData);
    System_LoadResourceAndInvokeCallback(data_ov031_0224bba4,LoadToMainBGStandardPalette);
    System_LoadResourceAndInvokeCallback(data_ov031_0224bbbc,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short*)0x04001008;
    volatile unsigned short *main = (volatile unsigned short*)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
