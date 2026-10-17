#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" unsigned int data_ov031_02290fa4;
// Original: arm9/ov031 @ 0x0223FA0C; symbol: func_ov031_0223fa0c; size: 0x14.
extern "C" void System_LockSharedMutex(void) { _Z9LockMutexP5Mutex(&data_ov031_02290fa4); }
