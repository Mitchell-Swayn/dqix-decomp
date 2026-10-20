#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" int Queue_PeekValueWithOptionalBlockingAndIRQGuard(void *, unsigned *, unsigned);
// Original: arm9/ov031 @ 0x0220F68C; symbol: func_ov031_0220f68c; size: 0x54.
extern "C" void Network_WaitForYssdRequest(void) {
    void *queue = StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
    Queue_PeekValueWithOptionalBlockingAndIRQGuard(queue, (unsigned *)((unsigned char *)queue + 0x24), 1);
    void *record = *(void **)((unsigned char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x24);
    if (record == 0) return;
    *(unsigned *)((unsigned char *)record + 0x1c) = 0;
    record = *(void **)((unsigned char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x24);
    *(unsigned *)((unsigned char *)record + 0x20) = 0;
    record = *(void **)((unsigned char *)StoreReadySharedValue_UnknownRoleZeroInitializedStorage + 0x24);
    *(unsigned *)((unsigned char *)record + 0x24) = 0;
}
