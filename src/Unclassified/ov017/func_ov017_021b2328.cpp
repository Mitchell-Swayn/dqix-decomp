#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov017_021d83f0[];
extern "C" void func_ov011_02184740(void *);
// Original: arm9/ov017 @ 0x021B2328; symbol: func_ov017_021b2328; size: 0x20.
extern "C" void func_ov017_021b2328(void) {
    void *p = (void *)data_ov017_021d83f0[1];
    if (p) func_ov011_02184740(p);
}
