#include <globaldefs.h>
ARM
struct GlobalState {
    int field0;
    int field4;
    char padding8[4];
    int fieldC;
    int field10;
    char padding14[12];
    int field20;
};
// Original data: arm9/ov016 @ 0x219d1c0; symbol: data_ov016_0219d1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" GlobalState GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov016 @ 0x0218FCAC; symbol: func_ov016_0218fcac; size: 0x28.
extern "C" void ModsDecoder_ConfigureSecondaryCache(int a0, int a1) {
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage.field10 = a0;
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage.fieldC = a1 & ~3;
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage.field4 = 0;
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage.field0 = 0;
    GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage.field20 = 0;
}
