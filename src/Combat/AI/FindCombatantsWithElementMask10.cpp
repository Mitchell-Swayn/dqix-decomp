#include <globaldefs.h>
ARM
extern "C" void Combat_CopyPartyIdsWhenAnyLacksDamageRecoverableAilment(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F08F8; symbol: FindCombatantsWithElementMask10; size: 0x14.
// Checks queried combatants for the element mask tested by Object_TestElement5Mask10 and returns the list on success.
extern "C" void FindCombatantsWithElementMask10(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    Combat_CopyPartyIdsWhenAnyLacksDamageRecoverableAilment(a, b, c, d, e);
}
