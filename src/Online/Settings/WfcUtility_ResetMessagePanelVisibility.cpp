#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bac; symbol: data_ov031_02250bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02223358; symbol: func_ov031_02223358; size: 0x14.
extern "C" void WfcUtility_ResetMessagePanelVisibility(void) {
    OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage = 0;
}
