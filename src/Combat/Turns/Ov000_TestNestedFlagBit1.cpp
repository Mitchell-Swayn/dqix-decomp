#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021598EC; symbol: func_ov000_021598ec; size: 0x18.
extern "C" int Ov000_TestNestedFlagBit1(void *object) {
    void *nested = *(void **)((char *)object + 0x138);
    return (*(unsigned int *)((char *)nested + 0x18) & 2) != 0;
}
