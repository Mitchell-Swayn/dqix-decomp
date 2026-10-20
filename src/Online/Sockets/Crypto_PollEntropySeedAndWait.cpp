#include <globaldefs.h>
ARM
extern "C" void OS_GetLowEntropyData(unsigned long *);
extern "C" void Crypto_HashInputWithStaticSeed(const void *, unsigned);
extern "C" void _Z9LockMutexP5Mutex(void *);
extern "C" void _Z11UnlockMutexP5Mutex(void *);
extern "C" void _Z19SleepCurrentContextj(unsigned);
// Original: arm9/ov031 @ 0x02217ECC; symbol: func_ov031_02217ecc; size: 0x78.
extern "C" int Crypto_PollEntropySeedAndWait(unsigned char *context) {
    if (*(unsigned int *)(context + 0x1130) == 1) {
        OS_GetLowEntropyData((unsigned long *)(context + 0x19d4));
        Crypto_HashInputWithStaticSeed(context + 0x19d4, 0x20);
    }
    _Z9LockMutexP5Mutex(context + 0x1bf8);
    if (*(unsigned int *)(context + 0x1c10) == 1) {
        _Z11UnlockMutexP5Mutex(context + 0x1bf8);
        return 0;
    }
    _Z11UnlockMutexP5Mutex(context + 0x1bf8);
    _Z19SleepCurrentContextj(10);
    return 1;
}
