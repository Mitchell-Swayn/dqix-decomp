#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov017 @ 0x21d8474; symbol: data_ov017_021d8474.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern unsigned PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original: arm9/ov017 @ 0x021C0160; symbol: func_ov017_021c0160; size: 0x44.
void Memory_ReleaseAllocatorAndSignedAllocation(void *p) {
    PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage = 0;
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char *)p + 8);
    if (!allocator) return;
    _ZN13SafeAllocator7DestroyEv((char *)p + 8);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
}
}
