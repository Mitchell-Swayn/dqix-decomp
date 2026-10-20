#include <globaldefs.h>
ARM

extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InitializeActionWhenBothContextsClear(void);

// Original: arm9/ov031 @ 0x02230FB4; symbol: func_ov031_02230fb4; size: 0x54.
extern "C" void System_ConfigureDisplayPlanesMask14(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x14, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x14);
    WfcUtility_SetMainLoopCallback(System_InitializeActionWhenBothContextsClear);
}
