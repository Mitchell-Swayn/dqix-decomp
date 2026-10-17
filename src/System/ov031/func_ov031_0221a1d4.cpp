#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e60c[];
extern "C" void _Z9LockMutexP5Mutex(void *);
extern "C" void _Z11UnlockMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0221A1D4; symbol: func_ov031_0221a1d4; size: 0x44.
extern "C" void func_ov031_0221a1d4(void *value) {
    unsigned char *base = *(unsigned char **)data_ov031_0224e60c;
    _Z9LockMutexP5Mutex(base + 0x11dc);
    *(void **)(*(unsigned char **)data_ov031_0224e60c + 0x1000) = value;
    base = *(unsigned char **)data_ov031_0224e60c;
    _Z11UnlockMutexP5Mutex(base + 0x11dc);
}
