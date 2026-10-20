#include <globaldefs.h>
extern "C" {
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern signed char* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov031 @ 0x02222E20; symbol: func_ov031_02222e20; size: 0x20.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void WfcUtility_LatchBottomButtonSelection(signed char value)
{
    signed char* p=WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
    if(p[0x16]==-1) p[0x16]=value;
}
