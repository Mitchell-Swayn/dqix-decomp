#include <globaldefs.h>
ARM
struct Nibble { unsigned value : 4; };
// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02227558; symbol: func_ov031_02227558; size: 0x18.
extern "C" unsigned WfcUtility_GetInitialMenuSelector(void) {
    return ((struct Nibble *)&Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[2])->value;
}
