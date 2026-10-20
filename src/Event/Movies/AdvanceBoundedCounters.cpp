#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218F2F0; symbol: func_ov016_0218f2f0; size: 0x40.
extern "C" int AdvanceBoundedCounters(void *self) {
    unsigned *base = (unsigned *)self;
    unsigned completed = base[0x9c / 4];
    if (completed >= base[0xa0 / 4]) return 0;
    base[0x9c / 4] = completed + 1;
    unsigned current = base[0xc4 / 4] + 1;
    base[0xc4 / 4] = current;
    if (current == base[0xa8 / 4]) base[0xc4 / 4] = 0;
    return 1;
}
