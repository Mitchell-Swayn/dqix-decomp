#include <globaldefs.h>
ARM
extern unsigned char data_02111304[];
extern "C" void func_ov031_0220321c(void);
// Original: arm9/ov031 @ 0x0220321C; symbol: func_ov031_0220321c; size: 0x34.
extern "C" void func_ov031_0220321c(void) {
    void *base = *(void **)(data_02111304 + 4);
    void *object = *(void **)((char *)base + 0xA4);
    if (object == 0) return;
    *(void **)object = base;
    *(unsigned char *)((char *)object + 8) = 0;
    *(unsigned int *)((char *)object + 0x44) = 0;
    *(unsigned int *)((char *)object + 0x60) = 0;
    *(unsigned int *)((char *)object + 0x38) = 0;
}
