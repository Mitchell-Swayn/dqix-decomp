#include <globaldefs.h>
ARM
extern "C" void Util_RemoveHeadFromCircularList(void **p);
// Original data: arm9/ov031 @ 0x2290fdc; symbol: data_ov031_02290fdc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022402E0; symbol: func_ov031_022402e0; size: 0x14.
extern "C" void Http_DequeuePendingRequest(void) {
    Util_RemoveHeadFromCircularList(&HttpDequeuePendingRequest_UnknownRoleZeroInitializedStorage);
}
