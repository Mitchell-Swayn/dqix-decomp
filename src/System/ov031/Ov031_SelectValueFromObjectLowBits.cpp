#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022140B0; symbol: func_ov031_022140b0; size: 0x1C.
extern "C" unsigned int Ov031_SelectValueFromObjectLowBits(const volatile unsigned char *object) {
    unsigned int shifted = (unsigned int)object[0xd0b] << 30;
    unsigned int low = shifted >> 30;
    if (low == 1) return 0x30000;
    return 0x20000;
}
