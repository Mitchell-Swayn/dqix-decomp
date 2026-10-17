#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_0224c980;
// Original: arm9/ov031 @ 0x02200524; symbol: func_ov031_02200524; size: 0x10.
extern "C" void func_ov031_02200524(unsigned value) {
    *(unsigned *)((char *)&data_ov031_0224c980 + 0x3c) = value;
}
