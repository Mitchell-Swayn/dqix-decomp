#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290fdc; symbol: data_ov031_02290fdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern volatile unsigned int HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage[];
extern "C" void Resource_RemoveReadyCircularNodeAndNotifyOwner(unsigned int);
// Original: arm9/ov031 @ 0x022402B0; symbol: System_ProcessGlobalQueueUntilEmpty; size: 0x30.
// Processes the current global entry word at +8 repeatedly until the shared global pointer becomes null.
extern "C" void System_ProcessGlobalQueueUntilEmpty(void) {
    unsigned int pointer = HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage[0];
    if (pointer != 0) {
        do {
            Resource_RemoveReadyCircularNodeAndNotifyOwner(*(unsigned int *)(pointer + 8));
            pointer = HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage[0];
        } while (pointer != 0);
    }
}
