#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02163344; symbol: func_ov000_02163344; size: 0x34.
extern "C" void func_ov000_02163344(unsigned char *base, unsigned int value, unsigned short field_cc, unsigned char field_c8, unsigned short field_c9, unsigned short field_ca) {
    *(unsigned int *)(base + 0x58C4) = value;
    *(unsigned short *)(base + 0x58CC) = field_cc;
    *(unsigned char *)(base + 0x58C8) = field_c8;
    *(unsigned char *)(base + 0x58C9) = (unsigned char)field_c9;
    *(unsigned short *)(base + 0x58CA) = field_ca;
    *(unsigned int *)(base + 0x55F4) |= 0x2000;
}
