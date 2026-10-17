#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov004_021707d8[];
extern "C" void func_ov004_021578a8(void *object);
// Original: arm9/ov004 @ 0x0215CD64; symbol: func_ov004_0215cd64; size: 0x24.
extern "C" int SetGlobalModeFiveAndRunObjectRoutine(void *object) {
    unsigned char *global = *(unsigned char **)(data_ov004_021707d8 + 8);
    global[0x3e] = 5;
    func_ov004_021578a8(object);
    return 0;
}
