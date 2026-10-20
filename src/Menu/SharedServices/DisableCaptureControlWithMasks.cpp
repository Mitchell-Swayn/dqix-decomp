#include <globaldefs.h>
ARM
extern "C" void G3X_SetClearColor(unsigned int, unsigned int, unsigned short, unsigned int, int);
// Original: arm9/ov004 @ 0x0216D7F8; symbol: func_ov004_0216d7f8; size: 0x28.
extern "C" int DisableCaptureControlWithMasks(void) {
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    return 0;
}
