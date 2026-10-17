#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned long long data_ov016_0219d0c0[];
// Original: arm9/ov016 @ 0x0218BCC4; symbol: func_ov016_0218bcc4; size: 0x24.
extern "C" void IncrementGlobal64BitCounterAt48(void) {
    ++data_ov016_0219d0c0[9];
}
