// Original: arm9/main @ 0x0204BD7C; symbol: func_0204bd7c; size: 0x44.
#include <globaldefs.h>
// ARM9 main, original func_0204bd7c at 0x0204bd7c.
// Proposed semantic name: DecodePackedDecimalIdentifier.
extern "C" ARM unsigned short DecodePackedDecimalIdentifier(const unsigned short *packed)
{
    unsigned short value = *packed;
    unsigned short hundreds = value & 31;
    unsigned short tens = (value & 0x3e0) >> 5;
    unsigned short units = (value & 0x7c00) >> 10;
    return 30000 + hundreds * 100 + tens * 10 + units;
}
