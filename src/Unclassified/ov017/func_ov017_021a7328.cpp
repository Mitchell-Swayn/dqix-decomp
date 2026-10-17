#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);
extern "C" void InitializeSelectionControlsAndTextBuffers(unsigned char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void ClearRecordAndInvalidateTwoIndices(char *);
// Original: arm9/ov017 @ 0x021A7328; symbol: func_ov017_021a7328; size: 0x50.
extern "C" void func_ov017_021a7328(signed char *obj) {
    InitializeFourWordsWithInvalidIndex(obj);
    *(unsigned char *)obj = 0x3f;
    int zero = 0;
    *(unsigned int *)(obj + 8) = zero;
    *(unsigned int *)(obj + 0xc) = zero;
    *(unsigned int *)(obj + 0x10) = zero;
    *(unsigned int *)(obj + 0x20) = zero - 1;
    *(unsigned int *)(obj + 0x14) = zero;
    *(unsigned int *)(obj + 0x18) = zero;
    InitializeSelectionControlsAndTextBuffers((unsigned char *)obj + 0x24);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x25c);
    ClearRecordAndInvalidateTwoIndices((char *)obj + 0x270);
}
