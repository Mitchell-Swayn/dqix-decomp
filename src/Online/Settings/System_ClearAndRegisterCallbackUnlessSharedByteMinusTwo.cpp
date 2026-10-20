#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateConnectionErrorInput(void);
// Original: arm9/ov031 @ 0x0222E868; symbol: func_ov031_0222e868; size: 0x28.
extern "C" void System_ClearAndRegisterCallbackUnlessSharedByteMinusTwo(void) { if (WfcUtility_GetBottomButtonSelection() != -2) { WfcUtility_EnableBottomButtonTouch(); WfcUtility_SetMainLoopCallback(WfcUtility_UpdateConnectionErrorInput); } }
