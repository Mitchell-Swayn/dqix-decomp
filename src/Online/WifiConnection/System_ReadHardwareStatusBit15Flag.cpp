#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022348AC; symbol: func_ov031_022348ac; size: 0x20.
extern "C" int System_ReadHardwareStatusBit15Flag(void) {
    unsigned int status = *(volatile unsigned short *)0x027fffa8;
    int bit = (int)(status & 0x8000) >> 15;
    bool isSet = bit;
    return isSet;
}
