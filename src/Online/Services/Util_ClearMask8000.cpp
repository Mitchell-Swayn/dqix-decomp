#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02211018; symbol: Util_ClearMask8000; size: 0x8.
// Returns the input word with bit mask 0x8000 cleared.
extern "C" unsigned int Util_ClearMask8000(unsigned int value) {
    return value & ~0x8000u;
}
