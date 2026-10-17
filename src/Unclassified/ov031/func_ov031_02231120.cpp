#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02231120; symbol: func_ov031_02231120; size: 0x20.
extern "C" unsigned func_ov031_02231120(void) {
    volatile unsigned short *reg = (volatile unsigned short *)0x027fffa8;
    int value = *reg & 0x8000;
    int bit = value >> 15;
    return bit ? 1 : 0;
}
