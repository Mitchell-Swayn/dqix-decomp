#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov023_021fd563[];
// Original: arm9/ov023 @ 0x021DCB70; symbol: func_ov023_021dcb70; size: 0x34.
extern "C" int func_ov023_021dcb70(volatile unsigned int *value) {
    if (value == 0)
        return 0;
    unsigned int type = (value[2] << 28) >> 28;
    unsigned int index = type <= 7;
    return data_ov023_021fd563[index];
}
