#include <globaldefs.h>
extern "C" ARM void _Z9LockMutexP5Mutex(void *);
extern "C" ARM void _Z11UnlockMutexP5Mutex(void *);
THUMB
// Original data: arm9/ov031 @ 0x224f704; symbol: data_ov031_0224f704.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ResolveIndexUnderOptionalMutex_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F9A0; symbol: func_ov031_0221f9a0; size: 0x30.
extern "C" int ResolveIndexUnderOptionalMutex(void *unused, int index) {
    if (index > 0) {
        _Z9LockMutexP5Mutex(ResolveIndexUnderOptionalMutex_UnknownRoleZeroInitializedStorage);
        int result = ((int (*)(int))(*(void **)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage + 4)))(index);
        _Z11UnlockMutexP5Mutex(ResolveIndexUnderOptionalMutex_UnknownRoleZeroInitializedStorage);
        return result;
    }
    return 0;
}
