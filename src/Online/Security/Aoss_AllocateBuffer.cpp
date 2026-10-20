#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f4c0; symbol: data_ov031_0224f4c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void (*AossAllocateBuffer_UnknownRoleZeroInitializedStorage)(int);
// Original: arm9/ov031 @ 0x0221C49C; symbol: func_ov031_0221c49c; size: 0x10.
extern "C" void Aoss_AllocateBuffer(int a0) {
    AossAllocateBuffer_UnknownRoleZeroInitializedStorage(a0);
}
