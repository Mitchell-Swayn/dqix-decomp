#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BD38C; symbol: func_ov017_021bd38c; size: 0xC.
extern "C" void func_ov017_021bd38c(unsigned char *p, unsigned int a, unsigned int b) {
    *(unsigned int *)(p + 0x120) = a;
    *(unsigned int *)(p + 0x138) = b;
}
