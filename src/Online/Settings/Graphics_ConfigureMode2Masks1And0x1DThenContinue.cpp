#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_InstallInputStateCallbackWhenBothContextBytesAreClear(void);
// Original: arm9/ov031 @ 0x0222EE70; symbol: Graphics_ConfigureMode2Masks1And0x1DThenContinue; size: 0x54.
// Configures two mode-2 records, enables display masks 1 and 0x1D, and schedules the continuation callback.
extern "C" void Graphics_ConfigureMode2Masks1And0x1DThenContinue(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x1D, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x1D);
    WfcUtility_SetMainLoopCallback((void*)System_InstallInputStateCallbackWhenBothContextBytesAreClear);
}
