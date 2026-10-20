#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22918bc; symbol: data_ov031_022918bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned HttpWaitForRequestQueueMessage_UnknownRoleZeroInitializedStorage;
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void *queue, unsigned *output, unsigned flags);
// Original: arm9/ov031 @ 0x022403D8; symbol: func_ov031_022403d8; size: 0x1C.
extern "C" int Http_WaitForRequestQueueMessage(void) {
    unsigned message;
    return MessageQueue_ReceiveWithOptionalBlocking(&HttpWaitForRequestQueueMessage_UnknownRoleZeroInitializedStorage, &message, 1);
}
