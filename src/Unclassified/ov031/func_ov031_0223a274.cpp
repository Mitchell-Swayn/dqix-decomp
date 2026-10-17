#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d18[];
// Original: arm9/ov031 @ 0x0223A274; symbol: func_ov031_0223a274; size: 0x14.
extern "C" void func_ov031_0223a274(unsigned int value) {
    *(unsigned int *)(data_ov031_02290d18[1] + 0x4c) = value;
}
