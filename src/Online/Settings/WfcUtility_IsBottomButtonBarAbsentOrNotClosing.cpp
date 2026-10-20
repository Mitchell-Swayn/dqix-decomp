#pragma optimize_for_size on
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
// Original: arm9/ov031 @ 0x02222E54; symbol: func_ov031_02222e54; size: 0x2C.
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing()
{
    unsigned char *p=WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
    if(!p)return 1;
    if(p[0x19])return 0;
    return 1;
}
