#include <globaldefs.h>
ARM
struct Mutex;
extern "C" void _Z11UnlockMutexP5Mutex(Mutex *);
// Original data: arm9/ov031 @ 0x22918a4; symbol: data_ov031_022918a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Mutex SystemLockGlobalMutex_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02240324; symbol: func_ov031_02240324; size: 0x14.
extern "C" void Http_UnlockRequestQueueMutex(void) { _Z11UnlockMutexP5Mutex(&SystemLockGlobalMutex_UnknownRoleZeroInitializedStorage); }
