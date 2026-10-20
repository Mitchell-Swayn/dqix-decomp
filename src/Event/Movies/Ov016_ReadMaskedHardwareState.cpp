#include <globaldefs.h>
// Original: arm9/ov016 @ 0x0218D2BC; symbol: func_ov016_0218d2bc; size: 0x38.
extern "C" ARM unsigned short Ov016_ReadMaskedHardwareState() {
    unsigned short first = *(volatile unsigned short*)0x04000130;
    unsigned short second = *(volatile unsigned short*)0x027fffa8;
    return (unsigned short)(((first | second) ^ 0x2fff) & 0x2fff);
}
