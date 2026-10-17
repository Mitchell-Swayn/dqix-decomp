#include <globaldefs.h>
extern "C" int rand();

// Original: arm9/main @ 0x020404C0; symbol: func_020404c0; size: 0x44.
extern "C" void InitializeEightWordsWithRandomDelay2000To3999(int output[8])
{
    output[0] = 0;
    output[1] = rand() % 2000 + 2000;
    output[3] = 0;
    output[2] = 0;
    output[5] = 0;
    output[6] = 0;
    output[7] = 0;
    output[4] = 0;
}
