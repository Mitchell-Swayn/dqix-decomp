#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Original: arm9/ov000 @ 0x0216D19C; symbol: func_ov000_0216d19c; size: 0x14.
extern "C" int CombatScript_InvokeHandler02169bb4With8D(void *parameters, int argumentCount) {
    Combat_AllocateAndRegisterOwnerEntry(0x8d);
    return 1;
}
