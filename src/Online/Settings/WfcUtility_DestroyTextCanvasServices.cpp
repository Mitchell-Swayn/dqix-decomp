#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02290d38; symbol: data_ov031_02290d38.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
namespace ContextStorageAddress { extern "C" void *WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage; }
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void *);
extern "C" void Memory_FreeSharedAllocation(void *);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x0223C40C; symbol: func_ov031_0223c40c; size: 0x4C.
// Releases both text archives, the shared canvas allocation and its context.
extern "C" void WfcUtility_DestroyTextCanvasServices(void)
{
    int i = 0;
    do {
        WfcUtility_FreeArchiveResourceAndReturnPoolEntry(*(void **)((char *)WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x674 + i * 4));
        ++i;
    } while (i < 2);
    Memory_FreeSharedAllocation(*(void **)((char *)WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x670));
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
