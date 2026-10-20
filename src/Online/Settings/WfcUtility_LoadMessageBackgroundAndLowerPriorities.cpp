#include <globaldefs.h>
ARM
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const void *request, void (*callback)(const void *, unsigned, unsigned));
extern "C" void LoadToMainBG2ScreenData(const void *data, unsigned offset, unsigned length);
extern "C" unsigned char WfcUtility_LoadMessageBackgroundAndLowerPriorities_PathCharYb5MultiNscL[];
// Original: arm9/ov031 @ 0x0222A1A4; symbol: func_ov031_0222a1a4; size: 0x6C.
extern "C" void WfcUtility_LoadMessageBackgroundAndLowerPriorities(void) {
    WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_LoadMessageBackgroundAndLowerPriorities_PathCharYb5MultiNscL, LoadToMainBG2ScreenData);
    volatile unsigned short *display = (volatile unsigned short *)0x04001008;
    volatile unsigned short *display2 = (volatile unsigned short *)0x0400000a;
    display[0] = (display[0] & ~3u) | 3u;
    display[1] = (display[1] & ~3u) | 3u;
    *display2 = (*display2 & ~3u) | 3u;
    display2[1] = (display2[1] & ~3u) | 3u;
}
