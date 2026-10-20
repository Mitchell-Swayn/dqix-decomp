#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original: arm9/ov017 @ 0x021BAC8C; symbol: func_ov017_021bac8c; size: 0x4C.
extern "C" void Overlay_DestroyAllocatorAndFreeSignedAllocation(void* self) {
    if (*(unsigned*)((char*)self + 0x20) != 0) {
        OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
        *(unsigned*)((char*)self + 0x20) = 0;
    }
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)self + 0xc);
    _ZN13SafeAllocator7DestroyEv((char*)self + 0xc);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
}
