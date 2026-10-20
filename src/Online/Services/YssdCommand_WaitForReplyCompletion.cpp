void SleepCurrentContext(unsigned);
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220FEA0; symbol: func_ov031_0220fea0; size: 0x38.
extern "C" void YssdCommand_WaitForReplyCompletion() {
    while(StoreReadySharedValue_UnknownRoleZeroInitializedStorage && !StoreReadySharedValue_UnknownRoleZeroInitializedStorage[11]) SleepCurrentContext(100);
}
