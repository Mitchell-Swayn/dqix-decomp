#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage[];
extern "C" int Graphics_HasIndexedSlotAnimationStopped(void *, int);
// Original: arm9/ov001 @ 0x02159B04; symbol: Graphics_IsAnimationNotStoppedForObjectField70; size: 0x28.
// Uses object field +0x70 as a slot index and returns whether Graphics_HasIndexedSlotAnimationStopped returns zero.
extern "C" int CutsceneActor_WaitForAnimationStopped(void *, const void *p) {
    return Graphics_HasIndexedSlotAnimationStopped(*(void **)AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage, *(int *)((const char *)p + 0x70)) == 0;
}
