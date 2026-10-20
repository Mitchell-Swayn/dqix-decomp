#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216C490; symbol: CombatScript_QueueValue65Entry; size: 0x14.
// Queues value 0x65 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue65Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x65);
    return 1;
}
