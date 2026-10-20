#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02236474; symbol: func_ov031_02236474; size: 0x10.
extern "C" int WfcUtility_GetConnectionProfileStorage(void) {
    return NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
}
