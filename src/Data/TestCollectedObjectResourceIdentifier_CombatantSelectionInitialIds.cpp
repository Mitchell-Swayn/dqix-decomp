// Original data: arm9/ov000 @ 0x2182c44; symbol: data_ov000_02182c44.
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero. Copied as halfwords into local selection storage by TestCollectedObjectResourceIdentifier.
// Observed values: hex ffff0000000000000000000000000000.
// Span: 16 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Default combatant-ID selection buffer: signed -1 sentinel, remaining IDs zero.
// Copied as halfwords into local selection storage by TestCollectedObjectResourceIdentifier.
extern "C" {
extern const signed short TestCollectedObjectResourceIdentifier_CombatantSelectionInitialIds[8] = {-1};
}
