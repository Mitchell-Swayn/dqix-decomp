#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x02159240; symbol: func_ov003_02159240; size: 0x10.
extern "C" void Ov003_SetFlagBit3At59F(void *object) {
    *(unsigned char *)((char *)object + 0x59f) |= 8;
}
