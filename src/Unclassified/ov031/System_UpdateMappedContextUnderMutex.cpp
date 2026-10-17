#include <globaldefs.h>
ARM
extern "C" void * volatile data_ov031_0224e588;

extern "C" void func_ov031_0221038c(int);
extern "C" void _Z9LockMutexP5Mutex(void *);
extern "C" void _Z11UnlockMutexP5Mutex(void *);
extern "C" void func_ov031_02207428(int, int);
// Original: arm9/ov031 @ 0x02210250; symbol: func_ov031_02210250; size: 0x78.
extern "C" int System_UpdateMappedContextUnderMutex(void) {
    if (data_ov031_0224e588 == 0) return 1;
    func_ov031_0221038c(2);
    volatile unsigned char *context = (volatile unsigned char *)data_ov031_0224e588;
    int index = *(volatile int *)(context + 0x1b8);
    if (index >= 0) {
        _Z9LockMutexP5Mutex((void *)(context + 0x1bc));
        context = (volatile unsigned char *)data_ov031_0224e588;
        index = *(volatile int *)(context + 0x1b8);
        if (index >= 0) func_ov031_02207428(*(volatile int *)(context + 0x1b8), 2);
        _Z11UnlockMutexP5Mutex((unsigned char *)data_ov031_0224e588 + 0x1bc);
    }
    return 1;
}
