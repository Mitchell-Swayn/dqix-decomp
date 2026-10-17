#include <globaldefs.h>
ARM
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned int value);
extern "C" void System_ConfigureSecondaryDisplayMode(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02233700; symbol: func_ov031_02233700; size: 0x20.
extern "C" void SetSharedByteAndScheduleCallback33720(void) {
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(System_ConfigureSecondaryDisplayMode);
}
