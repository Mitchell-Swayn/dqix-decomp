#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned);
// Original: arm9/ov000 @ 0x0216D1B0; symbol: RegisterScriptOpcode8E; size: 0x14.
// Registers script opcode 0x8E by forwarding its selector to the shared registration helper.
extern "C" unsigned CombatScript_QueueOpcode8E(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x8e);
    return 1;
}
