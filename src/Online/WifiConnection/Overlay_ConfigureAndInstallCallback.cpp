#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallAlternateCallbackIfScreenZeroContextByteIsClear(void);
// Original: arm9/ov031 @ 0x02233C94; symbol: func_ov031_02233c94; size: 0x28.
extern "C" void Overlay_ConfigureAndInstallCallback(void) {
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(System_InstallAlternateCallbackIfScreenZeroContextByteIsClear);
}
