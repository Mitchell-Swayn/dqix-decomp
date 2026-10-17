#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int value);
extern "C" void func_ov031_02229548(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02229528; symbol: func_ov031_02229528; size: 0x20.
extern "C" void SetSharedByteAndScheduleCallback(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(func_ov031_02229548);
}
