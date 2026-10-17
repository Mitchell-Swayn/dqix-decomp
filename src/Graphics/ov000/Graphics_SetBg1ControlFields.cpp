#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02172978; symbol: func_ov000_02172978; size: 0x34.
extern "C" void Graphics_SetBg1ControlFields(unsigned int field14, unsigned int field7, unsigned int field8, unsigned int field2, unsigned int field13) {
    *(volatile unsigned short *)0x0400100A = (*(volatile unsigned short *)0x0400100A & 0x43) | (field14 << 14) | (field7 << 7) | (field8 << 8) | (field2 << 2) | (field13 << 13);
}
