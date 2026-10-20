#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Graphics_PrepareMainDisplayAndSelectModeCallback(void);
// Original: arm9/ov031 @ 0x022298A8; symbol: func_ov031_022298a8; size: 0x28.
extern "C" void System_ConfigureModeAndInstallCallback(void) {
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(Graphics_PrepareMainDisplayAndSelectModeCallback);
}
