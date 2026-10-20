#include <globaldefs.h>
ARM
extern "C" void System_ClearSharedPairUnlessContextStateNine(void);
// Original data: arm9/ov031 @ 0x224e598; symbol: data_ov031_0224e598.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int YssdClientSetError_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02211820; symbol: func_ov031_02211820; size: 0x28.
extern "C" void System_ResetGlobalPairUnlessStateNine(void) { System_ClearSharedPairUnlessContextStateNine(); if (YssdClientSetError_UnknownRoleZeroInitializedStorage[0] != 9) { YssdClientSetError_UnknownRoleZeroInitializedStorage[0] = 0; YssdClientSetError_UnknownRoleZeroInitializedStorage[1] = 0; } }
