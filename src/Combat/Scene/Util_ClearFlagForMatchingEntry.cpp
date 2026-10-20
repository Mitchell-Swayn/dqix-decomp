#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02167434; symbol: func_ov000_02167434; size: 0x50.
extern "C" void Util_ClearFlagForMatchingEntry(void *base, int value) {
    int i = 0;
    while (i < *(volatile unsigned char *)((unsigned char *)base + 0x5E00)) {
        if (*(int *)((unsigned char *)base + 0x5E04 + i * 4) == value) {
            *(unsigned char *)((unsigned char *)base + 0x5E01) &= ~(1 << i);
            return;
        }
        i++;
    }
}
