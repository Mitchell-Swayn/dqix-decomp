#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_LoadBlankBackgroundAndLowerLayerPriorities_PathCharXb4NoneNscL;
extern "C" void LoadToMainBG2ScreenData(void);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*, void*);
// Original: arm9/ov031 @ 0x02234118; symbol: func_ov031_02234118; size: 0x6C.
extern "C" void WfcUtility_LoadBlankBackgroundAndLowerLayerPriorities(void) {
    WfcUtility_LoadLocalizedResourceAndApply(&WfcUtility_LoadBlankBackgroundAndLowerLayerPriorities_PathCharXb4NoneNscL, (void*)LoadToMainBG2ScreenData);
    volatile unsigned short* display = (volatile unsigned short*)0x04001008;
    volatile unsigned short* control = (volatile unsigned short*)0x0400000a;
    display[0] = (display[0] & ~3) | 3;
    display[1] = (display[1] & ~3) | 3;
    control[0] = (control[0] & ~3) | 3;
    control[1] = (control[1] & ~3) | 3;
}
