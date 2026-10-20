// Original data: arm9/ov000 @ 0x2182c14; symbol: data_ov000_02182c14.
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero. Copied as halfwords into local selection storage by Combat_SelectRandomOtherCandidateIndex.
// Observed values: hex ffff0000000000000000000000000000.
// Span: 16 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero.
// Copied as halfwords into local selection storage by Combat_SelectRandomOtherCandidateIndex.
extern "C" {
extern const signed short Combat_SelectRandomOtherCandidateIndex_CombatantSelectionInitialIds_Copy2[8] = {-1};
}
