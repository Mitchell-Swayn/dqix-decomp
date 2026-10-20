#include <globaldefs.h>
ARM

// Original: arm9/ov027 @ 0x021DAB38; symbol: func_ov027_021dab38; size: 0x4C.
extern "C" unsigned int Network_CalculateOnesComplementChecksum(const unsigned short *data, int byteLength) {
    unsigned int sum = 0;
    int count = byteLength >> 1;
    if (count > 0) {
        do {
            sum += *data++;
            count--;
        } while (count > 0);
    }
    unsigned int high = sum >> 16;
    sum = (sum << 16) >> 16;
    sum += high;
    sum += sum >> 16;
    return (sum ^ 0xFFFF) & 0xFFFF;
}
