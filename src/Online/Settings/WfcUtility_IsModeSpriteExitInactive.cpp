#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x02237388; symbol: func_ov031_02237388; size: 0x2C.
extern "C" int WfcUtility_IsModeSpriteExitInactive(void) {
    unsigned char *object = *(unsigned char **)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage + 4);
    if (object == 0)
        return 1;
    return object[0x18] == 0;
}
