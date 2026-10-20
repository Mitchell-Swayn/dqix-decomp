extern "C"
{
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
    extern unsigned char *WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0223CAEC; symbol: func_ov031_0223caec; size: 0x24.
extern "C" void WfcUtility_MarkBackgroundTextCanvasDirty(void *p)
{
    unsigned char *q=WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
    if(p==q+0x610)q[0x67c]=1;
    else q[0x67d]=1;
}
