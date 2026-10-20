#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216CF04; symbol: CombatScript_QueueValue81Entry; size: 0x14.
// Queues value 0x81 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue81Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x81);
    return 1;
}
