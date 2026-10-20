#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopy16(const void*, volatile void*, int);
extern "C" void WfcUtility_RequestTaskRemoval(unsigned int, void*);
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02235034; symbol: func_ov031_02235034; size: 0x2C.
extern "C" void Graphics_CopySixteenHalfwordsToEdgeColorRegisters(const void* p) { MIi_CpuCopy16((void*)WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[1], (volatile void*)WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage[2], 0x20); WfcUtility_RequestTaskRemoval(1, (void*)p); }
