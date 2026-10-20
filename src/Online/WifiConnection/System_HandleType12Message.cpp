#include <globaldefs.h>
ARM

extern "C" void System_CancelAndRestartStateNineAlarm(void);
extern "C" void _Z15UnblockContextsP18BlockedContextList(void *);
// Original data: arm9/ov031 @ 0x224e540; symbol: data_ov031_0224e540.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemHandleType12Message_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e544; symbol: data_ov031_0224e544.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemHandleType12Message_UnknownRoleZeroInitializedStorage_Variant2[];

// Original: arm9/ov031 @ 0x0220F28C; symbol: func_ov031_0220f28c; size: 0x40.
extern "C" void System_HandleType12Message(const unsigned short *message) {
    if (message[0] != 0x12) {
        return;
    }
    *(unsigned int *)(SystemHandleType12Message_UnknownRoleZeroInitializedStorage + 0x24) = message[1];
    if (message[1] == 0) {
        System_CancelAndRestartStateNineAlarm();
    }
    _Z15UnblockContextsP18BlockedContextList(SystemHandleType12Message_UnknownRoleZeroInitializedStorage_Variant2);
}
