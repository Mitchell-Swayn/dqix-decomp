#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char*);
extern "C" void ClearWordAndTwoHalfwords_Main020727D8(char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov017 @ 0x021A6BE4; symbol: func_ov017_021a6be4; size: 0x48.
extern "C" void func_ov017_021a6be4(signed char* p) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x3e;
    *(unsigned int*)(p + 8) = 0;
    *(unsigned int*)(p + 0x44) = 0xffffffff;
    *(unsigned int*)(p + 0xc) = 0;
    p[0x10] = 0;
    ClearWordAndTwoHalfwords_Main020727D8((char*)p + 0x14);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 0x1c);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 0x30);
}
