#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02199998; symbol: func_ov017_02199998; size: 0x1C.
extern "C" void Graphics_SetBG1Priority(unsigned int priority) {
    volatile unsigned short *control = (volatile unsigned short *)0x0400000a;
    *control = (unsigned short)((*control & ~3) | priority);
}
