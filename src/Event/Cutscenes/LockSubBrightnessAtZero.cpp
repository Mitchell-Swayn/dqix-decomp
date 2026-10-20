#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x0215B614; symbol: LockSubBrightnessAtZero; size: 0x1C.
// Dispatches mode 8, which sets sub-screen brightness to zero and locks it.
extern "C" int LockSubBrightnessAtZero(unsigned int a, unsigned int b) { Script_SetBrightnessByMode(8, a, b); return 1; }
