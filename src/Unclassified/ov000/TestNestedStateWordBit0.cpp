#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02156258; symbol: func_ov000_02156258; size: 0x18.
extern "C" int TestNestedStateWordBit0(void* object) {
    unsigned int* nested = *(unsigned int**)((unsigned char*)object + 0x138);
    return (nested[6] & 1) != 0;
}
