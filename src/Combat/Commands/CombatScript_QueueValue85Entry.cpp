#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216CFD4; symbol: CombatScript_QueueValue85Entry; size: 0x14.
// Queues value 0x85 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue85Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x85);
    return 1;
}
