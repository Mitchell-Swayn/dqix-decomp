#include <globaldefs.h>
ARM
// Original: arm9/ov006 @ 0x021585AC; symbol: func_ov006_021585ac; size: 0x18.
extern "C" void KrakPot_RequestMenuExitOnce(unsigned char *p) {
    if (p[0x434] == 0) { p[0x434] = 1; p[0x433] = 1; }
}
