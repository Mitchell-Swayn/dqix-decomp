#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov027_021e33e0[];
// Original: arm9/ov027 @ 0x021DCEE8; symbol: func_ov027_021dcee8; size: 0x10.
extern "C" void func_ov027_021dcee8(unsigned short value) {
    *(unsigned short *)(data_ov027_021e33e0 + 0x26) = value;
}
