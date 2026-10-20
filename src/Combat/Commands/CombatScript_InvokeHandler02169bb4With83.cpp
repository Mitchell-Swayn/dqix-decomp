#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Original: arm9/ov000 @ 0x0216CF70; symbol: func_ov000_0216cf70; size: 0x14.
extern "C" int CombatScript_InvokeHandler02169bb4With83(void *parameters, int argumentCount) {
    Combat_AllocateAndRegisterOwnerEntry(0x83);
    return 1;
}
