#include <globaldefs.h>
#include <System/Memory.h>
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original: arm9/ov017 @ 0x021BE40C; symbol: func_ov017_021be40c; size: 0x5C.
extern "C" void Ov017_InitializeAllocatorRecordTypeFourE(char *record) {
    InitializeFourWordsWithInvalidIndex((signed char *)record);
    record[0] = 0x4e;
    *(unsigned int *)(record + 8) = 0;
    *(unsigned int *)(record + 0x0c) = 0;
    *(unsigned int *)(record + 0x20) = 0xffffffff;
    *(unsigned int *)(record + 0x1c) = 0;
    record[0x38] = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(record + 0x24);
    *(unsigned int *)(record + 0x10) = 0;
    *(unsigned int *)(record + 0x14) = 0;
    *(unsigned int *)(record + 0x18) = 0;
    record[0x39] = 0;
    VectorizedMemset(record + 0x3a, 0, 0x10);
}
