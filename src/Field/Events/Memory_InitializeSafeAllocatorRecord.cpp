#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
extern "C" void MessageTextTable_Reset(char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original: arm9/ov017 @ 0x021BEFE4; symbol: func_ov017_021befe4; size: 0x30.
extern "C" void Memory_InitializeSafeAllocatorRecord(signed char *record) {
    LinkedQueue_InitializeNodeStatus(record);
    record[0] = 0x35;
    *(int *)(record + 8) = 0;
    MessageTextTable_Reset((char *)record + 0xc);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(record + 0x14);
}
