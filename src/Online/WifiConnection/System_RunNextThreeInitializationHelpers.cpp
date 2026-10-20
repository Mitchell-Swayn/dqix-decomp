#include <globaldefs.h>
ARM
extern "C" void Graphics_HandleSevenRectangleSelectionAndControlInput(void);
extern "C" void WfcUtility_RunProfileSelectionNoOp(void);
extern "C" void WfcUtility_DispatchConnectionProfileSelection(void);
// Original: arm9/ov031 @ 0x02232844; symbol: func_ov031_02232844; size: 0x14.
extern "C" void System_RunNextThreeInitializationHelpers(void) {
    Graphics_HandleSevenRectangleSelectionAndControlInput();
    WfcUtility_RunProfileSelectionNoOp();
    WfcUtility_DispatchConnectionProfileSelection();
}
