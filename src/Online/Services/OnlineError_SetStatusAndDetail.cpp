struct State {
    unsigned a,b;
};
// Original data: arm9/ov031 @ 0x224e5a4; symbol: data_ov031_0224e5a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" State OnlineErrorIsSet_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02211B08; symbol: func_ov031_02211b08; size: 0x18.
extern "C" void OnlineError_SetStatusAndDetail(unsigned a,unsigned b) {
    if(OnlineErrorIsSet_UnknownRoleZeroInitializedStorage.a!=9) {
        OnlineErrorIsSet_UnknownRoleZeroInitializedStorage.a=a;
        OnlineErrorIsSet_UnknownRoleZeroInitializedStorage.b=b;
    }
}
