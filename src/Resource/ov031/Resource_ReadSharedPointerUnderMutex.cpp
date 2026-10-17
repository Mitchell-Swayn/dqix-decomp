#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_0224e60c[];
extern "C" void _Z9LockMutexP5Mutex(void *mutex);
extern "C" void _Z11UnlockMutexP5Mutex(void *mutex);
// Original: arm9/ov031 @ 0x022191E0; symbol: func_ov031_022191e0; size: 0x40.
extern "C" void *Resource_ReadSharedPointerUnderMutex(void) {
    unsigned char *object = *data_ov031_0224e60c;
    _Z9LockMutexP5Mutex(object + 0x11DC);
    object = *data_ov031_0224e60c;
    void *value = *(void **)(object + 0x1000);
    _Z11UnlockMutexP5Mutex(object + 0x11DC);
    return value;
}
