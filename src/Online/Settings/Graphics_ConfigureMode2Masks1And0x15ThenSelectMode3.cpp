#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_WaitForMultiScreenFade(void);
// Original: arm9/ov031 @ 0x02228664; symbol: Graphics_ConfigureMode2Masks1And0x15ThenSelectMode3; size: 0x54.
// Configures two mode-2 records, enables display masks 1 and 0x15, and registers a continuation that selects mode 3.
extern "C" void Graphics_ConfigureMode2Masks1And0x15ThenSelectMode3(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_WaitForMultiScreenFade);
}
