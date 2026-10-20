#include <globaldefs.h>
extern "C" int Script_StartArchiveEntry(void *, int);
extern "C" void Event_AdvanceObjectAndMotionSessions();
// Original data: arm9/ov001 @ 0x2165828; symbol: data_ov001_02165828.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 84 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x216580c; symbol: data_ov001_0216580c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSelectScriptEntryAndRefreshSessions_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x02153948; symbol: func_ov001_02153948; size: 0x4C.
extern "C" int Event_SelectScriptEntryAndRefreshSessions(void *item) {
    int result = Script_StartArchiveEntry(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage, (int)item);
    if (result == -1) return 0;
    if (result != 0) {
        *(void **)EventSelectScriptEntryAndRefreshSessions_UnknownRoleZeroInitializedStorage = item;
        Event_AdvanceObjectAndMotionSessions();
    }
    return result;
}
