#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290ca0;
// Original: arm9/ov031 @ 0x02230EF0; symbol: func_ov031_02230ef0; size: 0x10.
extern "C" void func_ov031_02230ef0(unsigned char value) {
    *((unsigned char *)&data_ov031_02290ca0 + 1) = value;
}
