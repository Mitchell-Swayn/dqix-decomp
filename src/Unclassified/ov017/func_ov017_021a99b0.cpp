#include <globaldefs.h>
ARM
extern "C" void func_ov008_0218946c(void *object);
// Original: arm9/ov017 @ 0x021A99B0; symbol: func_ov017_021a99b0; size: 0x18.
extern "C" void func_ov017_021a99b0(void *object) {
    void *activity = *(void **)((char *)object + 0x20);
    if (activity)
        func_ov008_0218946c(activity);
}
