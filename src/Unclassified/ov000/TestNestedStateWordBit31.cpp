#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02158324; symbol: func_ov000_02158324; size: 0x18.
extern "C" int TestNestedStateWordBit31(void* object) {
    unsigned int* nested = *(unsigned int**)((unsigned char*)object + 0x138);
    return (nested[5] & 0x80000000u) != 0;
}
