#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int value);
// Original: arm9/ov000 @ 0x0216C500; symbol: func_ov000_0216c500; size: 0x14.
extern "C" int Ov000_ApplyValue67AndReturnOne(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x67);
    return 1;
}
