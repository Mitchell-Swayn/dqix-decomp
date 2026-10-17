#include <globaldefs.h>
ARM

extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" int data_ov017_021d840c;

// Original: arm9/ov017 @ 0x021B2C4C; symbol: func_ov017_021b2c4c; size: 0x3C.
extern "C" void func_ov017_021b2c4c(unsigned char *p) {
    InitializeFourWordsWithInvalidIndex((signed char *)p);
    p[0] = 0x12;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 0xc);
    *(unsigned int *)(p + 8) = 0;
    data_ov017_021d840c = 0;
    p[0x20] = 0xff;
}
