#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e540; symbol: data_ov031_0224e540.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemHandleType12Message_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void *);
// Original: arm9/ov031 @ 0x0220EF5C; symbol: func_ov031_0220ef5c; size: 0x40.
extern "C" void System_InitializeWorkspaceMutex(void) {
    if (SystemHandleType12Message_UnknownRoleZeroInitializedStorage[0] != 0) return;
    SystemHandleType12Message_UnknownRoleZeroInitializedStorage[0] = 1;
    *(unsigned int *)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 0x24) = 0;
    *(unsigned int *)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 8) = 0;
    *(unsigned int *)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 4) = 0;
    _Z19ZeroInitializeMutexP5Mutex(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 0xc);
}
