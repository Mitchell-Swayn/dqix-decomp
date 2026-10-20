#include <globaldefs.h>
ARM
extern "C" void Network_QueueSavedPartyMemberMode(int);
// Original data: arm9/ov017 @ 0x21d8478; symbol: data_ov017_021d8478.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void * volatile FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage;
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int Main_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/ov017 @ 0x021C1394; symbol: func_ov017_021c1394; size: 0x70.
extern "C" void FieldScreen_ReleaseOverlayThreeSession(void *state) {
    if (*((unsigned char *)state + 0x1e) != 0) Network_QueueSavedPartyMemberMode(0);
    if (FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage != 0) {
        FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage = 0;
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
        OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
    }
    void *allocator = (char *)state + 8;
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    _ZN13SafeAllocator7DestroyEv(allocator);
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
}
