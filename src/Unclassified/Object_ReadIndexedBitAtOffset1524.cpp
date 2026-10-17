#include <globaldefs.h>
ARM
extern "C" {
// Original: arm9/main @ 0x0205E830; symbol: func_0205e830; size: 0x24.
unsigned int Object_ReadIndexedBitAtOffset1524(unsigned char *p, int index) {
    unsigned char *bits = p + ((unsigned int)index >> 3) + 0x1524;
    int value = *bits;
    return (1U << (index % 8)) & value;
}
}
