#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d0c;
// Original: arm9/ov031 @ 0x022376E4; symbol: func_ov031_022376e4; size: 0x18.
extern "C" void func_ov031_022376e4(unsigned int value) {
    *(unsigned int *)(*(unsigned int *)&data_ov031_02290d0c + 0x1370) = value;
}
