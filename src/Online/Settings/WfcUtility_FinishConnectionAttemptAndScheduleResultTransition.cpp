#include <globaldefs.h>
ARM
#pragma force_active on
struct ConnectionAttemptState { unsigned char result; unsigned char padding[3]; int active; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290cd0; symbol: data_ov031_02290cd0; zero-initialized connection state.
extern ConnectionAttemptState InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage;
int Network_ProcessAccessPointConnection();
void WfcUtility_DestroyWirelessRegionIndicator();
void WfcUtility_StopSequenceImmediately();
void WfcUtility_PlaySequenceArchiveEntry(int);
int Network_GetAccessPointConnectionStatus();
void WfcUtility_SetConnectionErrorCode(int);
void WfcUtility_SetMainLoopCallback(void (*)());
void Overlay_ConfigureAndInstallCallback();
void WfcUtility_RequestTaskRemoval(unsigned,void*);
}
// Original: arm9/ov031 @ 0x02233d84; symbol: func_ov031_02233d84; size: 0xa4.
// Polls an active connection, records its result, and schedules the result-screen transition.
// Indicator and sound teardown do not change the connection-mode word at offset 4.
extern "C" void WfcUtility_FinishConnectionAttemptAndScheduleResultTransition(void* task)
{
    int result;
    if (InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage.active) {
        result=Network_ProcessAccessPointConnection();
        if (!result) return;
    }
    WfcUtility_DestroyWirelessRegionIndicator();
    WfcUtility_StopSequenceImmediately();
    if (InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage.active && result>0) {
        InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage.result=1;
        WfcUtility_PlaySequenceArchiveEntry(0x11);
    } else {
        int error=InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage.active ? Network_GetAccessPointConnectionStatus() : -50199;
        if (error>=-10) error=-50199;
        WfcUtility_SetConnectionErrorCode(error);
        WfcUtility_PlaySequenceArchiveEntry(0x12);
    }
    WfcUtility_SetMainLoopCallback(Overlay_ConfigureAndInstallCallback);
    WfcUtility_RequestTaskRemoval(0,task);
}

#pragma force_active reset
