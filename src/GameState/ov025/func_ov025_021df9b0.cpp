#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov025 @ 0x021DF9B0; symbol: func_ov025_021df9b0; size: 0x44.
extern "C" void func_ov025_021df9b0(void *p) {
    *(unsigned int *)((char *)p + 0x158) = 0;
    *(unsigned int *)((char *)p + 0x15c) = 0;
    *(unsigned int *)((char *)p + 0x160) = 0;
    *(unsigned int *)((char *)p + 0x164) = 0;
    *(unsigned int *)((char *)p + 0x168) = 0;
    *(unsigned int *)((char *)p + 0x16c) = 0;
    *((unsigned char *)p + 0x18a) = 0;
    *((unsigned char *)p + 0x18b) = 0;
    *(unsigned int *)((char *)p + 0x170) = 1;
    memset((char *)p + 0x176, 0, 0x14);
}
