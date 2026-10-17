#include <globaldefs.h>
ARM
extern "C" unsigned *data_ov031_02250bfc;
// Original: arm9/ov031 @ 0x02223FB4; symbol: func_ov031_02223fb4; size: 0x14.
extern "C" void func_ov031_02223fb4(unsigned char value) {
    *((unsigned char *)*(&data_ov031_02250bfc) + 0x123) = value;
}
