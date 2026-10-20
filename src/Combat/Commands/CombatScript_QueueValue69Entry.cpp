#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216C570; symbol: CombatScript_QueueValue69Entry; size: 0x14.
// Queues value 0x69 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue69Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x69);
    return 1;
}
