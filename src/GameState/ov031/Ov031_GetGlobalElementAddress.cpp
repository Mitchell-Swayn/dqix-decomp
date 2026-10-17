#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02290d60;
// Original: arm9/ov031 @ 0x0223DAA4; symbol: func_ov031_0223daa4; size: 0x18.
extern "C" void *Ov031_GetGlobalElementAddress(unsigned int row, unsigned int index) {
    return data_ov031_02290d60 + row * 0x400 + index * 8;
}
