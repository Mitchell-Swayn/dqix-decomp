#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216341C; symbol: func_ov000_0216341c; size: 0x24.
extern "C" void func_ov000_0216341c(void *p, unsigned char a, unsigned char b, unsigned short c) {
    *(int *)((char *)p + 0x6e24) = 1;
    *(unsigned char *)((char *)p + 0x6e2a) = a;
    *(unsigned char *)((char *)p + 0x6e2b) = b;
    *(unsigned short *)((char *)p + 0x6e2c) = c;
}
