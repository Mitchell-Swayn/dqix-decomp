#include <globaldefs.h>
ARM
extern "C" void Combat_CopyPartyIdsWhenAnyLacksPrimaryStatusBit5(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F0720; symbol: FilterCombatantsByDescriptorFlag20; size: 0x14.
// Checks the queried combatants for a clear descriptor flag 0x20 and returns the matched list on success.
extern "C" void FilterCombatantsByDescriptorFlag20(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    Combat_CopyPartyIdsWhenAnyLacksPrimaryStatusBit5(a, b, c, d, e);
}
