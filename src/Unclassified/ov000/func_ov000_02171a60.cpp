#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02171A60; symbol: func_ov000_02171a60; size: 0x14.
extern "C" unsigned func_ov000_02171a60(void *object) {
    return (*(unsigned *)((char *)object + 0x28) & 1) != 0;
}
