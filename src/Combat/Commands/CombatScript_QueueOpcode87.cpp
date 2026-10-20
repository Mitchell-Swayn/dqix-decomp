#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int value);
// Original: arm9/ov000 @ 0x0216CFFC; symbol: func_ov000_0216cffc; size: 0x14.
extern "C" int CombatScript_QueueOpcode87(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x87);
    return 1;
}
