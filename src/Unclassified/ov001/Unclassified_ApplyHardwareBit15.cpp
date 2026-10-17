#include <globaldefs.h>
ARM

extern "C" void System_SetRegisterBit15(int value);

// Original: arm9/ov001 @ 0x0215B560; symbol: func_ov001_0215b560; size: 0x38.
extern "C" int Unclassified_ApplyHardwareBit15(void) {
    int bit = (*(volatile unsigned short *)0x04000304 & 0x8000) >> 15;
    if (bit == 0) {
        System_SetRegisterBit15(1);
    } else {
        System_SetRegisterBit15(0);
    }
    return 1;
}
