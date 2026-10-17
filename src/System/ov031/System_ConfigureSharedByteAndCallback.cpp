#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void System_ConfigureDisplayModeFromGlobalState(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x022287D4; symbol: func_ov031_022287d4; size: 0x20.
extern "C" void System_ConfigureSharedByteAndCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback((void *)System_ConfigureDisplayModeFromGlobalState);
}
