#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void Overlay_InitializeConditionalLayerAndRegisterCallback(void);
// Original: arm9/ov031 @ 0x02231724; symbol: System_SetSharedByte18AndRegisterConditionalLayerCallback; size: 0x20.
// Sets shared byte 0x18, schedules mode 8, and installs the conditional-layer callback.
extern "C" void System_SetSharedByte18AndRegisterConditionalLayerCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(Overlay_InitializeConditionalLayerAndRegisterCallback);
}
