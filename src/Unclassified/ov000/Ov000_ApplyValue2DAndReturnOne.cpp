#include <globaldefs.h>
ARM
extern "C" void Combat_AllocateAndRegisterOwnerEntry(unsigned int value);
// Original: arm9/ov000 @ 0x0216B16C; symbol: func_ov000_0216b16c; size: 0x14.
extern "C" int Ov000_ApplyValue2DAndReturnOne(void) {
    Combat_AllocateAndRegisterOwnerEntry(0x2d);
    return 1;
}
