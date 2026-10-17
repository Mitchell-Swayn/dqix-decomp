#include <globaldefs.h>
ARM
extern "C" void *func_ov023_021e2418(int, int);
// Original: arm9/ov023 @ 0x021E2CC8; symbol: func_ov023_021e2cc8; size: 0x20.
extern "C" void Util_SetHalfwordPairIfResultExists(int a0, int a1, unsigned int value1, unsigned int value2) {
    unsigned char *object = (unsigned char *)func_ov023_021e2418(a0, a1);
    if (object) {
        *(unsigned short *)(object + 8) = value1;
        *(unsigned short *)(object + 0xa) = value2;
    }
}
