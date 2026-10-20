#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5dc; symbol: data_ov031_0224e5dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02216758; symbol: func_ov031_02216758; size: 0x14.
extern "C" void Ov031_SetGlobalFieldToFour(void) {
    Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage[2] = 4;
}
