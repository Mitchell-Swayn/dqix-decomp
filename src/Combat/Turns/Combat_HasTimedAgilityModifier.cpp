#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215994C; symbol: func_ov000_0215994c; size: 0x18.
extern "C" int Combat_HasTimedAgilityModifier(void *object) {
    unsigned int *nested = *(unsigned int **)((char *)object + 0x138);
    return (*(unsigned int *)((char *)nested + 0x14) & 0x1000) != 0;
}
