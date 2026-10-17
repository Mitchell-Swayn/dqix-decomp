#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov003 @ 0x02160B2C; symbol: func_ov003_02160b2c; size: 0x24.
extern "C" void ClearGlobalFlagByteWhenObjectMaskUnset(void *object) {
    if ((*(unsigned int *)((char *)object + 0x464) & 0x20000) == 0) {
        unsigned char *base = (unsigned char *)ReadWordFieldAtOffset1C();
        base[0x19ae] = 0;
    }
}
