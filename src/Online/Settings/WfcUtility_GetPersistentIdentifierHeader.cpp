#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e6ac; symbol: data_ov031_0224e6ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221B9A4; symbol: func_ov031_0221b9a4; size: 0xC.
extern "C" unsigned char *WfcUtility_GetPersistentIdentifierHeader(void) {
    return Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage;
}
