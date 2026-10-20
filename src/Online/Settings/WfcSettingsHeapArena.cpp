// Original BSS: arm9/ov031 @ 0x02250C40; symbol: data_ov031_02250c40.
// Zero-filled byte arena for the wireless settings HPXE heap (256 KiB).
// WfcUtility_RunSettingsModal passes this address to the modal loop, which
// stores it in the status block. System_InitializeModalOverlayServices passes
// that same value to Memory_InitializeHPXEAllocatorAtLocation. The initializer
// clears exactly 0x40000 bytes and calls HPXEAllocator::CreateAtLocation with
// that capacity. The next original global starts at 0x02290C40, the exact end.
// The declaration preserves the original address's 32-byte alignment.
// Four existing interior reference labels remain linker aliases; their roles
// and ambiguous cross-overlay references do not define separate heap objects.
extern "C" {
__declspec(align(32)) unsigned char WfcUtilityRunSettingsModal_UnknownRoleZeroInitializedStorage[0x40000];
}
