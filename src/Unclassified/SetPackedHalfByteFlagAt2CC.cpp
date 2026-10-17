#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0206E2A0; symbol: func_0206e2a0; size: 0x3C.
ARM void SetPackedHalfByteFlagAt2CC(void *param_1, int param_2) {
    if (param_2 >= 0xcc) return;
    if (param_2 < 0) return;
    int index = param_2 / 2;
    unsigned int bit = (param_2 % 2) ? 0x80 : 8;
    unsigned char *byte = (unsigned char *)param_1 + 0x2cc + index;
    *byte |= bit;
}
}
