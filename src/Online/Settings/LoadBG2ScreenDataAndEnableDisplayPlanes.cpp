#include <globaldefs.h>
ARM
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void *, void (*)(void));
extern "C" void LoadToMainBG2ScreenData(void);
extern "C" unsigned char LoadBG2ScreenDataAndEnableDisplayPlanes_PathCharXb4MultiNscL;
// Original: arm9/ov031 @ 0x0222B48C; symbol: LoadBG2ScreenDataAndEnableDisplayPlanes; size: 0x6C.
// Loads BG2 screen data and sets low two control bits on both display registers.
extern "C" void LoadBG2ScreenDataAndEnableDisplayPlanes(void) {
 WfcUtility_LoadLocalizedResourceAndApply(&LoadBG2ScreenDataAndEnableDisplayPlanes_PathCharXb4MultiNscL, LoadToMainBG2ScreenData);
 volatile unsigned short *reg1 = (volatile unsigned short *)0x04001008;
 volatile unsigned short *reg2 = (volatile unsigned short *)0x0400000a;
 *reg1 = (*reg1 & ~3u) | 3u;
 reg1[1] = (reg1[1] & ~3u) | 3u;
 *reg2 = (*reg2 & ~3u) | 3u;
 reg2[1] = (reg2[1] & ~3u) | 3u;
}
