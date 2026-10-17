#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E85A8; symbol: func_ov025_021e85a8; size: 0x20.
extern "C" int func_ov025_021e85a8(void *p) {
    void *base = *(void **)(data_ov025_021ef988 + 0xc);
    *(unsigned short *)((char *)base + 0x74a) = *(unsigned short *)((char *)p + 8);
    return 1;
}
