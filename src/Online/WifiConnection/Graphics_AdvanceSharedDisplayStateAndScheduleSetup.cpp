#include <globaldefs.h>
ARM
extern "C" void WfcUtility_FreeWirelessScanBufferWhenInactive();
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned *, unsigned *);
extern "C" void WfcUtility_LoadBlankBackgroundAndLowerLayerPriorities();
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void WfcUtility_CommitEditedConnectionProfile();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_StartSelectedMessageScreenFadeIn();
// Original: arm9/ov031 @ 0x022340C0; symbol: Graphics_AdvanceSharedDisplayStateAndScheduleSetup; size: 0x58.
// Initializes shared display state, runs the 0x31/-1 operation and state completion helpers, then schedules the next display setup callback.
extern "C" void Graphics_AdvanceSharedDisplayStateAndScheduleSetup(void) {
    WfcUtility_FreeWirelessScanBufferWhenInactive();
    unsigned value;
    WfcUtility_GetScreenOperationArguments(0, &value);
    WfcUtility_LoadBlankBackgroundAndLowerLayerPriorities();
    WfcUtility_ShowFormattedMessagePanel(0x31, 0x31 - 0x32, 0);
    if (value != 2)
        System_ConvertSharedRegionByteToIndexPlusFive();
    if (value == 1)
        WfcUtility_CommitEditedConnectionProfile();
    WfcUtility_SetMainLoopCallback(WfcUtility_StartSelectedMessageScreenFadeIn);
}
