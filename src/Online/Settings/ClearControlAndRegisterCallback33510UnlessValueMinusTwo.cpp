#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void InitializeOverlaySelectionState(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x022334E8; symbol: func_ov031_022334e8; size: 0x28.
extern "C" void ClearControlAndRegisterCallback33510UnlessValueMinusTwo(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(InitializeOverlaySelectionState);
    }
}
