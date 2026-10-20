#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
// Original: arm9/ov031 @ 0x02217598; symbol: func_ov031_02217598; size: 0x44.
extern "C" void System_SetSharedWordUnderMutex(void* value) {
    _Z9LockMutexP5Mutex((char*)*(void**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8) + 0x13d8);
    *(void**)(*(unsigned char**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8) + 0x1004) = value;
    _Z11UnlockMutexP5Mutex((char*)*(void**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8) + 0x13d8);
}
