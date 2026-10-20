#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_ConfigureTransitionAndRegisterLoop(void);
// Original: arm9/ov031 @ 0x02234B2C; symbol: System_SetSharedByte18AndRegisterTransitionCallback; size: 0x20.
// Sets shared byte 0x18, schedules mode 8, and installs the transition callback.
extern "C" void System_SetSharedByte18AndRegisterTransitionCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(Overlay_ConfigureTransitionAndRegisterLoop);
}
