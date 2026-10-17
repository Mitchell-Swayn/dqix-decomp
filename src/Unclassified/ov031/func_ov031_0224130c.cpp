#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0224130C; symbol: func_ov031_0224130c; size: 0xC.
extern "C" unsigned int func_ov031_0224130c(unsigned int value) {
    if (value & 0x8000) value &= ~0x8000;
    return value;
}
