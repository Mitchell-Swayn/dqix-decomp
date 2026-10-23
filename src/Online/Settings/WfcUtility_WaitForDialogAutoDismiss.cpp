#include <globaldefs.h>
ARM
#pragma force_active on

struct DialogContext { char prefix[0x14]; void *task; unsigned short timer; unsigned char selection; signed char marker; };
// Original data: arm9/ov031 @ 0x02290D10; symbol: data_ov031_02290d10.
// Zero-initialized dialog pointer; task, timer and marker offsets follow the instructions.
extern "C" DialogContext *WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_RequestTaskRemoval(unsigned,void*);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" void IncrementGlobalCounterAndNotifyAtEight(void*,void*);
// Original: arm9/ov031 @ 0x0223815C; symbol: func_ov031_0223815c; size: 0x6C.
// Counts 120 frames, removes the current task and installs the dialog dismissal callback.
extern "C" void WfcUtility_WaitForDialogAutoDismiss(void* task,void*)
{
    WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->marker = -1;
    ++WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->timer;
    if (WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->timer < 120) return;
    WfcUtility_RequestTaskRemoval(0, task);
    WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->task = WfcUtility_CreateTaskWithBorrowedContext(1, IncrementGlobalCounterAndNotifyAtEight, 0, 120);
}
#pragma force_active reset
