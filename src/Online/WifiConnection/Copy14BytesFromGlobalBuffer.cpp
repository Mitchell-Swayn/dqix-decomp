#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(void *, const void *, unsigned int);
// Original data: arm9/ov031 @ 0x224e6ac; symbol: data_ov031_0224e6ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221B140; symbol: func_ov031_0221b140; size: 0x18.
extern "C" void Copy14BytesFromGlobalBuffer(void *dst) { MI_CpuCopy8(dst, Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage, 0xe); }
