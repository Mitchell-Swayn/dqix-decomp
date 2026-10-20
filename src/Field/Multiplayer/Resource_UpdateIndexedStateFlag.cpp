#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021954C4; symbol: func_ov017_021954c4; size: 0x5C.
extern "C" void Resource_UpdateIndexedStateFlag(unsigned char* base, unsigned index) {
    unsigned char* state = base + 0x4000;
    unsigned char* entry = *(unsigned char**)(state + 0x41c);
    if (entry[0] != 0 && entry[2] == index) {
        entry[0] = 0;
        entry[1] = 0;
        unsigned char* object = *(unsigned char**)(base + 0x3b30);
        if (object[3] != 0) object[8] = 1;
    }
    base[0x431e] = base[0x431e] | (1 << index);
}
