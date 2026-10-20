#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220FDEC; symbol: System_ValidateInputSizeAndStoreCallbackResult; size: 0x58.
// Defaults result to 1; for a matching size of at least 12, invokes the shared callback at object+0x28 when present and stores its result at object+0x2C.
extern "C" void System_ValidateInputSizeAndStoreCallbackResult(int size, const unsigned int* value) {
    unsigned int result = 1;
    if (size >= 0 && (unsigned int)size >= 0xc && *value == (unsigned int)size) {
        void* object = *(void**)&StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
        typedef unsigned int (*Callback)(const unsigned int*);
        Callback callback = *(Callback*)((char*)object + 0x28);
        if (callback) result = callback(value);
    }
    void* object = *(void**)&StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
    *(unsigned int*)((char*)object + 0x2c) = result;
}
