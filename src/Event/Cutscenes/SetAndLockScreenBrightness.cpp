#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x0215B5F8; symbol: SetAndLockScreenBrightness; size: 0x1C.
// Dispatches brightness mode 7, which sets and locks combined screen brightness using script parameters.
extern "C" int SetAndLockScreenBrightness(unsigned int a, unsigned int b) {
    Script_SetBrightnessByMode(7, a, b);
    return 1;
}
