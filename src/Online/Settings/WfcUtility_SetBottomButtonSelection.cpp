#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" signed char* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
// Stores the input byte in the shared object at offset 0x16.
// Original: arm9/ov031 @ 0x02222E40; symbol: func_ov031_02222e40; size: 0x14.
extern "C" ARM void WfcUtility_SetBottomButtonSelection(signed char value)
{
    WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[0x16] = value;
}
