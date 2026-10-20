#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220BE04; symbol: func_ov031_0220be04; size: 0x34.
extern "C" void Math_AddCarryToHalfwords(unsigned short *values, unsigned int carry, int index, int limit) {
    while (carry != 0 && index < limit) {
        unsigned int sum = values[index] + carry;
        values[index] = (unsigned short)sum;
        carry = sum >> 16;
        index++;
    }
}
