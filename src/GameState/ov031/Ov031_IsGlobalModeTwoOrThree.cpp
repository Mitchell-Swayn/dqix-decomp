#include <globaldefs.h>
ARM
extern "C" unsigned int *data_ov031_0224e590;
// Original: arm9/ov031 @ 0x022113C0; symbol: func_ov031_022113c0; size: 0x50.
extern "C" int Ov031_IsGlobalModeTwoOrThree(void) {
    unsigned int *state = data_ov031_0224e590;
    if (state == 0) return 0;
    switch (*state) {
    case 0:
    case 1:
        return 0;
    case 2:
    case 3:
        return 1;
    default:
        return 0;
    }
}
