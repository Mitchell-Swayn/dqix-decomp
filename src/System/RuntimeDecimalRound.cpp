#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x0200966C; symbol: func_0200966c; size: 0x40.
extern "C" void RuntimeDecimalRound_RoundToDigitCount(RuntimeDecimal* decimal, int digits)
{
    if (digits <= 0)
        return;
    if (digits >= decimal->length)
        return;
    int direction = Runtime_CompareDiscardedDecimalDigitsToHalf(decimal, digits);
    decimal->length = digits;
    if (direction < 0)
        return;
    __dorounddecup(decimal, digits);
}
