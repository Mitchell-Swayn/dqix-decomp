extern "C"
{
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
    extern unsigned char *WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x02222E80; symbol: func_ov031_02222e80; size: 0x18.
extern "C" void WfcUtility_EnableBottomButtonTouch()
{
    WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[0x18]=0;
}
