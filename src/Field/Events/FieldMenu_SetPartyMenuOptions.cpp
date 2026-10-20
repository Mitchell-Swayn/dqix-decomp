#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021A55A4; symbol: func_ov017_021a55a4; size: 0xC.
extern "C" void FieldMenu_SetPartyMenuOptions(unsigned char *p, unsigned char a, unsigned char b) {
    p[0x20] = a;
    p[0x21] = b;
}
