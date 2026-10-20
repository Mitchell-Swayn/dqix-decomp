#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_ConfigureSharedByteAndCallback(void);
extern "C" void WfcUtility_HandleMultiScreenOperationResult(void);
extern "C" void WfcUtility_CreateSlidingDialog(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
// Original: arm9/ov031 @ 0x0222876C; symbol: func_ov031_0222876c; size: 0x68.
extern "C" void WfcUtility_DispatchMultiScreenChoice(void) {
    int state = WfcUtility_GetBottomButtonSelection();
    if (state == 0) goto zero_state;
    if (state == 1) goto one_state;
    return;
zero_state:
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback(System_ConfigureSharedByteAndCallback);
    return;
one_state:
    WfcUtility_PlaySequenceArchiveEntry(6);
    WfcUtility_CreateSlidingDialog(0x18, 0, 1, -1, 0);
    WfcUtility_DisableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(WfcUtility_HandleMultiScreenOperationResult);
}
