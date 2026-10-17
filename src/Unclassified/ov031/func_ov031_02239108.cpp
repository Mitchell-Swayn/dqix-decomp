#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d14;
// Original: arm9/ov031 @ 0x02239108; symbol: func_ov031_02239108; size: 0x14.
extern "C" void func_ov031_02239108(unsigned short value) {
    *(unsigned short *)(*(unsigned int *)&data_ov031_02290d14) = value;
}
