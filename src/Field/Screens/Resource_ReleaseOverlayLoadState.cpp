#include <globaldefs.h>
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator,void* allocation);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int enabled);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int enabled);
extern "C" void Graphics_ResetOverlayBackgroundState(char* p);
// Original data: arm9/ov017 @ 0x21d83f0; symbol: data_ov017_021d83f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" char *ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021B2200; symbol: func_ov017_021b2200; size: 0x8C.
extern "C" void Resource_ReleaseOverlayLoadState(char *self) {
    if (*(int*)(self + 12) > -1) {
        void *loader = _ZN16BackgroundLoader11GetInstanceEv();
        _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(self + 12));
        *(int*)(self + 12) = -1;
    }
    if (ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1]) {
        Graphics_ResetOverlayBackgroundState(ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1]);
        ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[1] = 0;
        OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
        OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
    }
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(self + 16);
    if (allocation) {
        _ZN13SafeAllocator7DestroyEv(self + 16);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
}
