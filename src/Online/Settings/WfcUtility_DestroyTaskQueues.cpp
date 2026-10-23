#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void Memory_FreeSharedAllocationFromFirstArgument(void *);
extern "C" void Memory_FreeSharedAllocation(void *);
// Original data: arm9/ov031 @ 0x02290D9C; symbol: data_ov031_02290d9c.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x0223E120; symbol: func_ov031_0223e120; size: 0x48.
// Releases both task queues and their backing allocations.
extern "C" void WfcUtility_DestroyTaskQueues(void) {
    int i = 0;
    do {
        Memory_FreeSharedAllocationFromFirstArgument(*(void **)((char *)WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage + i * 0x40 + 8));
        Memory_FreeSharedAllocation(*(void **)((char *)WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage + i * 0x40));
    } while (++i < 2);
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
