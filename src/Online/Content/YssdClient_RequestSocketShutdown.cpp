#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void * volatile YssdClientRunWorker_UnknownRoleZeroInitializedStorage;

extern "C" void System_SetSharedStateUnlessTwoUnderMutex(int);
extern "C" void _Z9LockMutexP5Mutex(void *);
extern "C" void _Z11UnlockMutexP5Mutex(void *);
extern "C" void NetworkSocket_Shutdown(int, int);
// Original: arm9/ov031 @ 0x02210250; symbol: func_ov031_02210250; size: 0x78.
extern "C" int YssdClient_RequestSocketShutdown(void) {
    if (YssdClientRunWorker_UnknownRoleZeroInitializedStorage == 0) return 1;
    System_SetSharedStateUnlessTwoUnderMutex(2);
    volatile unsigned char *context = (volatile unsigned char *)YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
    int index = *(volatile int *)(context + 0x1b8);
    if (index >= 0) {
        _Z9LockMutexP5Mutex((void *)(context + 0x1bc));
        context = (volatile unsigned char *)YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
        index = *(volatile int *)(context + 0x1b8);
        if (index >= 0) NetworkSocket_Shutdown(*(volatile int *)(context + 0x1b8), 2);
        _Z11UnlockMutexP5Mutex((unsigned char *)YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0x1bc);
    }
    return 1;
}
