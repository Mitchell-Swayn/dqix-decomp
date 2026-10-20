#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(int, int, int);
// Original: arm9/ov001 @ 0x0215B64C; symbol: LockMainBrightnessAtZero; size: 0x1C.
// Dispatches mode 10, which sets main-screen brightness to zero and locks it.
extern "C" int LockMainBrightnessAtZero(int first, int second) {
    Script_SetBrightnessByMode(10, first, second);
    return 1;
}
