#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void ConfigureThirdContextAfterTransition(void);
// Original: arm9/ov031 @ 0x0222A598; symbol: System_SetSharedByte18AndInstallMode8Callback; size: 0x20.
// Sets shared byte 0x18, passes selector 8 to the setup routine, and installs callback 0x0222A5B8.
extern "C" void WfcUtility_QueueResponsePromptExit(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(ConfigureThirdContextAfterTransition);
}
