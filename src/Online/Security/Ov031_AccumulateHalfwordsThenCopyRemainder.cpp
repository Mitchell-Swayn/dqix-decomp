#include <globaldefs.h>
// Original: arm9/ov031 @ 0x0220BC18; symbol: func_ov031_0220bc18; size: 0x64.
extern "C" void Ov031_AccumulateHalfwordsThenCopyRemainder(unsigned short *destination, const unsigned short *source, unsigned int accumulator, int count) {
    int i = 0;
    if (count > 0) {
        for (;;) {
            accumulator += source[i];
            destination[i] = (unsigned short)accumulator;
            accumulator >>= 16;
            if (accumulator == 0) break;
            i++;
            if (i >= count) break;
        }
    }
    if (destination == source) return;
    i++;
    if (i >= count) return;
    do {
        destination[i] = source[i];
        i++;
    } while (i < count);
}
