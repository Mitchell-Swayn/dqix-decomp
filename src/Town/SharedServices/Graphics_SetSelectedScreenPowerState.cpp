#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0217C2A0; symbol: func_ov003_0217c2a0; size: 0x1C.
extern "C" void Graphics_SetSelectedScreenPowerState(unsigned int enabled) {
    volatile unsigned short *control = (volatile unsigned short *)0x04000304;
    *control = (unsigned short)((*control & ~0x8000) | (enabled << 15));
}
