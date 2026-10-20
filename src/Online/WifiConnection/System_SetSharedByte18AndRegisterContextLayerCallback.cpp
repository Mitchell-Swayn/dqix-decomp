#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_StartConditionalSubscreenFadeOut(void);
// Original: arm9/ov031 @ 0x02234770; symbol: System_SetSharedByte18AndRegisterContextLayerCallback; size: 0x20.
// Sets shared byte 0x18, schedules mode 8, and installs the context-layer callback.
extern "C" void System_SetSharedByte18AndRegisterContextLayerCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_StartConditionalSubscreenFadeOut);
}
