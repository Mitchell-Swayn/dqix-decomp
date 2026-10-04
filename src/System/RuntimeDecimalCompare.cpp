#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

// Compare discarded digits to half; an exact tie rounds to an even last digit.
extern "C" int func_020095b0(RuntimeDecimal* decimal, int index)
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
