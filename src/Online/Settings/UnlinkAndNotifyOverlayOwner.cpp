#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d64; symbol: data_ov031_02290d64.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_UnlinkListNode(void *);
extern "C" void PushPointerIntoInterruptProtectedRing(void *, void *);
// Original: arm9/ov031 @ 0x0223DCF4; symbol: func_ov031_0223dcf4; size: 0x40.
extern "C" void UnlinkAndNotifyOverlayOwner(void *pointer) {
    int segment = 0;
    WfcUtility_UnlinkListNode(pointer);
    unsigned char *base = (unsigned char *)UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage;
    if ((unsigned char *)pointer >= base + 0x1a0) segment = 1;
    unsigned char *table = base + segment * 0x1a0;
    void *callbackData = *(void **)(table + 0x19c);
    PushPointerIntoInterruptProtectedRing(callbackData, pointer);
}
