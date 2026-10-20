#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02156050; symbol: func_ov000_02156050; size: 0x18.
extern "C" int Combat_HasTransientActionBlockingStatus(void *p) {
    unsigned int value = *(unsigned int *)(*(unsigned char **)((unsigned char *)p + 0x138) + 0x14);
    return (value & 0x80000) != 0;
}
