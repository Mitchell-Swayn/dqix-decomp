#include <globaldefs.h>
extern "C" ARM void _Z9LockMutexP5Mutex(void *);
extern "C" ARM void _Z11UnlockMutexP5Mutex(void *);
THUMB
extern "C" unsigned char data_ov031_0224f704[];
extern "C" unsigned char data_ov031_0224f670[];
// Original: arm9/ov031 @ 0x0221F9A0; symbol: func_ov031_0221f9a0; size: 0x30.
extern "C" int ResolveIndexUnderOptionalMutex(void *unused, int index) {
    if (index > 0) {
        _Z9LockMutexP5Mutex(data_ov031_0224f704);
        int result = ((int (*)(int))(*(void **)(data_ov031_0224f670 + 4)))(index);
        _Z11UnlockMutexP5Mutex(data_ov031_0224f704);
        return result;
    }
    return 0;
}
