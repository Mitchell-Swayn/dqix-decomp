#include <globaldefs.h>
ARM
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3;
struct Obj { unsigned char pad0[8]; unsigned char allocator[0x14]; unsigned char active; unsigned char restore; unsigned char pad2[2]; void* pending; };
// Original: arm9/ov017 @ 0x021C1A24; symbol: Memory_CleanupOverlayContextAllocator; size: 0x74.
// Cleans up pending overlay/global-stack state, destroys and frees the signed allocator when present, resets its pointer, and clears the active byte. Caller is an ov017 teardown path.
extern "C" void Memory_CleanupOverlayContextAllocator(Obj* self) {
    if (self->pending) {
        self->pending = 0;
        if (self->restore) OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
    }
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv(self->allocator);
    if (allocator) {
        _ZN13SafeAllocator7DestroyEv(self->allocator);
        Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
    }
    _ZN13SafeAllocator21ResetAllocatorPointerEv(self->allocator);
    self->active = 0;
}
