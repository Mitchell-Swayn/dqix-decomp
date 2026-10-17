#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E856C; symbol: func_ov025_021e856c; size: 0x18.
extern "C" int func_ov025_021e856c(void) {
    *(unsigned char *)((char *)*(void **)(data_ov025_021ef988 + 0xc) + 0x578) = 1;
    return 1;
}
