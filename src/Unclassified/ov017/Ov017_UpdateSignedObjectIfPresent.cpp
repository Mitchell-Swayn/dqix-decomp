#include <globaldefs.h>
ARM
extern "C" void func_ov008_02184878(signed char *object);
// Original: arm9/ov017 @ 0x021C11F0; symbol: func_ov017_021c11f0; size: 0x18.
extern "C" void Ov017_UpdateSignedObjectIfPresent(void *owner) {
    signed char *object = *(signed char **)((char *)owner + 0x1c);
    if (object)
        func_ov008_02184878(object);
}
