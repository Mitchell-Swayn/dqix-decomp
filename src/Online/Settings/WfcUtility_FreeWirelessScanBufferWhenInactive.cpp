#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" unsigned WM_GetAllowedChannel(void);
// Original data: arm9/ov031 @ 0x02290CF8; symbol: data_ov031_02290cf8.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x022357B4; symbol: func_ov031_022357b4; size: 0x34.
// Waits for wireless inactivity before freeing the scan buffer.
extern "C" void WfcUtility_FreeWirelessScanBufferWhenInactive(void) {
    if (WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage == 0) return;
    while (WM_GetAllowedChannel() != 0x8000) {}
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
