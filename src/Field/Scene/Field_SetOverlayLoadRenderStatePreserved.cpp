#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B2C0C; symbol: func_ov017_021b2c0c; size: 0x18.
extern "C" void Field_SetOverlayLoadRenderStatePreserved(void *p, unsigned int value) {
    unsigned int word = *(unsigned int *)((char *)p + 0x38);
    *(unsigned int *)((char *)p + 0x38) = (word & ~0x20u) | ((value & 1) << 5);
}
