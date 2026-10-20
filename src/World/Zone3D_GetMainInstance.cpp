#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20fb3f0; symbol: data_020fb3f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 10276 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Zone3DGetMainInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02012FE4; symbol: func_02012fe4; size: 0xC.
extern "C" void* Zone3D_GetMainInstance() { return Zone3DGetMainInstance_UnknownRoleZeroInitializedStorage; }
