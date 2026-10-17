#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original: arm9/ov017 @ 0x021ABB68; symbol: func_ov017_021abb68; size: 0x40.
extern "C" void func_ov017_021abb68(signed char *p, unsigned char value) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x1c;
    p[8] = 0;
    *(unsigned short *)(p + 0xa) = 0;
    p[0xc] = value;
    *(unsigned int *)(p + 0x24) = 0xffffffff;
    p[0xd] = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 0x10);
}
