#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader8GetFlag0Ev(void *);
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" int Filesystem_AreBackgroundTasksReady(void *);
// Original: arm9/ov025 @ 0x021E413C; symbol: Filesystem_AreBackgroundTasksReadyWhenLoaderFlag0Set; size: 0x2C.
// Returns zero when BackgroundLoader Flag0 is clear; otherwise checks readiness using the state at data_ov025_021ef988+0xC.
extern "C" int Filesystem_AreBackgroundTasksReadyWhenLoaderFlag0Set(void) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    if (!_ZN16BackgroundLoader8GetFlag0Ev(loader))
        return 0;
    return Filesystem_AreBackgroundTasksReady(*(void **)((char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc));
}
