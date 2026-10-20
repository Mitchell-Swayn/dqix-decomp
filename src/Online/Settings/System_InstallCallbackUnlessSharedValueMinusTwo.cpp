#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_DispatchShortTextPromptResult(void);
// Original: arm9/ov031 @ 0x0222A86C; symbol: func_ov031_0222a86c; size: 0x24.
extern "C" void System_InstallCallbackUnlessSharedValueMinusTwo(void) {
    if (WfcUtility_GetDialogSelectionResult() != -2)
        WfcUtility_SetMainLoopCallback(WfcUtility_DispatchShortTextPromptResult);
}
