#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
// Original data: arm9/ov017 @ 0x21d8478; symbol: data_ov017_021d8478.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned int FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov017 @ 0x021C1350; symbol: func_ov017_021c1350; size: 0x44.
extern "C" void FieldScreen_InitializeOverlayThreeSession(unsigned char *record, unsigned char first, unsigned char second) {
    LinkedQueue_InitializeNodeStatus((signed char *)record);
    record[0] = 0x2e;
    FieldScreenUpdateOverlayThreeSession_UnknownRoleZeroInitializedStorage = 0;
    record[0x1c] = 0;
    record[0x1e] = first;
    record[0x1f] = second;
    record[0x1d] = 0xff;
}
