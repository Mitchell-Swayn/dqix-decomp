#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x214e4a0; symbol: data_0214e4a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D8704; symbol: func_020d8704; size: 0x10.
extern "C" unsigned Graphics_GetSwapPhase(){return GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[0];}
