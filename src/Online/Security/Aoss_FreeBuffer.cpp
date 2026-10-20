#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f4cc; symbol: data_ov031_0224f4cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void (*AossFreeBuffer_UnknownRoleZeroInitializedStorage)(int);

// Original: arm9/ov031 @ 0x0221C4AC; symbol: func_ov031_0221c4ac; size: 0x10.
extern "C" void Aoss_FreeBuffer(int argument) {
    AossFreeBuffer_UnknownRoleZeroInitializedStorage(argument);
}
