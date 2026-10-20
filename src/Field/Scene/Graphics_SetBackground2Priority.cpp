#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021999E0; symbol: func_ov017_021999e0; size: 0x1C.
extern "C" void Graphics_SetBackground2Priority(unsigned int priority) {
    volatile unsigned short *reg = (volatile unsigned short *)0x0400000c;
    unsigned short value = *reg;
    *reg = (unsigned short)((value & ~3u) | priority);
}
