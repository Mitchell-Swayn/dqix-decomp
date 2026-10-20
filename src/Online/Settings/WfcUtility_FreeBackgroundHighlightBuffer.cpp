#include <globaldefs.h>
ARM
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void** p);
// Original data: arm9/ov031 @ 0x2250bf4; symbol: data_ov031_02250bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02223984; symbol: func_ov031_02223984; size: 0x14.
extern "C" void WfcUtility_FreeBackgroundHighlightBuffer(void) { WfcUtility_FreeAllocationAndClearPointer(&LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage); }
