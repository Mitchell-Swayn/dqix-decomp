#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 3
// Original: arm9/main @ 0x020D1B28; symbol: func_020d1b28; size: 0x40.
extern "C" void CRC_InitializeEightBitPolynomialTable(unsigned char* table, unsigned int polynomial)
{
    unsigned int value;
    unsigned int index = 0;
    do {
        value = index;
        unsigned int bit = 0;
        do {
            if (value & 0x80)
                value = polynomial ^ (value << 1);
            else
                value <<= 1;
            ++bit;
        } while (bit < 8);
        table[index] = (unsigned char)value;
        ++index;
    } while (index < 0x100);
}
