#include <globaldefs.h>
ARM
extern "C" void Network_SendCurrentSocketPayloadSpans(void *, void *, int, int);
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov031 @ 0x02203B8C; symbol: ProcessAndClearRootEntryPendingValue; size: 0x40.
// Processes the shared root entry when +0x60 is nonnull, then clears that pending pointer.
extern "C" void ProcessAndClearRootEntryPendingValue(void) {
 void *root = *(void **)((char *)&OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4);
 char *entry = *(char **)((char *)root + 0xa4);
 if (!entry || !*(void **)(entry + 0x60)) return;
 Network_SendCurrentSocketPayloadSpans(*(void **)(entry + 0x5c), *(void **)(entry + 0x60), 0, 0);
 *(void **)(entry + 0x60) = 0;
}
