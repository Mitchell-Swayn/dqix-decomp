#include <globaldefs.h>
ARM
#pragma force_active on
struct SetupTaskState { unsigned char result; unsigned char padding[3]; void* task; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290c80; symbol: data_ov031_02290c80; initially zero, setup result and task.
extern SetupTaskState WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage;
void WfcUtility_QueueSetupCancelFromButtonOrSystemGate();
void WfcUtility_RunEmptySetupUpdateHook();
void WfcUtility_CancelSetupTaskAndBeginExit();
int WfcUtility_ProcessNetworkRequestAndClassifyResult();
void WfcUtility_RemoveTaskImmediately(unsigned,void*);
void WfcUtility_SetMainLoopCallback(void (*)());
void WfcUtility_UpdateSetupTimeout();
void WfcUtility_StopSequenceImmediately();
void WfcUtility_CreateSlidingDialog(int,int,int,int,int);
void WfcUtility_PlaySequenceArchiveEntry(int);
void WfcUtility_DisableBottomButtonTouch();
void Overlay_InstallCallbackWhenSharedByteZero();
}
// Original: arm9/ov031 @ 0x0222b094; symbol: func_ov031_0222b094; size: 0xd4.
// Polls setup after its input hooks, removes the completed task, and selects success or timeout handling.
extern "C" void WfcUtility_UpdateSetupTaskStatus()
{
    WfcUtility_QueueSetupCancelFromButtonOrSystemGate();
    WfcUtility_RunEmptySetupUpdateHook();
    WfcUtility_CancelSetupTaskAndBeginExit();
    switch (WfcUtility_ProcessNetworkRequestAndClassifyResult()) {
    case 0: return;
    case 1:
        if (!WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.task) return;
        WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.result=1;
        WfcUtility_RemoveTaskImmediately(1,WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.task);
        WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.task=0;
        WfcUtility_SetMainLoopCallback(WfcUtility_UpdateSetupTimeout);
        return;
    case 2:
        if (!WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.task) return;
        WfcUtility_StopSequenceImmediately();
        WfcUtility_CreateSlidingDialog(12,1,1,-1,0);
        WfcUtility_PlaySequenceArchiveEntry(9);
        WfcUtility_DisableBottomButtonTouch();
        WfcUtility_RemoveTaskImmediately(1,WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.task);
        WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.task=0;
        WfcUtility_SetMainLoopCallback(Overlay_InstallCallbackWhenSharedByteZero);
        return;
    }
}
#pragma force_active reset
