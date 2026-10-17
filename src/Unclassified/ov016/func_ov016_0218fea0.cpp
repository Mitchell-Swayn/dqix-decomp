#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218FEA0; symbol: func_ov016_0218fea0; size: 0x14.
extern "C" void func_ov016_0218fea0(int a0, int a1) {
    *(int *)(a0 + 4) = *(unsigned char *)a1;
    *(int *)a0 = *(signed short *)(a1 + 2);
}
