#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224c980[];

// Original: arm9/ov031 @ 0x022006F0; symbol: func_ov031_022006f0; size: 0x40.
extern "C" int func_ov031_022006f0(unsigned int value) {
    int result = 1;
    if (value != 0xffffffff && value != 0x7f000001) {
        unsigned int mask = *(unsigned int *)(data_ov031_0224c980 + 0x1c);
        if ((value & mask) != (*(unsigned int *)(data_ov031_0224c980 + 0x50) & mask))
            result = 0;
    }
    return result;
}
