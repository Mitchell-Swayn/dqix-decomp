#include <globaldefs.h>
ARM
struct RecordDirectory { unsigned char pad[0x1c]; unsigned char * volatile records; unsigned char rest[4]; void *optional; };
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" struct RecordDirectory EventGetObjectSession_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void AdvanceSessionCommandLists(void *);
extern "C" void CutsceneCamera_AdvanceCommandListsAndApplyCamera(void);
// Original: arm9/ov001 @ 0x0215A9B4; symbol: func_ov001_0215a9b4; size: 0x60.
extern "C" int Event_AdvanceObjectAndMotionSessions(void) {
    for (int i = 0; i < 0x18; i++) AdvanceSessionCommandLists(EventGetObjectSession_UnknownRoleZeroInitializedStorage.records + i * 0x588);
    if (*(int *)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xe4) != 0 && EventGetObjectSession_UnknownRoleZeroInitializedStorage.optional != 0) CutsceneCamera_AdvanceCommandListsAndApplyCamera();
    return 1;
}
