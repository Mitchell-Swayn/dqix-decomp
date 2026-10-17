#include <globaldefs.h>
THUMB
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" void* data_ov031_0224f704;
extern "C" unsigned int data_ov031_0224f670[];
// Original: arm9/ov031 @ 0x0221F9D0; symbol: func_ov031_0221f9d0; size: 0x28.
extern "C" void System_CallSharedObjectCallbackUnderMutex(void* unused, unsigned int value, int count) { if (value && count > 0) { _Z9LockMutexP5Mutex(&data_ov031_0224f704); ((void (*)(unsigned int))data_ov031_0224f670[3])(value); _Z11UnlockMutexP5Mutex(&data_ov031_0224f704); } }
