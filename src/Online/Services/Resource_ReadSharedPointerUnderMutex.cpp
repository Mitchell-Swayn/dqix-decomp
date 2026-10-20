#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e60c; symbol: data_ov031_0224e60c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z9LockMutexP5Mutex(void *mutex);
extern "C" void _Z11UnlockMutexP5Mutex(void *mutex);
// Original: arm9/ov031 @ 0x022191E0; symbol: func_ov031_022191e0; size: 0x40.
extern "C" void *Resource_ReadSharedPointerUnderMutex(void) {
    unsigned char *object = *WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
    _Z9LockMutexP5Mutex(object + 0x11DC);
    object = *WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
    void *value = *(void **)(object + 0x1000);
    _Z11UnlockMutexP5Mutex(object + 0x11DC);
    return value;
}
