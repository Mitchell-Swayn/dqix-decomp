#include <globaldefs.h>
ARM
extern "C" int Script_SetBrightnessByMode(int, void *, void *);
// Original: arm9/ov001 @ 0x0215B684; symbol: func_ov001_0215b684; size: 0x1C.
extern "C" unsigned int Script_UnlockBothScreensAndTransitionBrightnessToZero(void *arg0, void *arg1) {
    Script_SetBrightnessByMode(0xC, arg0, arg1);
    return 1;
}
