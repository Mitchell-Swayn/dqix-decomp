#include "AnimatedRectangle.h"

extern "C" void func_ov005_021538fc(AnimatedRectangle*, const fix32_t* target, fix32_t* current,
                                   fix32_t rate, fix32_t threshold)
{
    fix32_t difference = *target - *current;
    fix32_t value;
    if (fix32abs(difference) < threshold)
        value = *target;
    else {
        difference = FIX32_MULTIPLY(difference, rate);
        value = *current + difference;
    }
    *current = value;
}
