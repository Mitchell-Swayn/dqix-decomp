#include <globaldefs.h>
extern "C" void InitializeFourWordsWithInvalidIndex(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" unsigned int data_ov017_021d83ec;
// The external word and cleared fields retain offset-based descriptions.
// Original: arm9/ov017 @ 0x021b14a0; symbol: func_ov017_021b14a0; size: 0x4c.
extern "C" void InitializeKind2BObjectAndClearFields(unsigned char* p) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x2b;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 8);
    *(unsigned*)(p + 0x1c) = 0;
    data_ov017_021d83ec = 0;
    p[0x30] = 0;
    p[0x31] = 0;
    p[0x48] = 0;
    p[0x49] = 1;
    p[0x4a] = 0;
}
