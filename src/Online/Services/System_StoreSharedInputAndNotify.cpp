#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2291e68; symbol: data_ov031_02291e68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemStoreSharedInputAndNotify_UnknownRoleZeroInitializedStorage[];
extern "C" void InitializeObjectRandomState(void *, unsigned int);

// Original: arm9/ov031 @ 0x0224342C; symbol: System_StoreSharedInputAndNotify; size: 0x24.
// Stores the input at shared data+0x10 and forwards it with the shared notification object.
extern "C" void System_StoreSharedInputAndNotify(unsigned int value) {
    ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[4] = value;
    InitializeObjectRandomState(SystemStoreSharedInputAndNotify_UnknownRoleZeroInitializedStorage, value);
}
