#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215B598; symbol: func_ov001_0215b598; size: 0x1C.
extern "C" void System_SetRegisterBit15(unsigned int value) {
    unsigned short *reg = (unsigned short *)0x04000304;
    unsigned int old = *reg;
    *reg = (unsigned short)((old & ~0x8000u) | (value << 15));
}
