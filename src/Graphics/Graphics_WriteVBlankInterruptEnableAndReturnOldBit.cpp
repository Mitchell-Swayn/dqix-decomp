#pragma optimize_for_size off
#include <globaldefs.h>

// Original: arm9/main @ 0x020C3864; symbol: func_020c3864; size: 0x34.
extern "C" unsigned short Graphics_WriteVBlankInterruptEnableAndReturnOldBit(int enable)
{
    volatile unsigned short* displayStatus = (volatile unsigned short*)0x04000004;
    unsigned short previous = *displayStatus;
    unsigned short previousBit = previous & 8;
    if (enable != 0)
    {
        unsigned short current = *displayStatus;
        *displayStatus = current | 8;
        return previousBit;
    }
    unsigned short current = *displayStatus;
    *displayStatus = current & ~8;
    return previousBit;
}
