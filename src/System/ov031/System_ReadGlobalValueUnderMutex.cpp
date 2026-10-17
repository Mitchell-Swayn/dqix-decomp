#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void* mutex);
extern "C" void _Z11UnlockMutexP5Mutex(void* mutex);
extern "C" char data_ov031_0224e5e8[];
// Original: arm9/ov031 @ 0x02216AB4; symbol: func_ov031_02216ab4; size: 0x4C.
extern "C" unsigned System_ReadGlobalValueUnderMutex(void) {
    void* state = *(void**)(data_ov031_0224e5e8 + 8);
    if (state == 0)
        return 0x16;
    void* mutex = (char*)state + 0x13d8;
    _Z9LockMutexP5Mutex(mutex);
    state = *(void**)(data_ov031_0224e5e8 + 8);
    unsigned value = *(unsigned*)((char*)state + 0x1004);
    _Z11UnlockMutexP5Mutex((char*)state + 0x13d8);
    return value;
}
