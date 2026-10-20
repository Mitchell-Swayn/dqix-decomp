#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02159964; symbol: func_ov000_02159964; size: 0x18.
extern "C" int Combat_HasTimedCharmModifier(void *object) {
    unsigned int *pointer = *(unsigned int **)((unsigned char *)object + 0x138);
    return (pointer[5] & 0x2000) != 0;
}
