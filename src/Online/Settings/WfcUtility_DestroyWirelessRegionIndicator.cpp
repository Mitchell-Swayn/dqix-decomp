#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void WfcUtility_RemoveTaskImmediately(unsigned, void *);
extern "C" void WfcUtility_ReleaseOamSprite(void *);
// Original data: arm9/ov031 @ 0x02250BF8; symbol: data_ov031_02250bf8.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x02223B1C; symbol: func_ov031_02223b1c; size: 0x44.
// Releases the task, sprite and context when the region indicator exists.
extern "C" void WfcUtility_DestroyWirelessRegionIndicator(void) {
    if (WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage == 0) return;
    WfcUtility_RemoveTaskImmediately(0, *(void **)((char *)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage + 0x4));
    WfcUtility_ReleaseOamSprite(*(void **)((char *)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage + 0));
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
