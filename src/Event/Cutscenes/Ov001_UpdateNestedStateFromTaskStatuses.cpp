#include <globaldefs.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*, unsigned);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original data: arm9/ov001 @ 0x21658e0; symbol: data_ov001_021658e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 100 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215EDB8; symbol: func_ov001_0215edb8; size: 0x74.
extern "C" ARM int Ov001_UpdateNestedStateFromTaskStatuses(void* object) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    for (int i = 0; i < *(int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0x88); ++i) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, BackgroundLoaderRemoveAllQueuedTasks_UnknownRoleZeroInitializedStorage[i]) == 0) {
            Script_WriteIntegerReferenceOutput(object, 1);
            return 1;
        }
    }
    Script_WriteIntegerReferenceOutput(object, 0);
    return 1;
}
