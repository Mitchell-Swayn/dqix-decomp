#include <globaldefs.h>
extern "C" void Ov031_AccumulateHalfwordsThenCopyRemainder(unsigned short *, const unsigned short *, unsigned int, int);
// Original: arm9/ov031 @ 0x0220BC7C; symbol: func_ov031_0220bc7c; size: 0x40.
extern "C" void Ov031_InvertThenAccumulateHalfwords(unsigned short *values, int count) {
    int i = 0;
    if (count <= 0) goto finished;
    do {
        values[i] = (unsigned short)~values[i];
        i++;
    } while (i < count);
finished:
    Ov031_AccumulateHalfwordsThenCopyRemainder(values, values, 1, count);
}
