#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void*);
// Original: arm9/ov000 @ 0x0216BBD8; symbol: CombatScript_QueueValue4AEntry; size: 0x14.
// Queues value 0x4a through the shared linked-entry allocator.
extern "C" int CombatScript_QueueValue4AEntry(void) {
    Combat_AllocateAndRegisterOwnerEntry((void*)0x4a);
    return 1;
}
