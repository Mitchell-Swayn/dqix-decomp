#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned int FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021A5568; symbol: func_ov017_021a5568; size: 0x3C.
extern "C" void FieldMenu_InitializePartyMenuCommand(signed char *p) {
    LinkedQueue_InitializeNodeStatus(p);
    p[0] = 12;
    *(unsigned int *)(p + 8) = 0;
    FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage = 0;
    p[0x20] = 0;
    p[0x21] = 0;
    *(short *)(p + 0x22) = -1;
}
