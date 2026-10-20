#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223607C; symbol: func_ov031_0223607c; size: 0x18.
extern "C" unsigned int WfcUtility_GetConnectionProfileType(unsigned int index) { volatile unsigned char* p = NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage + (index << 8); return p[0xe7]; }
