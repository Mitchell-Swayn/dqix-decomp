#include <globaldefs.h>
ARM
extern "C" unsigned data_ov017_021d83f0;
extern "C" void Ov011_ForwardObjectAt118(void *object);
// Original: arm9/ov017 @ 0x021B2348; symbol: func_ov017_021b2348; size: 0x20.
extern "C" void func_ov017_021b2348(void) {
    void *object = *(void **)((char *)&data_ov017_021d83f0 + 4);
    if (object)
        Ov011_ForwardObjectAt118(object);
}
