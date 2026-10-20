extern "C"
{
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
    extern unsigned short *WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage[];
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0223D394; symbol: func_ov031_0223d394; size: 0x40.
extern "C" bool WfcUtility_AreButtonsPressedOrRepeating(unsigned mask)
{
    if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15)return false;
    return mask==(mask&WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage[1][0x1a]);
}
