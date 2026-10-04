#include "std_library_functions.h"

extern "C" uint32_t data_020eef30 = 1;

int rand()
{
    data_020eef30 = data_020eef30 * 0x41c64e6d + 12345;
    return (data_020eef30 >> 16) & 0x7fff;
}

void srand(int seed)
{
    data_020eef30 = seed;
}
