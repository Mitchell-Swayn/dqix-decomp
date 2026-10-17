#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02156B08; symbol: func_ov000_02156b08; size: 0x18.
extern "C" int HasNestedField138Flag40At18(void* object) {
    unsigned char* bytes = (unsigned char*)object;
    unsigned int state = *(unsigned int*)(*(unsigned int*)(bytes + 0x138) + 0x18);
    return (state & 0x40) != 0;
}
