#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E6030; symbol: func_ov025_021e6030; size: 0x1C.
extern "C" int func_ov025_021e6030(void *p) {
    unsigned int value = *(unsigned int *)((unsigned char *)p + 8);
    *(unsigned int *)(data_ov025_021ef988[3] + 0x224) = value;
    return 1;
}
