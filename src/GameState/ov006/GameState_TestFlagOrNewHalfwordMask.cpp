#include <globaldefs.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *p, unsigned int mask);
extern "C" unsigned char data_02114e54[];
extern "C" unsigned short data_02114e30[];
// Original: arm9/ov006 @ 0x02158C70; symbol: func_ov006_02158c70; size: 0x3C.
extern "C" int GameState_TestFlagOrNewHalfwordMask(void) {
    int result = 0;
    unsigned char flag = data_02114e54[0x55];
    if (Object_TestNewlySetHalfwordMask(data_02114e30, 0x7f3) != 0 || flag != 0)
        result = 1;
    return result;
}
