#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original: arm9/ov003 @ 0x0217E630; symbol: func_ov003_0217e630; size: 0x4C.
extern "C" void Memory_InitializeTypeEighteenAllocatorState(signed char *p, unsigned char value) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x18;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x1c) = 0;
    p[0xb4] = value;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 8);
    *(unsigned short *)(p + 0xa0) = 0;
    *(int *)(p + 0xa4) = 0;
    *(int *)(p + 0xa8) = 0;
    *(int *)(p + 0xac) = 0;
    *(int *)(p + 0xb0) = 0;
}
