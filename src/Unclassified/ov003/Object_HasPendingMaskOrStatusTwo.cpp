#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*, unsigned);
extern "C" int func_0205d97c(void*);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov003 @ 0x0215DD00; symbol: func_ov003_0215dd00; size: 0x3C.
extern "C" int Object_HasPendingMaskOrStatusTwo(void* self) {
    if (Object_TestNewlySetHalfwordMask(&data_02114e30, 2)) return 1;
    return func_0205d97c((char*)self + 0x98) == 2;
}
