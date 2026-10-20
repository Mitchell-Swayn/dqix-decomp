#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void* mutex);
extern "C" void _Z11UnlockMutexP5Mutex(void* mutex);
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02216AB4; symbol: func_ov031_02216ab4; size: 0x4C.
extern "C" unsigned System_ReadGlobalValueUnderMutex(void) {
    void* state = *(void**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8);
    if (state == 0)
        return 0x16;
    void* mutex = (char*)state + 0x13d8;
    _Z9LockMutexP5Mutex(mutex);
    state = *(void**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8);
    unsigned value = *(unsigned*)((char*)state + 0x1004);
    _Z11UnlockMutexP5Mutex((char*)state + 0x13d8);
    return value;
}
