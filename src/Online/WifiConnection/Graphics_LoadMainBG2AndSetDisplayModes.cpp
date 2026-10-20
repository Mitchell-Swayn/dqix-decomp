#include <globaldefs.h>
extern "C" unsigned char Graphics_LoadMainBG2AndSetDisplayModes_PathCharXb4MultiNscL[];
extern "C" void LoadToMainBG2ScreenData();
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*, void (*)());
// Original: arm9/ov031 @ 0x02233E7C; symbol: func_ov031_02233e7c; size: 0x6C.
extern "C" void Graphics_LoadMainBG2AndSetDisplayModes() {
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2AndSetDisplayModes_PathCharXb4MultiNscL, LoadToMainBG2ScreenData);
    volatile unsigned short* first = (volatile unsigned short*)0x04001008;
    volatile unsigned short* second = (volatile unsigned short*)0x0400000a;
    *first = (unsigned short)((*first & ~3u) | 3u);
    *(first + 1) = (unsigned short)((*(first + 1) & ~3u) | 3u);
    *second = (unsigned short)((*second & ~3u) | 3u);
    *(second + 1) = (unsigned short)((*(second + 1) & ~3u) | 3u);
}
