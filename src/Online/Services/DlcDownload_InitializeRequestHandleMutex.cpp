#include <globaldefs.h>
ARM
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *);
// Original data: arm9/ov031 @ 0x2290fa4; symbol: data_ov031_02290fa4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SystemLockSharedMutex_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223F9F0; symbol: func_ov031_0223f9f0; size: 0x18.
extern "C" int DlcDownload_InitializeRequestHandleMutex(void) {
    _Z19ZeroInitializeMutexP5Mutex(&SystemLockSharedMutex_UnknownRoleZeroInitializedStorage);
    return 1;
}
