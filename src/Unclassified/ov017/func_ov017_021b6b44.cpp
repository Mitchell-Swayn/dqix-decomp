#include <globaldefs.h>
ARM
extern "C" void func_ov003_021600b8(void *p);
// Original: arm9/ov017 @ 0x021B6B44; symbol: func_ov017_021b6b44; size: 0x18.
extern "C" void func_ov017_021b6b44(void *object) {
    void *p = *(void **)((char *)object + 0x24);
    if (p)
        func_ov003_021600b8(p);
}
