#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290fa4; symbol: data_ov031_02290fa4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char SystemLockSharedMutex_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z11UnlockMutexP5Mutex(void *mutex);
// Original: arm9/ov031 @ 0x0223FA20; symbol: func_ov031_0223fa20; size: 0x14.
extern "C" void NasAuth_UnlockRequestMutex(void) {
    _Z11UnlockMutexP5Mutex(SystemLockSharedMutex_UnknownRoleZeroInitializedStorage);
}
