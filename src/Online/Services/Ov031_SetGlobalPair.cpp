#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5ac; symbol: data_ov031_0224e5ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int Ov031SetGlobalPair_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02211B40; symbol: func_ov031_02211b40; size: 0x14.
extern "C" void Ov031_SetGlobalPair(unsigned int first, unsigned int second) {
    Ov031SetGlobalPair_UnknownRoleZeroInitializedStorage[1] = first;
    Ov031SetGlobalPair_UnknownRoleZeroInitializedStorage[0] = second;
}
