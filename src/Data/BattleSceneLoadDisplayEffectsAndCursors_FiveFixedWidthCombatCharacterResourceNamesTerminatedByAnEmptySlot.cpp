// Original data: arm9/ov000 @ 0x2183910; symbol: data_ov000_02183910.
// Five fixed-width combat character resource names, terminated by an empty slot.
// Initial values: hex 6562303030302e6368720000000000006562303031302e6368720000000000006562303239302e6368720000000000006562303238302e636872000000000000 ...; full span in module reference.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
#include <globaldefs.h>
// Five fixed-width combat character resource names, terminated by an empty slot.
extern "C" {
char BattleSceneLoadDisplayEffectsAndCursors_FiveFixedWidthCombatCharacterResourceNamesTerminatedByAnEmptySlot[5][16] = {
    "eb0000.chr",
    "eb0010.chr",
    "eb0290.chr",
    "eb0280.chr",
    "",
};
}
