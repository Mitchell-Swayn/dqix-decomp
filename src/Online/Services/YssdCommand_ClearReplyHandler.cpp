#include <globaldefs.h>
ARM

// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void * volatile StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" void YssdClient_SetPacketCallback(int value);

// Original: arm9/ov031 @ 0x0220FED8; symbol: func_ov031_0220fed8; size: 0x40.
extern "C" void YssdCommand_ClearReplyHandler(void) {
    void *state = StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
    if (state == 0) {
        return;
    }
    YssdClient_SetPacketCallback(0);
    *(unsigned int *)((char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x28) = 0;
    *(unsigned int *)((char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x2c) = 1;
}
