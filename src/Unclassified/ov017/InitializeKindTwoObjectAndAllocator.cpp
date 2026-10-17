#include <globaldefs.h>
extern "C" void InitializeFourWordsWithInvalidIndex(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// The meanings of the remaining object fields are not established.
// Original: arm9/ov017 @ 0x021a124c; symbol: func_ov017_021a124c; size: 0x38.
extern "C" void InitializeKindTwoObjectAndAllocator(unsigned char* p) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 2;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 8);
    *(unsigned*)(p + 0x1c) = 0;
    p[0x20] = 2;
    p[0x21] = 0;
    p[0x22] = 0;
}
