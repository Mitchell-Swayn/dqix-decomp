#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* volatile StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" int System_BlockContextUntilReady();
extern "C" void YssdClient_SetPacketCallback(void*);
extern "C" void System_ValidateInputSizeAndStoreCallbackResult();
// Original: arm9/ov031 @ 0x0220FE44; symbol: func_ov031_0220fe44; size: 0x5C.
extern "C" int StoreReadySharedValue(void* value) {
    if (StoreReadySharedValue_UnknownRoleZeroInitializedStorage == 0) return 0;
    if (!System_BlockContextUntilReady()) return 0;
    *(unsigned*)((char*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x2c) = 0;
    *(void**)((char*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x28) = value;
    YssdClient_SetPacketCallback((void*)System_ValidateInputSizeAndStoreCallbackResult);
    return 1;
}
