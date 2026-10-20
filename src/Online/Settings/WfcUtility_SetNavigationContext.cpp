// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022274D0; symbol: func_ov031_022274d0; size: 0x14.
extern "C" void WfcUtility_SetNavigationContext(unsigned a,unsigned b) {
    Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[4]=a;
    Ov031GetStatusCode_UnknownRoleZeroInitializedStorage[5]=b;
}
