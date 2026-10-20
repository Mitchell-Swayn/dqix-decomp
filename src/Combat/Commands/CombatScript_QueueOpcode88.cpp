#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int);
// Original: arm9/ov000 @ 0x0216D010; symbol: RegisterScriptOpcode88; size: 0x14.
// Registers script opcode 0x88 by forwarding its selector to the shared registration helper.
extern "C" int CombatScript_QueueOpcode88(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x88);
    return 1;
}
