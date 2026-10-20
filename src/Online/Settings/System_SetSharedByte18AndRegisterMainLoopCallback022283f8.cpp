#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_FadeOutMainMenuForSelection(void);
// Original: arm9/ov031 @ 0x022283D8; symbol: System_SetSharedByte18AndRegisterMainLoopCallback022283f8; size: 0x20.
// Sets shared byte 0x18, schedules mode 8, and installs the callback at 0x022283F8.
extern "C" void System_SetSharedByte18AndRegisterMainLoopCallback022283f8(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_FadeOutMainMenuForSelection);
}
