#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunNextThreeInitializationHelpers(void);
// Original: arm9/ov031 @ 0x02233154; symbol: func_ov031_02233154; size: 0x24.
extern "C" void System_ClearControlAndRegisterMainLoopWhenNoSharedObject(void) { if (!WfcUtility_IsDialogActive()) { WfcUtility_EnableBottomButtonTouch(); WfcUtility_SetMainLoopCallback(System_RunNextThreeInitializationHelpers); } }
