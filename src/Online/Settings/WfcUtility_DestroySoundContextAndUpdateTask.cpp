#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void WfcUtility_RequestTaskRemoval(unsigned, void *);
// Original data: arm9/ov031 @ 0x02290D00; symbol: data_ov031_02290d00.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage;
namespace SoundContextAddress { extern "C" void *WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x0223684C; symbol: func_ov031_0223684c; size: 0x2C.
// Requests sound-update task removal and frees its context.
extern "C" void WfcUtility_DestroySoundContextAndUpdateTask(void) {
    WfcUtility_RequestTaskRemoval(0, *(void **)((char *)WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage + 0x9c));
    WfcUtility_FreeAllocationAndClearPointer(&SoundContextAddress::WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
