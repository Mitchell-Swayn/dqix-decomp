#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D41D8; symbol: func_020d41d8; size: 0x10.
extern "C" unsigned int WMi_GetSystemWork() { return *(unsigned int*)(WMiCheckIdle_UnknownRoleZeroInitializedStorage+4); }
