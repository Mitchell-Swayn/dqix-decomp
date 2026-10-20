/* Two bounded values are written to indexed wireless registers0x13 and0x35. */
#pragma dont_inline on
extern int ARM7_WriteWirelessIndexedRegister(unsigned int index, unsigned int value);
// Original: arm7/mainram @ 0x027E9674; symbol: func_027e9674; size: 0x44.
int ARM7_SetWirelessIndexedParameterPair(unsigned short first, unsigned short second)
{
    if (first > 3) return 5;
    if (second > 63) return 5;
    ARM7_WriteWirelessIndexedRegister(0x13, first);
    ARM7_WriteWirelessIndexedRegister(0x35, second);
    return 0;
}
