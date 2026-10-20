#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" int WfcUtility_IsConnectionContextAbsent(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_UpdateResponsePromptInput(void);
// Original: arm9/ov031 @ 0x0222A4BC; symbol: func_ov031_0222a4bc; size: 0x34.
extern "C" void WfcUtility_ArmResponsePromptInput(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2) return;
    if (!WfcUtility_IsConnectionContextAbsent()) return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_UpdateResponsePromptInput);
}
