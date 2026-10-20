#include <globaldefs.h>
ARM

extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_ResetSelectorsAndInitializeContext(void);

// Original: arm9/ov031 @ 0x02227CE4; symbol: func_ov031_02227ce4; size: 0x3C.
extern "C" void System_ConfigureDisplayPlanesAndCallback(void) {
    WfcUtility_StartScreenBrightnessTransition(3, 1, 0x3F, 0x14);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x3F, 0x14);
    WfcUtility_SetMainLoopCallback(System_ResetSelectorsAndInitializeContext);
}
