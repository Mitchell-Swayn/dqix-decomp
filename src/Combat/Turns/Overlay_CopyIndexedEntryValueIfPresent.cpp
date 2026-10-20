#include <globaldefs.h>
ARM
extern "C" void *Combat_GetDisplayRecordSlot(void *p, int i);
// Original data: arm9/ov025 @ 0x21ef994; symbol: data_ov025_021ef994.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" void *CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov000 @ 0x02181990; symbol: func_ov000_02181990; size: 0x38.
extern "C" int Overlay_CopyIndexedEntryValueIfPresent(int index, unsigned *out) {
    void *entry = Combat_GetDisplayRecordSlot(CombatAdvanceActionPresentation_UnknownRoleZeroInitializedStorage, index);
    if (!entry) return 0;
    *out = *(unsigned *)entry;
    return 1;
}
