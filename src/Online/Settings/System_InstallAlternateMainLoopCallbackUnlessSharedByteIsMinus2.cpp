#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_UpdateMultiReturnNotice(void);
extern "C" void WfcUtility_SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x02229CF4; symbol: func_ov031_02229cf4; size: 0x28.
extern "C" void System_InstallAlternateMainLoopCallbackUnlessSharedByteIsMinus2(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback((void *)WfcUtility_UpdateMultiReturnNotice);
    }
}
