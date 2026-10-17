#include "std_library_functions.h"

extern "C" uint32_t data_020eef30 = 1;

// Original: arm9/main @ 0x02003D14; symbol: rand; size: 0x34.
int rand()
{
    data_020eef30 = data_020eef30 * 0x41c64e6d + 12345;
    return (data_020eef30 >> 16) & 0x7fff;
}

// Original: arm9/main @ 0x02003D48; symbol: srand; size: 0x10.
void srand(int seed)
{
    data_020eef30 = seed;
}
