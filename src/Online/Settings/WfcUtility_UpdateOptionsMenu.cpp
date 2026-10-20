#include <globaldefs.h>
ARM
extern "C" void WfcUtility_ReadOptionsMenuInput(void);
extern "C" void WfcUtility_RunOptionsMenuInputHook(void);
extern "C" void System_SelectSharedStateAndInstallCallback(void);
// Original: arm9/ov031 @ 0x02229378; symbol: func_ov031_02229378; size: 0x14.
extern "C" void WfcUtility_UpdateOptionsMenu(void) {
    WfcUtility_ReadOptionsMenuInput();
    WfcUtility_RunOptionsMenuInputHook();
    System_SelectSharedStateAndInstallCallback();
}
