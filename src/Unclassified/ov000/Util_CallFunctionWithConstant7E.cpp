#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(int);
// Original: arm9/ov000 @ 0x0216CE48; symbol: func_ov000_0216ce48; size: 0x14.
extern "C" int Util_CallFunctionWithConstant7E(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x7e);
    return 1;
}
