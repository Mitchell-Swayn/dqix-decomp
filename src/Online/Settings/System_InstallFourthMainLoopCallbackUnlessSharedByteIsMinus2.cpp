#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void System_SleepAndRunContextSteps(void);
extern "C" void WfcUtility_SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0223125C; symbol: func_ov031_0223125c; size: 0x28.
extern "C" void System_InstallFourthMainLoopCallbackUnlessSharedByteIsMinus2(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback((void *)System_SleepAndRunContextSteps);
    }
}
