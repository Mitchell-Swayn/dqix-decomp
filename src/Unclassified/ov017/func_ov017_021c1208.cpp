#include <globaldefs.h>
ARM
extern "C" void func_ov008_02184918(signed char *object);
// Original: arm9/ov017 @ 0x021C1208; symbol: func_ov017_021c1208; size: 0x18.
extern "C" void func_ov017_021c1208(void *object) {
    signed char *p = *(signed char **)((char *)object + 0x1c);
    if (p)
        func_ov008_02184918(p);
}
