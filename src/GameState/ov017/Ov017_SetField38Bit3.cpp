#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B2BDC; symbol: func_ov017_021b2bdc; size: 0x18.
extern "C" void Ov017_SetField38Bit3(void *object, unsigned int value) {
    unsigned int *field = (unsigned int *)((char *)object + 0x38);
    *field = (*field & ~8u) | ((value & 1u) << 3);
}
