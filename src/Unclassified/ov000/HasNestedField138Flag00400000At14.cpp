#include <globaldefs.h>

// Original: arm9/ov000 @ 0x021598D4; symbol: func_ov000_021598d4; size: 0x18.
extern "C" int HasNestedField138Flag00400000At14(void* object) {
    unsigned char* bytes = (unsigned char*)object;
    unsigned int state = *(unsigned int*)(*(unsigned int*)(bytes + 0x138) + 0x14);
    return (state & 0x00400000) != 0;
}
