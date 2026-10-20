#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218BC70; symbol: func_ov016_0218bc70; size: 0x1C.
extern "C" void Movie_SetDisplayEngineSelection(unsigned value) {
    volatile unsigned short *reg = (volatile unsigned short *)0x04000304;
    unsigned old = *reg;
    *reg = (unsigned short)((old & ~0x8000) | (value << 15));
}
