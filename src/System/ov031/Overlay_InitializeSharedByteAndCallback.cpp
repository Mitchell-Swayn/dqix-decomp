#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void Ov031_ConfigureThirdDisplayContext(void);
// Original: arm9/ov031 @ 0x02229B5C; symbol: func_ov031_02229b5c; size: 0x20.
extern "C" void Overlay_InitializeSharedByteAndCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(Ov031_ConfigureThirdDisplayContext);
}
