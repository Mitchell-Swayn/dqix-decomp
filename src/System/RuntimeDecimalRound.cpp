#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

extern "C" void func_0200966c(RuntimeDecimal* decimal, int digits)
{
    if (digits <= 0)
        return;
    if (digits >= decimal->length)
        return;
    int direction = func_020095b0(decimal, digits);
    decimal->length = digits;
    if (direction < 0)
        return;
    func_0200961c(decimal, digits);
}
