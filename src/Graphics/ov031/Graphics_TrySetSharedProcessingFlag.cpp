#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" unsigned int data_ov031_02290f88;
extern "C" unsigned char data_ov031_02290f8c[];
// Original: arm9/ov031 @ 0x0223FA60; symbol: func_ov031_0223fa60; size: 0x48.
extern "C" int Graphics_TrySetSharedProcessingFlag(void) {
    _Z9LockMutexP5Mutex(data_ov031_02290f8c);
    int acquired = data_ov031_02290f88 == 0;
    if (acquired) data_ov031_02290f88 = 1;
    _Z11UnlockMutexP5Mutex(data_ov031_02290f8c);
    return acquired;
}
