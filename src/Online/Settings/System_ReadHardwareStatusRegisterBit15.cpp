#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02231538; symbol: func_ov031_02231538; size: 0x20.
extern "C" int System_ReadHardwareStatusRegisterBit15(void) {
    unsigned int status = *(volatile unsigned short *)0x027fffa8;
    int bit = (int)(status & 0x8000) >> 15;
    bool isSet = bit;
    return isSet;
}
