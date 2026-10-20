#include <globaldefs.h>
ARM
extern "C" void Graphics_HandleTwoRectangleSelectionAndControlInput(void);
extern "C" void WfcUtility_RunMainMenuInputHook(void);
extern "C" void WfcUtility_DispatchMainMenuChoice(void);
// Original: arm9/ov031 @ 0x02228244; symbol: func_ov031_02228244; size: 0x14.
extern "C" void WfcUtility_UpdateMainMenu(void) {
    Graphics_HandleTwoRectangleSelectionAndControlInput();
    WfcUtility_RunMainMenuInputHook();
    WfcUtility_DispatchMainMenuChoice();
}
