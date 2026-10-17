#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int value);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void Overlay_StartTransitionSequence(void);
// Original: arm9/ov031 @ 0x0222E8F0; symbol: func_ov031_0222e8f0; size: 0x20.
extern "C" void System_SetSharedContextAndInstallSecondCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(Overlay_StartTransitionSequence);
}
