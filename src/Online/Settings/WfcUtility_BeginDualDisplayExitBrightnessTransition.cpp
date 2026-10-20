#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_InitializeMainCallbackWhenBothContextsClear(void);
// Original: arm9/ov031 @ 0x02231088; symbol: func_ov031_02231088; size: 0x3C.
extern "C" void WfcUtility_BeginDualDisplayExitBrightnessTransition(void) {
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x14, 8);
    WfcUtility_SetMainLoopCallback(Overlay_InitializeMainCallbackWhenBothContextsClear);
}
