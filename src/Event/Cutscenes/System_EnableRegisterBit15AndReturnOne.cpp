#include <globaldefs.h>
ARM
extern "C" void System_SetRegisterBit15(unsigned int value);
// Original: arm9/ov001 @ 0x0215B5B4; symbol: func_ov001_0215b5b4; size: 0x14.
extern "C" int System_EnableRegisterBit15AndReturnOne(void) {
    System_SetRegisterBit15(1);
    return 1;
}
