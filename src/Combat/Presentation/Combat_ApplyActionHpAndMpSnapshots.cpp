#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" void Combat_ApplyActionMpResultsAndShowRecovery(void *);
extern "C" void Combat_SynchronizeActionHpResults(void *);
// Original: arm9/ov025 @ 0x021E7FB4; symbol: Unclassified_RunGlobalResourceHelpers_021E7FB4; size: 0x28.
// Loads the pointer at data_ov025_021ef988+0x0C and passes it to two helpers before returning 1. Their combined operation is unresolved; temporary address suffix pending naming refinement.
extern "C" int Combat_ApplyActionHpAndMpSnapshots(void) {
    Combat_ApplyActionMpResultsAndShowRecovery(*(void **)((unsigned char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc));
    Combat_SynchronizeActionHpResults(*(void **)((unsigned char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc));
    return 1;
}
