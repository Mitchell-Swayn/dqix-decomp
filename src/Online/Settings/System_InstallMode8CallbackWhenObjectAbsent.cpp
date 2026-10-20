#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByteAndInstallMode8Callback(void);
// Original: arm9/ov031 @ 0x02232004; symbol: func_ov031_02232004; size: 0x20.
extern "C" void System_InstallMode8CallbackWhenObjectAbsent(void) {
    if (!WfcUtility_IsDialogActive()) WfcUtility_SetMainLoopCallback(System_SetSharedByteAndInstallMode8Callback);
}
