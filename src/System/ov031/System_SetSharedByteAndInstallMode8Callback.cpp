#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void Overlay_ContinueModeThreeIfStateClear(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x02231DF8; symbol: func_ov031_02231df8; size: 0x20.
extern "C" void System_SetSharedByteAndInstallMode8Callback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(Overlay_ContinueModeThreeIfStateClear);
}
