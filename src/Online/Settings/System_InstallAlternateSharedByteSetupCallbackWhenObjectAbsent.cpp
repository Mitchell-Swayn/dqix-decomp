#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureSharedByteAndAlternateCallback(void);
// Original: arm9/ov031 @ 0x02231518; symbol: func_ov031_02231518; size: 0x20.
extern "C" void System_InstallAlternateSharedByteSetupCallbackWhenObjectAbsent(void) {
    if (!WfcUtility_IsDialogActive()) WfcUtility_SetMainLoopCallback(System_ConfigureSharedByteAndAlternateCallback);
}
