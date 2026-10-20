int DisableIRQInterrupts();
void SetIRQInterruptState(int);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220D540; symbol: func_ov031_0220d540; size: 0x30.
extern "C" unsigned Network_GetWirelessLifecycleState() {
    int state=DisableIRQInterrupts();
    unsigned value=0;
    char* p=NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
    if(p)value=*(unsigned*)(p+0x2260);
    SetIRQInterruptState(state);
    return value;
}
