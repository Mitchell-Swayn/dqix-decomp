#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int value);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_022323a0(void);
// Original: arm9/ov031 @ 0x02232380; symbol: func_ov031_02232380; size: 0x20.
extern "C" void System_SetSharedContextAndInstallThirdCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(func_ov031_022323a0);
}
