#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void Overlay_InitializeModeThreeWhenContextClear(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0223130C; symbol: func_ov031_0223130c; size: 0x20.
extern "C" void System_ConfigureSharedByteAndAlternateCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback((void *)Overlay_InitializeModeThreeWhenContextClear);
}
