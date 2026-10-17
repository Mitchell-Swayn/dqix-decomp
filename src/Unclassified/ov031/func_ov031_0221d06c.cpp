#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224e6e0;
// Original: arm9/ov031 @ 0x0221D06C; symbol: func_ov031_0221d06c; size: 0xC.
extern "C" unsigned int func_ov031_0221d06c(void) {
    return *(unsigned int *)((unsigned char *)&data_ov031_0224e6e0 + 0x10);
}
