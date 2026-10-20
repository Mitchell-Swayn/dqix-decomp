#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290f8c; symbol: data_ov031_02290f8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/ov031 @ 0x2290f88; symbol: data_ov031_02290f88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0223FA34; symbol: func_ov031_0223fa34; size: 0x28.
extern "C" int InitializeOverlayMutexAndClearMetadata(void) {
    _Z19ZeroInitializeMutexP5Mutex(GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage_Variant2);
    GraphicsTrySetSharedProcessingFlag_UnknownRoleZeroInitializedStorage = 0;
    return 1;
}
