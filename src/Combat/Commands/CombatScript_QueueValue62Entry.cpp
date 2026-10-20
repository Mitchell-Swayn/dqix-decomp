#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216C3EC; symbol: CombatScript_QueueValue62Entry; size: 0x14.
// Queues value 0x62 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue62Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x62);
    return 1;
}
