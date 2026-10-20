#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_UpdateMainMenu(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222821C; symbol: func_ov031_0222821c; size: 0x28.
extern "C" void ClearControlAndRegisterCallbackUnlessValueMinusTwo(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(WfcUtility_UpdateMainMenu);
    }
}
