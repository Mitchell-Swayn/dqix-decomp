#include <globaldefs.h>
ARM
extern "C" unsigned data_ov001_02165880[];
extern "C" void func_ov001_02159044(void *);
// Original: arm9/ov001 @ 0x0215D768; symbol: func_ov001_0215d768; size: 0x1C.
extern "C" unsigned func_ov001_0215d768(void) {
    func_ov001_02159044(*(void **)((char *)data_ov001_02165880 + 0x24));
    return 1;
}
