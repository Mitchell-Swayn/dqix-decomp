#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0215516C; symbol: func_ov000_0215516c; size: 0x18.
extern "C" int HasNestedField138Flag08000000At14(void* object) {
    unsigned char* bytes = (unsigned char*)object;
    unsigned int state = *(unsigned int*)(*(unsigned int*)(bytes + 0x138) + 0x14);
    return (state & 0x08000000) != 0;
}
