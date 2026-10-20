#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216BA00; symbol: CombatScript_QueueValue43Entry; size: 0x14.
// Queues value 0x43 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue43Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x43);
    return 1;
}
