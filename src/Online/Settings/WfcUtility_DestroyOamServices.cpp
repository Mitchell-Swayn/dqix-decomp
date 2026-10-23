#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void WfcUtility_RemoveTaskImmediately(unsigned, void *);
// Original data: arm9/ov031 @ 0x02290D60; symbol: data_ov031_02290d60.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x0223DA0C; symbol: func_ov031_0223da0c; size: 0x2C.
// Removes the OAM service task and frees its context.
extern "C" void WfcUtility_DestroyOamServices(void) {
    WfcUtility_RemoveTaskImmediately(1, *(void **)((char *)WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage + 0x808));
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
