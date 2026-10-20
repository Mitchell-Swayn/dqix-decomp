#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e204; symbol: data_ov031_0224e204.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkRecycleSocketCommand_UnknownRoleZeroInitializedStorage[];
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void *, unsigned int *, unsigned int);
// Original: arm9/ov031 @ 0x0220510C; symbol: func_ov031_0220510c; size: 0x28.
extern "C" unsigned int ReceiveGlobalQueueValueWithFlags(unsigned int flags) {
    unsigned int value;
    if (MessageQueue_ReceiveWithOptionalBlocking(NetworkRecycleSocketCommand_UnknownRoleZeroInitializedStorage, &value, flags))
        return value;
    return 0;
}
