#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02156038; symbol: func_ov000_02156038; size: 0x18.
extern "C" int Combat_HasParalysis(void *object) {
    unsigned int *nested = *(unsigned int **)((char *)object + 0x138);
    return (*(unsigned int *)((char *)nested + 0x14) & 8) != 0;
}
