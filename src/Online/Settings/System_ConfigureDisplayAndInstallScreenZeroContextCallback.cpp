#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallCallbackWhenScreenZeroIsClear();
// Original: arm9/ov031 @ 0x02228A24; symbol: System_ConfigureDisplayAndInstallScreenZeroContextCallback; size: 0x34.
// Configures display mode and plane mask 0x15, then installs the callback that checks screen 0 context byte 9.
extern "C" void System_ConfigureDisplayAndInstallScreenZeroContextCallback() {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenScreenZeroIsClear);
}
