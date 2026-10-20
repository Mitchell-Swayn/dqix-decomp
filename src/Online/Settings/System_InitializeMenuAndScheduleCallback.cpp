#include <globaldefs.h>
extern "C" void Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(int);
extern "C" void WfcUtility_CreateWirelessRegionIndicator(int);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Ov031_SetDisplayPlaneAndCallback();
// Original: arm9/ov031 @ 0x02229774; symbol: func_ov031_02229774; size: 0x38.
extern "C" void System_InitializeMenuAndScheduleCallback() {
    Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x1e);
    WfcUtility_CreateAnimatedStatusSprite(0);
    WfcUtility_CreateWirelessRegionIndicator(1);
    WfcUtility_PlaySequenceArchiveEntry(0xb);
    WfcUtility_SetMainLoopCallback(Ov031_SetDisplayPlaneAndCallback);
}
