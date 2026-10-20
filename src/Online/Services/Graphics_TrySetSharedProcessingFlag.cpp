#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
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
extern "C" unsigned char GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x0223FA60; symbol: func_ov031_0223fa60; size: 0x48.
extern "C" int Graphics_TrySetSharedProcessingFlag(void) {
    _Z9LockMutexP5Mutex(GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2);
    int acquired = GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage == 0;
    if (acquired) GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage = 1;
    _Z11UnlockMutexP5Mutex(GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2);
    return acquired;
}
