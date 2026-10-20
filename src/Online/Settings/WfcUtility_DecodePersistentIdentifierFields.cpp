extern "C"
{
    void MI_CpuCopy8(const void*,void*,unsigned);
// Original data: arm9/ov031 @ 0x224e6ac; symbol: data_ov031_0224e6ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e6b1; symbol: data_ov031_0224e6b1.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e6b6; symbol: data_ov031_0224e6b6.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e6b8; symbol: data_ov031_0224e6b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
    extern unsigned char Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[],WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage[],WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage_Variant2[],WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage_Variant3[];
    struct Fields
    {
        unsigned long long a,b;
        unsigned short c,d;
    };
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov031 @ 0x0221AE00; symbol: func_ov031_0221ae00; size: 0xD8.
extern "C" void WfcUtility_DecodePersistentIdentifierFields(Fields *p)
{
    MI_CpuCopy8(Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage,&p->a,6);
    p->a &= 0x7ffffffffffULL;
    MI_CpuCopy8(WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage,&p->b,6);
    p->b >>=3;
    p->b &=0x7ffffffffffULL;
    MI_CpuCopy8(WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage_Variant2,&p->c,2);
    p->c >>=6;
    p->c &=0x3ff;
    MI_CpuCopy8(WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage_Variant3,&p->d,2);
}
