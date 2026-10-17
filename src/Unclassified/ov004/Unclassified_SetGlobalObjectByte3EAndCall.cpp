#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void func_ov004_021578a8(void *);
// Original: arm9/ov004 @ 0x0215CCD4; symbol: func_ov004_0215ccd4; size: 0x24.
extern "C" int Unclassified_SetGlobalObjectByte3EAndCall(void *argument) {
    void *object = *(void **)(data_ov004_021707d8 + 8);
    *(unsigned char *)((unsigned char *)object + 0x3E) = 1;
    func_ov004_021578a8(argument);
    return 0;
}
