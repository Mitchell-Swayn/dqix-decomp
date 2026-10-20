#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0221D06C; symbol: func_ov031_0221d06c; size: 0xC.
extern "C" unsigned int Aoss_GetLastError(void) {
    return *(unsigned int *)((unsigned char *)&AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage + 0x10);
}
