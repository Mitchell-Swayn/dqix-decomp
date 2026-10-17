#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original: arm9/ov017 @ 0x021C0334; symbol: func_ov017_021c0334; size: 0x30.
extern "C" void ResetObjectAllocatorAndFields(signed char *p) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x28;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 8);
    *(int *)(p + 0x1c) = 0;
    *(int *)(p + 0x20) = 0;
    p[0x24] = 0;
}
