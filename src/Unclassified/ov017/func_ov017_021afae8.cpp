#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AFAE8; symbol: func_ov017_021afae8; size: 0x14.
extern "C" void func_ov017_021afae8(void *p, unsigned int bit) {
    *(unsigned char *)((char *)p + 0x1f) |= 1 << bit;
}
