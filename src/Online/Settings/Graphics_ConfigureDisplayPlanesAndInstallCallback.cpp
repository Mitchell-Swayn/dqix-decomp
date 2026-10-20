#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int screen, unsigned planes);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_FinishSetupPromptFadeIn(void);
// Original: arm9/ov031 @ 0x0222AFBC; symbol: func_ov031_0222afbc; size: 0x54.
extern "C" void Graphics_ConfigureDisplayPlanesAndInstallCallback(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(WfcUtility_FinishSetupPromptFadeIn);
}
