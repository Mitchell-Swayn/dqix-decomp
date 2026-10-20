#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02236F68; symbol: func_ov031_02236f68; size: 0x20.
extern "C" unsigned WfcUtility_IsModeSpriteAnimationScheduled(void) {
    char *object = *(char **)((char *)&AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage + 4);
    return *(unsigned *)(object + 0x14) != 0;
}
