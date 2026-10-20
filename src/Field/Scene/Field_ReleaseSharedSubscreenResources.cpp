#include <globaldefs.h>
ARM
extern "C" void Graphics_ReleaseOverlayTasksAllocatorsAndSharedState(void*);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/ov017 @ 0x021A18C8; symbol: ReleasePendingOverlayAndAllocatorState; size: 0x5C.
// Cleans and clears pending handle +0x1C, pops overlay/global stacks, then destroys and frees the signed allocator at +8 when present.
extern "C" void Field_ReleaseSharedSubscreenResources(unsigned char* self) {
    if (*(void**)(self + 0x1c)) {
        Graphics_ReleaseOverlayTasksAllocatorsAndSharedState(*(void**)(self + 0x1c));
        *(unsigned int*)(self + 0x1c) = 0;
        OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
    }
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv(self + 8);
    if (!allocator) return;
    _ZN13SafeAllocator7DestroyEv(self + 8);
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
}
