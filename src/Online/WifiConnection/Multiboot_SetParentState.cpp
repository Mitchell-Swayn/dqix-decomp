#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int MultibootGetParentState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02239108; symbol: func_ov031_02239108; size: 0x14.
extern "C" void Multiboot_SetParentState(unsigned short value) {
    *(unsigned short *)(*(unsigned int *)&MultibootGetParentState_UnknownRoleZeroInitializedStorage) = value;
}
