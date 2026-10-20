// Original data: arm9/ov000 @ 0x2182c94; symbol: data_ov000_02182c94.
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero. Copied as halfwords into local selection storage by SelectWeightedEligibleCombatantIndex.
// Observed values: hex ffff0000000000000000000000000000.
// Span: 16 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero.
// Copied as halfwords into local selection storage by SelectWeightedEligibleCombatantIndex.
extern "C" {
extern const signed short SelectWeightedEligibleCombatantIndex_CombatantSelectionInitialIds[8] = {-1};
}
