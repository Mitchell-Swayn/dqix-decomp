#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *object);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *self);
// Original: arm9/ov017 @ 0x021A6608; symbol: func_ov017_021a6608; size: 0x40.
extern "C" void GameObject_InitializeType3DEntry(void *object) {
    signed char *bytes = (signed char *)object;
    InitializeFourWordsWithInvalidIndex(bytes);
    bytes[0] = 0x3d;
    bytes[8] = 0;
    *(short *)(bytes + 0x0e) = (short)(bytes[8] - 1);
    bytes[9] = 0;
    bytes[10] = 0;
    bytes[11] = 0;
    bytes[12] = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(bytes + 0x10);
}
