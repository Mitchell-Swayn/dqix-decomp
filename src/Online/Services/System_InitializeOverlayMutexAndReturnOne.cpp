#include <globaldefs.h>
ARM
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *mutex);
// Original data: arm9/ov031 @ 0x22918a4; symbol: data_ov031_022918a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemLockGlobalMutex_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022402F4; symbol: func_ov031_022402f4; size: 0x18.
extern "C" int System_InitializeOverlayMutexAndReturnOne(void) {
    _Z19ZeroInitializeMutexP5Mutex(SystemLockGlobalMutex_UnknownRoleZeroInitializedStorage);
    return 1;
}
