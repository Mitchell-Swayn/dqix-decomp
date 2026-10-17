#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
extern "C" void ClearWordAndTwoHalfwords_Main020727D8(char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original: arm9/ov017 @ 0x021BEFE4; symbol: func_ov017_021befe4; size: 0x30.
extern "C" void Memory_InitializeSafeAllocatorRecord(signed char *record) {
    InitializeFourWordsWithInvalidIndex(record);
    record[0] = 0x35;
    *(int *)(record + 8) = 0;
    ClearWordAndTwoHalfwords_Main020727D8((char *)record + 0xc);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(record + 0x14);
}
