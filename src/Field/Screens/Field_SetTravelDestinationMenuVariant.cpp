#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021A932C; symbol: func_ov017_021a932c; size: 0x10.
extern "C" void Field_SetTravelDestinationMenuVariant(void *object, int value) {
    if (value)
        value = 1;
    *(unsigned int *)((unsigned char *)object + 0x14) = value;
}
