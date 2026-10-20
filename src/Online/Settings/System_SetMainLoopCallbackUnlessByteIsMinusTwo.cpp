#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunThreeInitializationHelpers(void);
// Original: arm9/ov031 @ 0x0222ABE8; symbol: func_ov031_0222abe8; size: 0x24.
extern "C" void System_SetMainLoopCallbackUnlessByteIsMinusTwo(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2)
        WfcUtility_SetMainLoopCallback(System_RunThreeInitializationHelpers);
}
