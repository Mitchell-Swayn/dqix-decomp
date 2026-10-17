#include <globaldefs.h>
ARM
struct Overlay8Activity;
extern "C" void func_ov008_02189404(Overlay8Activity *object);
// Original: arm9/ov017 @ 0x021A9998; symbol: func_ov017_021a9998; size: 0x18.
extern "C" void func_ov017_021a9998(void *a0) {
    Overlay8Activity *object = *(Overlay8Activity **)((char *)a0 + 0x20);
    if (object)
        func_ov008_02189404(object);
}
