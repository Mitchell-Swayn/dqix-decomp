#include <globaldefs.h>
ARM
extern "C" void WfcUtility_ReturnFromLeadingExitHook(void);
extern "C" void WfcUtility_ReturnFromTrailingExitHook(void);
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_BeginDualDisplayExitBrightnessTransition(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x02231058; symbol: func_ov031_02231058; size: 0x28.
extern "C" void RegisterCallbackWhenSharedObjectAbsent(void) {
    WfcUtility_ReturnFromLeadingExitHook();
    WfcUtility_ReturnFromTrailingExitHook();
    if (!WfcUtility_IsDialogActive())
        WfcUtility_SetMainLoopCallback(WfcUtility_BeginDualDisplayExitBrightnessTransition);
}
