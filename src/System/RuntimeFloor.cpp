#pragma optimize_for_size off

// Binary64 word access follows the pinned little-endian ARM runtime ABI.
extern "C" double func_02008f5c(double value)
{
    int high = ((int*)&value)[1];
    unsigned int mask, incremented;
    int exponent = ((high >> 20) & 0x7ff) - 1023;
    int low = ((int*)&value)[0];
    if (exponent < 20) {
        if (exponent < 0) {
            if (1.0e300 + value > 0.0) {
                if (high >= 0) high = low = 0;
                else if ((high & 0x7fffffff) | low) {
                    high = 0xbff00000;
                    low = 0;
                }
            }
        } else {
            mask = 0x000fffff >> exponent;
            if (((high & mask) | low) == 0)
                return value;
            if (1.0e300 + value > 0.0) {
                if (high < 0) high += 0x00100000 >> exponent;
                high &= ~mask;
                low = 0;
            }
        }
    } else if (exponent > 51) {
        if (exponent == 1024)
            return value + value;
        return value;
    } else {
        mask = 0xffffffff >> (exponent - 20);
        if ((low & mask) == 0)
            return value;
        if (1.0e300 + value > 0.0) {
            if (high < 0) {
                if (exponent == 20) ++high;
                else {
                    incremented = low + (1 << (52 - exponent));
                    if (incremented < (unsigned int)low) ++high;
                    low = incremented;
                }
            }
            low &= ~mask;
        }
    }
    ((int*)&value)[1] = high;
    ((int*)&value)[0] = low;
    return value;
}
