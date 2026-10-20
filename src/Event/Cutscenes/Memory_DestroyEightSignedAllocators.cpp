#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern void *EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[8];
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov001 @ 0x0215AA5C; symbol: func_ov001_0215aa5c; size: 0x4C.
void Memory_DestroyEightSignedAllocators(void) {
    for (int i = 0; i < 8; i++) {
        if (EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[i] && _ZNK13SafeAllocator18GetSignedAllocatorEv(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[i])) {
            _ZN13SafeAllocator7DestroyEv(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[i]);
            EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[i] = 0;
        }
    }
}
}
