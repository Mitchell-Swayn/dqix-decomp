#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e200; symbol: data_ov031_0224e200.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char NetworkCleanupSocketStack_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x022050C4; symbol: func_ov031_022050c4; size: 0x48.
extern "C" int Overlay_InvokeCallbackWhenProgressComplete(void) {
    int progress = *(volatile int*)(NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage + 0x20);
    int limit = *(volatile int*)(NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage + 0x18);
    if (progress < limit) return -1;
    void* argument = *(void* volatile*)NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage;
    void* table = *(void* volatile*)NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
    void (**callback)(void*) = (void (**)(void*))((char*)table + 0x1c);
    (*callback)(argument);
    *(volatile int*)NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage = 0;
    return 0;
}
