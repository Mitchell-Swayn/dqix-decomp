#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021B1FFC; symbol: func_ov017_021b1ffc; size: 0x14.
extern "C" void *OnlineDownload_GetErrorCode(void *object) {
    void *value = *(void **)((char *)object + 0x24);
    return value ? *(void **)((char *)value + 0x394) : 0;
}
