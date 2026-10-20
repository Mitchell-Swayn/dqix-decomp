#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290d34; symbol: data_ov031_02290d34.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223C054; symbol: func_ov031_0223c054; size: 0x24.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM unsigned int WfcUtility_IsScreenTransitionBusy(int screen) {
 unsigned char* p; if(screen==1) p=WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage; else p=WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage+12; return p[9];
}
