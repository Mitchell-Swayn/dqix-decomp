// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned* WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/ov031 @ 0x022393E4; symbol: func_ov031_022393e4; size: 0x20.
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value) {
    unsigned* p=WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[1];
    if(p[16]-9>1)p[21]=value;
}
