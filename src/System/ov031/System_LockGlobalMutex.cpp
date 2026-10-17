#include <globaldefs.h>
ARM
#include <System/Mutex.h>
extern "C" Mutex data_ov031_022918a4;

// Original: arm9/ov031 @ 0x02240310; symbol: func_ov031_02240310; size: 0x14.
extern "C" void System_LockGlobalMutex(void) {
    LockMutex(&data_ov031_022918a4);
}
