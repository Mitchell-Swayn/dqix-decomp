#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218CA70; symbol: func_ov016_0218ca70; size: 0x38.
extern "C" unsigned int System_ReadMaskedHardwareStatus(void) {
    unsigned int status = *(volatile unsigned short *)0x04000130;
    status |= *(volatile unsigned short *)0x027fffa8;
    status = (status ^ 0x2fff) & 0x2fff;
    return status & 0xffff;
}
