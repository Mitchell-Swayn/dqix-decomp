#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d18[];

// Original: arm9/ov031 @ 0x02239BC0; symbol: func_ov031_02239bc0; size: 0x14.
extern "C" void func_ov031_02239bc0(unsigned int value) {
    ((unsigned int *)data_ov031_02290d18[1])[2] = value;
}
