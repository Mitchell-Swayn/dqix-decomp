#include <globaldefs.h>
ARM
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int enabled);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator, void* allocation);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021C07D0; symbol: func_ov017_021c07d0; size: 0x50.
extern "C" void Memory_DestroySignedSafeAllocator(void* self) {
    if (*(int*)((char*)self + 0x1C) != 0) {
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
        *(int*)((char*)self + 0x1C) = 0;
    }
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)self + 8);
    if (allocator == 0) return;
    _ZN13SafeAllocator7DestroyEv((char*)self + 8);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
}
