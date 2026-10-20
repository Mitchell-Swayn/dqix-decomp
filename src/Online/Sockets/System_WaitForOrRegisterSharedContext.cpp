#include <globaldefs.h>
ARM
extern "C" unsigned _Z16GetProcessorModev(void);
extern "C" void _Z19SleepCurrentContextj(unsigned);
// Original data: arm9/ov031 @ 0x224c9d0; symbol: data_ov031_0224c9d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224e1c8; symbol: data_ov031_0224e1c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned SystemWaitForOrRegisterSharedContext_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224e1c4; symbol: data_ov031_0224e1c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov031 @ 0x02206F3C; symbol: func_ov031_02206f3c; size: 0x68.
extern "C" void* System_WaitForOrRegisterSharedContext(void) {
    void* context = NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;
    if (!context) {
        if ((SystemWaitForOrRegisterSharedContext_UnknownRoleZeroInitializedStorage & 3) == 1 && _Z16GetProcessorModev() != 0x12)
            _Z19SleepCurrentContextj(10);
    } else if (!NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant2) {
        NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant2 = context;
    }
    return NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;
}
