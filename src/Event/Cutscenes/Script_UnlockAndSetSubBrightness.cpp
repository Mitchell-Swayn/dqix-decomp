#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x0215B6D8; symbol: Script_UnlockAndSetSubBrightness; size: 0x1C.
// Dispatches mode 15, which unlocks and sets sub-screen brightness from script parameters.
extern "C" int Script_UnlockAndSetSubBrightness(unsigned int a, unsigned int b) { Script_SetBrightnessByMode(0xf, a, b); return 1; }
