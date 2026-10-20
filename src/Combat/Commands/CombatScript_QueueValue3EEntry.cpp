#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216B898; symbol: CombatScript_QueueValue3EEntry; size: 0x14.
// Queues value 0x3e through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue3EEntry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x3e);
    return 1;
}
