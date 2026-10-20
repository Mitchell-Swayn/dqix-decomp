#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B04C0; symbol: func_ov017_021b04c0; size: 0x20.
extern "C" unsigned int Ov017_ClearBytesOrReadStatus(void *object) {
    if (*(unsigned int *)((char *)object + 0x28)) {
        *((unsigned char *)object + 0x21) = 0;
        *((unsigned char *)object + 0x22) = 0;
        return 7;
    }
    return *((unsigned char *)object + 0x0a);
}
