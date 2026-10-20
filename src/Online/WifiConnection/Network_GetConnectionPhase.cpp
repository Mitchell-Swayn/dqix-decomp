// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[4];
// Original: arm9/ov031 @ 0x022134B0; symbol: func_ov031_022134b0; size: 0x1C.
extern "C" unsigned Network_GetConnectionPhase() {
    char* p=NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3];
    return p ? (unsigned char)p[9] : 0;
}
