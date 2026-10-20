#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InitializeSecondContextDisplay(void);
// Original: arm9/ov031 @ 0x02229D7C; symbol: System_SetSharedByte18AndRegisterSecondContextDisplayCallback; size: 0x20.
// Sets shared byte 0x18, schedules mode 8, and installs the second-context display callback.
extern "C" void System_SetSharedByte18AndRegisterSecondContextDisplayCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(System_InitializeSecondContextDisplay);
}
