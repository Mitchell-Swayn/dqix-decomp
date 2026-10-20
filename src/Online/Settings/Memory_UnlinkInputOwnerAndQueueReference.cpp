#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage[];
extern "C" void UnlinkAndNotifyOverlayOwner(void *);
extern "C" void PushPointerIntoInterruptProtectedRing(void *, void *);
// Original: arm9/ov031 @ 0x0223C534; symbol: Memory_UnlinkInputOwnerAndQueueReference; size: 0x2C.
// Unlinks the owner pointer at input+0x28, then enqueues the input pointer in the selected overlay ring buffer.
extern "C" void Memory_UnlinkInputOwnerAndQueueReference(void *p) {
    UnlinkAndNotifyOverlayOwner(*(void **)((char *)p + 0x28));
    PushPointerIntoInterruptProtectedRing(*(void **)((char *)*(void **)WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + 0x670), p);
}
