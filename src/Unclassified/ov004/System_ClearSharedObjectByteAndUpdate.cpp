#include <globaldefs.h>
ARM
extern unsigned char data_ov004_021707d8[];
extern "C" void func_ov004_021578a8(void *);
// Original: arm9/ov004 @ 0x0215CCB0; symbol: func_ov004_0215ccb0; size: 0x24.
extern "C" int System_ClearSharedObjectByteAndUpdate(void *argument) {
    unsigned char *object = *(unsigned char **)(data_ov004_021707d8 + 8);
    object[0x3e] = 0;
    func_ov004_021578a8(argument);
    return 0;
}
