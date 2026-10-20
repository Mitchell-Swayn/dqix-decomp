#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_UpdatePendingInputAndSelectCallbackFromSharedByte(void);
// Original: arm9/ov031 @ 0x022346A8; symbol: func_ov031_022346a8; size: 0x28.
extern "C" void System_ClearControlAndInstallCallbackUnlessSentinel(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2)
        return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(System_UpdatePendingInputAndSelectCallbackFromSharedByte);
}
