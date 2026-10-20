#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1CA8; symbol: func_ov017_021b1ca8; size: 0x1C.
extern "C" void System_SetRegisterBit15_Overlay017(unsigned int value) {
    unsigned short *reg = (unsigned short *)0x04000304;
    unsigned int old = *reg;
    *reg = (unsigned short)((old & ~0x8000u) | (value << 15));
}
