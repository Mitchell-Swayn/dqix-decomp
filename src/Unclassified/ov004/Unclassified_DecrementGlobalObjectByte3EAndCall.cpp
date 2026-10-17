#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void func_ov004_021578a8(void *);
// Original: arm9/ov004 @ 0x0215CC84; symbol: func_ov004_0215cc84; size: 0x2C.
extern "C" int Unclassified_DecrementGlobalObjectByte3EAndCall(void *argument) {
    unsigned char *object = *(unsigned char **)(data_ov004_021707d8 + 8);
    if (object[0x3E] != 0)
        --object[0x3E];
    func_ov004_021578a8(argument);
    return 0;
}
