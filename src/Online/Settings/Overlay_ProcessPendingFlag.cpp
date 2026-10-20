#include <globaldefs.h>
ARM
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(unsigned);
// Original data: arm9/ov031 @ 0x2250bac; symbol: data_ov031_02250bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02223440; symbol: func_ov031_02223440; size: 0x38.
extern "C" int Overlay_ProcessPendingFlag(void) {
    if (OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage[0] == 0) return 0;
    Graphics_ClearIndexedMainBackgroundCharacterData(1);
    OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage[0] = 0;
    return 1;
}
