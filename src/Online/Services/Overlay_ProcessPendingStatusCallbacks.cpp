#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x22919bc; symbol: data_ov031_022919bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov031 @ 0x22919c4; symbol: data_ov031_022919c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage[];
extern "C" void Http_CloseSocketAndWait(void*, int);
extern "C" void Util_InvokeObjectCallbacks(void*);
// Original: arm9/ov031 @ 0x022417FC; symbol: func_ov031_022417fc; size: 0x60.
extern "C" void Overlay_ProcessPendingStatusCallbacks(void) {
    if (HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[0] == HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[1]) return;
    do {
        Http_CloseSocketAndWait(0, *(unsigned*)(QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage + HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[1] * 8));
        Util_InvokeObjectCallbacks(*(void**)(QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage + HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[1] * 8 + 4));
        HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[1] = (HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[1] + 1) & 7;
    } while (HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[0] != HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3[1]);
}
