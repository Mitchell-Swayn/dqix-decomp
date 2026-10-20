#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x02235204; symbol: func_ov031_02235204; size: 0x18.
extern "C" void WfcScrollbar_EnableTouchInput(void) {
    *((unsigned char *)WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage[0] + 0x1e) = 0;
}
