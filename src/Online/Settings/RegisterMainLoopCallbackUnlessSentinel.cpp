#include <globaldefs.h>
ARM
extern "C" unsigned int WfcKeyboard_GetInputCode(void);
extern "C" void System_ProcessQueuedInput(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222CEA0; symbol: func_ov031_0222cea0; size: 0x20.
extern "C" void RegisterMainLoopCallbackUnlessSentinel(void) {
    if (WfcKeyboard_GetInputCode() != 0xff)
        WfcUtility_SetMainLoopCallback(System_ProcessQueuedInput);
}
