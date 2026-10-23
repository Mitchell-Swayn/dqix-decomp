#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void WfcUtility_RemoveTaskImmediately(unsigned, void *);
extern "C" void Network_UnlinkNodeAndReleaseRecords(void *);
// Original data: arm9/ov031 @ 0x02290CF4; symbol: data_ov031_02290cf4.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x02235194; symbol: func_ov031_02235194; size: 0x3C.
// Removes the scrollbar task, releases its records, and frees its context.
extern "C" void WfcScrollbar_Destroy(void) {
    WfcUtility_RemoveTaskImmediately(0, *(void **)((char *)WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage + 0xc));
    Network_UnlinkNodeAndReleaseRecords(*(void **)WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
