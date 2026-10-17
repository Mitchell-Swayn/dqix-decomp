#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB23C; symbol: func_ov023_021fb23c; size: 0x10.
extern "C" void func_ov023_021fb23c(void *p, unsigned short a, unsigned short b, unsigned short c) {
    *(unsigned short *)((char *)p + 0x3c) = a;
    *(unsigned short *)((char *)p + 0x3e) = b;
    *(unsigned short *)((char *)p + 0x40) = c;
}
