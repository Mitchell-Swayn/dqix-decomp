#include <globaldefs.h>
ARM
struct GlobalObjectRef { unsigned char pad[8]; void *object; };
extern "C" GlobalObjectRef data_ov004_021707d8;
extern "C" void func_ov004_021578a8(void *argument);
// Original: arm9/ov004 @ 0x0215CCF8; symbol: func_ov004_0215ccf8; size: 0x24.
extern "C" int SetObjectModeTwoAndContinue(void *argument) {
    *((unsigned char *)data_ov004_021707d8.object + 0x3e) = 2;
    func_ov004_021578a8(argument);
    return 0;
}
