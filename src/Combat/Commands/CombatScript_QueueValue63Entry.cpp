#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216C400; symbol: CombatScript_QueueValue63Entry; size: 0x14.
// Queues value 0x63 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue63Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x63);
    return 1;
}
