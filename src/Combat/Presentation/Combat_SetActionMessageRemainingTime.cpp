#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" void Combat_SetActiveMessageRemainingTime(void *self, unsigned short value);
// Original: arm9/ov025 @ 0x021E80D8; symbol: Unclassified_CopyObjectHalfword8ToGlobalField5E8; size: 0x28.
// Reads the input halfword at +8 and writes it through the field writer to the global pointer plus +0x5E8, then returns 1.
extern "C" unsigned Combat_SetActionMessageRemainingTime(void *object) {
    unsigned short value = *(unsigned short *)((char *)object + 8);
    char *target = *(char **)((char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    Combat_SetActiveMessageRemainingTime(target + 0x5e8, value);
    return 1;
}
