#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*, unsigned*);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_WaitForSettingsHeaderScreenDisplays(void);
// Original: arm9/ov031 @ 0x02233BD4; symbol: func_ov031_02233bd4; size: 0x6C.
extern "C" void WfcUtility_BeginSettingsHeaderScreenTransition(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    unsigned value;
    WfcUtility_GetScreenOperationArguments(0, &value);
    if (value == 0) {
        WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
        WfcUtility_EnableDisplayPlanes(1, 1);
    }
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_WaitForSettingsHeaderScreenDisplays);
}
