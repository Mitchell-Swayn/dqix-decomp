#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290f88; symbol: data_ov031_02290f88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2290f8c; symbol: data_ov031_02290f8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" void _Z9LockMutexP5Mutex(void *);
extern "C" void _Z11UnlockMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0223FAA8; symbol: Unclassified_ClearMappedIndexUnderMutex; size: 0x2C.
// Locks the shared mutex, clears the mapped index word, and unlocks the mutex.
extern "C" void NasAuth_ReleaseRequestProcessingGuard(void) {
    _Z9LockMutexP5Mutex(&GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2);
    GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage = 0;
    _Z11UnlockMutexP5Mutex(&GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2);
}
