#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216C720; symbol: CombatScript_QueueValue6FEntry; size: 0x14.
// Queues value 0x6f through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue6FEntry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x6f);
    return 1;
}
