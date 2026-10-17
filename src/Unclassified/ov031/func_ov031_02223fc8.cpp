#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02250bfc;

// Original: arm9/ov031 @ 0x02223FC8; symbol: func_ov031_02223fc8; size: 0x14.
extern "C" void func_ov031_02223fc8(unsigned char value) {
    data_ov031_02250bfc[0x124] = value;
}
