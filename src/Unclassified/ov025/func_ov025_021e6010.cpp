#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E6010; symbol: func_ov025_021e6010; size: 0x20.
extern "C" int func_ov025_021e6010(void *p) {
    unsigned short value = *(unsigned short *)((unsigned char *)p + 8);
    *(unsigned short *)(data_ov025_021ef988[3] + 0x21c) = value;
    return 1;
}
