#include <globaldefs.h>
#pragma optimization_level 4
ARM
// Original: arm9/ov024 @ 0x021EDCA4; symbol: func_ov024_021edca4; size: 0x24.
extern "C" int Ov024_TestNestedByteEqualFive(void *object) {
    int value = *((unsigned char *)*(void **)((char *)object + 0x138) + 0x21);
    int result = value == 5;
    if (result != 0)
        return 1;
    return 0;
}
