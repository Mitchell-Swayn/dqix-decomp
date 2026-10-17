#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);

// Original: arm9/ov001 @ 0x0215E4F0; symbol: func_ov001_0215e4f0; size: 0x24.
extern "C" int Unclassified_ClearGlobalByte19B1WhenField1CExists(void) {
    unsigned char *object = (unsigned char *)ReadWordFieldAtOffset1C();
    if (object == 0)
        return 0;
    object += 0x1000;
    object[0x9b1] = 0;
    return 1;
}
