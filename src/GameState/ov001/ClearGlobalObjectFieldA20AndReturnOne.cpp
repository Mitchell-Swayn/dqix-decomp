#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov001_02165880[];
extern "C" void func_ov001_02159290(char *);
// Original: arm9/ov001 @ 0x0215E0C0; symbol: func_ov001_0215e0c0; size: 0x1C.
extern "C" int ClearGlobalObjectFieldA20AndReturnOne(void) {
    func_ov001_02159290(*(char **)(data_ov001_02165880 + 0x24));
    return 1;
}
