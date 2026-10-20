#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021599DC; symbol: func_ov000_021599dc; size: 0x18.
extern "C" int Ov000_TestNestedFlagBit8(void *object) {
    void *nested = *(void **)((char *)object + 0x138);
    return (*(unsigned int *)((char *)nested + 0x18) & 0x100) != 0;
}
