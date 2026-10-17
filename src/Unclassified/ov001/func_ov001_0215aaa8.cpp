#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov001_021658b8[];
// Original: arm9/ov001 @ 0x0215AAA8; symbol: func_ov001_0215aaa8; size: 0x10.
extern "C" void func_ov001_0215aaa8(unsigned int index, unsigned int value) {
    data_ov001_021658b8[index] = value;
}
