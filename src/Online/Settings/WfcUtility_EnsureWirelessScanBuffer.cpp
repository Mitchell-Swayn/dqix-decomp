#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage;
extern "C" void* Memory_AllocateZeroedBlock(void*, unsigned);
// Original: arm9/ov031 @ 0x02235780; symbol: func_ov031_02235780; size: 0x34.
extern "C" void WfcUtility_EnsureWirelessScanBuffer(void) {
    if (WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage != 0) return;
    WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage = Memory_AllocateZeroedBlock((void*)0x1e60, 0x20);
}
