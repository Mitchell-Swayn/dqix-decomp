#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" void CutsceneCamera_ClearFollowActor(char *);
// Original: arm9/ov001 @ 0x0215E0C0; symbol: func_ov001_0215e0c0; size: 0x1C.
extern "C" int Script_ClearMotionTrackingTarget(void) {
    CutsceneCamera_ClearFollowActor(*(char **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24));
    return 1;
}
