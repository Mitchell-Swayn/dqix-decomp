#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov004 @ 0x0216768C; symbol: func_ov004_0216768c; size: 0x18.
extern "C" int Ov004_SetField2C8OnReadObject(void) {
    unsigned int object = ReadWordFieldAtOffset1C();
    *(unsigned int *)(object + 0x2c8) = 1;
    return 0;
}
