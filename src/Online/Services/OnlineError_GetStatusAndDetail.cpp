#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5a4; symbol: data_ov031_0224e5a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022119B0; symbol: func_ov031_022119b0; size: 0x20.
extern "C" unsigned int OnlineError_GetStatusAndDetail(unsigned int *p) {
    if (p) *p = OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[1];
    return OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[0];
}
