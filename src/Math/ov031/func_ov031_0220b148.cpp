#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0220B148; symbol: func_ov031_0220b148; size: 0x44.
extern "C" unsigned int func_ov031_0220b148(unsigned int index, unsigned int* table) {
    unsigned int value = table[(index + 0xd) & 0xf] ^ table[index ^ 8] ^ table[(index + 2) & 0xf] ^ table[index];
    value = (value << 1) | (value >> 31);
    table[index] = value;
    return value;
}
