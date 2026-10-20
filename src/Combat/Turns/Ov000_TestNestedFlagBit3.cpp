#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02156C94; symbol: func_ov000_02156c94; size: 0x18.
extern "C" int Ov000_TestNestedFlagBit3(void *object) {
    void *nested = *(void **)((char *)object + 0x138);
    return (*(unsigned int *)((char *)nested + 0x18) & 8) != 0;
}
