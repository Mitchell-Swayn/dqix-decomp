#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcSettingsList_DestroyScreenAndDispatchAction();
// Original: arm9/ov031 @ 0x0222F6AC; symbol: Unclassified_ConfigureDisplayMode3Context1DAndCallback; size: 0x4C.
// When selected context byte 9 is clear, issues display configuration commands (3,1,1,8) and (3,0,0x1D,8), then installs the next callback.
extern "C" void WfcSettingsList_BeginExitBrightnessTransition() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x1d, 8);
    WfcUtility_SetMainLoopCallback(WfcSettingsList_DestroyScreenAndDispatchAction);
}
