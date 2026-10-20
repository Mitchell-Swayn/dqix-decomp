#include <globaldefs.h>
ARM
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x21d840c; symbol: data_ov017_021d840c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void* volatile OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021B2C88; symbol: func_ov017_021b2c88; size: 0x60.
extern "C" void Overlay_PopAndDestroyObject(void* object) {
    if (OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage != 0) {
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
        OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
        OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage = 0;
    }
    void* allocatorObject = (char*)object + 0xc;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocatorObject);
    _ZN13SafeAllocator7DestroyEv(allocatorObject);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
}
