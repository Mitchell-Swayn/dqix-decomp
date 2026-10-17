#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void func_ov004_021578a8(void *);
// Original: arm9/ov004 @ 0x0215CD40; symbol: func_ov004_0215cd40; size: 0x24.
extern "C" int SetGlobalObjectByte3EAndInitialize(void *argument) {
    unsigned int value = 4;
    unsigned char *object = *(unsigned char **)(data_ov004_021707d8 + 8);
    object[0x3e] = value;
    func_ov004_021578a8(argument);
    return 0;
}
