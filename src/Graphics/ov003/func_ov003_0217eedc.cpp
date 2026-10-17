#include <globaldefs.h>
ARM
extern "C" void func_ov009_02184c30(void *);
// Original: arm9/ov003 @ 0x0217EEDC; symbol: func_ov003_0217eedc; size: 0x18.
extern "C" void func_ov003_0217eedc(void *p) {
    void *state = *(void **)((unsigned char *)p + 0x1c);
    if (state) func_ov009_02184c30(state);
}
