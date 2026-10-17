#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F69B4; symbol: func_ov024_021f69b4; size: 0x68.
extern "C" void *Grotto_FindEntryBySlotIndex(void *base, int index) {
    int valid;
    if (index < 0) goto invalid;
    if (index > 3) goto invalid;
    valid = 1;
    goto checked;
invalid:
    valid = 0;
checked:
    if (valid == 0) goto no_match;
    for (int i = 0; i < 4; ++i) {
        int stride = i * 0x448;
        if (*(int *)((char *)base + stride + 0x9A4) == index)
            return (char *)base + 0x958 + stride;
    }
no_match:
    return 0;
}
