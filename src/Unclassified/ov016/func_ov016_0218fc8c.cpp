#include <globaldefs.h>
ARM
extern "C" unsigned data_ov016_0219d1c0[];
// Original: arm9/ov016 @ 0x0218FC8C; symbol: func_ov016_0218fc8c; size: 0x20.
extern "C" void func_ov016_0218fc8c(unsigned first, unsigned second) {
    data_ov016_0219d1c0[6] = first;
    data_ov016_0219d1c0[5] = second & ~3u;
    data_ov016_0219d1c0[2] = 0;
}
