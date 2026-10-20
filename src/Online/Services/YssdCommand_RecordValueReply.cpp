#include <globaldefs.h>
ARM
struct State { char pad[32]; int dirty; int value; };
struct Owner { char pad[36]; State *state; };
struct Message { int pad[2]; int kind; int value; };
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Owner *StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220FF78; symbol: func_ov031_0220ff78; size: 0x80.
extern "C" int YssdCommand_RecordValueReply(Message *message) {
    switch (message->kind) {
    case 201:
        StoreReadySharedValue_UnknownRoleZeroInitializedStorage->state->value = message->value;
        StoreReadySharedValue_UnknownRoleZeroInitializedStorage->state->dirty = 1;
        break;
    case 202:
        if ((unsigned)(message->value - 2) <= 1) {
            StoreReadySharedValue_UnknownRoleZeroInitializedStorage->state->value = 0;
            StoreReadySharedValue_UnknownRoleZeroInitializedStorage->state->dirty = 1;
        }
        break;
    }
    return 1;
}
