#include <globaldefs.h>
ARM
extern "C" void *data_ov017_021d83f0[];
extern "C" void func_ov011_02184760(void *object);
// Original: arm9/ov017 @ 0x021B2368; symbol: func_ov017_021b2368; size: 0x20.
extern "C" void Ov017_ProcessGlobalObjectIfPresent(void) {
    void *object = data_ov017_021d83f0[1];
    if (object)
        func_ov011_02184760(object);
}
