#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int);
// Original: arm9/ov000 @ 0x0216D024; symbol: RegisterScriptOpcode89; size: 0x14.
// Registers script opcode 0x89 by forwarding its selector to the shared registration helper.
extern "C" int CombatScript_QueueOpcode89(void) { Combat_AllocateAndRegisterOwnerEntry(0x89); return 1; }
