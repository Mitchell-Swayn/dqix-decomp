#include <globaldefs.h>
THUMB
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
// Original data: arm9/ov031 @ 0x224f704; symbol: data_ov031_0224f704.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* ResolveIndexUnderOptionalMutex_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F9D0; symbol: func_ov031_0221f9d0; size: 0x28.
extern "C" void System_CallSharedObjectCallbackUnderMutex(void* unused, unsigned int value, int count) { if (value && count > 0) { _Z9LockMutexP5Mutex(&ResolveIndexUnderOptionalMutex_UnknownRoleZeroInitializedStorage); ((void (*)(unsigned int))WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[3])(value); _Z11UnlockMutexP5Mutex(&ResolveIndexUnderOptionalMutex_UnknownRoleZeroInitializedStorage); } }
