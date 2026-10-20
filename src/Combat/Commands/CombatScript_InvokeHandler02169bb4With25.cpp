#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Original: arm9/ov000 @ 0x0216ADA4; symbol: func_ov000_0216ada4; size: 0x14.
extern "C" int CombatScript_InvokeHandler02169bb4With25(void *parameters, int argumentCount) {
    Combat_AllocateAndRegisterOwnerEntry(0x25);
    return 1;
}
