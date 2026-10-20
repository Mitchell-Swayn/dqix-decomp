#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x0216574C; symbol: func_ov002_0216574c; size: 0x18.
extern "C" void Util_UpdateBit3(int a0, int a1) {
    unsigned char *field = (unsigned char *)(a0 + 0xc5);
    if (a1)
        *field |= 8;
    else
        *field &= ~8;
}
