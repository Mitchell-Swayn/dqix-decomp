#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f4c0; symbol: data_ov031_0224f4c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int AossAllocateBuffer_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221E458; symbol: func_ov031_0221e458; size: 0x18.
extern "C" int WirelessSetup_AllocatePositiveSize(void* unused, int count) { return count > 0 ? ((int (*)(int))AossAllocateBuffer_UnknownRoleZeroInitializedStorage[0])(count) : 0; }
