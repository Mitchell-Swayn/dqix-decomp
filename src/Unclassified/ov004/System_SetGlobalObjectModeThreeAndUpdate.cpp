#include <globaldefs.h>
ARM
extern unsigned char data_ov004_021707d8[];
extern "C" void func_ov004_021578a8(void *);
// Original: arm9/ov004 @ 0x0215CD1C; symbol: func_ov004_0215cd1c; size: 0x24.
extern "C" int System_SetGlobalObjectModeThreeAndUpdate(void *argument) {
    unsigned char *object = *(unsigned char **)(data_ov004_021707d8 + 8);
    object[0x3e] = 3;
    func_ov004_021578a8(argument);
    return 0;
}
