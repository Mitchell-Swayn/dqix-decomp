#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x0215B6BC; symbol: UnlockSubBrightnessAtZero; size: 0x1C.
// Dispatches mode 14, which unlocks and sets sub-screen brightness to zero.
extern "C" int UnlockSubBrightnessAtZero(unsigned int a, unsigned int b) {
    Script_SetBrightnessByMode(14, a, b);
    return 1;
}
