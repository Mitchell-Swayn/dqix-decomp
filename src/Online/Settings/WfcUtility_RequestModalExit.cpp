#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222758C; symbol: func_ov031_0222758c; size: 0x14.
extern "C" void WfcUtility_RequestModalExit(void) { Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[1] = 1; }
