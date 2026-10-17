#include <globaldefs.h>
ARM
extern "C" unsigned short data_020f226c;
extern "C" unsigned short data_02111220;
// Original: arm9/main @ 0x020C38D4; symbol: func_020c38d4; size: 0x48.
// NitroSDK GX_DispOn restores the saved main display mode, defaulting to graphics.
extern "C" void GX_DispOn()
{
    data_020f226c = 1;
    volatile unsigned int* displayControl = (volatile unsigned int*)0x04000000;
    if (data_02111220)
        *displayControl = (*displayControl & ~0x30000) | (data_02111220 << 16);
    else
        *displayControl = *displayControl | 0x10000;
}
