#include <globaldefs.h>
ARM
extern unsigned char data_ov031_0224e6a0[];
// Original: arm9/ov031 @ 0x0221B8B4; symbol: func_ov031_0221b8b4; size: 0x30.
extern "C" unsigned short System_SetGlobalControlByteAndReturnHalfword(int, unsigned int value, int overrideValue) {
    *(volatile unsigned short *)data_ov031_0224e6a0 = (unsigned short)(value & 0xff);
    *(volatile unsigned int *)(data_ov031_0224e6a0 + 4) = 1;
    if (overrideValue)
        *(volatile unsigned short *)data_ov031_0224e6a0 = 0xff;
    return *(volatile unsigned short *)data_ov031_0224e6a0;
}
