#include "Util/Random.h"
// Original: arm9/main @ 0x02074838; symbol: func_02074838; size: 0x70.
// Scale an integer by a random factor from either [0.95,1.05] or [1.5,2.0].
extern "C" float RandomlyScaleInteger(int value, int narrowRange, Random* random)
{
    if (!random) random = &data_02108ddc;
    if (narrowRange)
        return (float)value * NextRandomFloatBetween(random, 0.95f, 1.05f);
    return (float)value * NextRandomFloatBetween(random, 1.5f, 2.0f);
}
