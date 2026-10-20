#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallCallbackWhenContextsClear();
// Original: arm9/ov031 @ 0x02232780; symbol: Graphics_ConfigureMode2Masks1And0x14ThenSelectMode0; size: 0x54.
// Configures two mode-2 records, enables display masks 1 and 0x14, and registers a continuation that selects mode 0.
extern "C" void Graphics_ConfigureMode2Masks1And0x14ThenSelectMode0() {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x14, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x14);
    WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenContextsClear);
}
