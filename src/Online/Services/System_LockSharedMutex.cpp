#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void*);
// Original data: arm9/ov031 @ 0x2290fa4; symbol: data_ov031_02290fa4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SystemLockSharedMutex_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223FA0C; symbol: func_ov031_0223fa0c; size: 0x14.
extern "C" void System_LockSharedMutex(void) { _Z9LockMutexP5Mutex(&SystemLockSharedMutex_UnknownRoleZeroInitializedStorage); }
