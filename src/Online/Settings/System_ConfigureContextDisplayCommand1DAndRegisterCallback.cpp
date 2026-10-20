#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void ConfigureDisplayGroupFromSharedByteAndInstallCallback(void);
// Original: arm9/ov031 @ 0x0222C128; symbol: System_ConfigureContextDisplayCommand1DAndRegisterCallback; size: 0x20.
// Checks context byte 9, selects the shared-state path, configures command 0x1D, and registers a callback.
extern "C" void System_ConfigureContextDisplayCommand1DAndRegisterCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(ConfigureDisplayGroupFromSharedByteAndInstallCallback);
}
