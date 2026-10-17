#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*, unsigned);
extern "C" int func_0205d97c(void*);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov023 @ 0x021E6E20; symbol: func_ov023_021e6e20; size: 0x40.
extern "C" int GameState_HasMaskOrModeTwoAtOffsetAC(void* object) {
    int hasMask = Object_TestNewlySetHalfwordMask(&data_02114e30, 2);
    int hasMode = func_0205d97c((char*)object + 0xac) == 2;
    return (hasMask | hasMode) != 0;
}
