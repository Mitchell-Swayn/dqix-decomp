#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0217EEA8; symbol: func_ov003_0217eea8; size: 0x1C.
extern "C" void Graphics_SetMainEngineOnUpperScreen(unsigned value) {
    volatile unsigned short *reg = (volatile unsigned short *)0x04000304;
    unsigned old = *reg;
    *reg = (unsigned short)((old & ~0x8000) | (value << 15));
}
