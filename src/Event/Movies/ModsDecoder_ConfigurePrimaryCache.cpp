#include <globaldefs.h>
ARM
// Original data: arm9/ov016 @ 0x219d1c0; symbol: data_ov016_0219d1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov016 @ 0x0218FC8C; symbol: func_ov016_0218fc8c; size: 0x20.
extern "C" void ModsDecoder_ConfigurePrimaryCache(unsigned first, unsigned second) {
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[6] = first;
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[5] = second & ~3u;
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[2] = 0;
}
