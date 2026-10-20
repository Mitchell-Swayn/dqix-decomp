#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e60c; symbol: data_ov031_0224e60c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z9LockMutexP5Mutex(void *);
extern "C" void _Z11UnlockMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0221A1D4; symbol: func_ov031_0221a1d4; size: 0x44.
extern "C" void System_SetSharedProcessorContextPointerUnderMutex(void *value) {
    unsigned char *base = *(unsigned char **)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
    _Z9LockMutexP5Mutex(base + 0x11dc);
    *(void **)(*(unsigned char **)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage + 0x1000) = value;
    base = *(unsigned char **)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
    _Z11UnlockMutexP5Mutex(base + 0x11dc);
}
