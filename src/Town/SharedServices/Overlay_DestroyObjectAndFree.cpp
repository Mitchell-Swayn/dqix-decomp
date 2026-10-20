#include <globaldefs.h>
ARM
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
// Original: arm9/ov003 @ 0x0217E36C; symbol: func_ov003_0217e36c; size: 0x4C.
extern "C" void Overlay_DestroyObjectAndFree(void* object) {
    if (*(unsigned*)((char*)object + 0x20) != 0) {
        OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
        *(unsigned*)((char*)object + 0x20) = 0;
    }
    void* allocatorObject = (char*)object + 0xc;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocatorObject);
    _ZN13SafeAllocator7DestroyEv(allocatorObject);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
}
