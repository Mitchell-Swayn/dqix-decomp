#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02211644; symbol: func_ov031_02211644; size: 0x14.
extern "C" int Ov031_TestLowBitAt20(void *object) {
    return (*(unsigned int *)((char *)object + 0x20) & 1) != 0;
}
