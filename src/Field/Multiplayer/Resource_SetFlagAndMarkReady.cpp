#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AFB34; symbol: func_ov017_021afb34; size: 0x50.
extern "C" void Resource_SetFlagAndMarkReady(unsigned char *entry, unsigned int bit) {
    entry[0x27] |= 1 << bit;
    for (int i = 1; i < 4; i++) {
        if ((entry + i)[0x1B] == 1 && (entry[0x27] & (1 << i)) == 0) break;
    }
    entry[0x27] |= 0x10;
}
