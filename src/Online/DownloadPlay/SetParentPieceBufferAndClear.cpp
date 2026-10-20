#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e3424; symbol: data_ov027_021e3424.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char IsGetAllRequestData_UnknownRoleZeroInitializedStorage[];
extern "C" void VectorizedMemset(void *destination, int value, unsigned int size);
// Original: arm9/ov027 @ 0x021DD5D4; symbol: func_ov027_021dd5d4; size: 0x20.
extern "C" void SetParentPieceBufferAndClear(void *buffer) {
    *(void **)(IsGetAllRequestData_UnknownRoleZeroInitializedStorage + 4) = buffer;
    VectorizedMemset(buffer, 0, 0x21c);
}
