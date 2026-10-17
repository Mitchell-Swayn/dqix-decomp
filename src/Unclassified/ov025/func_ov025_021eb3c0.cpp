#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021EB3C0; symbol: func_ov025_021eb3c0; size: 0x20.
extern "C" void func_ov025_021eb3c0(void *object) {
    *(unsigned short *)((char *)object + 4) = 0;
    *(unsigned short *)((char *)object + 6) = 0;
    *(unsigned char *)((char *)object + 8) = 0;
    *(unsigned char *)((char *)object + 9) = 0;
    *(unsigned *)object = 0xffffffff;
}
