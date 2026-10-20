#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02207074; symbol: func_ov031_02207074; size: 0x48.
extern "C" unsigned int Network_GetSocketReadableBytes(void *object) {
    void *context = *(void **)((char *)object + 0x64);
    unsigned int result = 0;
    if (context != 0) {
        int mode = *(signed char *)((char *)object + 0x73);
        if (mode == 1) {
            void *nested = *(void **)((char *)context + 0x104);
            if (nested != 0) result = *(unsigned short *)((char *)nested + 4);
        } else if (mode == 0 || mode == 4) {
            result = *(unsigned int *)((char *)object + 0x44) - *(unsigned int *)((char *)context + 0xf8);
        }
    }
    return result;
}
