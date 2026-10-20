#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" void Object_ResetMotionStateAndChildRecords(void *);
struct GlobalReady { unsigned char pad[0xE4]; unsigned int value; };
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" GlobalReady EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x0215D134; symbol: func_ov001_0215d134; size: 0x34.
extern "C" int GameState_InitializeObjectAndSetReadyFlag(void) {
    Object_ResetMotionStateAndChildRecords(*(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24));
    if (EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage.value == 0) {
        EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage.value = 1;
    }
    return 1;
}
