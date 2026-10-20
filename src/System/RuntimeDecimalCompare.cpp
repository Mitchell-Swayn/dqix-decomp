#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

// Compare discarded digits to half; an exact tie rounds to an even last digit.
// Original: arm9/main @ 0x020095B0; symbol: func_020095b0; size: 0x6C.
extern "C" int Runtime_CompareDiscardedDecimalDigitsToHalf(RuntimeDecimal* decimal, int index)
{
    const unsigned char* current = decimal->digits + index;
    if (*current > 5)
        return 1;
    if (*current < 5)
        return -1;
    const unsigned char* end = decimal->digits + decimal->length;
    ++current;
    if (current < end) {
        do {
            if (*current)
                return 1;
            ++current;
        } while (current < end);
    }
    return decimal->digits[index - 1] & 1 ? 1 : -1;
}
