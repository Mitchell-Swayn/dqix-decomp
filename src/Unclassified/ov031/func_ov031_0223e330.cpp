#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d9c[];

// Original: arm9/ov031 @ 0x0223E330; symbol: func_ov031_0223e330; size: 0x18.
extern "C" void func_ov031_0223e330(unsigned int index, unsigned char value) {
    *((unsigned char *)data_ov031_02290d9c[0] + index * 0x40 + 0x38) = value;
}
