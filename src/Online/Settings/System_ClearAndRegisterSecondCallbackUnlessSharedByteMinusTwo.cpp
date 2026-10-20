#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void HandleInputAndAdvanceTimedSelectionState(void);
// Original: arm9/ov031 @ 0x022321C4; symbol: func_ov031_022321c4; size: 0x28.
extern "C" void System_ClearAndRegisterSecondCallbackUnlessSharedByteMinusTwo(void) { if (WfcUtility_GetBottomButtonSelection() != -2) { WfcUtility_EnableBottomButtonTouch(); WfcUtility_SetMainLoopCallback(HandleInputAndAdvanceTimedSelectionState); } }
