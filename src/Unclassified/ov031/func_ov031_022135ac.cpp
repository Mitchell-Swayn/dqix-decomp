#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022135AC; symbol: func_ov031_022135ac; size: 0x10.
extern "C" unsigned int func_ov031_022135ac(unsigned int value) {
    if (value > 2) value = (value - 3) & 0xff;
    return value;
}
