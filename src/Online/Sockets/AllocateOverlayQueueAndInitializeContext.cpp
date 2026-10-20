#include <globaldefs.h>
ARM
extern "C" int Network_AllocateOverlayQueueRecords(int count);
extern "C" void *RegisterObjectCallbackAndReturnObject(void *);
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x22496dc; symbol: data_ov031_022496dc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000000ea0500000000eb0600000000000000080d20.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AllocateOverlayQueueAndInitializeContext_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x224e1c0; symbol: data_ov031_0224e1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02204DF8; symbol: AllocateOverlayQueueAndInitializeContext; size: 0x40.
// Allocates the configured number of overlay queue records and, on success, stores the initialized context object at shared slot +0xC.
extern "C" int AllocateOverlayQueueAndInitializeContext(void) {
 int result = Network_AllocateOverlayQueueRecords(*(int *)(NetworkCleanupSocketStack_UnknownRoleInitializedBytes + 0x20));
 if (result >= 0) *(void **)((char *)&NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage + 0xc) = RegisterObjectCallbackAndReturnObject(&AllocateOverlayQueueAndInitializeContext_UnknownRoleInitializedBytes);
 return result;
}
