#include <globaldefs.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/ov031 @ 0x0220C92C; symbol: func_ov031_0220c92c; size: 0x44.
// Writes a little-endian halfword integer backwards into a big-endian byte buffer.
extern "C" void Math_StoreHalfwordIntegerBigEndian(unsigned char* output, const unsigned short* input, int length)
{
    output += length - 1;
    if (length > 1) do {
        *output-- = *input;
        *output-- = *input++ >> 8;
        length -= 2;
    } while (length > 1);
    if (length > 0) *output = *input;
}
