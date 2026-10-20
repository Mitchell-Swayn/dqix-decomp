#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216D368; symbol: Combat_StoreThreeWords; size: 0x8.
// Stores the three incoming 32-bit values consecutively at the destination, matching the caller-built combat selection record.
ARM
extern "C" void Combat_StoreThreeWords(void *destination, unsigned int first, unsigned int second, unsigned int third) {
    unsigned int *words = (unsigned int *)destination;
    words[0] = first;
    words[1] = second;
    words[2] = third;
}
