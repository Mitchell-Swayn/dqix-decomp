#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E6304; symbol: func_ov025_021e6304; size: 0x1C.
extern "C" int func_ov025_021e6304(void *p) {
    unsigned int value = *(unsigned int *)((unsigned char *)p + 8);
    *(unsigned int *)(data_ov025_021ef988[3] + 0x558) = value;
    return 1;
}
