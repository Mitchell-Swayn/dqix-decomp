#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(int, int, int);
// Original: arm9/ov001 @ 0x0215B6F4; symbol: UnlockMainBrightnessAtZero; size: 0x1C.
// Dispatches mode 16, which unlocks and sets main-screen brightness to zero.
extern "C" int UnlockMainBrightnessAtZero(int first, int second) {
    Script_SetBrightnessByMode(16, first, second);
    return 1;
}
