#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_HaltAfterMultiCompletionFade(void);
// Original: arm9/ov031 @ 0x02228B2C; symbol: func_ov031_02228b2c; size: 0x4C.
extern "C" void Overlay_InitializePairedResourcesAndRegisterCallback(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    WfcUtility_StartScreenBrightnessTransition(3, 1, 0x3f, 0x40);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x3f, 0x40);
    WfcUtility_SetMainLoopCallback(WfcUtility_HaltAfterMultiCompletionFade);
}
