#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f4e0; symbol: data_ov031_0224f4e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned NetworkSendQueueSessionEvent_UnknownRoleZeroInitializedStorage;
extern "C" int OS_SendMessage(void *queue, void *message, int flags);
// Original: arm9/ov031 @ 0x0221E7A8; symbol: func_ov031_0221e7a8; size: 0x14.
extern "C" int Network_SendQueueSessionEvent(void *message) {
    return OS_SendMessage(&NetworkSendQueueSessionEvent_UnknownRoleZeroInitializedStorage, message, 0);
}
