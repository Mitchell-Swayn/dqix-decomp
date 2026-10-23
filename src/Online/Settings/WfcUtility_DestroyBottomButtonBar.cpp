#include <globaldefs.h>
ARM
#pragma force_active on

struct BottomButtonBar { void *buttons[2]; void *background; void *reserved; void *task; };
// Original data: arm9/ov031 @ 0x02250BA8; symbol: data_ov031_02250ba8.
// Zero-initialized context pointer; only the observed sprite and task fields are projected.
extern "C" BottomButtonBar *WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
namespace ContextStorageAddress { extern "C" BottomButtonBar *WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage; }
extern "C" void WfcUtility_RequestTaskRemoval(unsigned, void *);
extern "C" void Network_UnlinkNodeAndReleaseRecords(void *);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x022231F0; symbol: func_ov031_022231f0; size: 0x78.
// Removes both tasks, releases the two optional buttons and background sprite, then clears the context.
extern "C" void WfcUtility_DestroyBottomButtonBar(void *task)
{
    WfcUtility_RequestTaskRemoval(0, task);
    if (WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->task)
        WfcUtility_RequestTaskRemoval(0, WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->task);
    int i = 0;
    do {
        if (WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->buttons[i])
            Network_UnlinkNodeAndReleaseRecords(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->buttons[i]);
        ++i;
    } while (i < 2);
    Network_UnlinkNodeAndReleaseRecords(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->background);
    WfcUtility_FreeAllocationAndClearPointer((void **)&ContextStorageAddress::WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset
