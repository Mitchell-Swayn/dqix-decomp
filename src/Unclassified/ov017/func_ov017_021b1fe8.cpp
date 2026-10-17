#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1FE8; symbol: func_ov017_021b1fe8; size: 0x14.
extern "C" unsigned int func_ov017_021b1fe8(void *object) {
    unsigned char *pointer = *(unsigned char **)((unsigned char *)object + 0x24);
    if (pointer != 0)
        return pointer[0x44];
    return 0;
}
