#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureSharedByteAndCallback(void);
// Original: arm9/ov031 @ 0x02228960; symbol: func_ov031_02228960; size: 0x20.
extern "C" void System_InstallSharedByteSetupCallbackWhenObjectAbsent(void) {
    if (!WfcUtility_IsDialogActive()) WfcUtility_SetMainLoopCallback(System_ConfigureSharedByteAndCallback);
}
