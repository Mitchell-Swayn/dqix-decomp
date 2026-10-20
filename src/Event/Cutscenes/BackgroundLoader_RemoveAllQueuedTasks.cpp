#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);
// Original data: arm9/ov001 @ 0x21658e0; symbol: data_ov001_021658e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 100 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" int BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov001 @ 0x0215AAC8; symbol: func_ov001_0215aac8; size: 0x58.
extern "C" void BackgroundLoader_RemoveAllQueuedTasks(void) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    for (int i = 0; i < *(int *)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x88); ++i) {
        int task = BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[i];
        _ZN16BackgroundLoader10RemoveTaskEi(loader, task);
        BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[i] = -1;
    }
    *(int *)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x88) = 0;
}
