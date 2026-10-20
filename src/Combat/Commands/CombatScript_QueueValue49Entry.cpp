#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216BBC4; symbol: CombatScript_QueueValue49Entry; size: 0x14.
// Queues value 0x49 through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue49Entry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x49);
    return 1;
}
