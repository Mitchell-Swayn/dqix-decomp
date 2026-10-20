#include <globaldefs.h>
ARM

extern "C" void YssdClient_SetError(int, int);
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *StoreReadySharedValue_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x0220FFF8; symbol: func_ov031_0220fff8; size: 0x4C.
extern "C" int YssdCommand_RecordInitializationReply(void *record) {
    if (*(unsigned int *)((char *)record + 8) == 0xd6 &&
        *(unsigned int *)((char *)record + 0xc) != 0) {
        unsigned int value = *(unsigned int *)((char *)record + 0x10);
        if (value == 0) {
            YssdClient_SetError(6, -0x14);
        }
        *(unsigned int *)((char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x30) = value;
    }
    return 1;
}
