#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216BE58; symbol: CombatScript_QueueValue55Entry; size: 0x14.
// Queues value 0x55 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue55Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x55);
    return 1;
}
