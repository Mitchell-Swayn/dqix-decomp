// Original data: arm9/ov000 @ 0x2182d34; symbol: data_ov000_02182d34.
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero. Copied as halfwords into local selection storage by ProcessCombatTurn.
// Observed values: hex ffff000000000000000000000000000000000000000000000000000000000000.
// Span: 32 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero.
// Copied as halfwords into local selection storage by ProcessCombatTurn.
extern "C" {
extern const signed short Combat_ProcessTurn_CombatantSelectionInitialIds_Copy3[16] = {-1};
}
