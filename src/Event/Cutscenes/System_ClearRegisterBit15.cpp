#include <globaldefs.h>
ARM
extern "C" void System_SetRegisterBit15(int);
// Original: arm9/ov001 @ 0x0215B5C8; symbol: func_ov001_0215b5c8; size: 0x14.
extern "C" int System_ClearRegisterBit15(void) {
    System_SetRegisterBit15(0);
    return 1;
}
