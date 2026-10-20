#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadStepThreeBackgroundAssets(void);
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive(void);
extern "C" void WfcUtility_CommitEditedConnectionProfile(void);
extern "C" void System_ConfigureDisplayPlanesMask14(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02230F00; symbol: func_ov031_02230f00; size: 0x20.
extern "C" void InitializeOverlayStateAndScheduleCallback(void) {
    Graphics_LoadStepThreeBackgroundAssets();
    System_ConvertSharedRegionByteToIndexPlusFive();
    WfcUtility_CommitEditedConnectionProfile();
    WfcUtility_SetMainLoopCallback(System_ConfigureDisplayPlanesMask14);
}
