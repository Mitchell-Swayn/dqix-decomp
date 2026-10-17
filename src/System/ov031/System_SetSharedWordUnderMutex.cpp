#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e5e8[];
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
// Original: arm9/ov031 @ 0x02217598; symbol: func_ov031_02217598; size: 0x44.
extern "C" void System_SetSharedWordUnderMutex(void* value) {
    _Z9LockMutexP5Mutex((char*)*(void**)(data_ov031_0224e5e8 + 8) + 0x13d8);
    *(void**)(*(unsigned char**)(data_ov031_0224e5e8 + 8) + 0x1004) = value;
    _Z11UnlockMutexP5Mutex((char*)*(void**)(data_ov031_0224e5e8 + 8) + 0x13d8);
}
