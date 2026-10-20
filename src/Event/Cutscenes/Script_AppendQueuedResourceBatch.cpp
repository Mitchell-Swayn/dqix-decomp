#include <globaldefs.h>
ARM

extern "C" unsigned int Script_ReadParameterString(void *);
extern "C" void QueueIndexedFileAndIncrementPendingCount(unsigned, unsigned);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov001 @ 0x0215ED74; symbol: func_ov001_0215ed74; size: 0x44.
extern "C" int Script_AppendQueuedResourceBatch(void *objects, int endIndex) {
    int index = *(int *)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x88);
    unsigned char *object = (unsigned char *)objects;
    while (index < endIndex) {
        unsigned int value = Script_ReadParameterString(object);
        object += 8;
        QueueIndexedFileAndIncrementPendingCount(value, (unsigned)index);
        index++;
    }
    return 1;
}
