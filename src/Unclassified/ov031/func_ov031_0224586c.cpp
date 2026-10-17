#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02291f24[];
// Original: arm9/ov031 @ 0x0224586C; symbol: func_ov031_0224586c; size: 0x10.
extern "C" void func_ov031_0224586c(int value) {
    *(int *)(data_ov031_02291f24 + 0xc) = value;
}
