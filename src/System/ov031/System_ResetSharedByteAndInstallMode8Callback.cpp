#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void func_ov031_0222a058(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222A038; symbol: func_ov031_0222a038; size: 0x20.
extern "C" void System_ResetSharedByteAndInstallMode8Callback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(func_ov031_0222a058);
}
