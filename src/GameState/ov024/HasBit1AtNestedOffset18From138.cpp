#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021FB430; symbol: func_ov024_021fb430; size: 0x18.
extern "C" int HasBit1AtNestedOffset18From138(void *object) {
    unsigned int *nested = *(unsigned int **)((char *)object + 0x138);
    return (*(unsigned int *)((char *)nested + 0x18) & 2) != 0;
}
