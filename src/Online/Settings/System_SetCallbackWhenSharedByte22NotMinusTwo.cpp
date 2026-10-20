#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateMultiScreenCompletionPrompt(void);

// Original: arm9/ov031 @ 0x02228A84; symbol: func_ov031_02228a84; size: 0x28.
extern "C" void System_SetCallbackWhenSharedByte22NotMinusTwo(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2)
        return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(WfcUtility_UpdateMultiScreenCompletionPrompt);
}
