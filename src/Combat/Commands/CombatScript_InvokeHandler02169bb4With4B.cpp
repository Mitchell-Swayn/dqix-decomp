#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int value);

// Original: arm9/ov000 @ 0x0216BBEC; symbol: func_ov000_0216bbec; size: 0x14.
extern "C" int CombatScript_InvokeHandler02169bb4With4B(void *parameters, int argumentCount) {
    Combat_AllocateAndRegisterOwnerEntry(0x4b);
    return 1;
}
