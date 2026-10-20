#include <globaldefs.h>
// Original data: arm9/ov027 @ 0x21e3420; symbol: data_ov027_021e3420.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBiSetTask_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021dd3b0; symbol: func_ov027_021dd3b0; size: 0x1c.
extern "C" int MBi_IsTaskAvailable() { return *(unsigned*)MBiSetTask_UnknownRoleZeroInitializedStorage != 0; }
