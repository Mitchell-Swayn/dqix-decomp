#include <globaldefs.h>

// Original: arm9/ov000 @ 0x021815c8; symbol: func_ov000_021815c8; size: 0x1c.
extern "C" int ReadSignedByteAtStoredIndex(void* object) {
    int index = *(signed char*)((unsigned char*)object + 0x1d6b);
    if (index < 0) return -1;
    return *(signed char*)((unsigned char*)object + 0x70 + index);
}
