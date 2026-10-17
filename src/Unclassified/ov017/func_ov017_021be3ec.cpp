#include <globaldefs.h>
ARM
extern "C" void DispatchStoredResourceHandleAtOffsetC0(unsigned char *);
extern "C" unsigned char data_02108760[];
// Original: arm9/ov017 @ 0x021BE3EC; symbol: func_ov017_021be3ec; size: 0x20.
extern "C" void func_ov017_021be3ec(unsigned char *p) {
    DispatchStoredResourceHandleAtOffsetC0(data_02108760);
    p[1] = 1;
}
