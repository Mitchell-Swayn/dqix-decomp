#include <globaldefs.h>
ARM
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_InitializePairedResourcesAndRegisterCallback(void);
// Original: arm9/ov031 @ 0x02228B0C; symbol: System_SetSharedByte18AndRegisterPairedResourceCallback; size: 0x20.
// Sets shared byte 0x18, schedules mode 8, and installs the paired-resource callback.
extern "C" void System_SetSharedByte18AndRegisterPairedResourceCallback(void) {
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(Overlay_InitializePairedResourcesAndRegisterCallback);
}
