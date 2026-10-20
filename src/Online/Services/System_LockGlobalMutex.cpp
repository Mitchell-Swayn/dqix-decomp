#include <globaldefs.h>
ARM
#include <System/Mutex.h>
// Original data: arm9/ov031 @ 0x22918a4; symbol: data_ov031_022918a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Mutex SystemLockGlobalMutex_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x02240310; symbol: func_ov031_02240310; size: 0x14.
extern "C" void System_LockGlobalMutex(void) {
    LockMutex(&SystemLockGlobalMutex_UnknownRoleZeroInitializedStorage);
}
