#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned);
// Original: arm9/ov000 @ 0x0216CFE8; symbol: RegisterScriptOpcode86; size: 0x14.
// Registers script opcode 0x86 by forwarding its selector to the shared registration helper.
extern "C" unsigned CombatScript_QueueOpcode86(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x86);
    return 1;
}
