#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned Script_ReadParameterString(void*);
extern "C" void QueueIndexedFileAndIncrementPendingCount(unsigned, unsigned);
// Original: arm9/ov001 @ 0x0215ED2C; symbol: func_ov001_0215ed2c; size: 0x48.
extern "C" int Script_QueueInitialResourceBatch(void* records, int count) {
    int index = 0;
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0x22] = 0;
    for (; index < count; ++index) {
        unsigned value = Script_ReadParameterString(records);
        records = (char*)records + 8;
        QueueIndexedFileAndIncrementPendingCount(value, (unsigned)index);
    }
    return 1;
}
