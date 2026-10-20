#include <globaldefs.h>
ARM
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215AA14; symbol: func_ov001_0215aa14; size: 0x48.
extern "C" void Memory_ResetAllocatorCache(void* allocator) {
    for (int i = 0; i < 8; ++i) EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[i] = 0;
    if (!allocator) return;
    _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(allocator);
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0] = (unsigned)allocator;
}
