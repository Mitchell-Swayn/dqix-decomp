#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_UpdateMultiNoticeCompletionPrompt(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02229AD4; symbol: Unclassified_ClearControlAndInstallMask1HandlerWhenSharedByteValid; size: 0x28.
// Returns when the shared signed byte is -2; otherwise clears control byte 0x18 and installs the handler sequence whose first helper tests input mask 1.
extern "C" void WfcUtility_EnableMultiNoticeCompletionInput(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2)
        return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(WfcUtility_UpdateMultiNoticeCompletionPrompt);
}
