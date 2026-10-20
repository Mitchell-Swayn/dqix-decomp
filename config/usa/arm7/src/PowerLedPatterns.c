/* Twelve software LED patterns selected by indices 4 through 15. */
#include "PowerLed.h"
const PowerLedPattern ARM7_PowerLedPatterns[12] = {
    {0xaa00000000000000ULL, 8, 1},
    {0xcc00000000000000ULL, 8, 1},
    {0xe380000000000000ULL, 12, 1},
    {0xf0f0000000000000ULL, 16, 1},
    {0xf83e000000000000ULL, 20, 1},
    {0xfc00000000000000ULL, 12, 1},
    {0xff00000000000000ULL, 16, 1},
    {0xffc0000000000000ULL, 20, 1},
    {0xff00000000000000ULL, 32, 1},
    {0xff00ff0000000000ULL, 32, 1},
    {0xffffff0000000000ULL, 32, 1},
    {0xc300000000000000ULL, 40, 2},
};
