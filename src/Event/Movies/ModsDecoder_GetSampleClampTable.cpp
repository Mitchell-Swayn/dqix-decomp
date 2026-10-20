#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov016 @ 0x219d1c0; symbol: data_ov016_0219d1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern unsigned GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov016 @ 0x219ca60; symbol: data_ov016_0219ca60.
// Movie decoder sample clamp, input biased by 64; output saturates to 0..255.
// Initial values: hex 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 384 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern unsigned char ModsDecoderGetSampleClampTable_MovieDecoderSampleClampInputBiasedBy64[];
void MIi_CpuCopyFast(const void*, void*, unsigned);
}
// Original: arm9/ov016 @ 0x0218FE30; symbol: func_ov016_0218fe30; size: 0x70.
extern "C" void *ModsDecoder_GetSampleClampTable() {
    if (!GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[8]) {
        if (GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[3] >= 0x180) {
            GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[8] = GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4];
            MIi_CpuCopyFast(ModsDecoderGetSampleClampTable_MovieDecoderSampleClampInputBiasedBy64, (void *)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4], 0x180);
            GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4] += 0x180;
            GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[3] -= 0x180;
        } else return ModsDecoderGetSampleClampTable_MovieDecoderSampleClampInputBiasedBy64;
    }
    return (void *)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[8];
}
