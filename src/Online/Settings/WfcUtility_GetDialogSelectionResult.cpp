// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" signed char* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02237E9C; symbol: func_ov031_02237e9c; size: 0x14.
extern "C" int WfcUtility_GetDialogSelectionResult() {
    return WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage[0x1b];
}
