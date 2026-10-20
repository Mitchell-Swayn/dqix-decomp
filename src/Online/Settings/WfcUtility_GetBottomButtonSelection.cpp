#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" signed char* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02222E0C; symbol: func_ov031_02222e0c; size: 0x14.
extern "C" int WfcUtility_GetBottomButtonSelection() {
    return WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[22];
}
