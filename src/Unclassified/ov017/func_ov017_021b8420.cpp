#include <globaldefs.h>
ARM
extern "C" void func_ov000_02160c60(void *);
// Original: arm9/ov017 @ 0x021B8420; symbol: func_ov017_021b8420; size: 0x18.
extern "C" void func_ov017_021b8420(void *p) {
    void *state = *(void **)((unsigned char *)p + 0x6ac);
    if (state) func_ov000_02160c60(state);
}
