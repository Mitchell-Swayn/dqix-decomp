#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(int value);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_02228f9c(void);
// Original: arm9/ov031 @ 0x02228F7C; symbol: func_ov031_02228f7c; size: 0x20.
extern "C" void System_SetSharedContextAndCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(func_ov031_02228f9c);
}
