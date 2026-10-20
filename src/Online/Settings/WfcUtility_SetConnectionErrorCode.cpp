#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c9c; symbol: data_ov031_02290c9c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int WfcUtilitySetConnectionErrorCode_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222EA14; symbol: func_ov031_0222ea14; size: 0x10.
extern "C" void WfcUtility_SetConnectionErrorCode(int a0) {
    WfcUtilitySetConnectionErrorCode_UnknownRoleZeroInitializedStorage = a0;
}
