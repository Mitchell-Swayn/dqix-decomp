#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_0224e5a4[];

// Original: arm9/ov031 @ 0x02211ACC; symbol: func_ov031_02211acc; size: 0x20.
extern "C" void func_ov031_02211acc(void) {
    if (data_ov031_0224e5a4[0] != 9) {
        data_ov031_0224e5a4[0] = 0;
        data_ov031_0224e5a4[1] = 0;
    }
}
