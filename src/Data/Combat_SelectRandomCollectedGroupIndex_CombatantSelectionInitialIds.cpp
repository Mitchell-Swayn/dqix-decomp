// Original data: arm9/ov000 @ 0x2182b14; symbol: data_ov000_02182b14.
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero. Copied as halfwords into local selection storage by Combat_SelectRandomCollectedGroupIndex.
// Observed values: hex ffff0000000000000000000000000000.
// Span: 16 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero.
// Copied as halfwords into local selection storage by Combat_SelectRandomCollectedGroupIndex.
extern "C" {
extern const signed short Combat_SelectRandomCollectedGroupIndex_CombatantSelectionInitialIds[8] = {-1};
}
