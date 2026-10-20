#include <globaldefs.h>

// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short* MultibootGetParentState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223911C; symbol: func_ov031_0223911c; size: 0x14.
extern "C" ARM unsigned short Multiboot_GetParentState(void) {
    return *MultibootGetParentState_UnknownRoleZeroInitializedStorage;
}
