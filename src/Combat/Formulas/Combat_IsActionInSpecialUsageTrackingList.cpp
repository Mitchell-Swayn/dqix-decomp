#include <globaldefs.h>
ARM
// The function searches the signed halfword table at data_ov024_021fe7aa for the second argument, returning true on a match and false at the -1 sentinel. Ten C loop/signature/optimization variants missed the original loop layout; no hand-assembly-only instructions are present, but source scheduling remains unresolved.
// Original: arm9/ov024 @ 0x021EB47C; symbol: SignedHalfwordTableContainsKey; size: 0x34.
// Original data: arm9/ov024 @ 0x21fe7aa; symbol: data_ov024_021fe7aa.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex f901fa01fb01fc01fd01fe01ff010002010202020f020402ffff.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatIsActionInSpecialUsageTrackingList_UnknownRoleInitializedBytes[];
extern "C" int Combat_IsActionInSpecialUsageTrackingList(int unused, int key) {
    short* entry = CombatIsActionInSpecialUsageTrackingList_UnknownRoleInitializedBytes;
    short value;
    goto check_sentinel;
compare:
    if (value == key) return 1;
    ++entry;
check_sentinel:
    value = *entry;
    if (value != -1) goto compare;
    return 0;
}
