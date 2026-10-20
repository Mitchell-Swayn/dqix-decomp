#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B8B34; symbol: func_ov017_021b8b34; size: 0x20.
extern "C" void Util_ClearSixHalfwords(void *data) {
    *(unsigned short *)((char *)data + 0) = 0;
    *(unsigned short *)((char *)data + 2) = 0;
    *(unsigned short *)((char *)data + 4) = 0;
    *(unsigned short *)((char *)data + 6) = 0;
    *(unsigned short *)((char *)data + 8) = 0;
    *(unsigned short *)((char *)data + 0xa) = 0;
}
