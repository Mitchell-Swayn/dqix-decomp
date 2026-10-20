#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];
extern "C" void AdvancePackedHighFieldToward152();
extern "C" int WfcUtility_CreateTaskWithBorrowedContext(int, void (*)(), int, int);
// Original: arm9/ov031 @ 0x02236E60; symbol: func_ov031_02236e60; size: 0x40.
extern "C" void WfcUtility_StartHeaderRightmostSpriteRetraction(void) {
    unsigned char *state = *(unsigned char **)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage + 4);
    state[0x18] = 1;
    int token = WfcUtility_CreateTaskWithBorrowedContext(0, AdvancePackedHighFieldToward152, 0, 0x78);
    *(int *)(*(unsigned char **)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage + 4) + 0x14) = token;
}
