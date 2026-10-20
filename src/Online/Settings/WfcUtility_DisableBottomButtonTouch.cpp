#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02222E98; symbol: func_ov031_02222e98; size: 0x18.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void WfcUtility_DisableBottomButtonTouch() {WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[0x18]=1;}
