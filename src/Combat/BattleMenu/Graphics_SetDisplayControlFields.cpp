#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02172944; symbol: func_ov000_02172944; size: 0x34.
extern "C" void Graphics_SetDisplayControlFields(unsigned int field14, unsigned int field7, unsigned int field8, unsigned int field2, unsigned int field13) {
    *(volatile unsigned short *)0x04001008 = (*(volatile unsigned short *)0x04001008 & 0x43) | (field14 << 14) | (field7 << 7) | (field8 << 8) | (field2 << 2) | (field13 << 13);
}
