#include <globaldefs.h>
ARM
extern "C" void _s32_div_f(void);
// Original: arm9/ov003 @ 0x0215E930; symbol: func_ov003_0215e930; size: 0x74.
extern "C" int Script_FindHalfwordAndReturnDividedIndex(void *array, int target, unsigned char *remainder, unsigned char *quotient) {

    signed char count = *((signed char *)array + 3);
    short *values = *(short **)((char *)array + 4);
    short index;
    short *current = values;
    for (index = 0; index < count; index++, current++) {
        if (*current == target) {
            *remainder = index % *((signed char *)array + 1);
            *quotient = index / *((signed char *)array + 1);
            return 0;
        }
    }
    return 1;
}
