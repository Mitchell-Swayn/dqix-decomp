#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021DFBD4; symbol: func_ov025_021dfbd4; size: 0x28.
extern "C" int GameState_MapIndexToOffset(int value) {
    int small;
    if (value < 0)
        goto not_small;
    if (value <= 3) {
        small = 1;
        goto apply;
    }
not_small:
    small = 0;
apply:
    if (small)
        value += 0xf2;
    else
        value += 0x36;
    return value;
}
